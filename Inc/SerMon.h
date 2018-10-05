/*
 * SerMon.h
 *
 *  Created on: 2. 10. 2018
 *      Author: ondrej.sakala
 */
#include "stm32f1xx_hal.h"

#ifndef SERMON_H_
#define SERMON_H_

#ifndef __OS_VER__
  #define __OS_VER__   "00.03.62"
#endif
#ifndef __PREG_VER__
  #define __PREG_VER__   "00.01.0A"
#endif


/*!!!!!!!!!!!!!!!!!!!!!!!!!!!! EXTERN DEFINITIONS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
extern UART_HandleTypeDef huart1;
extern void debugPrintln(UART_HandleTypeDef *huart,char _out[]);
extern void clear(void);

/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!  DEFINITIONS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
#define MAX_ROW_LENGTH_FLOAT   75.0
#define MAX_ROW_LENGTH   75
#define MAX_ROWS          5
#define MAX_BAUD_RATE   115200.0

#define MAX_TIME_DELAY_MS       (uint32_t) (((((1.0/MAX_BAUD_RATE)*10.0)*MAX_ROW_LENGTH_FLOAT)*1000.0)*2)



typedef struct {
  uint8_t       Com[5];
  void          (*Func)(void);
  unsigned int  Param;
} COM;

typedef struct {
	uint8_t Type;
	uint8_t *Vypis;
} PRINT_FORMAT;

const unsigned char ClrScr[]={                 /* vymazanie obrazovky */
  0x1B,0x5B,0x48,0x1B,0x5B,0x4A,0x00
};
const unsigned char Back[]={                  /* zmazanie znaku */
  0x08,0x20,0x08,0x00
};

const unsigned char CrLf[]={                  /* novy riadok */
  0x0D,0x0A,0x00
};

const unsigned char OsVerZ[]={" ...OS IAR PowerPac RTOS "};
const unsigned char VerZ[]={" ...program version: "};
const unsigned char DateZ[]={" ...compilation date: "};

const char Hlavicka[MAX_ROWS][MAX_ROW_LENGTH]={
  "ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป",
  "บ         Terminal control program for Live detection organism          บ",
  "บ                     running under FreeRTOS                            บ",
  "บ           (C) Ondrej Sakala for (R) GlobalLogic  s.r.o.               บ",
  "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ"
};


const COM Commands[2]={
  "RST\0",clear,'H',                  /* 0 */
  "CLS\0",clear,0,                    /* 1 */
};


PRINT_FORMAT ClearPrintTab[]={
  's',(unsigned char *)&ClrScr,
  's',(unsigned char *)&CrLf,                // novy riadok
  's',(unsigned char *)&OsVerZ,              // verzia OS
  's',(unsigned char *)__OS_VER__,
  's',(unsigned char *)&CrLf,                // novy riadok
  's',(unsigned char *)&VerZ,                // verzia programu
  's',(unsigned char *)__PREG_VER__,
  's',(unsigned char *)&CrLf,                // novy riadok
  's',(unsigned char *)&DateZ,               // datum kompilacie
  's',(unsigned char *)__DATE__,
  's',(unsigned char *)&CrLf,                // novy riadok
  's',(unsigned char *)&CrLf                 // novy riadok
};

#endif /* SERMON_H_ */
