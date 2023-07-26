/*
 * stmf411re_driver_I2C.h
 *
 *  Created on: 23 lip 2023
 *      Author: Kuba
 */

#ifndef INC_STMF411RE_DRIVER_I2C_H_
#define INC_STMF411RE_DRIVER_I2C_H_

#include "stmf411re.h"


typedef struct
{
	uint32_t I2C_SCLSpeed;
	uint8_t  I2C_DeviceAddress;
	uint8_t  I2C_AckControl;
	uint8_t  I2C_FMDutyCycle;

}I2C_Config_t;

typedef struct
{
	I2C_Reg_Def_t *pI2Cx;
	I2C_Config_t I2C_Config;
}I2C_Handle_t;


/*
 * @I2C_SCLSpeed
 */
#define I2C_SCL_SPEED_SM 	100000
#define I2C_SCL_SPEED_FM4K 	400000
#define I2C_SCL_SPEED_FM2K  200000





#define I2C_ACK_ENABLE        1
#define I2C_ACK_DISABLE       0


#define I2C_FM_DUTY_2        0
#define I2C_FM_DUTY_16_9     1

void I2C_PeripheralControl(I2C_Reg_Def_t *pI2Cx, uint8_t EnDi);

void I2C_PeriClockControl(I2C_Reg_Def_t *pI2Cx, uint8_t EnDi);

void I2C_Init(I2C_Handle_t *pI2CHandle);





#endif /* INC_STMF411RE_DRIVER_I2C_H_ */
