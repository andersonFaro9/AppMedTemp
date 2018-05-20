//#include "med_temp.h"

//DHT//
#define DHTPIN D3
#define DHTTYPE DHT22// SELECIONAR O TIPO DE SENSOR DHT11, DHT22
#include <DHT.h>

DHT DHTtempQueMostraNoVisorDoDisplay(DHTPIN, DHTTYPE);
DHT DHTtempQueMostraNoConsoleDoComp(DHTPIN, DHTTYPE);

//-WIFI-//
#include <ESP8266WiFi.h>
const char* ssid = "Robot";
const char* password = "F@/x?dr6y";
WiFiClient nodemcuClient;
#include <Adafruit_SSD1306.h>
#define OLED_RESET LED_BUILTIN
Adafruit_SSD1306 display(OLED_RESET);

////--MQTT--//
#include <PubSubClient.h>
const char* mqttBroker = "iot.eclipse.org";
const char* mqttClientId = "medtemp";

PubSubClient client (nodemcuClient);
const char* topicoTemperatura = "lab-medtemp/temperatura";
const char* topicoUmidade= "lab-medtemp/umidade";




int temperatura;
int umidade;

void setup() {

  Serial.begin(115200);
//  Display Graus;
    configurarMensagemNoDisplay();
   conectarWifi();
  client.setServer(mqttBroker,1883);
  

}

void medirATemperaturaDaCidade() {

  int temperatura;
  temperatura = DHTtempQueMostraNoConsoleDoComp.readTemperature(false);
  Serial.print("Temperatura: " );
  Serial.print(temperatura);
  Serial.println(" *C");
}

void loop() { // O cara principal, como um Main da linguagem Java

  
  medirATemperaturaDaCidade();
  medirAUmidadeDaCidade();

  temperatura = DHTtempQueMostraNoVisorDoDisplay.readTemperature(false);
  umidade = DHTtempQueMostraNoVisorDoDisplay.readHumidity();

  
  mostrarMensagemNoDisplay("Temperatura",(temperatura),"C");
  mostrarMensagemNoDisplay("Umidade",(umidade),"%");
  configurarMensagemNoDisplay();

  
  conectarWifi();

   reconectarServerMQTT();
    
   publicarTemperaturaEUmidadeNoTopico();

}


//TESTAR AQUI//


void medirAUmidadeDaCidade() {
  
  int umidade = DHTtempQueMostraNoConsoleDoComp.readHumidity();
  Serial.print("Umidade: ");
  Serial.println(umidade);
  delay(5000);
}

void configurarMensagemNoDisplay() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextColor(WHITE);
  display.clearDisplay(); 
}

void mostrarMensagemNoDisplay(const char* textoTemperatura,  int medicaoDaTemperatura, const char* umidade) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print(textoTemperatura);
  delay(2000);
  display.setTextSize(5);
  display.setCursor(20, 20);
  display.print(medicaoDaTemperatura);
  
  display.setTextSize(2);
  display.print(umidade);
  display.display();
  
  delay(2000);
}

void conectarWifi() {
  delay(10);
  display.setTextSize(2);
  display.setCursor(0,0);
  display.print("Conectando...");
  display.display();
  WiFi.begin(ssid, password);
  
  while(WiFi.status() != WL_CONNECTED) { // Enquanto não estiver conectado ele mostra o ponto
    delay(2000);
    Serial.print(".");  
    display.display();
  }
  
}

void  publicarTemperaturaEUmidadeNoTopico() {
  client.publish(topicoTemperatura, String(temperatura).c_str(), true);
  client.publish(topicoUmidade, String(umidade).c_str(), true);
}


void  reconectarServerMQTT() {
    // Loop until we're reconnected
    while (!client.connected()) {
      
      client.connect(mqttClientId); 
    }
}

