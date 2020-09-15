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
 * \file HT_sigfox_api.h
 * \brief Sigfox API with test functions
 * \author HT Micron Advanced R&D
 * \link support_iot@htmicron.com.br
 * \version 2.2
 * \date September 04, 2020
 *
 * This file defines some test routines for HT32SX.
 */

#ifndef _HT_SIGFOX_API_H_
#define _HT_SIGFOX_API_H_

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "HT_mcu_api.h"

#define DOWNLINK_MAX_FRAME_LENGTH 15
#define RX_SENSI_DATA_LENGTH 8
#define SENSI_COMMAND_FIELD_INDEX    	(sfx_u8)(7)

/* Functions ------------------------------------------------------------------*/

void HT_SigfoxApi_receiveGFSK(sfx_s32 frequency, sfx_u8 timeout);

/*!******************************************************************
 * \fn void HT_API_setSmpsVoltageAction(sfx_u8 mode)
 * \brief Enable S2LP boost mode.
 *
 * \param[in]  sfx_u8 mode                  Desired output voltage. Check UM2169 for more details.
 * \param[out] none
 *******************************************************************/
void HT_SigfoxApi_setSmpsVoltageAction(sfx_u8 mode);

/*!******************************************************************
 * \fn void HT_SigfoxApi_getParameters(char *tmp, int32_t *cmd)
 * \brief Get command parameters and convert to int32.
 *
 * \param[in]  cmd 	*tmp                  ASCII command.
 * \param[out] int32_t *cmd				 Parameter converted to int32.
 *******************************************************************/
void HT_SigfoxApi_getParameters(char *tmp, int32_t *cmd);

/*!******************************************************************
 * \fn void HT_API_downlinkCounter(char *tmp)
 * \brief Command processing to start downlink counter test (receive GFSK test).
 *
 * \param[in]  cmd 	*tmp                  Pointer containing all parameter to run receive GFSK test (downlink frequency and timeout).
 * \param[out] none
 *******************************************************************/
void HT_API_downlinkCounter(char *tmp);

/*!******************************************************************
 * \fn void HT_SigfoxApi_sendTestFrame(char *tmp)
 * \brief Command processing to a test frame (used in this context to configured Static Drift in SDR Dongle side).
 *
 * \param[in]  cmd 	*tmp                  Pointer containing the frequency uplink frequency.
 * \param[out] none
 *******************************************************************/
void HT_SigfoxApi_sendTestFrame(char *tmp);

/*!******************************************************************
 * \fn void HT_SigfoxApi_configRegion(char *tmp)
 * \brief Command processing to configures the device with the region specified by the user.
 *
 * \param[in]  cmd 	*tmp                  Pointer containing the RC to be configured.
 * \param[out] none
 *******************************************************************/
void HT_SigfoxApi_configRegion(char *tmp);

/*!******************************************************************
 * \fn void HT_SigfoxApi_switchBoost(char *tmp)
 * \brief Command processing to enable S2LP boost mode.
 *
 * \param[in]  cmd *tmp                 Pointer containing the flag which will turn on or turn off S2LP boost mode (1 on / 0 off).
 * \param[out] none
 *******************************************************************/
void HT_SigfoxApi_switchBoost(char *tmp);

/*!******************************************************************
 * \fn HT_SigfoxApi_switchPaAction(char *tmp)
 * \brief Command processing to Enable PA.
 *
 * \param[in]  cmd *tmp                 Pointer containing the flag which will turn on or turn off PA (1 on / 0 off).
 * \param[out] none
 *******************************************************************/
void HT_SigfoxApi_switchPaAction(char *tmp);

/*!******************************************************************
 * \fn void HT_SigfoxApi_reduceOutputPower(char *tmp)
 * \brief Command processing to set a new reduce output power value.
 *
 * \param[in]  cmd *tmp                 Pointer with the specific output power value.
 * \param[out] none
 *******************************************************************/
void HT_SigfoxApi_reduceOutputPower(char *tmp);

/*!******************************************************************
 * \fn void HT_SigfoxApi_close(void)
 * \brief Command processing to closes the library (Free the allocated memory of SIGFOX_API_open and close RF).
 *
 * \param[in]  none
 * \param[out] none
 *******************************************************************/
void HT_SigfoxApi_close(void);

#endif
