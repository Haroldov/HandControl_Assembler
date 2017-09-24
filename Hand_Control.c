#define _XTAL_FREQ 20000000


#include <xc.h>
#include "esp8266_functions.h"
#include "servo.h"

#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF       // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)


void main()
{
    ////////////////////////////////////////////////////////////////////////////
    Initialize_ESP8266() ; // Initialize ESP_PIC communication
    do  //Check if the ESP_PIC communication is successful
    {
    }while (!esp8266_isStarted()); //Wait untill the ESP send back "OK"   
    esp8266_mode(2); // Access point mode
    unsigned char ipAdd[4];
    esp8266_ip(ipAdd); // get IP
    _esp8266_enale_MUX(); // Enable multiple connections
    _esp8266_create_server();
    _esp8266_timeout(); //Timeout of server to 10ms
    esp8266_config_softAP("HackberryHand_SSVEP_Control","NeuroEngineering"); //Configuring ID and PASS of Access Point
    unsigned char data[1];
    unsigned char b[5];
    b[0] = '5';
    b[1] = '1';
    b[2] = '2';
    b[3] = '3';
    b[4] = '4';
    TRISB = 0;
    ////////////////////////////////////////////////////////////////////////////
    while(1)
    {
          esp8266_receive(data, 1, true);//receive command
          
          if (data[0] == b[0]){
              CerrarMano();
          }
          if (data[0] == b[1]){
              ManoAbierta();
          }
          if (data[0] == b[2]){
              ManoSenalando();
          }
          if (data[0] == b[3]){
              ManoOk();
          }
          if (data[0] == b[4]){
              Llamado();
          }
    }

}
