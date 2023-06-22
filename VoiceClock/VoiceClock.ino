#include <NTPClient.h>
#include <Ethernet2.h>
#include "EthernetUdp2.h"
#include "DFRobotDFPlayerMini.h"
#include "SoftwareSerial.h"

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
int sensorValue = 0;
SoftwareSerial mySoftwareSerial(2, 3); // RX, TX
EthernetUDP ntpUDP;
DFRobotDFPlayerMini myDFPlayer;
unsigned long last = 0;
unsigned long last_play = 0;

NTPClient timeClient(ntpUDP, "ntp.gh.ink", 8*3600, 60000);

void setup(){
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  mySoftwareSerial.begin(9600);
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini online."));

  //----Set volume----
  myDFPlayer.volume(15);  //Set volume value (0~30).

  // start the Ethernet connection:
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    while (true) {
      delay(1); // do nothing
    }
  }

  pinMode(5, OUTPUT);
  
  timeClient.begin();
}

void loop() {
  if (myDFPlayer.available()) {
    printDetail(myDFPlayer.readType(), myDFPlayer.read());
    //Print the detail message from DFPlayer to handle different errors and states.
  }
  
  timeClient.update();

  String now = timeClient.getFormattedTime();
  String hour = now.substring(0, 2);
  String minute = now.substring(3, 5);
  String second = now.substring(6, 8);
  
  sensorValue = analogRead(A0);
  if (sensorValue < 500) {
    digitalWrite(5, HIGH);
  } else {
    digitalWrite(5, LOW);
  }

  if ((millis() - last_play) > 1000) {
    if (second == "00") {
      if (minute == "00") {
        if (hour == "00") {
          myDFPlayer.playMp3Folder(2400);
          last_play = millis();
        } else if (hour == "01") {
          myDFPlayer.playMp3Folder(100);
          last_play = millis();
        } else if (hour == "02") {
          myDFPlayer.playMp3Folder(200);
          last_play = millis();
        } else if (hour == "03") {
          myDFPlayer.playMp3Folder(300);
          last_play = millis();
        } else if (hour == "04") {
          myDFPlayer.playMp3Folder(400);
          last_play = millis();
        } else if (hour == "05") {
          myDFPlayer.playMp3Folder(500);
          last_play = millis();
        } else if (hour == "06") {
          myDFPlayer.playMp3Folder(600);
          last_play = millis();
        } else if (hour == "07") {
          myDFPlayer.playMp3Folder(700);
          last_play = millis();
        } else if (hour == "08") {
          myDFPlayer.playMp3Folder(800);
          last_play = millis();
        } else if (hour == "09") {
          myDFPlayer.playMp3Folder(900);
          last_play = millis();
        } else if (hour == "10") {
          myDFPlayer.playMp3Folder(1000);
          last_play = millis();
        } else if (hour == "11") {
          myDFPlayer.playMp3Folder(1100);
          last_play = millis();
        } else if (hour == "12") {
          myDFPlayer.playMp3Folder(1200);
          last_play = millis();
        } else if (hour == "13") {
          myDFPlayer.playMp3Folder(1300);
          last_play = millis();
        } else if (hour == "14") {
          myDFPlayer.playMp3Folder(1400);
          last_play = millis();
        } else if (hour == "15") {
          myDFPlayer.playMp3Folder(1500);
          last_play = millis();
        } else if (hour == "16") {
          myDFPlayer.playMp3Folder(1600);
          last_play = millis();
        } else if (hour == "17") {
          myDFPlayer.playMp3Folder(1700);
          last_play = millis();
        } else if (hour == "18") {
          myDFPlayer.playMp3Folder(1800);
          last_play = millis();
        } else if (hour == "19") {
          myDFPlayer.playMp3Folder(1900);
          last_play = millis();
        } else if (hour == "20") {
          myDFPlayer.playMp3Folder(2000);
          last_play = millis();
        } else if (hour == "21") {
          myDFPlayer.playMp3Folder(2100);
          last_play = millis();
        } else if (hour == "22") {
          myDFPlayer.playMp3Folder(2200);
          last_play = millis();
        } else if (hour == "23") {
          myDFPlayer.playMp3Folder(2300);
          last_play = millis();
        }
      } else if (minute == "30") {
        if (hour == "00") {
          myDFPlayer.playMp3Folder(2430);
          last_play = millis();
        } else if (hour == "01") {
          myDFPlayer.playMp3Folder(130);
          last_play = millis();
        } else if (hour == "02") {
          myDFPlayer.playMp3Folder(230);
          last_play = millis();
        } else if (hour == "03") {
          myDFPlayer.playMp3Folder(330);
          last_play = millis();
        } else if (hour == "04") {
          myDFPlayer.playMp3Folder(430);
          last_play = millis();
        } else if (hour == "05") {
          myDFPlayer.playMp3Folder(530);
          last_play = millis();
        } else if (hour == "06") {
          myDFPlayer.playMp3Folder(630);
          last_play = millis();
        } else if (hour == "07") {
          myDFPlayer.playMp3Folder(730);
          last_play = millis();
        } else if (hour == "08") {
          myDFPlayer.playMp3Folder(830);
          last_play = millis();
        } else if (hour == "09") {
          myDFPlayer.playMp3Folder(930);
          last_play = millis();
        } else if (hour == "10") {
          myDFPlayer.playMp3Folder(1030);
          last_play = millis();
        } else if (hour == "11") {
          myDFPlayer.playMp3Folder(1130);
          last_play = millis();
        } else if (hour == "12") {
          myDFPlayer.playMp3Folder(1230);
          last_play = millis();
        } else if (hour == "13") {
          myDFPlayer.playMp3Folder(1330);
          last_play = millis();
        } else if (hour == "14") {
          myDFPlayer.playMp3Folder(1430);
          last_play = millis();
        } else if (hour == "15") {
          myDFPlayer.playMp3Folder(1530);
          last_play = millis();
        } else if (hour == "16") {
          myDFPlayer.playMp3Folder(1630);
          last_play = millis();
        } else if (hour == "17") {
          myDFPlayer.playMp3Folder(1730);
          last_play = millis();
        } else if (hour == "18") {
          myDFPlayer.playMp3Folder(1830);
          last_play = millis();
        } else if (hour == "19") {
          myDFPlayer.playMp3Folder(1930);
          last_play = millis();
        } else if (hour == "20") {
          myDFPlayer.playMp3Folder(2030);
          last_play = millis();
        } else if (hour == "21") {
          myDFPlayer.playMp3Folder(2130);
          last_play = millis();
        } else if (hour == "22") {
          myDFPlayer.playMp3Folder(2230);
          last_play = millis();
        } else if (hour == "23") {
          myDFPlayer.playMp3Folder(2330);
          last_play = millis();
        }
      }
    }
  }

  if ((millis() - last) > 1000) {
    Serial.println(now);
    last = millis();
  }
}

