/*
 * stm32f407xx.h
 *
 *  Created on: Jul 5, 2026
 *      Author: hailin
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h>

#define __vo volatile

/*
 * Base addresses of Flash and SRAM memories
 */

#define FLASH_BASEADDR         (0x08000000UL)
#define SRAM1_BASEADDR         (0x20000000UL)  //112KB
#define SRAM2_BASEADDR         (0x2001C000UL)  //
#define ROM_BASEADDR           (0x1FFF0000UL)
#define SRAM                   (SRAM1_BASEADDR)

/*
 * Base addresses of Bus domain: AHBx and APBx
 */
#define PERIPH_BASEADDR        (0x40000000UL)
#define APB1PERIPH_BASEADDR    (PERIPH_BASEADDR)
#define APB2PERIPH_BASEADDR    (0x40010000UL)
#define AHB1PERIPH_BASEADDR    (0x40020000UL)
#define AHB2PERIPH_BASEADDR    (0x50000000UL)

/*
 * Base addresses of peripherals hanging off AHB1 Bus
 */
#define GPIOA_BASEADDR         (AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR         (AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR         (AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR         (AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR         (AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR         (AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR         (AHB1PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR         (AHB1PERIPH_BASEADDR + 0x1C00)
#define GPIOI_BASEADDR         (AHB1PERIPH_BASEADDR + 0x2000)
#define RCC_BASEADDR           (AHB1PERIPH_BASEADDR + 0x3800)

/*
 * Base addresses of peripherals hanging off APB1 Bus
 */
#define I2C1_BASEADDR          (APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR          (APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR          (APB1PERIPH_BASEADDR + 0x5C00)

#define SPI2_BASEADDR          (APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR          (APB1PERIPH_BASEADDR + 0x3C00)

#define USART2_BASEADDR        (APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR        (APB1PERIPH_BASEADDR + 0x4800)
#define UART4_BASEADDR         (APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR         (APB2PERIPH_BASEADDR + 0x5000)

/*
 * Base addresses of peripherals hanging off APB2 Bus
 */
#define EXTI_BASEADDR          (APB2PERIPH_BASEADDR + 0x3C00)
#define SPI1_BASEADDR          (APB2PERIPH_BASEADDR + 0x3000)
#define SYSCFG_BASEADDR        (APB2PERIPH_BASEADDR + 0x3800)
#define USART1_BASEADDR        (APB2PERIPH_BASEADDR + 0x1000)
#define USART6_BASEADDR        (APB2PERIPH_BASEADDR + 0x1400)

/*******************************Peripheral Register Definition Structures**********************************/

/*
 * Peripheral register definition structure for GPIO
 */
typedef struct
{
	__vo uint32_t MODER;          //0x00
	__vo uint32_t OTYPER;         //0x04
	__vo uint32_t OSPEEDR;        //0x08
	__vo uint32_t PURDR;          //0x0C
	__vo uint32_t IDR;            //0x10
	__vo uint32_t ODR;            //0x14
	__vo uint32_t BSRR;           //0x18
	__vo uint32_t LCKR;           //0x1C
	__vo uint32_t AFR[2];         //0x20
//	__vo uint32_t AFRL;           //0x20
//	__vo uint32_t AFRH;           //0x24
}GPIO_RegDef_t;

typedef struct
{
	__vo uint32_t CR;             //0x00
	__vo uint32_t PLLCFGR;        //0x04
	__vo uint32_t CFGR;           //0x08
	__vo uint32_t CIR;            //0x0C
	__vo uint32_t AHB1RSTR;       //0x10
	__vo uint32_t AHB2RSTR;       //0x14
	__vo uint32_t AHB3RSTR;       //0x18
	__vo uint32_t RSVD1;          //0x1C
	__vo uint32_t APB1RSTR;       //0x20
	__vo uint32_t APB2RSTR;       //0x24
	__vo uint32_t RSVD2[2];       //0x28
	__vo uint32_t AHB1ENR;        //0x30
	__vo uint32_t AHB2ENR;        //0x34
	__vo uint32_t AHB3ENR;        //0x38
	__vo uint32_t RSVD3;          //0x3C
	__vo uint32_t APB1ENR;        //0x40
	__vo uint32_t APB2ENR;        //0x44
	__vo uint32_t RSVD4[2];       //0x48
	__vo uint32_t AHB1LPENR;      //0x50
	__vo uint32_t AHB2LPENR;      //0x54
	__vo uint32_t AHB3LPENR;      //0x58
	__vo uint32_t RSVD5;          //0x5C
	__vo uint32_t APB1LPENR;      //0x60
	__vo uint32_t APB2LPENR;      //0x64
	__vo uint32_t RSVD6[2];       //0x68
	__vo uint32_t BDCR;           //0x70
	__vo uint32_t CSR;            //0x74
	__vo uint32_t RSVD7[2];       //0x78
	__vo uint32_t SSCGR;          //0x80
	__vo uint32_t PLLI2SCFGR;     //0x84
	__vo uint32_t PLLSAICFGR;     //0x88
	__vo uint32_t DCKCFGR;        //0x8C

}RCC_RegDef_t;

/*
 * Peripheral definitions (Peripheral base addresses typecasted to xxx_RegDef_t)
 */

#define GPIOA                  ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB                  ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC                  ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD                  ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE                  ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF                  ((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG                  ((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH                  ((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define GPIOI                  ((GPIO_RegDef_t*)GPIOI_BASEADDR)

#define RCC                    ((RCC_RegDef_t*)RCC_BASEADDR)

/*
 * Clock Enable Macros for GPIOx peripherals
 */

