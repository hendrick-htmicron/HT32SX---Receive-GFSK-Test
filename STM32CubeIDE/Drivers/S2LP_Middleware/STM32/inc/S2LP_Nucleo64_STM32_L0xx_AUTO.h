/**
* @file    S2LP_Nucleo64_STM32_L0xx_AUTO.h
* @author  AMS RF application team
* @version V1.0.0
* @date    December, 2018
* @brief   This file contains definitions for S2LP Shields + Nucleo64 Eval Platforms
*
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
* TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
* DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
* FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
* CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*
* THIS SOURCE CODE IS PROTECTED BY A LICENSE.
* FOR MORE INFORMATION PLEASE CAREFULLY READ THE LICENSE AGREEMENT FILE LOCATED
* IN THE ROOT DIRECTORY OF THIS FIRMWARE PACKAGE.
*
* <h2><center>&copy; COPYRIGHT 2018 STMicroelectronics</center></h2>
*/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __S2LP_NUCLEO64_STM32_L0XX_AUTO_H
#define __S2LP_NUCLEO64_STM32_L0XX_AUTO_H

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************/
/*                            GENERAL CONFIG                                 */
/*****************************************************************************/

/** @brief Definition for XTAL speed (only relevant if EEPROM_PRESENT=EEPROM_NO)
  * XTAL frequency is expressed in Hertz */
#define XTAL_FREQUENCY                          50000000

#define EEPROM_YES					1
#define EEPROM_NO					0

/** XTAL frequency offset compensation value in Hertz
  * Please, take into account that if nominal frequency is 50 MHz and
  * measured XTAL frequency is (for example) 50000157, then XTAL_FREQUENCY_OFFSET must be
  * set to -157, If not avaialble set it to 0 */
#define XTAL_FREQUENCY_OFFSET                   0

/* This is getting the base frequency from the band defined in the board.
 * For user board, define the desired frequency in Hz (e.g: 868000000) */
#define BOARD_BASE_FREQUENCY                    (S2LPGetFrequencyBand())
#define BOARD_FREQUENCY_BAND                    2 /* 915MHz */ //JRF 3 /* 868MHz */

/**
* @brief Definitions for EEPROM
*/
#define EEPROM_PRESENT                          EEPROM_NO //JRFEEPROM_YES

/**
* @brief Definitions for PA
*/
#define S2LP_FEM_YES                            0
#define S2LP_FEM_NO                             1
#define S2LP_FEM_AUTO                           2
#define S2LP_FEM_PRESENT                        S2LP_FEM_AUTO

/**
* @brief Definitions for TCXO
*/
#define TCXO_YES                                0
#define TCXO_NO                                 1
#define TCXO_AUTO                               2
#define TCXO_PRESENT                            TCXO_AUTO
/* Pin C7 for TCXO Enable pin */
#define TCXO_EN_PIN                             GPIO_PIN_7

/*****************************************************************************/
/*                            S2-LP - SPI CONFIG                             */
/*****************************************************************************/

/**
* @brief SPI definitions
* and connections to S2-LP and EEPROM
*/
#define S2LP_SPI_PRESCALER                      SPI_BAUDRATEPRESCALER_2

#define S2LP_SPI_PERIPH_NB                      SPI1
#define S2LP_SPI_PERIPH_CLK_ENABLE()            __SPI1_CLK_ENABLE()
#define S2LP_SPI_PERIPH_CLK_DISABLE()           __SPI1_CLK_DISABLE()

/* Defines for chip select pin */
#define S2LP_SPI_CS_PORT                        GPIOA
#define S2LP_SPI_CS_PIN                         GPIO_PIN_15//JRF GPIO_PIN_1
#define S2LP_SPI_CS_CLK_ENABLE()                __GPIOA_CLK_ENABLE()
#define S2LP_SPI_CS_CLK_DISABLE()               __GPIOA_CLK_DISABLE()

/* Defines for MOSI pin*/
#define S2LP_SPI_MOSI_PORT                      GPIOA
#define S2LP_SPI_MOSI_PIN                       GPIO_PIN_7
#define S2LP_SPI_MOSI_AF                        GPIO_AF0_SPI1
#define S2LP_SPI_MOSI_CLK_ENABLE()              __GPIOA_CLK_ENABLE()
#define S2LP_SPI_MOSI_CLK_DISABLE()             __GPIOA_CLK_DISABLE()

