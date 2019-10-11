
#include <DS3231.h>
DS3231  rtc(A4, A5);
char alarm = "06:12";


void setup() {
  rtc.begin();
  Serial.begin(9600);

}

void loop() {
  Serial.println(rtc.getTimeStr(FORMAT_SHORT));
  delay(1000);
  if(rtc.getTimeStr(FORMAT_SHORT) == "06 : 13")
  {
    Serial.println("Time to Drink your Antibiotic Medicine");
  }


}
