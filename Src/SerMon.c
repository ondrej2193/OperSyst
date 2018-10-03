/*
 * SerMon.c
 *
 *  Created on: 2. 10. 2018
 *      Author: ondrej.sakala
 */

#include "SerMon.h"

void clear(void);    /* clear screen */

/*------------------------------------------------------------*/
/*                     zmazanie obrazovky                     */
/*------------------------------------------------------------*/
void clear(void){    /* zmazanie obrazovky */

	unsigned char  ucLocCount = 0;
    for (ucLocCount = 0; ucLocCount < MAX_ROWS; ucLocCount++) {
    	debugPrintln(&huart1,	&Hlavicka[ucLocCount][0]);	// print full line
    }
}
