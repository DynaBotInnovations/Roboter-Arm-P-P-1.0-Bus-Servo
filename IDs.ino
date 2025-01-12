//Genau Infos unter https://www.waveshare.com/wiki/ST3215_Servo 
//Achtung: bei der Ausführung des Programms darf nur ein Servo angeschlossen sein

#include <SCServo.h>

#define S_RXD 16 //je nach Steuereinheit kann die Pin-Belegung variieren     
#define S_TXD 17 //je nach Steuereinheit kann die Pin-Belegung variieren

SMS_STS st;
int ID_ChangeFrom = 1; // Ändern Sie die ursprüngliche Servo-ID, die Werkseinstellung ist 1.
int ID_Changeto = 2; // neue ID
void setup(){
   Serial1.begin(1000000, SERIAL_8N1, S_RXD, S_TXD);
  st.pSerial = &Serial1;
  //while(!Serial1) {}
  delay(1000);

  st.unLockEprom(ID_ChangeFrom); //Unlock EPROM-SAFE
  st.writeByte(ID_ChangeFrom, SMS_STS_ID, ID_Changeto);//Change ID
  st.LockEprom(ID_Changeto); // EPROM-SAFE is locked
}

void loop(){
  
}