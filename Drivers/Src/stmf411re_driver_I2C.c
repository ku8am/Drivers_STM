/*
 * stmf411re_driver_I2C.c
 *
 *  Created on: 23 lip 2023
 *      Author: Kuba
 */

#include "stmf411re_driver_I2C.h"

void I2C_PeripheralControl(I2C_Reg_Def_t *pI2Cx, uint8_t EnDi)
{
	if(EnDi == ENABLE)
	{
		pI2Cx->CR1 |= (1 << I2C_CR1_PE);
	}
	else if(EnDi == DISABLE)
	{
		pI2Cx->CR1 &= ~(1 << 0);
	}
}



void I2C_PeriClockControl(I2C_Reg_Def_t *pI2Cx, uint8_t EnDi)
{
	if(EnDi == ENABLE)
	{
		if(pI2Cx == I2C1)
		{
			I2C1_CLK_EN();
		}else if (pI2Cx == I2C2)
		{
			I2C2_CLK_EN();
		}else if (pI2Cx == I2C3)
		{
			I2C3_CLK_EN();
		}
	}
}

uint16_t AHB_PreScaler[8] = {2,4,8,16,64,128,256,512};
uint8_t APB1_PreScaler[4] = { 2, 4 , 8, 16};


uint32_t RCC_GetPCLK1Value(void)
{
	uint32_t pclk1,SystemClk;

	uint8_t clksrc,temp,ahbp,apb1p;

	clksrc = ((RCC->CFGR >> 2) & 0x3);

	if(clksrc == 0 )
	{
		SystemClk = 16000000;
	}else if(clksrc == 1)
	{
		SystemClk = 8000000;
	}else if (clksrc == 2)
	{
		//to do pll
	}

	temp = ((RCC->CFGR >> 4 ) & 0xF);

	if(temp < 8)
	{
		ahbp = 1;
	}else
	{
		ahbp = AHB_PreScaler[temp-8];
	}

	temp = ((RCC->CFGR >> 10 ) & 0x7);

	if(temp < 4)
	{
		apb1p = 1;
	}else
	{
		apb1p = APB1_PreScaler[temp-4];
	}

	pclk1 =  (SystemClk / ahbp) /apb1p;

	return pclk1;
}



void I2C_Init(I2C_Handle_t *pI2CHandle)
{
	I2C_PeriClockControl(pI2CHandle->pI2Cx,ENABLE);
	uint32_t temp =0;

	//rcc freq conf
	temp =RCC_GetPCLK1Value()/1000000;
	pI2CHandle->pI2Cx->CR2 |= temp;


	//3device addr (only when device is slave)
	temp=0;
	//only 7 bit mode
	pI2CHandle->pI2Cx->OAR1 |= (pI2CHandle->I2C_Config.I2C_DeviceAddress << 1);
	pI2CHandle->pI2Cx->OAR1 |= (1<<14);
	//4 enable acking
	pI2CHandle->pI2Cx->CR1 |= (pI2CHandle->I2C_Config.I2C_AckControl << 10);
	//1MODE(standard or fast)
	uint16_t ccr_value = 0;
	temp = 0;
	if(pI2CHandle->I2C_Config.I2C_SCLSpeed <= I2C_SCL_SPEED_SM)
	{
		//standard mode
		ccr_value = (RCC_GetPCLK1Value() / ( 2 * pI2CHandle->I2C_Config.I2C_SCLSpeed ) );
		temp|= ccr_value;
	}
	else
	{
		//fast mode
		temp |= ( 1 << 15);
		temp |= (pI2CHandle->I2C_Config.I2C_FMDutyCycle << 14);
		if(pI2CHandle->I2C_Config.I2C_FMDutyCycle == I2C_FM_DUTY_2)
		{
			ccr_value = (RCC_GetPCLK1Value() / ( 3 * pI2CHandle->I2C_Config.I2C_SCLSpeed ) );
		}else
		{
			ccr_value = (RCC_GetPCLK1Value() / ( 25 * pI2CHandle->I2C_Config.I2C_SCLSpeed ) );
		}
		temp |= (ccr_value & 0xFFF);
	}
	pI2CHandle->pI2Cx->CCR = temp;

	//configure all in disable periph mode
}
