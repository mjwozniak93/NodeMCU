#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <FS.h>   //Dołączenie obsługi plików

const char* imagefile = "/tlo.jpg";
const char* htmlfile = "/index.html";
 
//Konfiguracja AP dla ESP8266
const char *ssid = "NodeMCU";
const char *password = "password";
 
 
ESP8266WebServer server(80);
 
void handleRoot(){
  server.sendHeader("Location", "/index.html",true);   //Odniesienie do naszej strony
  server.send(302, "text/plane","");
}
 
void wyslij(){
  if(wczytywanie_plikow(server.uri())) return;
  String info = "Nie znaleziono plikow\n\n";
  info += "URI: ";
  info += server.uri();
  info += "\nMetoda: ";
  info += (server.method() == HTTP_GET)?"GET":"POST";
  info += "\nArgumenty: ";
  info += server.args();
  info += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    info += " Nazwa:"+server.argName(i) + "\n Wartosci:" + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", info);
  Serial.println(info);
}
 
void setup() {
  delay(1000);
  Serial.begin(115200);
  Serial.println();
 
  //Inicjalizacja obsługi plików
  SPIFFS.begin();
  Serial.println("Zainicjalizowano obsluge plikow");
 
  //Inicjalizacja ESP8266 w trybie AP
  WiFi.softAP(ssid);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("IP Web Serwera:");
  Serial.println(IP);
 
  //Inicjalizacja Web Serwera
  server.on("/",handleRoot);
  server.onNotFound(wyslij);
  server.begin();  
}
 
void loop() {
 server.handleClient();
}
 
bool wczytywanie_plikow(String sciezka){
  String typ_danych = "text/plain";
  if(sciezka.endsWith("/")) sciezka += "index.htm";
 
  if(sciezka.endsWith(".src")) sciezka = sciezka.substring(0, sciezka.lastIndexOf("."));
  else if(sciezka.endsWith(".html")) typ_danych = "text/html";
  else if(sciezka.endsWith(".htm")) typ_danych = "text/html";
  else if(sciezka.endsWith(".css")) typ_danych = "text/css";
  else if(sciezka.endsWith(".js")) typ_danych = "application/javascript";
  else if(sciezka.endsWith(".png")) typ_danych = "image/png";
  else if(sciezka.endsWith(".gif")) typ_danych = "image/gif";
  else if(sciezka.endsWith(".jpg")) typ_danych = "image/jpeg";
  else if(sciezka.endsWith(".ico")) typ_danych = "image/x-icon";
  else if(sciezka.endsWith(".xml")) typ_danych = "text/xml";
  else if(sciezka.endsWith(".pdf")) typ_danych = "application/pdf";
  else if(sciezka.endsWith(".zip")) typ_danych = "application/zip";
  File plik = SPIFFS.open(sciezka.c_str(), "r");
  if (server.hasArg("download")) typ_danych = "application/octet-stream";
  if (server.streamFile(plik, typ_danych) != plik.size()) {
  }
 
  plik.close();
  return true;
}
