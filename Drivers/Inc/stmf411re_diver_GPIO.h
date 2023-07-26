/*
 * stmf411re_diver_GPIO.h
 *
 *  Created on: Apr 20, 2023
 *      Author: Kuba
 */

#ifndef INC_STMF411RE_DIVER_GPIO_H_
#define INC_STMF411RE_DIVER_GPIO_H_

#include "stmf411re.h"
typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;


typedef struct
{
	GPIO_Reg_Def_t* pGPIOx;
	GPIO_PinConfig_t pcnfgGPIOx;
}GPIO_Handle_t;



void GPIO_PerClkConstrol(GPIO_Reg_Def_t *pGPIOx, uint8_t En_Di);



void GPIO_Init(GPIO_Handle_t *pGPIOHandle);


void GPIO_DeInit(GPIO_Reg_Def_t *pGPIOx);
uint8_t GPIO_ReadFromInputPin(GPIO_Reg_Def_t *pGPIOx, uint8_t Pin_Num);
uint16_t GPIO_ReadFromInputPort(GPIO_Reg_Def_t *pGPIOx);

void GPIO_WriteToOutputPin(GPIO_Reg_Def_t *pGPIOx, uint8_t Pin_Num, uint8_t Value );
void GPIO_WriteToOutputPort(GPIO_Reg_Def_t *pGPIOx, uint16_t Value );
void GPIO_ToggleOutputPin(GPIO_Reg_Def_t *pGPIOx, uint8_t Pin_Num);



void GPIO_IRQITConfig(uint8_t IRQNumber, uint8_t EnDi);

void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority);

void GPIO_IRQHandling(uint8_t PinNumber);


//possible modes
#define GPIO_MODE_IN 0
#define GPIO_MODE_OUT 1
#define GPIO_MODE_ALTFUN 2
#define GPIO_MODE_ANALOG 3
#define GPIO_MODE_IT_FT 4
#define GPIO_MODE_IT_RT 5
#define GPIO_MODE_ITFTRT 6

//output types
#define GPIO_OUT_TYPE_PP 0
#define GPIO_OUT_TYPE_OD 1

//output speed

#define GPIO_OUT_SPEED_LOW 0
#define GPIO_OUT_SPEED_MEDIUM 1
#define GPIO_OUT_SPEED_FAST 2
#define GPIO_OUT_SPEED_HIGH 3

//Pull-up, pull-down

#define GPIO_NO_PU_PD 0
#define GPIO_PU 1
#define GPIO_PD 2




#endif /* INC_STMF411RE_DIVER_GPIO_H_ */
