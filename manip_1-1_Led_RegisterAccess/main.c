#include <stdint.h> 

 
#define Reg_Enable_RCC (uint32_t*) 0x40021018
#define GPIOC_CRL (uint32_t*) 0x40011000
#define GPIOC_CRH (uint32_t*) 0x40011004
#define GPIOC_BSRR (uint32_t*) 0x40011010
#define GPIOC_BRR (uint32_t*) 0x40011014

main() {

	int i;
	// activate gpioc because it will be used
	*Reg_Enable_RCC |= 0x10;
	
	// activate pin 8 and 9 of the gpioc
	*GPIOC_CRH &= ~( (uint32_t)0xFF);
	*GPIOC_CRH |= 0x22; 
		
	while(1) {
	
		*GPIOC_BSRR = 3 << 8; // e.g: 0x300
		
		for(i=0xFFFFF; i != 0; i--); // Delay
		
		*GPIOC_BRR = 3 << 8; //e.g: 0x300
		for(i=0xFFFFF; i != 0; i--); // Delay
	}
	
}

