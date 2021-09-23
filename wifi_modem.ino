#define led 2

#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino
//needed for library
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager

String link = "http://192.168.1.102/arduino_n.php?v=121212121212";

//WiFiManagerParameter custom_mqtt_server("server", "mqtt server", mqtt_server, 40);
//wifiManager.addParameter(&custom_mqtt_server);


void setup() {
  Serial.begin(9600);
  delay(10);
  pinMode(led, OUTPUT);

  //#############################################################
  //WiFiManager
  //Local intialization. Once its business is done, there is no need to keep it around
  WiFiManager wifiManager;
  //reset saved settings
  //  wifiManager.resetSettings();

  //set custom ip for portal
  //wifiManager.setAPConfig(IPAddress(10,0,1,1), IPAddress(10,0,1,1), IPAddress(255,255,255,0));

  //fetches ssid and pass from eeprom and tries to connect
  //if it does not connect it starts an access point with the specified name
  //here  "AutoConnectAP"
  //and goes into a blocking loop awaiting configuration
  wifiManager.autoConnect("IoT");
  //or use this for auto generated name ESP + ChipID
  //wifiManager.autoConnect();


  //if you get here you have connected to the WiFi
  Serial.println("connected...yeey :)");

  //#############################################################

  //  web_req(link);
}

void loop() {
  while (Serial.available() > 0) {
    // read the incoming byte:
    link = Serial.readString();
    // say what you got:
    //    Serial.print("I received: ");
    //    Serial.println(link);
    web_req(link);
  }
  digitalWrite(led, 1);
  delay(200);
  digitalWrite(led, 0);
  delay(200);
}

