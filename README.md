# HT32SX---Receive-GFSK-Test

Firmware developed to implement Receive GFSK Test (Downlink counter). 

## Available Commands

| Name | Arguments | Descripton | 
| --- | --- | --- |
| **node_send_test_frame** | **Frequency:**  Uplink frequency.<br/> | Send a test frame to the specified frequency. **It must be used only after a node_config_rcz command**. Error 0 means success.<br/> Example (RC6 uplink frequency):<br/> **node_send_test_frame 865200000**|
| **node_downlink_counter** | **Frequency:**  Downlink frequency.<br/> **Timeout:**Timeout to wait for a downlink. | Starts the GFSK receive test mode. It will wait for 1000 frames and return RSSI, number of downlink received and number of errors. <br/>Example (RC6 downlink frequency):<br/>**node_downlink_counter 866300000 2**|
| **node_config_rcz** | **RCZ:** Integer corresponding to the radio zone. | Opens SigFox Library according to the zone. Returns 0 if ok.<br/>Example (configuring to RC6):<br/>node_config_rcz 6 |
| **node_switch_pa** | **Pa_flag:** 1 to turn on PA and 0 to turn off. | Turn on or turn off PA. <br/>Example (turning on):<br/> **node_switch_pa 1**|
| **node_switch_boost** | **Boost_flag:** 1 to turn on S2LP boost mode and 0 to turn off. | Turn on or turn off S2LP boost mode.<br/>Example (turning off):<br/>**node_switch_boost 0** |
| **node_reduce_output_power** | **Ouput_power:** New output power value. | Set a new output power.<br/> Example:<br/>**node_reduce_output_power -20** |
| **node_close** | None | Closes the library (Free the allocated memory of SIGFOX_API_open and close RF).<br/>Example:<br/>**node_close** |