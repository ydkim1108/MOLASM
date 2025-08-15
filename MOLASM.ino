/*
 *                         ATtiny85
 *                      -------u-------
 *        A0 - (D 5) --| 1 PB5   VCC 8 |-- Vcc +5V
 *                     |               |
 * BLE TX A3 - (D 3) --| 2 PB3   PB2 7 |-- (D 2) - A1  -  BLE RX 
 *                     |               | 
 *        A2 - (D 4) --| 3 PB4   PB1 6 |-- (D 1) - PWM --> MOSFET
 *                     |               |      
 *              Gnd ---| 4 GND   PB0 5 |-- (D 0) - PWM --> Disabled
 *                     -----------------
 */
 
// normal delay() won't work anymore because we are changing Timer1 behavior
// Adds delay_ms and delay_us functions
#include <util/delay.h>
#include <SoftSerial.h>
#include <arduino.h>

// Clock at 8mHz
#define F_CPU 8000000  //F_CPU 8000000. This is used by delay.h library
 

#define RxD 3 //RXD = 3 
#define TxD 2 //TxD = 2
const int PWMPin = 1;  // Only works with Pin 1(PB1)

SoftSerial blueToothSerial(RxD,TxD); 


void setup() 
{ 
  blueToothSerial.begin(9600); 
  pinMode(RxD, INPUT);
  pinMode(TxD, OUTPUT);
  pinMode(PWMPin,OUTPUT);
//  setupBlueToothConnection();   

// Change the PWM frequency to 1000 Hz
  // Fast PWM Mode, Prescaler = /64
  // PWM on Pin 1(PB1), Pin 0(PB0) disabled
  // 8Mhz / (Pre-scale factor * (OCR0A + 1)
  //  TCCR0A = _BV(COM0B1) | _BV(WGM01) | _BV(WGM00);
  TCCR0A |= (1<<COM0B1) | (1<<WGM01) | (1<<WGM00); //(FAST-PWM mode / OC0B non-inverting mode / OC0B disconnected)

  //  TCCR0B = _BV(WGM02) | _BV(CS02);
  TCCR0B |= (1<<WGM02) | (1<<CS01) | (1<<CS00); // (FAST-PWM mode / Pre-scale factor = 64 / TOP = OCRA)
  // Set TOP and initialize duty cycle to zero(0)
  OCR0A = 255;    // f_PWM = 8Mhz / (Pre-scale factor * (OCR0A + 1)) = 1 kHz - DO NOT CHANGE, SETS PWM PULSE RATE)
  OCR0B = 0;     // duty cycle for Pin 1(PB1) - generates 1 500nS pulse even when 0
} 
 
void loop() 
{ 
  if(blueToothSerial.available() > 0){
    int PWMduty;
    char aa;
    String aa1;

    while (aa != 'c'){ 
      aa = blueToothSerial.read();
      aa1 += aa;
   }
  
    int aa2 = aa1.toInt();
    PWMduty = map(aa2, 0, 100, 0, 255); //(DUTY value, 0%, 100%, 0, 254)
    OCR0B = PWMduty; 

    //analogWrite(PWMPin,PWMduty);
//  blueToothSerial.print(aa2);
  delay(1000);
} 
}





