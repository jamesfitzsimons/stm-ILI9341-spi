#include "config.h"
#include <stm32f10x.h>
#include <stm32f10x_spi.h>
#include "delay.h"

#include "../USART_lib/usart.h"

#ifndef TEST1_ILI9341_CORE_H
#define TEST1_ILI9341_CORE_H

//<editor-fold desc="Display commands">
/* Level 1 Commands */
#define LCD_SWRESET             0x01   /* Software Reset */
#define LCD_READ_DISPLAY_ID     0x04   /* Read display identification information */
#define LCD_RDDST               0x09   /* Read Display Status */
#define LCD_RDDPM               0x0A   /* Read Display Power Mode */
#define LCD_RDDMADCTL           0x0B   /* Read Display MADCTL */
#define LCD_RDDCOLMOD           0x0C   /* Read Display Pixel Format */
#define LCD_RDDIM               0x0D   /* Read Display Image Format */
#define LCD_RDDSM               0x0E   /* Read Display Signal Mode */
#define LCD_RDDSDR              0x0F   /* Read Display Self-Diagnostic Result */
#define LCD_SPLIN               0x10   /* Enter Sleep Mode */
#define LCD_SLEEP_OUT           0x11   /* Sleep out register */
#define LCD_PTLON               0x12   /* Partial Mode ON */
#define LCD_NORMAL_MODE_ON      0x13   /* Normal Display Mode ON */
#define LCD_DINVOFF             0x20   /* Display Inversion OFF */
#define LCD_DINVON              0x21   /* Display Inversion ON */
#define LCD_GAMMA               0x26   /* Gamma register */
#define LCD_DISPLAY_OFF         0x28   /* Display off register */
#define LCD_DISPLAY_ON          0x29   /* Display on register */
#define LCD_COLUMN_ADDR         0x2A   /* Colomn address register */
#define LCD_PAGE_ADDR           0x2B   /* Page address register */
#define LCD_GRAM                0x2C   /* GRAM register */
#define LCD_RGBSET              0x2D   /* Color SET */
#define LCD_RAMRD               0x2E   /* Memory Read */
#define LCD_PLTAR               0x30   /* Partial Area */
#define LCD_VSCRDEF             0x33   /* Vertical Scrolling Definition */
#define LCD_TEOFF               0x34   /* Tearing Effect Line OFF */
#define LCD_TEON                0x35   /* Tearing Effect Line ON */
#define LCD_MAC                 0x36   /* Memory Access Control register*/
#define LCD_VSCRSADD            0x37   /* Vertical Scrolling Start Address */
#define LCD_IDMOFF              0x38   /* Idle Mode OFF */
#define LCD_IDMON               0x39   /* Idle Mode ON */
#define LCD_PIXEL_FORMAT        0x3A   /* Pixel Format register */
#define LCD_WRITE_MEM_CONTINUE  0x3C   /* Write Memory Continue */
#define LCD_READ_MEM_CONTINUE   0x3E   /* Read Memory Continue */
#define LCD_SET_TEAR_SCANLINE   0x44   /* Set Tear Scanline */
#define LCD_GET_SCANLINE        0x45   /* Get Scanline */
#define LCD_WDB                 0x51   /* Write Brightness Display register */
#define LCD_RDDISBV             0x52   /* Read Display Brightness */
#define LCD_WCD                 0x53   /* Write Control Display register*/
#define LCD_RDCTRLD             0x54   /* Read CTRL Display */
#define LCD_WRCABC              0x55   /* Write Content Adaptive Brightness Control */
#define LCD_RDCABC              0x56   /* Read Content Adaptive Brightness Control */
#define LCD_WRITE_CABC          0x5E   /* Write CABC Minimum Brightness */
#define LCD_READ_CABC           0x5F   /* Read CABC Minimum Brightness */
#define LCD_READ_ID1            0xDA   /* Read ID1 */
#define LCD_READ_ID2            0xDB   /* Read ID2 */
#define LCD_READ_ID3            0xDC   /* Read ID3 */

