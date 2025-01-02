#include <Adafruit_GFX.h>       // Core graphics library
#include <Adafruit_ST7735.h>    // Hardware-specific library for ST7735


//1. backlight anode
// 5V out

//2. Ground
// GND

//3. Reset
#define TFT_RESET 2

//4. Data / Command selection
#define TFT_DATA_COM 3

//5. SPI data (MOSI)
#define TFT_MOSI 11

//6. SPI Clock
#define TFT_CLK 13

//7. 3.3v (VDD)
// 3V3

//8. Chip Select
#define TFT_CS 4

#define SCREEN_WIDTH 160
#define SCREEN_HEIGHT 80

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DATA_COM, TFT_RESET);

const uint8_t mickey[] PROGMEM = {
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xdf,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x1,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x7f,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x3f,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0x1f,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0x83,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0xf,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xbd,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0xf,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0x7e,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0xf,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0x7e,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x40,0x7,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xfe,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0xc0,0x7,0xff,0xf0,
0xff,0xff,0xff,0xff,0xfe,0xfe,0xff,0xff,0xff,0xff,0xff,0xff,0xf9,0xf0,0x7,0xff,0xf0,
0xff,0xff,0xff,0xff,0xfe,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfb,0xfc,0x3,0xff,0xf0,
0xff,0xff,0xff,0xff,0xfe,0xfd,0xff,0xff,0xff,0xff,0xfc,0xf,0xf7,0xff,0x81,0xff,0xf0,
0xff,0xff,0xff,0xc0,0x2,0xfd,0xff,0xff,0xff,0xff,0xf8,0x3,0xef,0xff,0x81,0xff,0xf0,
0xff,0xff,0xff,0x3c,0xfc,0xfd,0xff,0xff,0xff,0xff,0xe0,0x1,0xcf,0xff,0x81,0xff,0xf0,
0xff,0xff,0xfe,0xfb,0xff,0x7b,0xff,0xff,0xff,0xff,0xc0,0x0,0x90,0xff,0x81,0xff,0xf0,
0xff,0xc3,0xf9,0xf7,0xff,0xbb,0xff,0xff,0xff,0xff,0xc0,0x0,0x3d,0xff,0xc1,0xff,0xf0,
0xff,0xbd,0xfb,0xf7,0xff,0xdb,0xff,0xff,0xff,0xff,0x80,0x0,0x7b,0xff,0x81,0xff,0xf0,
0xff,0x7d,0xf7,0xef,0xff,0xdb,0xff,0xff,0xff,0xfc,0x0,0x0,0xfb,0xff,0x81,0xff,0xf0,
0xff,0x7e,0xef,0xff,0xff,0xe7,0xff,0xff,0xff,0xf9,0x80,0x1,0xe7,0xff,0x3,0xff,0xf0,
0xff,0xfe,0xef,0xdf,0xff,0xe7,0xff,0xff,0xff,0xfb,0xe0,0x1,0xdf,0xfe,0x3,0xff,0xf0,
0xff,0x7f,0x5f,0xbf,0xff,0xf7,0xff,0xff,0xff,0xfb,0xf0,0x6,0x7f,0xfc,0x7,0xff,0xf0,
0xff,0x7f,0x5f,0xbf,0xff,0xf7,0xff,0xff,0xff,0xfb,0xf8,0xf,0xff,0xf8,0xf,0xff,0xf0,
0xff,0xff,0xbf,0xff,0xff,0xfb,0xff,0xff,0xff,0xfb,0xfc,0x1f,0xff,0xf0,0x1f,0xff,0xf0,
0xff,0xbf,0xbf,0x7f,0xf3,0xfb,0xff,0xff,0xff,0xf9,0xff,0x1f,0xff,0xf7,0xff,0xff,0xf0,
0xff,0xdf,0xdf,0x7f,0x9c,0xfd,0xff,0xff,0xff,0xfc,0xff,0xbf,0xff,0xef,0xff,0xff,0xf0,
0xff,0xdf,0xde,0xff,0x3f,0x7d,0xff,0xff,0xff,0xfe,0x61,0x8f,0xff,0xdf,0xff,0xff,0xf0,
0xff,0xef,0xee,0xff,0x1f,0xbd,0xff,0xff,0xff,0xff,0x7,0xf3,0xff,0xbe,0x7f,0xff,0xf0,
0xff,0xf7,0xee,0xfe,0xe8,0x3e,0xff,0xff,0xff,0xfe,0x1f,0xf8,0xff,0x30,0xf,0xff,0xf0,
0xff,0xf7,0xef,0xff,0xf7,0x9e,0xff,0xff,0xff,0xf9,0xff,0xfc,0x7e,0x40,0x3,0xff,0xf0,
0xff,0xfb,0xfd,0xfd,0xf7,0xbe,0xff,0xf0,0xff,0xf7,0xff,0xfe,0x1e,0x80,0x1,0xff,0xf0,
0xff,0xfd,0xed,0xff,0xf7,0xaf,0x7f,0xe0,0x7f,0xef,0xff,0xfe,0xd,0x0,0x1,0xff,0xf0,
0xff,0xfc,0xdd,0xfb,0xf7,0xaf,0x7f,0xe0,0x7f,0xef,0xff,0xfe,0x3,0x0,0x0,0xff,0xf0,
0xff,0xfd,0x3f,0xfb,0xff,0xb7,0x7f,0xe0,0x3f,0xc7,0xff,0xfe,0x2,0x0,0x0,0xff,0xf0,
0xff,0xfb,0xfb,0xf7,0xef,0xb7,0xff,0xe0,0x3f,0x8e,0x3f,0xfe,0x0,0x0,0x0,0xff,0xf0,
0xff,0xfb,0xfb,0xf7,0xef,0xb7,0xbf,0xf0,0x1,0x8c,0x3f,0xfc,0x0,0x0,0x0,0x7f,0xf0,
0xff,0xfb,0xfb,0xf7,0xef,0xff,0xbf,0xf0,0x1c,0xc,0x3f,0xfc,0x0,0x0,0x0,0x7f,0xf0,
0xff,0xfb,0xfb,0xff,0xef,0x7b,0xbf,0xf8,0x1f,0x18,0x7f,0xfc,0x0,0x0,0x0,0x7f,0xf0,
0xff,0xff,0xff,0xef,0xff,0x7b,0xbf,0xfc,0x1f,0xb8,0x7f,0xf8,0x0,0x0,0x0,0x7f,0xf0,
0xff,0xf7,0xf7,0xef,0xdf,0x7b,0xfc,0xfe,0x1f,0xd0,0xff,0xf3,0xe0,0x0,0x0,0xff,0xf0,
0xff,0xf7,0xf7,0xef,0xdf,0x7f,0xc0,0x1e,0xff,0xf1,0xff,0xef,0xf8,0x0,0x0,0xff,0xf0,
0xff,0xf7,0xf7,0xff,0xde,0x7f,0xc0,0xe,0xff,0xfb,0xff,0xdf,0xfc,0x0,0x0,0xff,0xf0,
0xff,0xf7,0xf7,0xdf,0xde,0x7d,0xc0,0x6,0xff,0xff,0xff,0xf8,0xfe,0x0,0x1,0xff,0xf0,
0xff,0xf7,0xf7,0xcf,0xde,0xfd,0xc0,0x3,0x7f,0xff,0xff,0xee,0x7e,0x0,0x3,0xff,0xf0,
0xff,0xf7,0xf7,0xd7,0x9f,0xbd,0xc0,0x1,0x7f,0xff,0xff,0xff,0xbf,0x0,0x7,0xff,0xf0,
0xff,0xff,0xff,0xd7,0xbd,0xbd,0xc0,0x1,0xbf,0xff,0xff,0xff,0xff,0x20,0x1f,0xff,0xf0,
0xff,0xef,0xff,0xff,0xbd,0xbd,0xc0,0x1,0xdf,0xff,0xff,0xf7,0xff,0x38,0x7f,0xff,0xf0,
0xff,0xef,0xef,0xfb,0xbd,0xbd,0xc0,0x0,0xef,0xff,0xff,0xe7,0xff,0x3f,0xff,0xff,0xf0,
0xff,0xef,0xef,0xbd,0xbf,0xbf,0xc0,0x0,0x79,0xff,0xff,0xcf,0xff,0x7f,0xff,0xff,0xf0,
0xff,0xef,0xef,0xbd,0xbb,0xbf,0xe0,0x0,0xe,0x3f,0xfe,0xf,0xff,0x7f,0xff,0xff,0xf0,
0xff,0xef,0xef,0xbe,0xfb,0xbf,0xe0,0x0,0x7,0x80,0x0,0x1f,0xff,0x7f,0xff,0xff,0xf0,
0xff,0xef,0xef,0x9e,0x3,0xc6,0xe0,0x0,0x0,0xcf,0xc1,0x1f,0xfe,0xff,0xff,0xff,0xf0,
0xff,0xef,0xef,0xaf,0x76,0x3a,0xe0,0x1,0x0,0x2f,0xdf,0xbf,0xfc,0xff,0xff,0xff,0xf0,
0xff,0xef,0xef,0xaf,0x76,0xfa,0xe0,0x3,0xc0,0x2f,0xff,0x7f,0xf9,0xff,0xff,0xff,0xf0,
0xff,0xff,0xef,0xb7,0x6f,0x7c,0xe0,0x7,0xf8,0x37,0xfe,0xff,0xf3,0xff,0xff,0xff,0xf0,
0xff,0xff,0xef,0x80,0x6f,0x7c,0xe0,0xf,0xfe,0x37,0xfd,0xff,0xe7,0xff,0xff,0xff,0xf0,
0xff,0xff,0xef,0x80,0x2f,0x7a,0xee,0x3f,0xff,0xdb,0xf3,0xff,0xdf,0xff,0xff,0xff,0xf0,
0xff,0xff,0xef,0x80,0xf,0x72,0xef,0xff,0xff,0xdc,0xe,0xff,0x3f,0xff,0xff,0xff,0xf0,
0xff,0xdf,0xef,0x80,0x9,0x4e,0xef,0xff,0xff,0xef,0xfd,0xfc,0x3f,0xff,0xff,0xff,0xf0,
0xff,0xdf,0xef,0x80,0x0,0x9e,0xef,0xff,0xff,0xf7,0xf3,0xe0,0x1f,0xff,0xff,0xff,0xf0,
0xff,0xdf,0xef,0x80,0x0,0xde,0xef,0xff,0xff,0xf8,0x0,0x0,0xf,0xff,0xff,0xff,0xf0,
0xff,0xdf,0xff,0x0,0x0,0xde,0xef,0xff,0xff,0xe0,0x0,0x0,0x7,0xff,0xff,0xff,0xf0,
0xff,0xdf,0xff,0x0,0x0,0xde,0xef,0xf8,0x0,0x0,0x1,0x0,0x3,0xff,0xff,0xff,0xf0,
0xff,0xdf,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x1,0xff,0xff,0xff,0xf0,
0xff,0xdf,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xc,0x0,0x0,0xff,0xff,0xff,0xf0,
0xff,0xc1,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7f,0xff,0xff,0xf0,
0xff,0x1e,0xff,0x80,0x0,0x0,0x0,0x0,0x1,0xff,0x0,0x0,0x0,0x3f,0xff,0xff,0xf0,
0xfc,0xff,0x6f,0x80,0x7,0x0,0xf,0xff,0xff,0xff,0x0,0x0,0x7f,0xcf,0xff,0xff,0xf0,
0xf3,0xff,0x6f,0x80,0x6,0xde,0xef,0xff,0xff,0xff,0x0,0xf,0xff,0xf3,0xff,0xff,0xf0,
0xe7,0xff,0x6f,0x80,0x6,0xdf,0xef,0xff,0xff,0xff,0x80,0x3f,0xff,0xf9,0xff,0xff,0xf0,
0xff,0xff,0x6f,0x80,0x0,0xff,0xff,0xff,0xff,0xff,0x80,0xff,0xff,0xfc,0xff,0xff,0xf0,
0xdf,0xfe,0xef,0x80,0x1f,0x7d,0xff,0xff,0xff,0xff,0xc7,0xff,0xff,0xfe,0xff,0xff,0xf0,
0xdf,0xfd,0xef,0xb7,0xaf,0x7d,0xdf,0xff,0xff,0xff,0xcf,0xfc,0x3f,0xff,0x7f,0xff,0xf0,
0xdf,0xfb,0xef,0xb7,0xaf,0xbd,0xdf,0xff,0xff,0xff,0xcf,0xf9,0xdf,0xff,0x7f,0xff,0xf0,
0xef,0xe7,0xef,0xb7,0xbf,0xbd,0xdf,0xff,0xff,0xff,0xdf,0xfb,0xef,0xff,0xbf,0xff,0xf0,
0xe7,0x8f,0xef,0xaf,0xf7,0xdd,0xdf,0xff,0xff,0xff,0xdf,0xfb,0xef,0xff,0xbf,0xff,0xf0,
0xf8,0xef,0xef,0xaf,0x7f,0xfd,0xdf,0xff,0xff,0xff,0xdf,0xfb,0xef,0xff,0xbf,0xff,0xf0,
0xff,0xef,0xef,0xaf,0x7b,0xed,0xdf,0xff,0xff,0xff,0xb0,0xf9,0xcf,0xff,0xdf,0xff,0xf0,
0xff,0xef,0xef,0xbf,0x7b,0xef,0xff,0xff,0xff,0xff,0xae,0xfc,0x9f,0xff,0xdf,0xff,0xf0,
0xff,0xef,0xff,0xdf,0x7d,0xf3,0xbf,0xff,0xff,0xff,0xaf,0x7f,0xff,0xff,0xdf,0xff,0xf0,
0xff,0xff,0xf7,0xdf,0xfd,0xf3,0xbf,0xff,0xff,0xff,0xbf,0x7f,0xff,0xff,0x9f,0xff,0xf0,
0xff,0xf7,0xf7,0xde,0xfe,0xeb,0xbf,0xff,0xff,0xff,0xaf,0x7f,0xff,0xff,0xbf,0xff,0xf0,
0xff,0xf7,0xf7,0xde,0xfe,0xeb,0xbf,0xff,0xff,0xff,0xaf,0x7f,0xff,0xff,0xbf,0xff,0xf0,
0xff,0xf7,0xf7,0xde,0xff,0x1f,0xbf,0xff,0xff,0xff,0xb0,0xff,0xff,0xff,0xbf,0xff,0xf0,
0xff,0xf7,0xf7,0xde,0xff,0x77,0xbf,0xff,0xff,0xff,0xbf,0xff,0xff,0xff,0x3f,0xff,0xf0,
0xff,0xf7,0xf7,0xef,0xfe,0xf7,0x7f,0xff,0xff,0xff,0xbf,0xff,0xff,0xff,0x7f,0xff,0xf0,
0xff,0xfb,0xff,0xed,0xfe,0xf7,0x7f,0xff,0xff,0xff,0xbf,0xff,0xff,0xfe,0x7f,0xff,0xf0,
0xff,0xfb,0xfb,0xed,0xfe,0xef,0x3f,0xff,0xff,0xff,0x9f,0xff,0xff,0xfe,0xff,0xff,0xf0,
0xff,0xfb,0xfb,0xf5,0xfd,0xef,0x3f,0xff,0xff,0xff,0x9f,0xff,0xff,0xfc,0xff,0xff,0xf0,
0xff,0xfb,0xfb,0xf5,0xfd,0xff,0xdf,0xff,0xff,0xfe,0x7f,0xff,0xff,0xfd,0xff,0xff,0xf0,
0xff,0xfd,0xfb,0xfb,0xfb,0xde,0xef,0xff,0xff,0xfe,0xff,0xff,0xff,0xfb,0xff,0xff,0xf0,
0xff,0xfd,0xfd,0xfb,0xf7,0xbe,0xef,0xff,0xff,0xfe,0x7f,0xff,0xff,0xf7,0xff,0xff,0xf0,
0xff,0xfd,0xfd,0xfd,0xf7,0xbe,0xf7,0xff,0xff,0xfc,0x3f,0xff,0xff,0xf7,0xff,0xff,0xf0,
0xff,0xff,0xfd,0xfd,0xef,0x7d,0xf7,0xff,0xff,0xf8,0x1f,0x9f,0xff,0xf3,0xff,0xff,0xf0,
0xff,0xfe,0xfe,0xfe,0x3e,0xfd,0xfb,0xff,0xff,0xe0,0x7,0xe0,0xff,0xf1,0xff,0xff,0xf0,
0xff,0xfe,0xfe,0xff,0x7d,0xf9,0xfb,0xff,0xff,0xc0,0x79,0xce,0xff,0xf0,0xff,0xff,0xf0,
0xff,0xff,0x7f,0xff,0x83,0xfa,0xfb,0xff,0xff,0xc0,0xfc,0x1e,0xff,0xf2,0xff,0xff,0xf0,
0xff,0xff,0x7f,0x7f,0xff,0xfa,0xfb,0xff,0xff,0x81,0xff,0xbe,0xff,0xe6,0x7f,0xff,0xf0,
0xff,0xff,0xbf,0x7f,0xff,0xf7,0x77,0xff,0xff,0x83,0xff,0xfe,0x0,0x1f,0x7f,0xff,0xf0,
0xff,0xff,0xbf,0xbf,0xff,0xf7,0x8f,0xff,0xff,0x7,0xff,0xff,0xf0,0x7f,0x7f,0xff,0xf0,
0xff,0xff,0xdf,0xff,0xff,0xef,0xff,0xff,0xff,0x7,0xff,0xff,0xf0,0x7f,0x3f,0xff,0xf0,
0xff,0xff,0xd8,0x5f,0xff,0xef,0xff,0xff,0xff,0x7,0xff,0xff,0xf0,0x7f,0x3f,0xff,0xf0,
0xff,0xff,0xe7,0xbf,0xff,0xdf,0xff,0xff,0xff,0xf,0xff,0xff,0xf0,0x7f,0xbf,0xff,0xf0,
0xff,0xff,0xef,0xaf,0xff,0xbf,0xff,0xff,0xff,0xf,0xff,0xff,0xf0,0x7f,0xbf,0xff,0xf0,
0xff,0xff,0xef,0xb7,0xff,0x7f,0xff,0xc7,0xff,0xf,0xff,0xff,0xf0,0x7f,0x9f,0xff,0xf0,
0xff,0xff,0xef,0xb9,0xfe,0xff,0xff,0x31,0xfc,0x3,0xff,0xff,0xf0,0x7f,0x9f,0xfe,0xf0,
0xff,0xff,0xff,0xbc,0xfd,0xff,0xfe,0xfc,0x79,0x8,0xff,0xff,0xe0,0x7f,0xdf,0xff,0x70,
0xff,0xff,0xdf,0xbf,0x3,0xff,0xfc,0xff,0xc7,0xe,0xff,0xff,0xc0,0xff,0xdf,0xff,0xb0,
0xff,0xff,0xdf,0xbf,0xff,0xff,0xfd,0xff,0xf7,0x6,0xff,0xff,0x80,0xff,0xdf,0xff,0xb0,
0xff,0xff,0xff,0xbf,0xff,0xff,0xfd,0xff,0xfb,0xfc,0xff,0xff,0x1,0xff,0xcf,0xff,0xd0,
0xff,0xff,0xbf,0xff,0xff,0xff,0xfd,0xff,0xff,0xf0,0xff,0xe0,0x3,0xff,0xef,0xff,0xd0,
0xff,0xff,0xbf,0xff,0xff,0xff,0xfd,0xff,0xff,0xff,0x7f,0xde,0x7,0xff,0xef,0xff,0xd0,
0xff,0xff,0xbf,0x7f,0xff,0xff,0xfc,0xff,0xff,0xff,0x7f,0xb8,0x7,0xff,0xe7,0xff,0xe0,
0xff,0xff,0xff,0x7f,0xff,0xff,0xf9,0x3f,0xff,0xff,0x7f,0xb8,0x37,0xff,0xf7,0xff,0xe0,
0xff,0xff,0xbf,0x7f,0xff,0xff,0xfd,0xc7,0xff,0xfe,0xff,0x9f,0xe0,0x7,0xf3,0xff,0xe0,
0xff,0xff,0xbf,0xff,0xff,0xff,0xfc,0xf0,0x3f,0xc0,0xff,0x6f,0xc0,0x73,0xfb,0xff,0xe0,
0xff,0xff,0xbe,0xff,0xff,0xff,0xfe,0x1f,0xf0,0xfe,0xff,0x7f,0xff,0xf9,0xfd,0xff,0xd0,
0xff,0xff,0xc9,0xff,0xff,0xff,0xff,0xe0,0xe,0x71,0xfe,0xff,0xff,0xfd,0xfe,0xff,0x90,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x8f,0xfe,0x7f,0xff,0xfd,0xff,0x3f,0x30,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xbf,0xff,0xfd,0xff,0x8c,0x70,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xbf,0xff,0xfd,0xff,0xe1,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x4f,0xff,0xfc,0x7f,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7,0xff,0xfa,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x81,0xff,0xf2,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xea,0x7f,0xe5,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x87,0x1b,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x38,0xe7,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x1f,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0
};


void setup() {
  // Initialize the serial port for debugging
  Serial.begin(9600);
  Serial.println("ST7735 Test");

  // Initialize the display
  tft.initR(INITR_MINI160x80);  // Initialize with the black tab version of ST7735
  tft.setRotation(1);

  tft.fillScreen(ST77XX_BLACK);

  // Display some text
  tft.setTextColor(ST77XX_WHITE);  // Set text color
  tft.setTextSize(2);              // Set text size
  tft.setCursor(0, 0);             // Set cursor position
  tft.println("Hello, Ida!");

  // Draw a rectangle
  tft.drawRect(10, 20, 50, 30, ST77XX_RED);

  // Draw a filled circle
  tft.fillCircle(80, 40, 15, ST77XX_BLUE);

  tft.drawBitmap(0, 0, mickey, 132, 132, ST77XX_WHITE);
  tft.drawGrayscaleBitmap()
}

void loop() {
  // put your main code here, to run repeatedly:

}