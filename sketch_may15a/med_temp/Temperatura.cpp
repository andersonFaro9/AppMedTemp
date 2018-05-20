//
//#include "med_temp.h"
//#include <DHT.h>
//#include <Adafruit_Sensor.h>
//#define DHTPIN D3
//#define DHTTYPE DHT22// SELECIONAR O TIPO DE SENSOR DHT11, DHT22
//DHT DHTtempQueMostraNoConsoleDoComp(DHTPIN, DHTTYPE);
//#include <Adafruit_SSD1306.h>
//#define OLED_RESET LED_BUILTIN
//Adafruit_SSD1306 display(OLED_RESET);
//
////-WIFI-//
//#include <ESP8266WiFi.h>
//const char* ssid = "Robot";
//const char* password = "F@/x?dr6y";
//WiFiClient nodemcuClientt;
//
////
//////--MQTT--//
//#include <PubSubClient.h>
//const char* mqttBroker = "iot.eclipse.org";
//const char* mqttClientId = "medtemp";
//PubSubClient client (nodemcuClientt);
//const char* topicoTemperatura = "lab-medtemp/temperatura";
//const char* topicoUmidade= "lab-medtemp/umidade";
//
//void Temperatura:: medirATemperaturaDaCidade() {
//
//  int temperatura;
//  temperatura = DHTtempQueMostraNoConsoleDoComp.readTemperature(false);
//  Serial.print("Temperatura: " );
//  Serial.print(temperatura);
//  Serial.println(" *C");
//}
//
//void Temperatura:: medirAUmidadeDaCidade() {
//  
//  int umidade = DHTtempQueMostraNoConsoleDoComp.readHumidity();
//  Serial.print("Umidade: ");
//  Serial.println(umidade);
//  delay(5000);
//}
//
//void Display:: configurarMensagemNoDisplay() {
//  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
//  display.setTextColor(WHITE);
//  display.clearDisplay(); 
//}
//
//void Display::mostrarMensagemNoDisplay(const char* textoTemperatura,  int medicaoDaTemperatura, const char* umidade) {
//  display.clearDisplay();
//  display.setTextSize(1);
//  display.setCursor(0, 0);
//  display.print(textoTemperatura);
//  
//  display.setTextSize(5);
//  display.setCursor(20, 20);
//  display.print(medicaoDaTemperatura);
//  
//  display.setTextSize(2);
//  display.print(umidade);
//  display.display();
//  
//  delay(2000);
//}
//
//void ProtocoloMqtt::conectarWifi() {
//  delay(10);
//  display.setTextSize(2);
//  display.setCursor(0,0);
//  display.print("Conectando...");
//  display.display();
//  WiFi.begin(ssid, password);
//  
//  while(WiFi.status() != WL_CONNECTED) { // Enquanto não estiver conectado ele mostra o ponto
//    delay(2000);
//    Serial.print(".");  
//    display.display();
//  }
//  
//}
//
//int temperaturaa;
//int umidadee;
//
//void ProtocoloMqtt:: publicarTemperaturaEUmidadeNoTopico() {
//  client.publish(topicoTemperatura, String(temperaturaa).c_str(), true);
//  client.publish(topicoUmidade, String(umidadee).c_str(), true);
//}
//
//
//void  ProtocoloMqtt::reconectarServerMQTT() {
//    // Loop until we're reconnected
//    while (!client.connected()) {
//      
//      client.connect(mqttClientId); 
//    }
//}

