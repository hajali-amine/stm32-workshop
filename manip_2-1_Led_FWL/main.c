#include "stm32f10x.h"
/* declaration des structures relatives aux periphs utilisés -----------------------------------------------------------*/
GPIO_InitTypeDef GPIO_InitStructure;

void Delay(vu32 nCount);
main() {
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
	// set the mode out push pull	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	// set the speed to 2Mhz
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;

	// initialization of the gpioc 
	GPIO_Init(GPIOC,&GPIO_InitStructure);

	while(1) {
		// set bit : pin 8 , 9 -> 1 : LED ON
		GPIO_SetBits(GPIOC,GPIO_Pin_9 | GPIO_Pin_8);
		
		// delay
		Delay(0xFFFFF);
		
		// reset bit : pin 8 , 9 -> 0 : LED OFF
		GPIO_ResetBits(GPIOC,GPIO_Pin_9 | GPIO_Pin_8);
		
		
		// delay
		Delay(0xFFFFF);
	}
}



void Delay(vu32 nCount)
{
	int i;
  for(i=nCount; i != 0; i--);
}
