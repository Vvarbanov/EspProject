#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

int relayPin = 12;
int pcPin = 13;
bool pinState = LOW;

void setup() {

pinMode(relayPin, OUTPUT);
pinMode(ledPin, OUTPUT);

Serial.begin(115200);
WiFi.begin(“MiPhone”, “12345678”);

while (WiFi.status() != WL_CONNECTED) { 
	
	delay(500);
	Serial.println(“Connecting”);
	
}

server.on(“/on”, turnOn);   
server.on(“/off”, turnOff); 

server.begin(); 
Serial.println(“Server started”);

digitalWrite(relayPin, HIGH);

}

void loop() {

server.handleClient();

}

void turnOn(){

pinState = HIGH;
digitalWrite(pcPin, pinState);
delay(500);
pinState = LOW;
digitalWrite(pcPin, pinState);
server.send(200, “text/plain”, “ON”);

}

void turnOff(){

pinState = HIGH;
digitalWrite(pcPin, pinState);
delay(5000);
pinState = LOW;
digitalWrite(pcPin, pinState);
server.send(200, “text/plain”, “OFF”);

}
