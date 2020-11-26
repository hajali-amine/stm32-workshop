#include <gpio.h>

int GPIO_TestPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN)
{
	int t=GPIOx->IDR & GPIO_PIN;
 if (t!=0)
	 return 0;
 else
	 return 1;
}

void GPIO_SetPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN)
{
	GPIOx->BSRR=GPIO_PIN;
}

void GPIO_ResetPin (GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN)
{
	GPIOx->BRR=GPIO_PIN;	
}


void GPIO_Init (GPIO_TypeDef* GPIOx,  GPIO_Struct*   GPIO_InitStruct){
	int t=0;
	int i=0;
	for (i=0;i<16;i++){
		t=GPIO_InitStruct->GPIO_PIN & (1<<i);
		if (t!=0){
			if (i<=7){
				GPIOx->CRL &= ~(0xF<<(4*i));
				GPIOx->CRL |= GPIO_InitStruct->GPIO_Mode <<(4*i);
			}
			else{
				GPIOx->CRH &= ~(0xF<<(4*(i-8)));
				GPIOx->CRH |= GPIO_InitStruct->GPIO_Mode <<(4*(i-8));
			}						
		}
	}
}