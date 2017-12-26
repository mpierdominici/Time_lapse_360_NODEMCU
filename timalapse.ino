#include <ESP8266WiFi.h> 
#include "WEB_SITE.h"

#define SPEED_CHANGE 10
#define ANGLE_CHANGE 10
#define MAX_SPEED 100
#define MIN_SPEED 0
#define MAX_ANGULO 360
#define MIN_ANGULO 0

#define _MIN(a,b) (((a)<(b))?(a):(b))
#define _MAX(a,b) (((a)>(b))?(a):(b))

typedef enum {GIRO_CONTINUO,GIRO_PERSONALIZADO,STOP} state;

const char ssid[]="timelapse";
const char password[]="123456789";
int velGiro= MIN_SPEED;//velocidad de giro en procentaje entre 0 y 100
int angulo=MIN_ANGULO;//angulo que gira, entre 0 y 360 grados
state estados=STOP;//estados del sitema

WiFiServer server(80);


void setup() {
  Serial.begin(115200);
  server.begin();
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid,password);

  Serial.print("Direccion IP Access Point - por defecto: ");      //Imprime la dirección IP
  Serial.println(WiFi.softAPIP()); 
  Serial.print("Direccion MAC Access Point: ");                   //Imprime la dirección MAC
  Serial.println(WiFi.softAPmacAddress()); 

}

void loop() {

  
  WiFiClient cliente=server.available();
  String peticion;
  if (cliente) { //chequeo si hay una solicitud de un cliente
    while(!cliente.available())//espero respuesta del cliente, creo que no bloquea demasiado la ejecucuon del programa (REVISAR!!!!!!!!!!)
    {
      delay(1);
    }
    //Serial.println("nuevo cliente");
    //Serial.printf("Clientes conectados al Access Point: %dn", WiFi.softAPgetStationNum());
    peticion=cliente.readStringUntil('r');
    cliente.flush();//borro el buffer del nodemcu
    
//***************Analizo el mensaje del cliente **********************    
    if (peticion.indexOf("/ANGL=+") != -1)
      {
        Serial.println("ANGULO +");
        angulo+=ANGLE_CHANGE;
        angulo=_MIN(angulo,MAX_ANGULO);
      } 
    if (peticion.indexOf("/ANGL=-") != -1)
      {
        Serial.println("ANGULO -");
        angulo-=ANGLE_CHANGE;
        angulo= _MAX(angulo,MIN_ANGULO);
      }
    if (peticion.indexOf("/SPEED=+") != -1)
      {
        Serial.println("SPEED +");
        velGiro+=SPEED_CHANGE;
        velGiro=_MIN(velGiro,MAX_SPEED);
      }
    if (peticion.indexOf("/SPEED=-") != -1)
      {
        Serial.println("SPEED -");
        velGiro-=SPEED_CHANGE;
        velGiro=_MAX(velGiro,MIN_SPEED);
      }
//*****************************************************************    
    
    drawWebSite(&cliente,&velGiro,&angulo);//se genera el sitio web
    delay(15);    
  }

//************************GIRO*************************************

  switch (estados)
  {
    case STOP:
    break;
    case GIRO_CONTINUO:
    break;
    case GIRO_PERSONALIZADO:
    break;
    default:
    break;
  }


 
  

}
