#include <fan.h>
#include <Arduino.h>

#define FAN_PWM_PIN 9
#define FAN_RPM_PIN 2
#define FAN_DEBOUNCE 0
#define FAN_STUCK_THRESHOLD 500

unsigned long volatile ts1=0,ts2=0;

void fan_init(){
    pinMode(FAN_RPM_PIN,INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(FAN_RPM_PIN),fan_rpmInteruptHandler,FALLING);
}

void fan_setSpeed(uint8_t speed){
    analogWrite(FAN_PWM_PIN,(int)speed * 2.55);
}

void fan_rpmInteruptHandler(){
    unsigned long m=millis();
    if((m-ts2)>FAN_DEBOUNCE){
        ts1=ts2;
        ts2=m;
    }
}

unsigned long fan_getRpm(){
    if(millis()-ts2<FAN_STUCK_THRESHOLD&&ts2!=0){
        return (60000/(ts2-ts1))/2;
    }
    else return 0;
}



