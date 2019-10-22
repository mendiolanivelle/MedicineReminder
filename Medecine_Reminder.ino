#include <DS3231.h>
#include <SoftwareSerial.h>


DS3231  rtc(A4, A5);
SoftwareSerial Module( 10 , 11 );

String PhoneNumber = "09391568859"; //change this number to the person who is going to drink the medicine
String SecondPhoneNumber = "09205482288"; // change this number to the supporting person of the patient
String PatientName = "Norman Digamos"; //Change the name of the patient

String MorningAlarm = "00:11"; //ilisi lang ning morning nga orasan
String MorningMedicine = "Anti-biotic"; // ilisi para sa name sa tambal
String MorningMedicineDosage = "300MG"; // ilisi para sa dosage sa tambal
String AfternoonAlarm = "00:18"; //ilisi lang ning afternoon nga orasan
String AfternoonMedicine = "BioGesic";// ilisi para sa name sa tambal
String AfternoonMedicineDosage = "500MG";// ilisi para sa dosage sa tambal
String EveningAlarm = "00:25";//ilisi lang ning evening nga tambal
String EveningMedicine = "Cocaine";// ilisi para sa name sa tambal
String EveningMedicineDosage = "1 grams";// ilisi para sa dosage sa tambal

bool CanText = false;


void setup() {
  rtc.begin();
  Serial.begin(9600);
  Module.begin(9600);
}

void loop() {
  Serial.println(rtc.getTimeStr(FORMAT_SHORT));
  String CurrentTime = rtc.getTimeStr(FORMAT_SHORT);
  delay(10000);
  if(CurrentTime == MorningAlarm)
  {
    SendMessage(PhoneNumber,MorningMedicine,MorningMedicineDosage);
    delay(3000);
    SendMessageToSupportingPerson(SecondPhoneNumber,MorningMedicine,MorningMedicineDosage,PatientName);
  }
  if(CurrentTime == AfternoonAlarm)
  {
    SendMessage(PhoneNumber,AfternoonMedicine,AfternoonMedicineDosage);
    delay(3000);
    SendMessageToSupportingPerson(SecondPhoneNumber,AfternoonMedicine,AfternoonMedicineDosage,PatientName);
  }
  if(CurrentTime == EveningAlarm)
  {
    SendMessage(PhoneNumber,EveningMedicine,EveningMedicineDosage);
    delay(3000);
    SendMessageToSupportingPerson(SecondPhoneNumber,EveningMedicine,EveningMedicineDosage,PatientName);
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

void SendMessage(String p_PhoneNumber,String Medicine,String Dosage) {
  Module.println( "AT+CMGF=1\r" );
  Module.println( "AT+CMGS=\"" + p_PhoneNumber + "\"\r" );
  delay( 100 );
  Module.print("Time to Drink your " + Medicine + Dosage);
  delay( 100 );
  Module.print( ( char )26 );
}
void SendMessageToSupportingPerson(String p_PhoneNumber,String Medicine,String Dosage,String Name) {
  Module.println( "AT+CMGF=1\r" );
  Module.println( "AT+CMGS=\"" + p_PhoneNumber + "\"\r" );
  delay( 100 );
  Module.print(Name + "should drink " + Medicine + Dosage);
  delay( 100 );
  Module.print( ( char )26 );
}

void ReadMessage() {
  Module.println( "AT+CMGF=1\r" );
  Module.println( "AT+CNMI=1,2,0,0,0" );
}
