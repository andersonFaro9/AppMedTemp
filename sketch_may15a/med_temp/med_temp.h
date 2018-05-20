//Cabeçalho .h, usado por convenção pela maioria para criar classes, por exemplo
//
//#include <Adafruit_SSD1306.h>
//#define OLED_RESET LED_BUILTIN

class Temperatura {

  public:
    virtual void medirATemperaturaDaCidade();
    virtual void medirAUmidadeDaCidade();

};

class Display {

  public:
    virtual void configurarMensagemNoDisplay();
    void mostrarMensagemNoDisplay(const char* textoTemperatura,  int medicaoDaTemperatura, const char* umidade);

};


class ProtocoloMqtt {

  public:
    virtual void conectarWifi();
    virtual void reconectarServerMQTT();
    virtual void publicarTemperaturaEUmidadeNoTopico();
    

};

