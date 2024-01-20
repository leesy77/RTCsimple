#include <Arduino.h>
#include <RTCZero.h>

#define LED_PIN   8

RTCZero rtc;

const byte sec = 0;
const byte minute = 0;
const byte hour = 16;
const byte day = 20;
const byte mon = 1;
const byte year = 24;
volatile bool TOGGLE = false;

void alarmMatch(void);

void setup() 
{
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
    rtc.begin();        //init 24hour format
    rtc.setTime(hour, minute, sec);
    rtc.setDate(day, mon, year);

    rtc.setAlarmTime(16, 0, 1);
    rtc.enableAlarm(rtc.MATCH_HHMMSS);

    rtc.attachInterrupt(alarmMatch);        			
}

void loop() 
{

}

void alarmMatch(void) 
{
    TOGGLE = !TOGGLE;
    digitalWrite(LED_PIN, TOGGLE ? HIGH : LOW);
    Serial.println("Alarm Match!");
    rtc.setTime(hour, minute, sec);
    rtc.setDate(day, mon, year);
    rtc.setAlarmTime(16, 0, 1);
}