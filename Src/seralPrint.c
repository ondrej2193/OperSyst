/*
 * seralPrint.c
 *
 *  Created on: 18. 9. 2018
 *      Author: ondrej.sakala
 */
#include "serialPrint.h"

void debugPrint(UART_HandleTypeDef *huart,char _out[]) {
	HAL_UART_Transmit(huart, (uint8_t *) _out, strlen(_out),10);
}


void debugPrintln(UART_HandleTypeDef *huart,char _out[]){
	HAL_UART_Transmit(huart, (uint8_t *) _out, strlen(_out),10);
	char newline[2] ="\r\n";
	HAL_UART_Transmit(huart, (uint8_t*) newline,2,1);
}
