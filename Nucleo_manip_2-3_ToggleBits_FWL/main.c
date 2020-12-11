
/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

/*----------------- Déclaration des structures relatives aux periphs utilisés ---------------*/
GPIO_InitTypeDef  GPIO_InitStructure;

/* ---------------Private functions ---------------*/
void Delay(vu32 nCount);

uint16_t appui; // variable appui pour lire l'etat du bouton

int main(void)
{ /*---------- Activer les horloges des ports utilsés (port A et port C)------------ */ 
 ...................... (........................................., .........);

/*-------------- Configure the GPIO_LED pin -----------------*/
  GPIO_InitStructure.GPIO_Pin = .................;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP ;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

/*-------------- Configure the GPIO_ Pushbutton pin -----------------*/
  GPIO_InitStructure.GPIO_Pin = ........;
  GPIO_InitStructure.GPIO_Mode = ............... ; // IN Floating
  GPIO_Init(......,...............);

  
/* ---------  Set one Led ON / one OFF ---------- */
GPIO_SetBits(.........);
GPIO_ResetBits(.........);


while (1)
 	 {
appui = ............................(GPIO...,..........); 

if(appui)	         {
 GPIO_ToggleBits(......................);
  	          }
else
                      {
  GPIO_ToggleBits(.......................);
                       }
          }
   }
/*******************************************************************************
* Function Name  : Delay
* Description    : Inserts a delay time.
* Input          : nCount: specifies the delay time length.
*******************************************************************************/
void Delay(vu32 nCount)
{
  for(; nCount != 0; nCount--);
}
