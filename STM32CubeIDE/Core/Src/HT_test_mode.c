/**
 *
 * Copyright (c) 2020 HT Micron Semicondutors S.A.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include "HT_test_mode.h"

/* Available commands */
char rxBuffer[MAX_UART_BUFF_SIZE];
static char node_downlink_counter[] = {"node_downlink_counter"};
static char node_send_test_frame[] = {"node_send_test_frame"};
static char node_config_rcz[] = {"node_config_rcz"};
static char node_switch_pa[] = {"node_switch_pa"};
static char node_reduce_output_power[] = {"node_reduce_output_power"};
static char node_close[] = {"node_close"};
static char node_switch_boost[] = {"node_switch_boost"};

/* Main routine */
void HT_test_mode(void) {
	while (1) {
		memset(rxBuffer,0,sizeof(rxBuffer));

		HAL_UART_Receive(&huart1, (uint8_t *)rxBuffer, sizeof(rxBuffer), 100);

		if(!(strncmp(node_downlink_counter, rxBuffer, strlen(node_downlink_counter)))) {
			HT_API_downlinkCounter(rxBuffer);
		} else if(!(strncmp(node_send_test_frame, rxBuffer, strlen(node_send_test_frame)))) {
			HT_SigfoxApi_sendTestFrame(rxBuffer);
		} else if(!(strncmp(node_config_rcz, rxBuffer, strlen(node_config_rcz)))) {
			HT_SigfoxApi_configRegion(rxBuffer);
		} else if(!(strncmp(node_switch_pa, rxBuffer, strlen(node_switch_pa)))) {
			HT_SigfoxApi_switchPaAction(rxBuffer);
		} else if(!(strncmp(node_reduce_output_power, rxBuffer, strlen(node_reduce_output_power)))) {
			HT_SigfoxApi_reduceOutputPower(rxBuffer);
		} else if(!(strncmp(node_close, rxBuffer, strlen(node_close)))) {
			HT_SigfoxApi_close();
		} else if(!(strncmp(node_switch_boost, rxBuffer, strlen(node_switch_boost)))) {
			HT_SigfoxApi_switchBoost(rxBuffer);
		}
	}
}

/************************ HT Micron Semicondutors S.A *****END OF FILE****/
