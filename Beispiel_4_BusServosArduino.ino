/*
Dies ist ein Beispiel Programm für den Arduino Uno  
Es kann beliebig erweitert oder verändert werden um es an die gewünschte Anwendung anzupassen.
Achtung: der Arduino darf wehrend dem Hochladen nicht mit der Wavesahre Platine und oder Servo verbunden sein!       
*/

#include <SCServo.h>  //die erforderliche Bibliothek    

SMS_STS st;


int BUTTON_PIN = 4; //ein Taster / Schalter startet das Programm; Arduino = Pin 4 + GND / ESP32 = Pin 10 (D34) + GND
#define S_RXD 2     //je nach Steuereinheit kann die Pin-Belegung variieren; Arduino = RXD 2 / ESP32 = 16
#define S_TXD 3     //je nach Steuereinheit kann die Pin-Belegung variieren; Arduino = TXD 3 / ESP32 = 17  


void setup()
{
  Serial.begin(115200);
  Serial.begin(1000000);
  st.pSerial = &Serial;
  delay(1000);
  pinMode(BUTTON_PIN, INPUT_PULLUP);//D4 als Eingang mit PullUp festlegen
}

void loop()
{
  if(digitalRead(BUTTON_PIN) == LOW)
  {
    st.WritePosEx(1, 4095, 1000, 50);//servo(ID1,Greifer drehen) speed=1000，acc=50，move to position=4095.
    delay(2000);
    
    st.WritePosEx(1, 2000, 1000, 50);//servo(ID1,Greifer drehen) speed=1000，acc=50，move to position=2000.
    delay(2000);

    st.WritePosEx(2, 4095, 3400, 50);//servo(ID2,Gelenk1 drehen) speed=3400，acc=50，move to position=4095.
    delay(2000);
    
    st.WritePosEx(2, 2000, 5000, 50);//servo(ID2,Gelenk1 drehen) speed=5000，acc=50，move to position=2000.
    delay(2000);

    st.WritePosEx(3, 4095, 3400, 50);//servo(ID3,Gelenk2 drehen) speed=3400，acc=50，move to position=4095.
    delay(2000);
    
    st.WritePosEx(3, 2000, 5000, 50);//servo(ID3,Gelenk2 drehen) speed=5000，acc=50，move to position=2000.
    delay(2000);

    st.WritePosEx(4, 4095, 3400, 50);//servo(ID4,Greifer öffnen/schließen) speed=3400，acc=50，move to position=4095.
    delay(2000);                     //der greifer darf nur in einem gewissen bereich geöffnet/geschlossen werden
    
    st.WritePosEx(4, 2000, 5000, 50);//servo(ID4,Greifer öffnen/schließen) speed=5000，acc=50，move to position=2000.
    delay(2000);                     //der greifer darf nur in einem gewissen bereich geöffnet/geschlossen werden
    
    //das Programm kann beliebig erweitert werden 

  }
}