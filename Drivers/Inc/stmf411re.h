/*
 * stmf411re.h
 *
 *  Created on: Apr 20, 2023
 *      Author: Kuba
 */

#ifndef INC_STMF411RE_H_
#define INC_STMF411RE_H_

#include "stdint.h"

/*
 *  AHBx and APBx bus Peripheral base addresses
 */
#define __vo 												volatile

//processor registers
#define NVIC_ISER0 											(__vo uint32_t*)0xE000E100
#define NVIC_ISER1 											(__vo uint32_t*)0xE000E104
#define NVIC_ISER2 											(__vo uint32_t*)0xE000E108

#define NVIC_ICER0 											(__vo uint32_t*)0xE000E180
#define NVIC_ICER1 											(__vo uint32_t*)0xE000E184
#define NVIC_ICER2 											(__vo uint32_t*)0xE000E188

#define NVIC_IPR_BASE_ADDR											(__vo uint32_t*)0xE000E400


#define PERIPH_BASE_ADDR									0x40000000U
#define APB1_PERIPH_BASE_ADDR								PERIPH_BASE_ADDR
#define APB2_PERIPH_BASE_ADDR								0x40010000U
#define AHB1_PERIPH_BASE_ADDR								0x40020000U
#define AHB2_PERIPH_BASE_ADDR								0x50000000U
#define AHB3_PERIPH_BASE_ADDR								0xA0000000U

/*
 * Base addresses of peripheral which hanging on AHB3 bus
 */

#define	FSMC_control_reg 									AHB3_PERIPH_BASE_ADDR

/*
 * Base addresses of peripheral which hanging on AHB2 bus
 */


#define	RNG_BASE_ADDR										0x50060800U
#define	HASH_BASE_ADDR										0x50060400U
#define	CRYP_BASE_ADDR										0x50060000U
#define	DCMI_BASE_ADDR										0x50050000U
#define	USB_OTG_FS_BASE_ADDR								0x50000000U


/*
 * Base addresses of peripheral which hanging on AHB1 bus
 */
//#define	USB_OTG_HS_BASE_ADDR			                	(AHB1_PERIPH_BASE_ADDR + 0x20000)
//#define	ETH_MAC_BASE_ADDR				                	(AHB1_PERIPH_BASE_ADDR + 0x8000)
#define	DMA2_BASE_ADDR					                	(AHB1_PERIPH_BASE_ADDR + 0x6400)
#define	DMA1_BASE_ADDR					                	(AHB1_PERIPH_BASE_ADDR + 0x6000)
#define	BKPSRAM_BASE_ADDR				                	(AHB1_PERIPH_BASE_ADDR + 0x4000)
#define	Flash_int_BASE_ADDR				                	(AHB1_PERIPH_BASE_ADDR + 0x3C00)
#define	RCC_BASE_ADDR					                	(AHB1_PERIPH_BASE_ADDR + 0x3800)
#define	CRC_BASE_ADDR					                	(AHB1_PERIPH_BASE_ADDR + 0x3000)
//#define	GPIOI_BASE_ADDR					                	(AHB1_PERIPH_BASE_ADDR + 0x2000)
#define	GPIOH_BASE_ADDR					                	(AHB1_PERIPH_BASE_ADDR + 0x1C00)
#define	GPIOG_BASE_ADDR					                	(AHB1_PERIPH_BASE_ADDR + 0x1800)
#define	GPIOF_BASE_ADDR					                	(AHB1_PERIPH_BASE_ADDR + 0x1400)
#define	GPIOE_BASE_ADDR					                	(AHB1_PERIPH_BASE_ADDR + 0x1000)
#define	GPIOD_BASE_ADDR					                	(AHB1_PERIPH_BASE_ADDR + 0x0C00)
#define	GPIOC_BASE_ADDR					                	(AHB1_PERIPH_BASE_ADDR + 0x0800)
#define	GPIOB_BASE_ADDR					                	(AHB1_PERIPH_BASE_ADDR + 0x0400)
#define	GPIOA_BASE_ADDR					                	 AHB1_PERIPH_BASE_ADDR

/*
 * Base addresses of peripheral which hanging on APB2 bus
 */

