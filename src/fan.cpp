#include <fan.h>
#include <Arduino.h>

static void setPwmPin9(float f);
static void setupTimer1();
static void setupTimer2();
unsigned long volatile ts1=0,ts2=0;

#define PIN_SENSE 2 //where we connected the fan sense pin. Must be an interrupt capable pin (2 or 3 on Arduino Uno)
#define DEBOUNCE 0 //0 is fine for most fans, crappy fans may require 10 or 20 to filter out noise
#define FANSTUCK_THRESHOLD 500 //if no interrupts were received for 500ms, consider the fan as stuck and report 0 RPM

void fan_init(){
    pinMode(9,OUTPUT);
    setupTimer1();
    setupTimer2();
    pinMode(PIN_SENSE,INPUT_PULLUP); //set the sense pin as input with pullup resistor
    attachInterrupt(digitalPinToInterrupt(PIN_SENSE),fan_rpmInteruptHandler,FALLING); //set tachISR to be triggered when the signal on the sense pin goes low
}

void fan_setSpeed(uint8_t speed){
    float speedFloat = (float)speed / 100;
    setPwmPin9(speedFloat);
}

static void setupTimer1(){
    //Set PWM frequency to about 25khz on pins 9,10 (timer 1 mode 10, no prescale, count to 320)
    TCCR1A = (1 << COM1A1) | (1 << COM1B1) | (1 << WGM11);
    TCCR1B = (1 << CS10) | (1 << WGM13);
    ICR1 = 320;
    OCR1A = 0;
    OCR1B = 0;
}

static void setupTimer2(){
    //Set PWM frequency to about 25khz on pin 3 (timer 2 mode 7, prescale 8, count to 79)
    TIMSK2 = 0;
    TIFR2 = 0;
    TCCR2A = (1 << COM2B1) | (1 << WGM21) | (1 << WGM20);
    TCCR2B = (1 << WGM22) | (1 << CS21);
    OCR2A = 79;
    OCR2B = 0;
}

static void setPwmPin9(float f){
    f=f<0?0:f>1?1:f;
    OCR1A = (uint16_t)(320*f);
}

void fan_rpmInteruptHandler(){
    unsigned long m=millis();
    if((m-ts2)>DEBOUNCE){
        ts1=ts2;
        ts2=m;
    }
}

unsigned long fan_getRpm(){
    if(millis()-ts2<FANSTUCK_THRESHOLD&&ts2!=0){
        return (60000/(ts2-ts1))/2;
    }else return 0;
}



