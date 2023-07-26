/*
 * stmf411re_driver_GPIO.c
 *
 *  Created on: Apr 20, 2023
 *      Author: Kuba
 */

#include "stmf411re_diver_GPIO.h"


void GPIO_PerClkConstrol(GPIO_Reg_Def_t *pGPIOx, uint8_t En_Di){
	if(En_Di==ENABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_CLK_EN();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_CLK_EN();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_CLK_EN();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_CLK_EN();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_CLK_EN();
		}
		else if(pGPIOx == GPIOF)
		{
			GPIOF_CLK_EN();
		}
		else if(pGPIOx == GPIOG)
		{
			GPIOG_CLK_EN();
		}
		else if(pGPIOx == GPIOH)
		{
			GPIOH_CLK_EN();
		}
	}
	else if(En_Di==DISABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_CLK_DI();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_CLK_DI();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_CLK_DI();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_CLK_DI();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_CLK_DI();
		}
		else if(pGPIOx == GPIOF)
		{
			GPIOF_CLK_DI();
		}
		else if(pGPIOx == GPIOG)
		{
			GPIOG_CLK_DI();
		}
		else if(pGPIOx == GPIOH)
		{
			GPIOH_CLK_DI();
		}

	}
}

void GPIO_Init(GPIO_Handle_t *pGPIOHandle){
	//MODE
	uint32_t temp=0;
	if(pGPIOHandle->pcnfgGPIOx.GPIO_PinMode <= GPIO_MODE_ANALOG) //no interrupt
	{
		temp= (pGPIOHandle->pcnfgGPIOx.GPIO_PinMode << (2*pGPIOHandle->pcnfgGPIOx.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER &= (~(0x3)<<(2*pGPIOHandle->pcnfgGPIOx.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER |= temp;
	}
	else //interrupt mode
	{	//input mode
		pGPIOHandle->pGPIOx->MODER &= (~(0x3)<<(2*pGPIOHandle->pcnfgGPIOx.GPIO_PinNumber));
		if(pGPIOHandle->pcnfgGPIOx.GPIO_PinMode==GPIO_MODE_IT_FT)
		{
			//ftsr configuration
			EXTI->FTSR |=  (1<< pGPIOHandle->pcnfgGPIOx.GPIO_PinNumber);
			EXTI->RTSR &=  ~(1<< pGPIOHandle->pcnfgGPIOx.GPIO_PinNumber);

		}
		else if(pGPIOHandle->pcnfgGPIOx.GPIO_PinMode==GPIO_MODE_IT_RT)
		{
			//configure rtsr
			EXTI->RTSR |=  (1<< pGPIOHandle->pcnfgGPIOx.GPIO_PinNumber);
			EXTI->FTSR &=  ~(1<< pGPIOHandle->pcnfgGPIOx.GPIO_PinNumber);

		}
		else if(pGPIOHandle->pcnfgGPIOx.GPIO_PinMode==GPIO_MODE_ITFTRT)
		{
			EXTI->RTSR |=  (1<< pGPIOHandle->pcnfgGPIOx.GPIO_PinNumber);
			EXTI->FTSR |=  (1<< pGPIOHandle->pcnfgGPIOx.GPIO_PinNumber);

		}
	//configure GPIO port selection SYSCFG_EXTICR
		uint8_t temp1= pGPIOHandle->pcnfgGPIOx.GPIO_PinNumber / 4;
		uint8_t temp2= pGPIOHandle->pcnfgGPIOx.GPIO_PinNumber % 4;
		SYSCFG_CLK_EN();
		uint8_t num = GPIOx_TO_NUMBER(pGPIOHandle->pGPIOx);


		SYSCFG->EXTICR[temp1] &= ~(0xF << (4 * temp2));
		SYSCFG->EXTICR[temp1] |= (num<< (4*temp2));


	//enable exti interrupt usin IMR
		EXTI->IMR |=  (1<< pGPIOHandle->pcnfgGPIOx.GPIO_PinNumber);

	}
	//SPEED
	temp=0;
	temp= (pGPIOHandle->pcnfgGPIOx.GPIO_PinSpeed << (2*pGPIOHandle->pcnfgGPIOx.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEED &= (~(0x3)<<(2*pGPIOHandle->pcnfgGPIOx.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEED |=temp;

	//PUPD
	temp=0;
	temp= (pGPIOHandle->pcnfgGPIOx.GPIO_PinPuPdControl << (2*pGPIOHandle->pcnfgGPIOx.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR &= (~(0x3)<<(2*pGPIOHandle->pcnfgGPIOx.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR |=temp;

	//OPTYPE

	temp=0;
	temp= (pGPIOHandle->pcnfgGPIOx.GPIO_PinOPType << (pGPIOHandle->pcnfgGPIOx.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OTYPER &= (~(0x1)<<(pGPIOHandle->pcnfgGPIOx.GPIO_PinNumber));

	pGPIOHandle->pGPIOx->OTYPER |=temp;

	//ALTFUN

	if(pGPIOHandle->pcnfgGPIOx.GPIO_PinMode == GPIO_MODE_ALTFUN)
	{
		uint32_t temp1,temp2;
		temp1= pGPIOHandle->pcnfgGPIOx.GPIO_PinNumber/8;
		temp2= pGPIOHandle->pcnfgGPIOx.GPIO_PinNumber%8;
		pGPIOHandle->pGPIOx->AFR[temp1] &=( 0xF <<(4*temp2) );
		pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->pcnfgGPIOx.GPIO_PinAltFunMode << (4*temp2));
	}
}

void GPIO_DeInit(GPIO_Reg_Def_t *pGPIOx)
{
	if(pGPIOx == GPIOA)
		{
		GPIOA_REG_RESET();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_REG_RESET();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_REG_RESET();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_REG_RESET();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_REG_RESET();
		}
		else if(pGPIOx == GPIOF)
		{
			GPIOF_REG_RESET();
		}
		else if(pGPIOx == GPIOG)
		{
			GPIOG_REG_RESET();
		}
		else if(pGPIOx == GPIOH)
		{
			GPIOH_REG_RESET();
		}
}

uint8_t GPIO_ReadFromInputPin(GPIO_Reg_Def_t *pGPIOx, uint8_t Pin_Num)
{
	uint8_t val;
	val= (uint8_t)((pGPIOx->IDR >> Pin_Num)& 0x00000001);
	return val;
}

uint16_t GPIO_ReadFromInputPort(GPIO_Reg_Def_t *pGPIOx)
{
	uint16_t val;
	val= (uint16_t)pGPIOx->IDR;
	return val;
}

void GPIO_WriteToOutputPin(GPIO_Reg_Def_t *pGPIOx, uint8_t Pin_Num, uint8_t Value )
{
	if(Value==1)
	{
		pGPIOx->ODR |= (1<<Pin_Num);
	}
	else if (Value==0)
	{
		pGPIOx->ODR &= ~(1<<Pin_Num);
	}
}


void GPIO_WriteToOutputPort(GPIO_Reg_Def_t *pGPIOx, uint16_t Value )
{
	pGPIOx->ODR = Value;

}


void GPIO_ToggleOutputPin(GPIO_Reg_Def_t *pGPIOx, uint8_t Pin_Num)
{
	pGPIOx->ODR ^= (1<<Pin_Num);
}


void GPIO_IRQITConfig(uint8_t IRQNumber, uint8_t EnDi)
{
	if(EnDi==ENABLE)
	{
		if(IRQNumber <= 31)
		{
			//iser0
			*NVIC_ISER0 |= (1<< IRQNumber);
		}
		else if(IRQNumber >31 && IRQNumber<=63)
		{
			*NVIC_ISER1 |= (1<< (IRQNumber %32));
		}
		else if(IRQNumber >63 && IRQNumber<=97)
		{
			*NVIC_ISER2 |= (1<< (IRQNumber %64));
		}
	}
	else if(IRQNumber==DISABLE)
	{
		if(IRQNumber <= 31)
		{
			*NVIC_ICER0 |= (1<< IRQNumber);
		}
		else if(IRQNumber >31 && IRQNumber<=63)
		{
			*NVIC_ICER1 |= (1<< (IRQNumber %32));
		}
		else if(IRQNumber >63 && IRQNumber<=97)
		{
			*NVIC_ICER2 |= (1<< (IRQNumber %64));
		}
	}
}
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority)
{
	uint8_t reg = IRQNumber/4;
	uint8_t sec = IRQNumber %4;

	*(NVIC_IPR_BASE_ADDR+reg) |= (IRQPriority << ((8*sec) + 4 )); // 4 - bits not implemented



}



void GPIO_IRQHandling(uint8_t PinNumber)
{
	//clear pending register exti
	if(EXTI->PR & (1<<PinNumber))
	{
		EXTI->PR |= (1<<PinNumber);
	}
}