/* Defines for MISO pin */
#define S2LP_SPI_MISO_PORT                      GPIOB//JRF GPIOA
#define S2LP_SPI_MISO_PIN                       GPIO_PIN_4//JRF GPIO_PIN_6
#define S2LP_SPI_MISO_AF                        GPIO_AF0_SPI1
#define S2LP_SPI_MISO_CLK_ENABLE()              __GPIOB_CLK_ENABLE() //JRF __GPIOA_CLK_ENABLE()
#define S2LP_SPI_MISO_CLK_DISABLE()             __GPIOB_CLK_DISABLE() //JRF __GPIOA_CLK_DISABLE()

/* Defines for SCLK pin */
#define S2LP_SPI_SCLK_PORT                      GPIOB
#define S2LP_SPI_SCLK_PIN                       GPIO_PIN_3
#define S2LP_SPI_SCLK_AF                        GPIO_AF0_SPI1
#define S2LP_SPI_SCLK_CLK_ENABLE()              __GPIOB_CLK_ENABLE()
#define S2LP_SPI_SCLK_CLK_DISABLE()             __GPIOB_CLK_DISABLE()

/* SPI DMA configuration*/
#define S2LP_SPI_DMA_CLK_ENABLE()               __DMA1_CLK_ENABLE()
#define S2LP_SPI_TX_DMA_CHANNEL                 DMA1_Channel3
#define S2LP_SPI_RX_DMA_CHANNEL                 DMA1_Channel2
#define S2LP_SPI_DMA_TX_IRQn                    DMA1_Channel2_3_IRQn
#define S2LP_SPI_DMA_RX_IRQn                    DMA1_Channel2_3_IRQn
#define S2LP_SPI_RX_DMA_REQUEST                 DMA_REQUEST_1
#define S2LP_SPI_TX_DMA_REQUEST                 DMA_REQUEST_1

/*****************************************************************************/
/*                            S2-LP - EEPROM                                 */
/*****************************************************************************/

/** The EEPROM is an optional component, normally not required in customer's application.
 *  When using a custom board, normally this define should be set to EEPROM_NO.
 *  Since STEVAL kits use EEPROM, set it to EEPROM_YES  */
#define EEPROM_SPI_PERIPH_RCC                   __SPI1_CLK_ENABLE
#define EEPROM_SPI_PERIPH_NB                    SPI1

/* Defines for chip select pin for FKI boards */
#define EEPROM_SPI_CS_PORT                      GPIOA
#define EEPROM_SPI_CS_PIN                       GPIO_PIN_9
#define EEPROM_SPI_CS_RCC                       __GPIOA_CLK_ENABLE

/* Defines for chip select pin on XNUCLEO-S2868A1 */
#define EEPROM_SPI_XNUCLEO_CS_PORT              GPIOB
#define EEPROM_SPI_XNUCLEO_CS_PIN               GPIO_PIN_4
#define EEPROM_SPI_XNUCLEO_CS_RCC               __GPIOB_CLK_ENABLE

/* Defines for MOSI pin */
#define EEPROM_SPI_MOSI_PORT                    GPIOA
#define EEPROM_SPI_MOSI_PIN                     GPIO_PIN_7
#define EEPROM_SPI_MOSI_AF                      GPIO_AF0_SPI1
#define EEPROM_SPI_MOSI_RCC                     __GPIOA_CLK_ENABLE

/* Defines for MISO pin */
#define EEPROM_SPI_MISO_PORT                    GPIOA
#define EEPROM_SPI_MISO_PIN                     GPIO_PIN_6
#define EEPROM_SPI_MISO_AF                      GPIO_AF0_SPI1
#define EEPROM_SPI_MISO_RCC                     __GPIOA_CLK_ENABLE

/* Defines for SCLK pin */
#define EEPROM_SPI_CLK_PORT                     GPIOB
#define EEPROM_SPI_CLK_PIN                      GPIO_PIN_3
#define EEPROM_SPI_CLK_AF                       GPIO_AF0_SPI1
#define EEPROM_SPI_CLK_RCC                      __GPIOB_CLK_ENABLE

/*****************************************************************************/
/*                            S2-LP - GPIOs                                  */
/*****************************************************************************/

/* SDN */
#define S2LP_M2S_SDN_PORT                       GPIOB// JRF GPIOA
#define S2LP_M2S_SDN_PIN                        GPIO_PIN_8
#define S2LP_M2S_SDN_PUPD                       GPIO_NOPULL
#define S2LP_M2S_SDN_MODE                       GPIO_MODE_OUTPUT_PP
#define S2LP_M2S_SDN_SPEED                      GPIO_SPEED_HIGH
#define S2LP_M2S_SDN_CLOCK()                    __GPIOB_CLK_ENABLE() //JRF __GPIOA_CLK_ENABLE()

