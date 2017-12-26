#include "WEB_SITE.h"

void drawWebSite(WiFiClient * cliente,int * velGiro,int * angulo)
{
  cliente->println("HTTP/1.1 200 OK");
  cliente->println("");                                     //No olvidar esta línea de separación
  cliente->println("<!DOCTYPE HTML>");
  cliente->println("<meta charset='UTF-8'>");
  cliente->println("<html>");


  
  cliente->println("<table>");//INICIO DE LA TABLA
    cliente->println("<tr>");//inicio fila
    
      cliente->print("<td>Grados de giro:");//grados de giro
      cliente->print((*angulo));
      cliente->println("</td>");//grados de giro
    
      cliente->println("<td><button type='button' onClick=location.href='/ANGL=+'> AUMENTAR </button></td>");
      cliente->println("<td><button type='button' onClick=location.href='/ANGL=-'> DISMINUIR </button></td>");
    cliente->println("</tr>");//fin fila

    
    cliente->println("<tr>");//inicio fila
      cliente->print("<td>Velocidad de giro:");
      cliente->print((*velGiro));
      cliente->println("</td>");
      cliente->println("<td><button type='button' onClick=location.href='/SPEED=+'> AUMENTAR </button></td>");
      cliente->println("<td><button type='button' onClick=location.href='/SPEED=-'> DISMINUIR </button></td>");
    cliente->println("</tr>");//fin fila 

    cliente->println("<tr>");//inicio fila
      cliente->println("<td>Invertir giro:</td>");
      cliente->println("<td><button type='button' onClick=location.href='/TOGG=GIRO'> START </button></td>");
    cliente->println("</tr>");//fin fila
   
    cliente->println("<tr>");//inicio fila
      cliente->println("<td>Giro personalizado:</td>");
      cliente->println("<td><button type='button' onClick=location.href='/PERS=ON'> START </button></td>");
    cliente->println("</tr>");//fin fila
  
    cliente->println("<tr>");//inicio fila
      cliente->println("<td>Giro continuo:</td>");
      cliente->println("<td><button type='button' onClick=location.href='/CONT=ON'> START </button></td>");
    cliente->println("</tr>");//fin fila

    cliente->println("<tr>");//inicio fila
      cliente->println("<td>Full stop:</td>");
      cliente->println("<td><button type='button' onClick=location.href='/STOP=ON'> STOP </button></td>");
    cliente->println("</tr>");//fin fil

  cliente->println("</table>");//FIN DE TABLA



  
  cliente->println("</html>"); //fin de html
}

