//version 1.0.0
//IR sensor


#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
 
#define FIREBASE_HOST "" // Firebase host
#define FIREBASE_AUTH "" //Firebase Auth code
#define WIFI_SSID "" //Enter your wifi Name eg-Dialog 4g 734
#define WIFI_PASSWORD "" //Enter wifi password

//SharpIR SharpIR(IR, model);

void setup() {
  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting"); 
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  pinMode(BUILTIN_LED, OUTPUT);
}
 
void loop() {
 
   delay(500); 
   unsigned long startTime=millis();
   float dis=SharpIR.distance();
   //Firebase.setInt("Distance",dis); < firebase data out

}