/**
* @brief Definitions for S2-LP IRQ line
*/

/* S2LP GPIO 3 - IRQ Pin */
//#define M2S_GPIO_IRQ_PORT                       GPIOA//JRF GPIOC
//#define M2S_GPIO_IRQ_CLOCK()                    __GPIOA_CLK_ENABLE() //JRF __GPIOC_CLK_ENABLE()
//#define M2S_GPIO_IRQ_PIN                        GPIO_PIN_0
//#define M2S_GPIO_EXTI_IRQN                      EXTI0_1_IRQn
//#define M2S_GPIO_IRQ_SPEED                      GPIO_SPEED_HIGH
//#define M2S_GPIO_IRQ_PUPD                       GPIO_NOPULL
//#define M2S_GPIO_IRQ_MODE                       GPIO_MODE_INPUT
//#define M2S_GPIO_IRQ_EXTI_MODE                  GPIO_MODE_IT_FALLING
//#define M2S_GPIO_EDGE_EVENT                     0 /* 0 means falling edge, 1 raising */

/* S2LP GPIO 0 */
//JRF
//#define M2S_GPIO_0_PORT_NUCLEO                  GPIOA
//#define M2S_GPIO_0_CLOCK_NUCLEO()               __GPIOA_CLK_ENABLE()
//#define M2S_GPIO_0_PIN                         	GPIO_PIN_0
//#define M2S_GPIO_0_SPEED                       	GPIO_SPEED_HIGH
//#define M2S_GPIO_0_PUPD                        	GPIO_NOPULL
//#define M2S_GPIO_0_MODE                        	GPIO_MODE_INPUT
//#define M2S_GPIO_0_EXTI_MODE                   	GPIO_MODE_IT_FALLING
//#define M2S_GPIO_0_EXTI_IRQN                   	EXTI0_1_IRQn
//#define M2S_GPIO_0_EXTI_PREEMPTION_PRIORITY    	2
//#define M2S_GPIO_0_EXTI_SUB_PRIORITY           	2
//#define M2S_GPIO_0_EXTI_IRQ_HANDLER            	EXTI0_1_IRQHandler

/* S2LP GPIO 1 */
//JRF  
//#define M2S_GPIO_1_PORT_NUCLEO                 	GPIOA
//#define M2S_GPIO_1_CLOCK_NUCLEO()              	__GPIOA_CLK_ENABLE()
//#define M2S_GPIO_1_PIN                         	GPIO_PIN_4
//#define M2S_GPIO_1_SPEED                       	GPIO_SPEED_HIGH
//#define M2S_GPIO_1_PUPD                        	GPIO_NOPULL
//#define M2S_GPIO_1_MODE                       	GPIO_MODE_INPUT
//#define M2S_GPIO_1_EXTI_MODE                   	GPIO_MODE_IT_FALLING
//#define M2S_GPIO_1_EXTI_IRQN                   	EXTI4_15_IRQn
//#define M2S_GPIO_1_EXTI_PREEMPTION_PRIORITY    	2
//#define M2S_GPIO_1_EXTI_SUB_PRIORITY           	2
//#define M2S_GPIO_1_EXTI_IRQ_HANDLER            	EXTI4_15_IRQHandler

/* S2LP GPIO 2 */
//JRF
//#define M2S_GPIO_2_PORT_NUCLEO                  GPIOB
//#define M2S_GPIO_2_CLOCK_NUCLEO()               __GPIOB_CLK_ENABLE()
//#define M2S_GPIO_2_PIN                         	GPIO_PIN_0
//#define M2S_GPIO_2_SPEED                       	GPIO_SPEED_HIGH
//#define M2S_GPIO_2_PUPD                        	GPIO_NOPULL
//#define M2S_GPIO_2_MODE                        	GPIO_MODE_INPUT
//#define M2S_GPIO_2_EXTI_MODE                   	GPIO_MODE_IT_FALLING
//#define M2S_GPIO_2_EXTI_IRQN                   	EXTI0_1_IRQn
//#define M2S_GPIO_2_EXTI_PREEMPTION_PRIORITY    	2
//#define M2S_GPIO_2_EXTI_SUB_PRIORITY           	2
//#define M2S_GPIO_2_EXTI_IRQ_HANDLER            	EXTI0_1_IRQHandler

#ifdef __cplusplus
}
#endif

#endif /* __S2LP_NUCLEO64_STM32_L0XX_AUTO_H */

/******************* (C) COPYRIGHT 2018 STMicroelectronics *****END OF FILE*****/