#define	SPI6_BASE_ADDR			        					(APB2_PERIPH_BASE_ADDR + 0x5400)
#define	SPI5_BASE_ADDR			        					(APB2_PERIPH_BASE_ADDR + 0x5000)
#define	TIM11_BASE_ADDR			        					(APB2_PERIPH_BASE_ADDR + 0x4800)
#define	TIM10_BASE_ADDR			        					(APB2_PERIPH_BASE_ADDR + 0x4400)
#define	TIM9_BASE_ADDR			        					(APB2_PERIPH_BASE_ADDR + 0x4000)
#define	EXTI_BASE_ADDR			        					(APB2_PERIPH_BASE_ADDR + 0x3C00)
#define	SYSCFG_BASE_ADDR		        					(APB2_PERIPH_BASE_ADDR + 0x3800)
#define	SPI4_BASE_ADDR			        					(APB2_PERIPH_BASE_ADDR + 0x3400)
#define	SPI1_BASE_ADDR			        					(APB2_PERIPH_BASE_ADDR + 0x3000)
#define	SDIO_BASE_ADDR			        					(APB2_PERIPH_BASE_ADDR + 0x2C00)
#define	ADC1_2_3_BASE_ADDR		        					(APB2_PERIPH_BASE_ADDR + 0x2000)
#define	USART6_BASE_ADDR		        					(APB2_PERIPH_BASE_ADDR + 0x1400)
#define	USART1_BASE_ADDR		        					(APB2_PERIPH_BASE_ADDR + 0x1000)
#define	TIM8_BASE_ADDR			        					(APB2_PERIPH_BASE_ADDR + 0x0400)
#define	TIM1_BASE_ADDR			        					APB2_PERIPH_BASE_ADDR

/*
 * Base addresses of peripheral which hanging on APB1 bus
 */

#define	UART8_BASE_ADDR		 								(APB1_PERIPH_BASE_ADDR + 0x7C00)
#define	UART7_BASE_ADDR										(APB1_PERIPH_BASE_ADDR + 0x7800)
#define	DAC_BASE_ADDR										(APB1_PERIPH_BASE_ADDR + 0x7400)
#define	PWR_BASE_ADDR										(APB1_PERIPH_BASE_ADDR + 0x7000)
#define	CAN2_BASE_ADDR										(APB1_PERIPH_BASE_ADDR + 0x6800)
#define	CAN1_BASE_ADDR										(APB1_PERIPH_BASE_ADDR + 0x6400)
#define	I2C3_BASE_ADDR										(APB1_PERIPH_BASE_ADDR + 0x5C00)
#define	I2C2_BASE_ADDR										(APB1_PERIPH_BASE_ADDR + 0x5800)
#define	I2C1_BASE_ADDR										(APB1_PERIPH_BASE_ADDR + 0x5400)
#define	UART5_BASE_ADDR										(APB1_PERIPH_BASE_ADDR + 0x5000)
#define	UART4_BASE_ADDR										(APB1_PERIPH_BASE_ADDR + 0x4C00)
#define	USART3_BASE_ADDR									(APB1_PERIPH_BASE_ADDR + 0x4800)
#define	USART2_BASE_ADDR									(APB1_PERIPH_BASE_ADDR + 0x4400)
#define	I2S3ext_BASE_ADDR									(APB1_PERIPH_BASE_ADDR + 0x4000)
#define	SPI3_I2S3_BASE_ADDR									(APB1_PERIPH_BASE_ADDR + 0x3C00)
#define	SPI2_I2S2_BASE_ADDR									(APB1_PERIPH_BASE_ADDR + 0x3800)
#define	I2S2ext_BASE_ADDR									(APB1_PERIPH_BASE_ADDR + 0x3400)
#define	IWDG_BASE_ADDR										(APB1_PERIPH_BASE_ADDR + 0x3000)
#define	WWDG_BASE_ADDR										(APB1_PERIPH_BASE_ADDR + 0x2C00)
#define	RTC_BKPReg_BASE_ADDR								(APB1_PERIPH_BASE_ADDR + 0x2800)
#define	TIM14_BASE_ADDR										(APB1_PERIPH_BASE_ADDR + 0x2000)
#define	TIM13_BASE_ADDR										(APB1_PERIPH_BASE_ADDR + 0x1C00)
#define	TIM12_BASE_ADDR										(APB1_PERIPH_BASE_ADDR + 0x1800)
#define TIM7_BASE_ADDR										(APB1_PERIPH_BASE_ADDR + 0x1400)
#define TIM6_BASE_ADDR										(APB1_PERIPH_BASE_ADDR + 0x1000)
#define TIM5_BASE_ADDR										(APB1_PERIPH_BASE_ADDR + 0x0C00)
#define TIM4_BASE_ADDR										(APB1_PERIPH_BASE_ADDR + 0x0800)
#define TIM3_BASE_ADDR										(APB1_PERIPH_BASE_ADDR + 0x0400)
#define TIM2_BASE_ADDR										 APB1_PERIPH_BASE_ADDR





