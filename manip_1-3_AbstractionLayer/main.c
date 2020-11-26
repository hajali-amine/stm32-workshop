//#include <stm32map.h>
#include <gpio.h>



#define   RCC_APB2ENR     (uint32_t*) 0x40021018
uint8_t EtatBouton;

int main ()
{	
	GPIO_Struct GPIO_InitStruct;
	//Activate GPIOs Clocks
 
	 *RCC_APB2ENR  |=  0x14; //Activation de l'horloge du PORT A/C
	/*
	//Configure GPIO Pins (Push Button)=PA0:Input Floating Mode
	GPIOA->CRL &= ~((uint32_t) 0x0F);;
	GPIOA->CRL |= GPIO_Mode_InputFloating;
	//Configure GPIO Pins (LED)=PC9/PC8:Output Push Pull 2 MHZ
	GPIOC->CRH &= ~((uint32_t) 0xFF);
	GPIOC->CRH |= GPIO_Mode_OutputPP2Mhz;
	GPIOC->CRH |= GPIO_Mode_OutputPP2Mhz <<4 ;
	*/
	

	//Configure GPIO Pins (Push Button)=PA0:Input Floating Mode
	GPIO_InitStruct.GPIO_PIN= GPIO_PIN_0;
	GPIO_InitStruct.GPIO_Mode= GPIO_Mode_InputFloating;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	//Configure GPIO Pins (LED)=PC9/PC8:Output Push Pull 2 MHZ
	GPIO_InitStruct.GPIO_PIN = GPIO_PIN_8| GPIO_PIN_9 ;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OutputPP2Mhz;
	GPIO_Init(GPIOC, &GPIO_InitStruct) ;


 while (1)
  {		
		//Test Push Button
 		//Read Oush Button State (0=Pressed, 1=Released)
		EtatBouton=GPIO_TestPin(GPIOA,GPIO_PIN_0);
		
	if (EtatBouton==0)  //If Pressed, Led ON	
	GPIO_SetPin(GPIOC, GPIO_PIN_8|GPIO_PIN_9);
	else //Released, Led OFF
	GPIO_ResetPin(GPIOC, GPIO_PIN_8|GPIO_PIN_9);				
}
	}