#define GPIOA_PCLK_EN()  (RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()  (RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()  (RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()  (RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()  (RCC->AHB1ENR |= (1 << 4))
#define GPIOF_PCLK_EN()  (RCC->AHB1ENR |= (1 << 5))
#define GPIOG_PCLK_EN()  (RCC->AHB1ENR |= (1 << 6))
#define GPIOH_PCLK_EN()  (RCC->AHB1ENR |= (1 << 7))
#define GPIOI_PCLK_EN()  (RCC->AHB1ENR |= (1 << 8))


/*
 * Clock Enable Macros for I2Cx peripherals
 */

#define I2C1_PCLK_EN()  (RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN()  (RCC->APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN()  (RCC->APB1ENR |= (1 << 23))

/*
 * Clock Enable Macros for SPIx peripherals
 */

#define SPI1_PCLK_EN()  (RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN()  (RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN()  (RCC->APB1ENR |= (1 << 15))

/*
 * Clock Enable Macros for USARTx peripherals
 */

#define USART1_PCLK_EN()  (RCC->APB2ENR |= (1 << 4))
#define USART2_PCLK_EN()  (RCC->APB1ENR |= (1 << 17))
#define USART3_PCLK_EN()  (RCC->APB1ENR |= (1 << 18))
#define UART4_PCLK_EN()   (RCC->APB1ENR |= (1 << 19))
#define UART5_PCLK_EN()   (RCC->APB1ENR |= (1 << 20))
#define USART6_PCLK_EN()  (RCC->APB2ENR |= (1 << 5))

/*
 * Clock Enable Macros for SYSCFG peripheral
 */

#define SYSCFG_PCLK_EN()  (RCC->APB2ENR |= (1 << 14))

/*
 * Clock Disable Macros for GPIOx peripherals
 */

#define GPIOA_PCLK_DI()  (RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI()  (RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI()  (RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI()  (RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI()  (RCC->AHB1ENR &= ~(1 << 4))
#define GPIOF_PCLK_DI()  (RCC->AHB1ENR &= ~(1 << 5))
#define GPIOG_PCLK_DI()  (RCC->AHB1ENR &= ~(1 << 6))
#define GPIOH_PCLK_DI()  (RCC->AHB1ENR &= ~(1 << 7))
#define GPIOI_PCLK_DI()  (RCC->AHB1ENR &= ~(1 << 8))

/*
 * Clock Disable Macros for I2Cx peripherals
 */

#define I2C1_PCLK_DI()  (RCC->APB1ENR &= ~(1 << 21))
#define I2C2_PCLK_DI()  (RCC->APB1ENR &= ~(1 << 22))
#define I2C3_PCLK_DI()  (RCC->APB1ENR &= ~(1 << 23))

/*
 * Clock Disable Macros for SPIx peripherals
 */

#define SPI1_PCLK_DI()  (RCC->APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DI()  (RCC->APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DI()  (RCC->APB1ENR &= ~(1 << 15))

/*
 * Clock Disable Macros for USARTx peripherals
 */

#define USART1_PCLK_DI()  (RCC->APB2DIR &= ~(1 << 4))
#define USART2_PCLK_DI()  (RCC->APB1DIR &= ~(1 << 17))
#define USART3_PCLK_DI()  (RCC->APB1DIR &= ~(1 << 18))
#define UART4_PCLK_DI()   (RCC->APB1DIR &= ~(1 << 19))
#define UART5_PCLK_DI()   (RCC->APB1DIR &= ~(1 << 20))
#define USART6_PCLK_DI()  (RCC->APB2DIR &= ~(1 << 5))

/*
 * Clock Disable Macros for SYSCFG peripheral
 */

#define SYSCFG_PCLK_DI()  (RCC->APB2ENR &= ~(1 << 14))

/*
 * Macros to reset GPIOx peripherals
 */
#define GPIOA_REG_RESET()  do{ (RCC->AHB1RSTR |= (1<<0)); (RCC->AHB1RSTR &= ~(1<<0)); }while(0)
#define GPIOB_REG_RESET()  do{ (RCC->AHB1RSTR |= (1<<1)); (RCC->AHB1RSTR &= ~(1<<1)); }while(0)
#define GPIOC_REG_RESET()  do{ (RCC->AHB1RSTR |= (1<<2)); (RCC->AHB1RSTR &= ~(1<<2)); }while(0)
#define GPIOD_REG_RESET()  do{ (RCC->AHB1RSTR |= (1<<3)); (RCC->AHB1RSTR &= ~(1<<3)); }while(0)
#define GPIOE_REG_RESET()  do{ (RCC->AHB1RSTR |= (1<<4)); (RCC->AHB1RSTR &= ~(1<<4)); }while(0)
#define GPIOF_REG_RESET()  do{ (RCC->AHB1RSTR |= (1<<5)); (RCC->AHB1RSTR &= ~(1<<5)); }while(0)
#define GPIOG_REG_RESET()  do{ (RCC->AHB1RSTR |= (1<<6)); (RCC->AHB1RSTR &= ~(1<<6)); }while(0)
#define GPIOH_REG_RESET()  do{ (RCC->AHB1RSTR |= (1<<7)); (RCC->AHB1RSTR &= ~(1<<7)); }while(0)
#define GPIOI_REG_RESET()  do{ (RCC->AHB1RSTR |= (1<<8)); (RCC->AHB1RSTR &= ~(1<<8)); }while(0)

// Generic Macros
#define SET            (1)
#define RESET          (0)

typedef enum
{
	DISABLE,  //0
	ENABLE    //1
}State;

//GPIO_RegDef_t *pGPIOA = GPIOA;

#include "stm32f407xx_gpio_driver.h"

#endif /* INC_STM32F407XX_H_ */