typedef struct
{
	__vo uint32_t MODER;							//Address offset: 0x00
	__vo uint32_t OTYPER;							//Address offset: 0x04
	__vo uint32_t OSPEED;                            //Address offset: 0x08
	__vo uint32_t PUPDR;                             //Address offset: 0x0C
	__vo uint32_t IDR;                               //Address offset: 0x10
	__vo uint32_t ODR;                               //Address offset: 0x14
	__vo uint32_t BSRR;                              //Address offset: 0x18
	__vo uint32_t LCKR;                              //Address offset: 0x1C
	__vo uint32_t AFR[2];                              //Address offset: 0x20, 0x24
//	__vo uint32_t AFRH;                              //Address offset: 0x24
}GPIO_Reg_Def_t;




typedef struct
{
	__vo uint32_t CR1; //0x00
	__vo uint32_t CR2; //0x04
	__vo uint32_t OAR1; //0x08
	__vo uint32_t OAR2; //0x0C
	__vo uint32_t DR; //0x10
	__vo uint32_t SR1; //0x14
	__vo uint32_t SR2; //0x18
	__vo uint32_t CCR; //0x1C
	__vo uint32_t TRISE; //0x20
	__vo uint32_t FLTR; //0x24


}I2C_Reg_Def_t;


#define I2C1								((I2C_Reg_Def_t*)I2C1_BASE_ADDR)
#define I2C2								((I2C_Reg_Def_t*)I2C2_BASE_ADDR)
#define I2C3								((I2C_Reg_Def_t*)I2C3_BASE_ADDR)

#define I2C1_CLK_EN()					RCC->APB1ENR |= (1<<21)
#define I2C2_CLK_EN()					RCC->APB1ENR |= (1<<22)
#define I2C3_CLK_EN()					RCC->APB1ENR |= (1<<23)


/*
 * Peripheral register definition structure for RCC
 */

typedef struct
{
	__vo uint32_t CR;								 //Address offset: 0x00
	__vo uint32_t PLLCFGR;							//Address offset: 0x04
	__vo uint32_t CFGR;							//Address offset: 0x08
	__vo uint32_t CIR;								 //Address offset: 0x0C
	__vo uint32_t AHB1RSTR; //0x10
	__vo uint32_t AHB2RSTR; //0x14
	__vo uint32_t AHB3RSTR; //0x18
	__vo uint32_t RESERVED; //0x1C
	__vo uint32_t APB1RSTR; //0x20
	__vo uint32_t APB2RSTR; //0x24
	__vo uint32_t RESERVED1[2]; //0x28, 0x2C
	__vo uint32_t AHB1ENR; //0x30
	__vo uint32_t AHB2ENR; //0x34
	__vo uint32_t AHB3ENR; //0x38
	__vo uint32_t RESERVED2; //0x3C
	__vo uint32_t APB1ENR; //0x40
	__vo uint32_t APB2ENR; //0x44
	__vo uint32_t RESERVED3[2]; //0x48, 0x4C
	__vo uint32_t AHB1LPENR; //0x50
	__vo uint32_t AHB2LPENR; //0x54
	__vo uint32_t AHB3LPENR; //0x58
	__vo uint32_t RESERVED4; //0x5C
	__vo uint32_t APB1LPENR; //0x60
	__vo uint32_t APB2LPENR; //0x64
	__vo uint32_t RESERVED5[2]; //0x68, 0x6C
	__vo uint32_t BDCR; //0x70
	__vo uint32_t CSR; //0x74
	__vo uint32_t RESERVED6[2]; //0x78, 0x7C
	__vo uint32_t SSCGR; //0x80
	__vo uint32_t PLLI2SCFGR; //0x84
	__vo uint32_t PLLSAICFGR; //0x88
	__vo uint32_t DCKCFGR; //0x8C
	__vo uint32_t CKGATENR; //0x90
	__vo uint32_t DCKCFGR2; //0x94

}RCC_Reg_Def_t;

