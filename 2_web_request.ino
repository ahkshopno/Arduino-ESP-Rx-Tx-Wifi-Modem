#include <ESP8266HTTPClient.h>
//http://192.168.1.102/arduino_n.php?v=121212121212

void web_req(String url) {
//  Serial.println("in the web request");
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
//    Serial.println("wifi connection is ok");
    HTTPClient http;  //Declare an object of class HTTPClient

    //    http.begin("http://192.168.1.102/arduino_n.php?v=121212121212");  //Specify request destination
    http.begin(url);  //Specify request destination
    int httpCode = http.GET();                                                                  //Send the request
//    Serial.println("link parsed");
    if (httpCode > 0) { //Check the returning code
      String payload = http.getString();   //Get the request response payload
      Serial.println(payload);                     //Print the response payload
    }
    http.end();   //Close connection
//    Serial.println("HTTP end");
  }
  //  Serial.println("Return from web req");
}

