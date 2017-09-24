/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  


#include <xc.h> // include processor files - each processor file is guarded.  


void servoRotate0(int c) //0 Degree
{
  unsigned int i;
  if(c == 1){
  for(i=0;i<50;i++)
  {
    RB1 = 1;
    __delay_us(800);
    RB1 = 0;
    __delay_us(19200);
  }
  }
  if(c == 2){
  for(i=0;i<50;i++)
  {
    RB2 = 1;
    __delay_us(800);
    RB2 = 0;
    __delay_us(19200);
  }
  }
  if(c == 4){
  for(i=0;i<50;i++)
  {
    RB4 = 1;
    __delay_us(800);
    RB4 = 0;
    __delay_us(19200);
  }
  }
}

void servoRotate90(int b) //90 Degree
{
  unsigned int i;
  if(b ==1){
  for(i=0;i<50;i++)
  {
    RB1 = 1;
    __delay_us(1500);
    RB1 = 0;
    __delay_us(18500);
  }
  }
  if(b ==2){
  for(i=0;i<50;i++)
  {
    RB2 = 1;
    __delay_us(1500);
    RB2 = 0;
    __delay_us(18500);
  }
  }
  if(b ==4){
  for(i=0;i<50;i++)
  {
    RB4 = 1;
    __delay_us(1500);
    RB4 = 0;
    __delay_us(18500);
  }
  }
}

void servoRotate180(int a) //180 Degree
{
  unsigned int i;
  if (a == 1){
  for(i=0;i<50;i++)
  {
    RB1 = 1;
    __delay_us(2000);
    RB1 = 0;
    __delay_us(18000);
  }
 
  }
    if (a == 2){
  for(i=0;i<50;i++)
  {
    RB2 = 1;
    __delay_us(2000);
    RB2 = 0;
    __delay_us(18000);
  }
    }
    if (a == 4){
  for(i=0;i<50;i++)
  {
    RB4 = 1;
    __delay_us(2000);
    RB4 = 0;
    __delay_us(18000);
  }
 
  }

 
  }

void CerrarMano() // RB1=pulgar RB2= indice RB4=dedos 
{
    servoRotate180(2);
    __delay_ms(200);
    servoRotate0(1);
   __delay_ms(200);
   servoRotate0(4);
}

void ManoAbierta()
{
   servoRotate180(1);
    __delay_ms(200);
    servoRotate0(2);
   __delay_ms(200);
   servoRotate180(4); 

}
void ManoSenalando()
{
    servoRotate0(2);
    __delay_ms(200);
    servoRotate0(1);
   __delay_ms(200);
   servoRotate0(4);
}
void ManoOk()
{
servoRotate180(2);
    __delay_ms(200);
    servoRotate0(1);
   __delay_ms(200);
   servoRotate180(4);
}
void Llamado()
{
servoRotate180(1);
    ManoAbierta() ;
   __delay_ms(5);
   servoRotate180(2);
    
    servoRotate180(1);
   
   servoRotate0(4);
   __delay_ms(500);
   ManoAbierta();
   __delay_ms(5);
   servoRotate180(2);
    
    servoRotate180(1);
   
   servoRotate0(4);
}