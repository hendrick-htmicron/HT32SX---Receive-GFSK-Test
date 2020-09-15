/*

  _    _ _______   __  __ _____ _____ _____   ____  _   _
 | |  | |__   __| |  \/  |_   _/ ____|  __ \ / __ \| \ | |
 | |__| |  | |    | \  / | | || |    | |__) | |  | |  \| |
 |  __  |  | |    | |\/| | | || |    |  _  /| |  | | . ` |
 | |  | |  | |    | |  | |_| || |____| | \ \| |__| | |\  |
 |_|  |_|  |_|    |_|  |_|_____\_____|_|  \_\\____/|_| \_|
 =================== Advanced R&D ========================

*/

/*!
 * \file HT_test_mode.h
 * \brief Sigfox API with test functions
 * \author HT Micron Advanced R&D
 * \link support_iot@htmicron.com.br
 * \version 2.2
 * \date September 06, 2020
 *
 * This file defines some test routines for HT32SX.
 */

#ifndef _HT_TEST_MODE_H_
#define _HT_TEST_MODE_H_

#include "main.h"
#include "usart.h"
#include "HT_sigfox_api.h"

#define MAX_UART_BUFF_SIZE 50

/*!******************************************************************
 * \fn void HT_test_mode(void)
 * \brief Main routine for GFSK Receive Test.
 *
 * \param[in]  node
 * \param[out] none
 *******************************************************************/
void HT_test_mode(void);

#endif /* _HT_TEST_MODE_H_ */