#define RCC  												((RCC_Reg_Def_t*)RCC_BASE_ADDR)

/*
 * Clock enable macros for gpiox peripherals
 */

#define GPIOA_CLK_EN() RCC->AHB1ENR |= (1<<0)
#define GPIOB_CLK_EN() RCC->AHB1ENR |= (1<<1)
#define GPIOC_CLK_EN() RCC->AHB1ENR |= (1<<2)
#define GPIOD_CLK_EN() RCC->AHB1ENR |= (1<<3)
#define GPIOE_CLK_EN() RCC->AHB1ENR |= (1<<4)
#define GPIOF_CLK_EN() RCC->AHB1ENR |= (1<<5)
#define GPIOG_CLK_EN() RCC->AHB1ENR |= (1<<6)
#define GPIOH_CLK_EN() RCC->AHB1ENR |= (1<<7)

#define  SYSCFG_CLK_EN() RCC->APB2ENR |= (1<<14)
/*
 * Clock disable macros for gpiox peripherals
 */

#define GPIOA_CLK_DI() RCC->AHB1ENR &= ~(1<<0)
#define GPIOB_CLK_DI() RCC->AHB1ENR &= ~ (1<<1)
#define GPIOC_CLK_DI() RCC->AHB1ENR &= ~ (1<<2)
#define GPIOD_CLK_DI() RCC->AHB1ENR &= ~ (1<<3)
#define GPIOE_CLK_DI() RCC->AHB1ENR &= ~ (1<<4)
#define GPIOF_CLK_DI() RCC->AHB1ENR &= ~ (1<<5)
#define GPIOG_CLK_DI() RCC->AHB1ENR &= ~ (1<<6)
#define GPIOH_CLK_DI() RCC->AHB1ENR &= ~ (1<<7)


typedef struct{
	__vo uint32_t IMR; //0x00
	__vo uint32_t EMR; //0x04
	__vo uint32_t RTSR; //0x08
	__vo uint32_t FTSR; //0x0C
	__vo uint32_t SWIER; //0x10
	__vo uint32_t PR;    //0x14
}EXTI_Reg_Def_t;



typedef struct{
	__vo uint32_t MEMRMP; //0x00
	__vo uint32_t PMC; //0x04
	__vo uint32_t EXTICR[4];
//	uint32_t EXTICR1; //0x08
//	uint32_t EXTICR2; //0x0C
//	uint32_t EXTICR3; //0x10
//	uint32_t EXTICR4; //0x14
	__vo uint32_t CMPCR; //0x20
	__vo uint32_t CFGR; //0x2C

}SYSCFG_Reg_Def_t;

#define SYSCFG ((SYSCFG_Reg_Def_t*)SYSCFG_BASE_ADDR)

#define EXTI 											 ((EXTI_Reg_Def_t*)EXTI_BASE_ADDR)

/*
 * Peripheral base adresses typecasted to GPIO_Reg_def_t
 */

#define GPIOA  												((GPIO_Reg_Def_t*)GPIOA_BASE_ADDR)
#define GPIOB  												((GPIO_Reg_Def_t*)GPIOB_BASE_ADDR)
#define GPIOC  												((GPIO_Reg_Def_t*)GPIOC_BASE_ADDR)
#define GPIOD  												((GPIO_Reg_Def_t*)GPIOD_BASE_ADDR)
#define GPIOE  												((GPIO_Reg_Def_t*)GPIOE_BASE_ADDR)
#define GPIOF  												((GPIO_Reg_Def_t*)GPIOF_BASE_ADDR)
#define GPIOG  												((GPIO_Reg_Def_t*)GPIOG_BASE_ADDR)
#define GPIOH  												((GPIO_Reg_Def_t*)GPIOH_BASE_ADDR)
//#define GPIOI  												((GPIO_Reg_Def_t*)GPIOI_BASE_ADDR)


