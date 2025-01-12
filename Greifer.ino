/*
Dies ist ein Beispiel Programm für das einfahren/einsetzen der Greifer Backen in die Gelenk Stange oben  
Es kann beliebig verändert werden um es an die gewünschte Anwendung anzupassen.
Achtung: Sie müssen zuerst die IDs von dem Servo ändern      
*/

#include <SCServo.h>  //die erforderliche Bibliothek    

SMS_STS st;


#define BUTTON_PIN 27 //ein Taster / Schalter startet das Programm ESP32 = Pin 27 + GND
#define S_RXD 16      //je nach Steuereinheit kann die Pin-Belegung variieren ESP32 = 16
#define S_TXD 17      //je nach Steuereinheit kann die Pin-Belegung variieren ESP32 = 17  


void setup()
{
  Serial.begin(115200);
  Serial1.begin(1000000, SERIAL_8N1, S_RXD, S_TXD);
  st.pSerial = &Serial1;
  pinMode(BUTTON_PIN, INPUT_PULLUP); //D27 als Eingang mit PullUp festlegen
}

void loop()
{
  if(digitalRead(BUTTON_PIN) == LOW) //
  {

    Serial.println("Bewege Servo 4");
    st.WritePosEx(4, 3500, 5000, 50);//servo(ID4,Greifer öffnen/schließen) speed=5000，acc=50，move to position=2000.
    delay(5000);                     //Achtung, sie müssen den Positionswert vermutlich anpassen
    
    //das Programm kann beliebig verändert werden 

  }
}