/* Level 2 Commands */
#define LCD_RGB_INTERFACE       0xB0   /* RGB Interface Signal Control */
#define LCD_FRMCTR1             0xB1   /* Frame Rate Control (In Normal Mode) */
#define LCD_FRMCTR2             0xB2   /* Frame Rate Control (In Idle Mode) */
#define LCD_FRMCTR3             0xB3   /* Frame Rate Control (In Partial Mode) */
#define LCD_INVTR               0xB4   /* Display Inversion Control */
#define LCD_BPC                 0xB5   /* Blanking Porch Control register */
#define LCD_DFC                 0xB6   /* Display Function Control register */
#define LCD_ETMOD               0xB7   /* Entry Mode Set */
#define LCD_BACKLIGHT1          0xB8   /* Backlight Control 1 */
#define LCD_BACKLIGHT2          0xB9   /* Backlight Control 2 */
#define LCD_BACKLIGHT3          0xBA   /* Backlight Control 3 */
#define LCD_BACKLIGHT4          0xBB   /* Backlight Control 4 */
#define LCD_BACKLIGHT5          0xBC   /* Backlight Control 5 */
#define LCD_BACKLIGHT7          0xBE   /* Backlight Control 7 */
#define LCD_BACKLIGHT8          0xBF   /* Backlight Control 8 */
#define LCD_POWER1              0xC0   /* Power Control 1 register */
#define LCD_POWER2              0xC1   /* Power Control 2 register */
#define LCD_VCOM1               0xC5   /* VCOM Control 1 register */
#define LCD_VCOM2               0xC7   /* VCOM Control 2 register */
#define LCD_NVMWR               0xD0   /* NV Memory Write */
#define LCD_NVMPKEY             0xD1   /* NV Memory Protection Key */
#define LCD_RDNVM               0xD2   /* NV Memory Status Read */
#define LCD_READ_ID4            0xD3   /* Read ID4 */
#define LCD_PGAMMA              0xE0   /* Positive Gamma Correction register */
#define LCD_NGAMMA              0xE1   /* Negative Gamma Correction register */
#define LCD_DGAMCTRL1           0xE2   /* Digital Gamma Control 1 */
#define LCD_DGAMCTRL2           0xE3   /* Digital Gamma Control 2 */
#define LCD_INTERFACE           0xF6   /* Interface control register */

/* Extend register commands */
#define LCD_POWERA               0xCB   /* Power control A register */
#define LCD_POWERB               0xCF   /* Power control B register */
#define LCD_DTCA                 0xE8   /* Driver timing control A */
#define LCD_DTCB                 0xEA   /* Driver timing control B */
#define LCD_POWER_SEQ            0xED   /* Power on sequence register */
#define LCD_3GAMMA_EN            0xF2   /* 3 Gamma enable register */
#define LCD_PRC                  0xF7   /* Pump ratio control register */

/* Size of read registers */
#define LCD_READ_ID4_SIZE        3      /* Size of Read ID4 */
//</editor-fold>

//<editor-fold desc="Orientation">

#define ORIENTATION_PORTRAIT 0x48
#define ORIENTATION_LANDSCAPE 0x28
#define ORIENTATION_PORTRAIT_MIRROR 0x88
#define ORIENTATION_LANDSCAPE_MIRROR 0xE8

//</editor-fold>

// <editor-fold desc="Functions">

#define TFT_DC_SET      GPIO_SetBits(GPIOA, TFT_DC_PIN); usartSendString("DC+ ");
#define TFT_DC_RESET    GPIO_ResetBits(GPIOA, TFT_DC_PIN); usartSendString("DC- ");

#define TFT_RST_SET     GPIO_SetBits(GPIOA, TFT_RESET_PIN); usartSendString("RST+ ");
#define TFT_RST_RESET   GPIO_ResetBits(GPIOA, TFT_RESET_PIN); usartSendString("RST- ");

#define TOUCH_CS_SET      GPIO_SetBits(GPIOA, TOUCH_CS_PIN); usartSendString("CS+ ");
#define TOUCH_CS_RESET      GPIO_ResetBits(GPIOA, TOUCH_CS_PIN); usartSendString("CS- ");

#define TOUCH_GET_X_AXIS() GetAxis(0b10010000)
#define TOUCH_GET_Y_AXIS() GetAxis(0b11010000)

#define TFT_CS_SET      GPIO_SetBits(GPIOA, TFT_CS_PIN); usartSendString("CS+ ");
#define TFT_CS_RESET    GPIO_ResetBits(GPIOA, TFT_CS_PIN); usartSendString("CS- ");

#define TFT_LED_SET      GPIO_SetBits(GPIOA, TFT_LED_PIN);
#define TFT_LED_RESET    GPIO_ResetBits(GPIOA, TFT_LED_PIN);

// </editor-fold>

#define LCD_PIXEL_WIDTH       240
#define LCD_PIXEL_HEIGHT      320
#define LCD_PIXEL_COUNT    LCD_PIXEL_WIDTH * LCD_PIXEL_HEIGHT

void LCD_sendCommand8(u8 cmd);
void LCD_sendData8(u8 data);
void LCD_sendData16(u16 data);

void LCD_setSpi8(void);
void LCD_setSpi16(void);

u16 LCD_getWidth();
u16 LCD_getHeight();

void LCD_setAddressWindow(u16 x1, u16 y1, u16 x2, u16 y2);

void LCD_setOrientation(u8 o);

void debug();

#endif //TEST1_ILI9341_CORE_H