#define GPIOA_REG_RESET() do{ RCC->AHB1RSTR |= (1<<0);  RCC->AHB1RSTR &= ~(1<<0); } while(0)
#define GPIOB_REG_RESET() do{ RCC->AHB1RSTR |= (1<<1);	RCC->AHB1RSTR &= ~(1<<1); } while(0)
#define GPIOC_REG_RESET() do{ RCC->AHB1RSTR |= (1<<2);	RCC->AHB1RSTR &= ~(1<<2); } while(0)
#define GPIOD_REG_RESET() do{ RCC->AHB1RSTR |= (1<<3);	RCC->AHB1RSTR &= ~(1<<3); } while(0)
#define GPIOE_REG_RESET() do{ RCC->AHB1RSTR |= (1<<4);	RCC->AHB1RSTR &= ~(1<<4); } while(0)
#define GPIOF_REG_RESET() do{ RCC->AHB1RSTR |= (1<<5);	RCC->AHB1RSTR &= ~(1<<5); } while(0)
#define GPIOG_REG_RESET() do{ RCC->AHB1RSTR |= (1<<6);	RCC->AHB1RSTR &= ~(1<<6); } while(0)
#define GPIOH_REG_RESET() do{ RCC->AHB1RSTR |= (1<<7);	RCC->AHB1RSTR &= ~(1<<7); } while(0)


#define GPIOx_TO_NUMBER(x)	((x==GPIOA) ? 0 :\
							(x==GPIOB) ? 1 :\
							(x==GPIOC) ? 2 :\
							(x==GPIOD) ? 3 :\
							(x==GPIOE) ? 4 :\
							(x==GPIOF) ? 5 :\
							(x==GPIOG) ? 6 :\
							(x==GPIOH) ? 7 :0)

#define IRQ_NO_EXTI0 6
#define IRQ_NO_EXTI1 7
#define IRQ_NO_EXTI2 8
#define IRQ_NO_EXTI3 9
#define IRQ_NO_EXTI4 10

#define IRQ_NO_EXTI9_5 23
#define IRQ_NO_EXTI15_10 40

#define ENABLE 1
#define DISABLE 0

/*
 * Bit position definitions I2C_CR1
 */
#define I2C_CR1_PE						0
#define I2C_CR1_NOSTRETCH  				7
#define I2C_CR1_START 					8
#define I2C_CR1_STOP  				 	9
#define I2C_CR1_ACK 				 	10
#define I2C_CR1_SWRST  				 	15

/*
 * Bit position definitions I2C_CR2
 */
#define I2C_CR2_FREQ				 	0
#define I2C_CR2_ITERREN				 	8
#define I2C_CR2_ITEVTEN				 	9
#define I2C_CR2_ITBUFEN 			    10

/*
 * Bit position definitions I2C_SR1
 */

#define I2C_SR1_SB 					 	0
#define I2C_SR1_ADDR 				 	1
#define I2C_SR1_BTF 					2
#define I2C_SR1_ADD10 					3
#define I2C_SR1_STOPF 					4
#define I2C_SR1_RXNE 					6
#define I2C_SR1_TXE 					7
#define I2C_SR1_BERR 					8
#define I2C_SR1_ARLO 					9
#define I2C_SR1_AF 					 	10
#define I2C_SR1_OVR 					11
#define I2C_SR1_TIMEOUT 				14

/*
 * Bit position definitions I2C_SR2
 */
#define I2C_SR2_MSL						0
#define I2C_SR2_BUSY 					1
#define I2C_SR2_TRA 					2
#define I2C_SR2_GENCALL 				4
#define I2C_SR2_DUALF 					7

/*
 * Bit position definitions I2C_CCR
 */
#define I2C_CCR_CCR 					 0
#define I2C_CCR_DUTY 					14
#define I2C_CCR_FS  				 	15

#endif /* INC_STMF411RE_H_ */

