//Cabeçalho .h, usado por convenção pela maioria para criar classes, por exemplo

#include <Adafruit_SSD1306.h>
#define OLED_RESET LED_BUILTIN

//DHT//
#define DHTPIN D3
#define DHTTYPE DHT22// SELECIONAR O TIPO DE SENSOR DHT11, DHT22
#include <DHT.h>

DHT DHTtempQueMostraNoConsoleDoComp(DHTPIN, DHTTYPE);

class MedicaoDeTemperatura {

  public:
  
 
   void medirATemperaturaDaCidade() {

        
        int temperatura = DHTtempQueMostraNoConsoleDoComp.readTemperature(false);
        
        Serial.print("Temperatura atual: " );
        Serial.print(temperatura);
        
        Serial.println(" *C");
          delay(5000);
    }

    
    void medirAUmidadeDaCidade() {
      
      int umidade = DHTtempQueMostraNoConsoleDoComp.readHumidity();
      
      Serial.print("Umidade atual: ");
      Serial.println(umidade);
      
      delay(5000);
    }



};

