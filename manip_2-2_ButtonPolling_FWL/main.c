/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

GPIO_InitTypeDef GPIO_InitStructure;

// variable d'appui
uint16_t appui;
/* ---------------Private functions ---------------*/
void Delay(vu32 nCount);
int main() {
/*---------- Activer les horloges des ports utilsés (port A et port C)------------ */ 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOA,ENABLE);
	
/*-------------- Configure the GPIO_LED (GPIOC) pin -----------------*/
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
/*-------------- Configure the GPIO_PushButton(GPIOA) pin -----------------*/
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	
/*-------------- Initialization -----------------*/
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	while(1) {
		// read the input in pin 0 of the GPIOA
		appui = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0);
		// Button is pushed ? LED ON : LED OFF
		if(appui) {
			// LED ON
			GPIO_SetBits(GPIOC, GPIO_Pin_8 | GPIO_Pin_9); 
		} else {
			// LED OFF
			GPIO_ResetBits(GPIOC, GPIO_Pin_8 | GPIO_Pin_9);
		}
	}
}

void Delay(vu32 nCount) {

	int i;
	for(i = nCount; i !=0 ; i-- );
}

