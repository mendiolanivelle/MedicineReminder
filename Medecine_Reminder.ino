#include <DS3231.h>
#include <SoftwareSerial.h>


DS3231  rtc(A4, A5);
SoftwareSerial Module( 10 , 11 );

String PhoneNumber = "09981722700";

String AlarmMorning = "03:14";
String AlarmAfternoon = "12:00";
String AlarmEvening = "06:00";


void setup() {
  rtc.begin();
  Serial.begin(9600);
  Module.begin(9600);
}

void loop() {
  Serial.println(rtc.getTimeStr(FORMAT_SHORT));
  String CurrentTime = rtc.getTimeStr(FORMAT_SHORT);
  delay(10000);
  if(CurrentTime == AlarmMorning)
  {
    Serial.println("Sending Message");
    SendMessage(PhoneNumber);
    Serial.println("Finish Sending Message");
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

void SendMessage(String p_PhoneNumber) {
  Module.println( "AT+CMGF=1\r" );
  Module.println( "AT+CMGS=\"" + p_PhoneNumber + "\"\r" );
  delay( 100 );
  Module.print("Time to Drink your Antibiotic Medicine");
  delay( 100 );
  Module.print( ( char )26 );
}
