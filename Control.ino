void TOSR04_Relay_Control(){
       String path = HTTP.uri();
       char chAr[1+path.length()];
       path.toCharArray(chAr,1+path.length());
                   if ((chAr[1]==0x46)&(chAr[2]==0x46))
                      {
                      if ((chAr[3]==0x30)&(chAr[4]==0x31))  // Relay 01
                         {
                           if (chAr[6]==0x31) UART_SERVER_PORT.write("e", 1);
                           if (chAr[6]==0x30) UART_SERVER_PORT.write("o", 1);
                           if (chAr[6]==0x32){if(rstat[0]==0){UART_SERVER_PORT.write("e", 1);}else{UART_SERVER_PORT.write("o", 1);}}
                           return;
                         }
                      
                      if ((chAr[3]==0x30)&(chAr[4]==0x32))  // Relay 02
                         {
                           if (chAr[6]==0x31) UART_SERVER_PORT.write("f", 1);
                           if (chAr[6]==0x30) UART_SERVER_PORT.write("p", 1);
                           if (chAr[6]==0x32){if(rstat[1]==0){UART_SERVER_PORT.write("f", 1);}else{UART_SERVER_PORT.write("p", 1);}}
                           return;
                         }
                      
                      if ((chAr[3]==0x30)&(chAr[4]==0x33))  // Relay 03
                         {
                           if (chAr[6]==0x31) UART_SERVER_PORT.write("g", 1);
                           if (chAr[6]==0x30) UART_SERVER_PORT.write("q", 1);
                           if (chAr[6]==0x32){if(rstat[2]==0){UART_SERVER_PORT.write("g", 1);}else{UART_SERVER_PORT.write("q", 1);}}
                           return;
                         }
                         
                      if ((chAr[3]==0x30)&(chAr[4]==0x34))  // Relay 04
                         {
                           if (chAr[6]==0x31) UART_SERVER_PORT.write("h", 1);
                           if (chAr[6]==0x30) UART_SERVER_PORT.write("r", 1);
                           if (chAr[6]==0x32){if(rstat[3]==0){UART_SERVER_PORT.write("h", 1);}else{UART_SERVER_PORT.write("r", 1);}}
                           return;
                         }
                      
                      if ((chAr[3]==0x30)&(chAr[4]==0x30))  // Relay ALL
                         {
                           if (chAr[6]==0x31) UART_SERVER_PORT.write("d", 1);
                           if (chAr[6]==0x30) UART_SERVER_PORT.write("n", 1);
                           return;
                         }
                         
            }                  
}

void TOSR04_Relay_Status(){
  byte inByte=0x00;
  int i=0;
  unsigned long currentMillisR;
  unsigned long previousMillisR = millis();
    UART_SERVER_PORT.flush();
    UART_SERVER_PORT.write("[", 1);
    while (UART_SERVER_PORT.available()==0 ){
      currentMillisR = millis();
      if (currentMillisR - previousMillisR >= interval) {break;}
      }
    if (UART_SERVER_PORT.available() > 0) {
      inByte = UART_SERVER_PORT.read();
         for ( i=0; i < 8; ++i )  {
         rstat[i] = bitRead(inByte,i);
       }     
     }  
  UART_SERVER_PORT.flush();
}
