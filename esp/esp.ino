#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "index.h"
#include "DHT.h" // including the library of DHT11 temperature and humidity sensor
#define DHTTYPE DHT11 // DHT 11
#define dht_dpin 0 //D3
DHT dht(dht_dpin, DHTTYPE);

ESP8266WebServer server(80);
String webString="";


void handleRoot() {
 String s = MAIN_page; //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}

void setup()
{
  dht.begin();

  Serial.begin(115200);
  Serial.println();

  WiFi.begin("cycki", "cyckicycki");

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());

   server.on("/",handleRoot);
    server.on("/temp", [](){  // if you add this subdirectory to your webserver call, you get text below :)
    float temp = gettemperature();       // read sensor
    webString=String(float(temp));   // Arduino has a hard time with float to string
    server.send(200, "text/plain", webString);            // send to someones browser when asked
  });
 
  server.on("/humidity", [](){  // if you add this subdirectory to your webserver call, you get text below :)
    float humi = gethumidity();           // read sensor
    webString=String(float(humi));
    server.send(200, "text/plain", webString);               // send to someones browser when asked
  });
  server.begin();
  Serial.println("Server started");
}

void loop(void) {
 server.handleClient();
  }


  
  float gettemperature() {
   float t = dht.readTemperature();
    if (isnan(t)){
        Serial.println("Failed to read from DHT sensor!");
        }
    return t;}
  float gethumidity() {
     float h = dht.readHumidity();
      if (isnan(h)){
        Serial.println("Failed to read from DHT sensor!");
        }
        return h;
    }

   

