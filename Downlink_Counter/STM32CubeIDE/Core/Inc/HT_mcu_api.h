
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
 * \file HT_mcu_api.h
 * \brief HT api made for downlink counter app.
 * \author HT Micron Advanced R&D
 * \link support_iot@htmicron.com.br
 * \version 2.2
 * \date September 15, 2020
 *
 * This file defines a couple of control variables for downlink counter application (receive GFSK test).
 */

#ifndef _HT_MCU_API_H_
#define _HT_MCU_API_H_

extern uint32_t HT_API_getDownlinkCounter(void);
extern void HT_API_setDownlinkCounter(uint32_t value);
extern uint32_t HT_API_getDownlinkFailed(void);
extern uint32_t HT_API_getInd(void);
extern uint32_t HT_API_getDownlinkFailed(void);

extern void HT_API_setDownlinkFailed(uint32_t value);
extern void HT_API_setInd(uint32_t value);

#endif /* _HT_MCU_API_H_ */
