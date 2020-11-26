#include <stdint.h>
#include <stdio.h>
#define RCC_APB2ENR (uint32_t *) 0x40021018
#define GPIOC_CRH (uint32_t *) 0x40011004
#define GPIOC_BSRR (uint32_t *) 0x40011010
#define GPIOC_BRR (uint32_t *) 0x40011014

#define GPIOA_IDR (uint32_t *) 0x40010808
#define GPIOA_CRL (uint32_t *) 0x40010800

int etat_button;
main() {
	*RCC_APB2ENR |= 0x14; 
	
	// impose zero for two first pins : pin 8 et 9
	*GPIOC_CRH &= ~((uint32_t) 0xFF);
	// output push_pull 2Mhz
	*GPIOC_CRH |= 0x22;
	
	// impose zero for the first pin : 0
	*GPIOA_CRL &= ~((uint32_t) 0x0F);
	// input floating
	*GPIOA_CRL |= 0x04;
	
	while(1) {
		
		// read the value of the pin 0 (GPIOA)
		etat_button = *GPIOA_IDR & 0x01;
		
		if(etat_button == 0x1) {
			// led on
			*GPIOC_BSRR = 0x300;
		} else {
			// led off
			*GPIOC_BRR = 0x300;
		}
	}

}
