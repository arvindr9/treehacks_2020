/*
 * Steven Feng Feb 15, 2020
 */

//Libraries
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>

ESP8266WebServer server;

char* ssid = "Steven-Feng";
char* password = "password";


//These values track the connection frequency
unsigned long lastConnectMillis;
unsigned long connectMillis;


void setup() {
  // put your setup code here, to run once:
  //Connects to the wifi
  
  WiFi.begin(ssid,password);

  //Starts the serial monitor and outputs the connection status
  Serial.begin(115200);
  delay(500);
  Serial.println(" Set Up ");
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.print("IP Address: ");

  //This IP address is needed for the python client
  Serial.println(WiFi.localIP());

  //Sends a hello world to the client
  server.on("/",[](){server.send(200,"text/plain","Hello World!");});
  
  //Creates a page to send servo commands to
  server.on("/Server",setServer);
  server.begin();

}

void loop() {
  //Checks for input from the client
  server.handleClient();
  //tracks time since last connection
  lastConnectMillis = millis() - connectMillis;

  //Stops motors if connection is lost for over 1 second
  if (lastConnectMillis > 1000)
  {
    //setServer();
  }


}


void setServer(){
  //Updates time of last connection
  connectMillis = millis();

  //Reads data from client
  String data_string = server.arg("plain");
  Serial.println(data_string);
  StaticJsonDocument<400> jDoc;
  DeserializationError err = deserializeJson(jDoc, data_string);
  JsonObject object = jDoc.as<JsonObject>();
  const char* motor = object["motor"];
  //Sends empty response
  Serial.println(motor);
  
  server.send(204,"");
}
