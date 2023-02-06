// All the libraries
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPClient.h>



//connect the wifi
const char* ssid = "TP-Link_D7DC";
const char* password = "55044394";
const char* serverName = "http://192.168.0.111:1200/";

// device place information
const int this_device_number = 5;
int number_of_devices = 6;

//method for waiting - no delay, cause it causes crashes
// if loop() is working more than 1.5 seconds
// https://forum.arduino.cc/t/esp-01-what-does-cut-here-for-exception-decoder-mean/992697/9
void wait(unsigned long time) {
  unsigned long start = millis();
  while (millis() - start < time) {
    yield();
  }
};

void setup(void) {


  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.println("");
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    wait(200);
    Serial.print(".");
  };






  // unnecessary wifi information

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());



  // all the pins i want to control
  pinMode(SCL, OUTPUT);
  pinMode(SDA, OUTPUT);
  pinMode(SCK, OUTPUT);
  pinMode(MISO, OUTPUT);
  pinMode(MOSI, OUTPUT);
  pinMode(SS, OUTPUT);
  Serial.println("Setup ended");

}




// function for getting the page information
String httpGETRequest(const char* serverName) {
  Serial.println("httpGETRequest started");
  WiFiClient client;
  HTTPClient http;

  // Your IP address with path or Domain name with URL path
  http.begin(client, serverName);

  // If you need Node-RED/server authentication, insert user and password below
  //http.setAuthorization("REPLACE_WITH_SERVER_USERNAME", "REPLACE_WITH_SERVER_PASSWORD");

  // Send HTTP POST request
  int httpResponseCode = http.GET();

  String payload = "{}";

  if (httpResponseCode == 200) {
    /*
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    */
    payload = http.getString();
    Serial.println("we got the page");
    //Serial.println(payload);

  }
  else {
    payload = "-1";
    Serial.println("Sorry no data");

    /*Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    */
  }
  // Free resources
  http.end();

  return payload;
  Serial.println("httpGETRequest ended");
};






// function for sending the page information
String httpGETSendA0(const char* serverName, int val) {
  Serial.println("httpGETRequest started");
  WiFiClient client;
  HTTPClient http;
  const char* serverNameA;

  
  // wifi6 this_device_number + 1
  if (val == 0) {serverNameA = "wifi6/a0";};
  if (val == 1) {serverNameA = "wifi6/a1";};
  if (val == 2) {serverNameA = "wifi6/a2";};
  if (val == 3) {serverNameA = "wifi6/a3";};
  if (val == 4) {serverNameA = "wifi6/a4";};
    if (val == 5) {serverNameA = "wifi6/a5";};
  if (val == 6) {serverNameA = "wifi6/a6";};
  if (val == 7) {serverNameA = "wifi6/a7";};
  if (val == 8) {serverNameA = "wifi6/a8";};
  if (val == 9) {serverNameA = "wifi6/a9";};
    if (val == 10) {serverNameA = "wifi6/a10";};
  if (val == 11) {serverNameA = "wifi6/a11";};
  if (val == 12) {serverNameA = "wifi6/a12";};
  if (val == 13) {serverNameA = "wifi6/a13";};
  if (val == 14) {serverNameA = "wifi6/a14";};
    if (val == 15) {serverNameA = "wifi6/a15";};
  if (val == 16) {serverNameA = "wifi6/a16";};
  if (val == 17) {serverNameA = "wifi6/a17";};
  if (val ==  18) {serverNameA = "wifi6/a18";};
  if (val == 19) {serverNameA = "wifi6/a19";};

  if (val == 20) {serverNameA = "wifi6/a20";};
    
  String total( String(serverName) + String(serverNameA) );
  Serial.println(total);

  const char* sum_adress = total.c_str();

  Serial.println(sum_adress);
  // Your IP address with path or Domain name with URL path
  http.begin(client, sum_adress);
  int httpResponseCode = http.GET();
  return "Done";
  http.end();

  Serial.println("info was sended!");
};





// basic stuff
void loop(void) {

  Serial.println("loop started");

  //send the data:

  int sensorValue = analogRead(A0);
  
  int val = map(sensorValue, 0, 1023, 0, 20);
  
  Serial.println(val);

  String respond;

  respond = httpGETSendA0(serverName, val);

  String commandData;

  commandData = httpGETRequest(serverName);

  //get the data:
  
  String data[6];

  int number = 0;

  for (int i = 0; i < number_of_devices; i++) {

    int place = commandData.indexOf('@');
    Serial.println(place);

    if (!(place == -1)) {

      data[number] = commandData.substring( (place + 1), (place + 33) );

      Serial.println(data[number]);

      commandData = commandData.substring( (place + 33) );

      number++;
    };
  };



  const char* info = data[this_device_number].c_str();

  Serial.println(info);


  Serial.print(" SCL = ");
  Serial.println(info[0]);
  switch_pins(info[0], SCL);

  Serial.print(" SDA = ");
  Serial.println(info[1]);
  switch_pins(info[1], SDA);

  Serial.print(" SCK = ");
  Serial.println(info[2]);
  switch_pins(info[2], SCK);

  Serial.print(" MISO = ");
  Serial.println(info[3]);
  switch_pins(info[3], MISO);

  Serial.print(" MOSI = ");
  Serial.println(info[4]);
  switch_pins(info[4], MOSI);

  Serial.print(" SS = ");
  Serial.println(info[5]);
  switch_pins(info[5], SS);

  yield();

  if (info[6] == '2') {
    Serial.print("100 ms");    
    delay(100);
  } 

  if (info[6] == '1') {
    Serial.print("short delay");    
    delay(500);
  } 
  
  if (info[6] == '0') {
    Serial.print("long delay");
    delay(5000);
  } 


};




void switch_pins(char command, const uint8_t pin) {
  Serial.println("switch_pins! ");
  Serial.println(command);
  Serial.println(pin);

  if (command == '1') {

    digitalWrite(pin, HIGH);
    Serial.println("HIGH");
  };

  if (command == '0') {

    digitalWrite(pin, LOW);
    Serial.println("LOW");
  };

  Serial.println("switch_pins done ");
};
