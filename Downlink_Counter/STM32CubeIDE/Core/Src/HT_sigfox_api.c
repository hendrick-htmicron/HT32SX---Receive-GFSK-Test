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

#include "HT_sigfox_api.h"
#include "retriever_api.h"

uint32_t rx_counter = 0;
uint32_t err_counter = 0;

static sfx_u8 rx_gfsk_pattern[15] =  { 0x1F, 0x20, 0x41, 0x84, 0x32, 0x68, 0xC5, 0xBA, 0x53, 0xAE, 0x79, 0xE7, 0xF6, 0xDD, 0x9B  };

void HT_SigfoxApi_receiveGFSK(sfx_s32 frequency, sfx_u8 timeout) {
	sfx_s16 rssi = 0;
	sfx_u8 frame_buffer[15];

	enc_utils_set_test_id(1);
	enc_utils_set_test_key(1);

	for(int i = 0; i < DOWNLINK_MAX_FRAME_LENGTH; i++) {
		/* AA AA B2 27 1F 20 41 84 32 68 C5 BA 53 AE 79 E7 F6 DD 9B */
		frame_buffer[i] = rx_gfsk_pattern[i];
	}

	SIGFOX_API_receive_test_frame(frequency, AUTHENTICATION_OFF, frame_buffer, timeout, &rssi);

}

void HT_API_downlinkCounter(char *tmp) {
	int32_t cmd[2];

	printf("Running test...\n");

	HT_SigfoxApi_getParameters(tmp, cmd);

	HAL_Delay(500);

	for(int i = 0; i < MAX_N_FRAMES; ) {
		HT_SigfoxApi_receiveGFSK((sfx_s32) cmd[0], (sfx_u8)cmd[1]);
		rx_counter = HT_API_getDownlinkCounter();
		err_counter = HT_API_getDownlinkFailed();
		i = HT_API_getInd();
		printf("Ind: %d\n", i);
	}

	printf("\nTest finished.\n");
	printf("\nDownlink received: %ld\n", rx_counter);
	printf("Number of errors occurred: %ld\n", err_counter);

	HT_API_setDownlinkFailed(0);
	HT_API_setDownlinkCounter(0);
	HT_API_setInd(0);
}

void HT_SigfoxApi_sendTestFrame(char *tmp) {
	sfx_error_t err = 0;
	sfx_u8 customer_data[12] = {0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA};
	int32_t cmd[2];

	HT_SigfoxApi_getParameters(tmp, cmd);

	for(int i = 0;i < 3;i++) {
		err = SIGFOX_API_send_test_frame((sfx_s32) cmd[0], customer_data, sizeof((uint8_t *)customer_data), SFX_FALSE);
		HAL_Delay(1000);
	}

	printf("Send_test_frame error: %X\n", err);
}

void HT_SigfoxApi_setSmpsVoltageAction(sfx_u8 mode) {
	ST_RF_API_smps(mode);
	printf("Set_smps_voltage %d\n", mode);
}

void HT_SigfoxApi_switchPa(uint8_t state) {

	ST_RF_API_set_pa(state);

	printf("Switch PA: %d\n", state);
}

void HT_SigfoxApi_reduceOutputPower(char *tmp) {
	int32_t cmd[2];

	HT_SigfoxApi_getParameters(tmp, cmd);

	ST_RF_API_reduce_output_power((int16_t)cmd[0]);

	printf("Reduce output power: %d\n", (int)cmd[0]);
}

void HT_SigfoxApi_switchBoost(char *tmp) {
	int32_t cmd[2];

	HT_SigfoxApi_getParameters(tmp, cmd);

	if(cmd[0])
		HT_SigfoxApi_setSmpsVoltageAction(7);
	else
		HT_SigfoxApi_setSmpsVoltageAction(2);

	printf("Node switch boost mode: %ld\n", cmd[0]);
}

void HT_SigfoxApi_close(void) {
	sfx_error_t err;

	err = SIGFOX_API_close();
	printf("Node close error: 0x%X\n", err);
}

void HT_SigfoxApi_switchPaAction(char *tmp) {
	int32_t cmd[2];

	HT_SigfoxApi_getParameters(tmp, cmd);

	HT_SigfoxApi_switchPa((uint8_t)cmd[0]);
}

void HT_SigfoxApi_configRegion(char *tmp) {
	ST_SFX_ERR open_err = ST_SFX_ERR_NONE;
	rc_mask RCZ;
	int32_t cmd[2];

	HT_SigfoxApi_getParameters(tmp, cmd);

	RCZ = cmd[0];

	switch(RCZ){
	case RCZ1:
		ST_RF_API_reduce_output_power(RCZ1_OUTPUT_POWER);
		open_err = St_Sigfox_Open_RCZ(RCZ1);
		HT_SigfoxApi_switchPa(0);
		HT_SigfoxApi_setSmpsVoltageAction(7);

		if(open_err != 0)
			printf("Open rcz error: %X\n", open_err);

		break;
	case RCZ2:
		ST_RF_API_reduce_output_power(RCZ2_OUTPUT_POWER);
		open_err = St_Sigfox_Open_RCZ(RCZ2);
		HT_SigfoxApi_switchPa(1);

		if(open_err != 0)
			printf("Open rcz error: %X\n", open_err);

		break;
	case RCZ3:
		open_err = St_Sigfox_Open_RCZ(RCZ3);
		ST_RF_API_reduce_output_power(RCZ3_OUTPUT_POWER);
		HT_SigfoxApi_switchPa(0);
		HT_SigfoxApi_setSmpsVoltageAction(7);

		if(open_err != 0)
			printf("Open rcz error: %X\n", open_err);

		break;
	case RCZ4:
		open_err = St_Sigfox_Open_RCZ(RCZ4);
		ST_RF_API_reduce_output_power(RCZ4_OUTPUT_POWER);
		HT_SigfoxApi_switchPa(1);

		if(open_err != 0)
			printf("Open rcz error: %X\n", open_err);

		break;
	case RCZ5:
		open_err = St_Sigfox_Open_RCZ(RCZ5);
		ST_RF_API_reduce_output_power(RCZ5_OUTPUT_POWER);
		HT_SigfoxApi_switchPa(0);
		HT_SigfoxApi_setSmpsVoltageAction(7);

		if(open_err != 0)
			printf("Open rcz error: %X\n", open_err);

		break;
	case RCZ6:
		open_err = St_Sigfox_Open_RCZ(RCZ6);
		ST_RF_API_reduce_output_power(RCZ6_OUTPUT_POWER);
		HT_SigfoxApi_switchPa(0);
		HT_SigfoxApi_setSmpsVoltageAction(7);

		if(open_err != 0)
			printf("Open rcz error: %X\n", open_err);

		break;
	case RCZ7:
		open_err = St_Sigfox_Open_RCZ(RCZ7);
		ST_RF_API_reduce_output_power(RCZ7_OUTPUT_POWER);
		HT_SigfoxApi_switchPa(0);
		HT_SigfoxApi_setSmpsVoltageAction(7);

		if(open_err != 0)
			printf("Open rcz error: %X\n", open_err);

		break;
	default:
		break;
	}

}

void HT_SigfoxApi_getParameters(char *tmp, int32_t *cmd) {
	uint8_t i = 0;
	char *token;

	token = strtok(tmp, " \n");

	while( token != NULL ) {
		token = strtok(NULL, " \n");

		cmd[i] = atoi(token);
		i++;
	}
}

/************************ HT Micron Semicondutors S.A *****END OF FILE****/
