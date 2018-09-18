/*
 * serialPrint.h
 *
 *  Created on: 18. 9. 2018
 *      Author: ondrej.sakala
 */

#ifndef SERIALPRINT_H_
#define SERIALPRINT_H_

#include "stm32f1xx_hal.h"

	void debugPrint(UART_HandleTypeDef *huart,char _out[]);
	void debugPrintln(UART_HandleTypeDef *huart,char _out[]);


#endif /* SERIALPRINT_H_ */
