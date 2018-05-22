//
#include <Adafruit_SSD1306.h>
#define OLED_RESET LED_BUILTIN
Adafruit_SSD1306 display(OLED_RESET);

#define DHTPIN D3
#define DHTTYPE DHT22// SELECIONAR O TIPO DE SENSOR DHT11, DHT22
#include <DHT.h>

DHT DHTtempQueMostraNoVisorDoDisplay(DHTPIN, DHTTYPE);

class Display {

  public:
  
   int temperatura = DHTtempQueMostraNoVisorDoDisplay.readTemperature(false);
   int umidade = DHTtempQueMostraNoVisorDoDisplay.readHumidity();

   
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

};
