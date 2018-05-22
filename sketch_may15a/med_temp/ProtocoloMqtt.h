
#include <Adafruit_SSD1306.h>
#define OLED_RESET LED_BUILTIN
#define DHTTYPE DHT22// SELECIONAR O TIPO DE SENSOR DHT11, DHT22
#include <DHT.h>


////--MQTT--//
#include <PubSubClient.h>
const char* mqttBrokerEclipseQueHospedaEMandaParaOCelular = "iot.eclipse.org";
const char* mqttClientId = "medtemp";

const char* topicoTemperatura = "lab-medtemp/temperatura";
const char* topicoUmidade= "lab-medtemp/umidade";

//-WIFI-//
#include <ESP8266WiFi.h>
const char* ssid = "Robot";
const char* password = "F@/x?dr6y";
WiFiClient nodemcuClient;
PubSubClient client (nodemcuClient);
DHT DHTtempQueMostraNoVisorDoCelular(DHTPIN, DHTTYPE);

class ProtocoloMqtt {

  public:
     
     int temperatura = DHTtempQueMostraNoVisorDoCelular.readTemperature(false);
     int umidade = DHTtempQueMostraNoVisorDoCelular.readHumidity();

     void conectarWifi() {
        delay(10);
        display.setTextSize(2);
        display.setCursor(0,0);
        display.print("conectando...");
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
      
      while (!client.connected()) {
        
        client.connect(mqttClientId); 
      }
  }


};