void printDetail(uint8_t type, int value){
  switch (type) {
    case TimeOut:
      Serial.println(F("Time Out!"));
      break;
    case WrongStack:
      Serial.println(F("Stack Wrong!"));
      break;
    case DFPlayerCardInserted:
      Serial.println(F("Card Inserted!"));
      break;
    case DFPlayerCardRemoved:
      Serial.println(F("Card Removed!"));
      break;
    case DFPlayerCardOnline:
      Serial.println(F("Card Online!"));
      break;
    case DFPlayerPlayFinished:
      Serial.print(F("Number:"));
      Serial.print(value);
      Serial.println(F(" Play Finished!"));
      break;
    case DFPlayerError:
      Serial.print(F("DFPlayerError:"));
      switch (value) {
        case Busy:
          Serial.println(F("Card not found"));
          break;
        case Sleeping:
          Serial.println(F("Sleeping"));
          break;
        case SerialWrongStack:
          Serial.println(F("Get Wrong Stack"));
          break;
        case CheckSumNotMatch:
          Serial.println(F("Check Sum Not Match"));
          break;
        case FileIndexOut:
          Serial.println(F("File Index Out of Bound"));
          break;
        case FileMismatch:
          Serial.println(F("Cannot Find File"));
          break;
        case Advertise:
          Serial.println(F("In Advertise"));
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
}
