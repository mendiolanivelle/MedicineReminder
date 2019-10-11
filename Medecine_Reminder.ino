
#include <DS3231.h>
DS3231  rtc(A4, A5);
String AlarmMorning = "02:56";
String AlarmAfternoon = "12:00";
String AlarmEvening = "06:00";


void setup() {
  rtc.begin();
  Serial.begin(9600);
}

void loop() {
  Serial.println(rtc.getTimeStr(FORMAT_SHORT));
  String CurrentTime = rtc.getTimeStr(FORMAT_SHORT);
  delay(10000);
  if(CurrentTime == AlarmMorning)
  {
    Serial.println("Time to Drink your Antibiotic Medicine");
  }


}

void setdate(int date, int month, int year)
{
  rtc.setDate(date,month,year);
}

void setTime(int hour,int minutes)
{
  rtc.setTime(hour,minutes,00);
}
