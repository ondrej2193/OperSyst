/*
 * externDefTiISR.h
 *
 *  Created on: 21. 9. 2018
 *      Author: ondrej.sakala
 */

#ifndef EXTERNDEFTIISR_H_
#define EXTERNDEFTIISR_H_

#include "cmsis_os.h"


extern void SetxBinarySemaphoreHandleFromISR( BaseType_t xHiPriorTaskWok);
extern osSemaphoreId bISemGetCANDataHandle;
extern osSemaphoreId bISemSendCANDataHandle;
extern osSemaphoreId bISemGetSerialDataHandle;



#endif /* EXTERNDEFTIISR_H_ */
