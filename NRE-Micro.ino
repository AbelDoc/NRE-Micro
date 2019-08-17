 #include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>
#include <Adafruit_NeoPixel.h>

#include "src/Header/NRE_Micro.hpp"


ESP8266HTTPUpdateServer httpUpdater; // instance pour l'OTA (obligatoire)
ESP8266WebServer server(7980);

const char *SERVER_WIFI_SSID = "freebox_YA";
const char *SERVER_WIFI_PASS = "hxklwhxklw";

String routine="phrase";

String jarvis="jarvis";
bool phrase=false;
bool stopvar=false;
bool connection=false;
int delaiPhrase = 125;
String mac="";

#define del 15 //broche liée led
#define NUMPIXELS      29 //nombre de led

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, del, NEO_GRB + NEO_KHZ800);


int r=255;
int g=0;
int b=0;
int coeurR=0;
int coeurG=0;
int coeurB=255;


void setupWiFi()
{
//  WiFi.mode(WIFI_STA);
/*

   WiFi.begin(SERVER_WIFI_SSID,SERVER_WIFI_PASS);
  // WiFi.setAutoConnect(false);
 //  WiFi.setAutoReconnect(false);
   while(WiFi.status() != WL_CONNECTED)
   {
     delay(500);
     Serial.print("...");
   }
    Serial.println("connected");
      Serial.println(WiFi.localIP());

      */

        WiFi.scanNetworks(true,false);
  int n=WiFi.scanComplete();
  while (n<0){
    n=WiFi.scanComplete();
    delay(10);
  }

  for (int i=0;i<n;i++){
    if (WiFi.SSID(i)=="androidYA"){ //tel julien
      WiFi.begin("androidYA","hxklwhxklw");
      connection=true;

      break;
    }
  }


  if (connection==false){
    for (int i=0;i<n;i++){
      if (WiFi.SSID(i)=="freebox_YA"){ //tel julien
        WiFi.begin("freebox_YA","hxklwhxklw");

        connection=true;

        break;
      }
    }
  }

 if (connection==false){
    for (int i=0;i<n;i++){
     if (WiFi.SSID(i)=="julien"){ //tel julien
        WiFi.begin("julien","julienabel");
        connection=true;

        break;
      }
    }
  }
/*
  if (connection==false){
    for (int i=0;i<n;i++){
     if (WiFi.SSID(i)=="freebox_OLVXPT"){ //tel julien
        WiFi.begin("freebox_OLVXPT","julienabeletmarion");
        connection=true;

        break;
      }
    }
  }*/
  if (connection==false){
    for (int i=0;i<n;i++){
     if (WiFi.SSID(i)=="freebox_AB"){ //tel julien
        WiFi.begin("freebox_AB","mireilleetdidier");
        connection=true;

        break;
      }
    }
  }

//  if (connection==false){

    WiFi.softAP("pomme", "mireilleabel");
  //}

}




void setup() {
  Serial.begin(9600);
  pixels.begin();
  for (int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, 0,0,0);
  }
  pixels.show();
  setupWiFi();
    httpUpdater.setup(&server); //on lance l'instance gérant l'OTA
  server.begin(); //on démarrage le serveur web




  server.on("/", [](){

    if (server.argName(0)=="nuit"){
      if (server.arg(0)=="on"){
        jarvis="nuit";
        stopvar=true;
      } else {
        jarvis="jarvis";

      }
       server.send(200, "text/html", jarvis);
     }

     if (server.argName(0)=="jarvis"){
      Serial.println(server.arg(0));
      if (server.arg(0)!="phrase"){
        stopvar=true;
      } else {
        stopvar=false;
      }
      if (phrase==false || server.arg(0)!="phrase" ) {
        if ( server.arg(0)=="color"){
          r=server.arg(1).toInt();
          g=server.arg(2).toInt();
          b=server.arg(3).toInt();
          coeurR=server.arg(4).toInt();
          coeurG=server.arg(5).toInt();
          coeurB=server.arg(6).toInt();
        }

        if (server.arg(0)=="phrase"){
          r=server.arg(1).toInt();
          g=server.arg(2).toInt();
          b=server.arg(3).toInt();
          coeurR=server.arg(4).toInt();
          coeurG=server.arg(5).toInt();
          coeurB=server.arg(6).toInt();
        }
        routine = server.arg(0);
      }
      server.send(200, "text/html", server.arg(0));
    }




    if (server.argName(0)=="delay"){
      Serial.println(server.arg(0));
      server.send(200, "text/html", server.arg(0));
      delaiPhrase=server.arg(0).toInt();
    }
    if (server.argName(0)=="reset"){
      Serial.println("reset");
      server.send(200, "text/html", "reset");
      stopvar=false;
      phrase=false;

    }
      if (server.argName(0)=="stopnuit"){
      Serial.println("stopnuit");
      server.send(200, "text/html", "stopnuit");
      allumeStop();

    }

 server.send(200, "text/html", "nothing");

  });

//allumeResponse();

}

void allumeColor(){
  for (int i=0;i<24;i++){
    pixels.setPixelColor(i, r,g,b);
  }
  for (int i=24;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, coeurR,coeurG,coeurB);
  }
  pixels.show();

 }


void allumeError(){
  for (int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, 255,0,0);
  }

  pixels.show();
}

void allumeResponse(){
  for (int i=0;i<24;i++){
    pixels.setPixelColor(i, 0,0,255);
  }
  for (int i=24;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, 255,255,255);
  }
  pixels.show();
}

void allumeStop(){
  for (int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, 0,0,0);
  }
  pixels.show();



}


void loop() {

 server.handleClient();




 if (routine=="phrase"){
   routine="";
   if (phrase==false){
     for (int i=0;i<NUMPIXELS;i++){
       pixels.setPixelColor(i, 0,0,0);
     }
     pixels.show();
     for (int i=24;i<NUMPIXELS;i++){
       pixels.setPixelColor(i, coeurR,coeurG,coeurB);
     }
     pixels.show();
     phrase=true;
   }  //permet d'éviter de lancer l'animation à chaque mot
 }
 if (phrase==true){
   if (stopvar==false){
     for (int i=0;i<24;i++){
      pixels.setPixelColor(i, r,g,b);
      pixels.show();
      delay(delaiPhrase);
      server.handleClient();
      if (stopvar==true) break;
     }
   }
   if (stopvar==false){
     for (int i=0;i<24;i++){
      pixels.setPixelColor(i, 0,0,0);
      pixels.show();
      delay(delaiPhrase);
      server.handleClient();
      if (stopvar==true) break;
     }
   }
 } else {
   delay(200);
 }


 if (routine != ""){
   if (routine == "response"){
     routine="";
     allumeResponse();
     phrase=false;
   }

  if (routine == "color"){
     routine="";
     allumeColor();
     phrase=false;
  }

   if (routine == "error"){
     routine="";
     allumeError();
     delay(2000);
     allumeResponse();
     phrase=false;
   }
   if (routine == "stop"){
     routine="";
     allumeStop();
   }

 }


}
