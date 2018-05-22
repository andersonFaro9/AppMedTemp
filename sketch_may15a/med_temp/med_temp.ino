#include "MedicaoDeTemperatura.h"
#include "ProtocoloMqtt.h"

MedicaoDeTemperatura *medicaoDeTemperatura;
Display *displayMedidor;

ProtocoloMqtt *protocoloMqtt;


void setup() {


   Serial.begin(115200);

    displayMedidor->configurarMensagemNoDisplay();
    protocoloMqtt = new ProtocoloMqtt();
    protocoloMqtt->conectarWifi();
  
   client.setServer(mqttBrokerEclipseQueHospedaEMandaParaOCelular,1883);

}


void loop() { // O cara principal, como um Main da linguagem Java
  
  medicaoDeTemperatura = new MedicaoDeTemperatura();
  medicaoDeTemperatura->medirATemperaturaDaCidade();  
  medicaoDeTemperatura->medirAUmidadeDaCidade();  
  
  displayMedidor = new Display();
  displayMedidor->mostrarMensagemNoDisplay("Temperatura atual",(displayMedidor->temperatura),"C");
  displayMedidor->mostrarMensagemNoDisplay("Umidade atual",(displayMedidor->umidade),"%");
  displayMedidor->configurarMensagemNoDisplay();
  
  protocoloMqtt = new ProtocoloMqtt();
  protocoloMqtt->conectarWifi();
  
  protocoloMqtt->reconectarServerMQTT();
  protocoloMqtt->publicarTemperaturaEUmidadeNoTopico();
  
}


