#ifndef TEST1_ILI9341_DMA_CORE_H
#define TEST1_ILI9341_DMA_CORE_H

#define ILI9341_TFTWIDTH  240
#define ILI9341_TFTHEIGHT 320

#define ILI9341_NOP     0x00
#define ILI9341_SWRESET 0x01
#define ILI9341_RDDID   0x04
#define ILI9341_RDDST   0x09

#define ILI9341_SLPIN   0x10
#define ILI9341_SLPOUT  0x11
#define ILI9341_PTLON   0x12
#define ILI9341_NORON   0x13

#define ILI9341_RDMODE  0x0A
#define ILI9341_RDMADCTL  0x0B
#define ILI9341_RDPIXFMT  0x0C
#define ILI9341_RDIMGFMT  0x0D
#define ILI9341_RDDSPSGNMODE  0x0E
#define ILI9341_RDSELFDIAG  0x0F

#define ILI9341_INVOFF  0x20
#define ILI9341_INVON   0x21
#define ILI9341_GAMMASET 0x26
#define ILI9341_DISPOFF 0x28
#define ILI9341_DISPON  0x29

#define ILI9341_CASET   0x2A
#define ILI9341_PASET   0x2B
#define ILI9341_RAMWR   0x2C
#define ILI9341_RAMRD   0x2E

#define ILI9341_PTLAR   0x30
#define ILI9341_MADCTL  0x36
#define ILI9341_IDMOFF  0x38
#define ILI9341_IDMON   0x39
#define ILI9341_PIXFMT  0x3A

#define ILI9341_FRMCTR1 0xB1
#define ILI9341_FRMCTR2 0xB2
#define ILI9341_FRMCTR3 0xB3
#define ILI9341_INVCTR  0xB4
#define ILI9341_DFUNCTR 0xB6

#define ILI9341_PWCTR1  0xC0
#define ILI9341_PWCTR2  0xC1
#define ILI9341_PWCTR3  0xC2
#define ILI9341_PWCTR4  0xC3
#define ILI9341_PWCTR5  0xC4
#define ILI9341_VMCTR1  0xC5
#define ILI9341_VMCTR2  0xC7

#define ILI9341_RDID1   0xDA
#define ILI9341_RDID2   0xDB
#define ILI9341_RDID3   0xDC
#define ILI9341_RDID4   0xDD

#define ILI9341_GMCTRP1 0xE0
#define ILI9341_GMCTRN1 0xE1

#define TFT_LED_PIN     GPIO_Pin_0
#define TFT_RESET_PIN   GPIO_Pin_2
#define TFT_DC_PIN      GPIO_Pin_3
#define TFT_CS_PIN      GPIO_Pin_4

#define TFT_DC_SET      GPIO_SetBits(GPIOA, TFT_DC_PIN);
#define TFT_DC_RESET    GPIO_ResetBits(GPIOA, TFT_DC_PIN);

#define TFT_RST_SET     GPIO_SetBits(GPIOA, TFT_RESET_PIN);
#define TFT_RST_RESET   GPIO_ResetBits(GPIOA, TFT_RESET_PIN);

#define TFT_CS_SET      GPIO_SetBits(GPIOA, TFT_CS_PIN);
#define TFT_CS_RESET    GPIO_ResetBits(GPIOA, TFT_CS_PIN);

#define TFT_LED_SET      GPIO_SetBits(GPIOA, TFT_LED_PIN);
#define TFT_LED_RESET    GPIO_ResetBits(GPIOA, TFT_LED_PIN);

#define LCD_WIDTH       240
#define LCD_HEIGHT      320
#define LCD_PIXEL_COUNT    LCD_WIDTH * LCD_HEIGHT

void LCD_DMA_Init(void);

#endif //TEST1_ILI9341_DMA_CORE_H
