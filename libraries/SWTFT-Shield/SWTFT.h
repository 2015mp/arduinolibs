// Code provided by Smoke And Wires
// http://www.smokeandwires.co.nz
// This code has been taken from the Adafruit TFT Library and modified
//  by us for use with our TFT Shields / Modules
// For original code / licensing please refer to
// https://github.com/adafruit/TFTLCD-Library

// IMPORTANT: SEE COMMENTS @ LINE 15 REGARDING SHIELD VS BREAKOUT BOARD USAGE.

// Graphics library by ladyada/adafruit with init code from Rossum
// MIT license

#ifndef _SWTFT_H_
#define _SWTFT_H_

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif
#include "mega_24_shield.h"
//#include "uno_24_shield.h"
#include <Adafruit_GFX.h>
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
/*
#define ILI9341_PWCTR6  0xFC

*/

// Color definitions
#define ILI9341_BLACK       0x0000      /*   0,   0,   0 */
#define ILI9341_NAVY        0x000F      /*   0,   0, 128 */
#define ILI9341_DARKGREEN   0x03E0      /*   0, 128,   0 */
#define ILI9341_DARKCYAN    0x03EF      /*   0, 128, 128 */
#define ILI9341_MAROON      0x7800      /* 128,   0,   0 */
#define ILI9341_PURPLE      0x780F      /* 128,   0, 128 */
#define ILI9341_OLIVE       0x7BE0      /* 128, 128,   0 */
#define ILI9341_LIGHTGREY   0xC618      /* 192, 192, 192 */
#define ILI9341_DARKGREY    0x7BEF      /* 128, 128, 128 */
#define ILI9341_BLUE        0x001F      /*   0,   0, 255 */
#define ILI9341_GREEN       0x07E0      /*   0, 255,   0 */
#define ILI9341_CYAN        0x07FF      /*   0, 255, 255 */
#define ILI9341_RED         0xF800      /* 255,   0,   0 */
#define ILI9341_MAGENTA     0xF81F      /* 255,   0, 255 */
#define ILI9341_YELLOW      0xFFE0      /* 255, 255,   0 */
#define ILI9341_WHITE       0xFFFF      /* 255, 255, 255 */
#define ILI9341_ORANGE      0xFD20      /* 255, 165,   0 */
#define ILI9341_GREENYELLOW 0xAFE5      /* 173, 255,  47 */
#define ILI9341_PINK        0xF81F
#define swrite8(d) { \
  if (d==lastdata) {WR_STROBE;} \
  else {write8(d); lastdata=d;} \
  }

class SWTFT : public Adafruit_GFX {

 public:

  SWTFT(void);
 // SWTFT(void);

  void     begin(uint16_t id = 0x9325);
  void     drawPixel(int16_t x, int16_t y, uint16_t color);
  /////////////////////////////////////////
  void     writeA16B3(uint16_t address, uint8_t ub, uint8_t mb, uint8_t lb);
  void     drawPixel3(int16_t x, int16_t y, uint8_t r, uint8_t g, uint8_t b);
  void     drawLine3Byte(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint8_t r, uint8_t g, uint8_t b) ;
  //////////////////////////////////////////
  void     drawFastHLine(int16_t x0, int16_t y0, int16_t w, uint16_t color);
  void     drawHLine(int16_t x0, int16_t y0, int16_t w, uint16_t color);
  void     drawFastVLine(int16_t x0, int16_t y0, int16_t h, uint16_t color);
  void     drawVLine(int16_t x0, int16_t y0, int16_t h, uint16_t color);
  void     fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t c);
  void     fillScreen(uint16_t color);
  void     reset(void);
  void     setRegisters8(uint8_t *ptr, uint8_t n);
  void     setRegisters16(uint16_t *ptr, uint8_t n);
  void     setRotation(uint8_t x);
       // These methods are public in order for BMP examples to work:
  void     setAddrWindow(int x1, int y1, int x2, int y2);
  void     pushColors(uint16_t *data, uint8_t len, boolean first);

  uint16_t color565(uint8_t r, uint8_t g, uint8_t b),
           readPixel(int16_t x, int16_t y),
           readID(void);

 private:

  void     init(),
           // These items may have previously been defined as macros
           // If not, function versions are declared:
#ifndef write8
           write8(uint8_t value),
#endif
#ifndef setWriteDir
           setWriteDir(void),
#endif
#ifndef setReadDir
           setReadDir(void),
#endif
#ifndef writeRegister8
           writeRegister8(uint8_t a, uint8_t d),
#endif
#ifndef writeRegister16
           writeRegister16(uint16_t a, uint16_t d),
#endif
#ifndef writeRegisterPair
           writeRegisterPair(uint8_t aH, uint8_t aL, uint16_t d),
#endif
           writeRegister32(uint8_t a, uint32_t d),
           setLR(void),
           flood(uint16_t color, uint32_t len);
  uint8_t  driver;
  uint8_t  lastdata=0;
#ifndef read8
  uint8_t  read8fn(void);
  #define  read8isFunctionalized
#endif
protected:
void setAddr(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
  __attribute__((always_inline)) {
	writecommand_cont(ILI9341_CASET); // Column addr set
	writedata16_cont(x0);   // XSTART
	writedata16_cont(x1);   // XEND
	writecommand_cont(ILI9341_PASET); // Row addr set
	writedata16_cont(y0);   // YSTART
	writedata16_cont(y1);   // YEND
}

#define SWTFT_SHORTDELAY 1
void writecommand_cont(uint8_t c) __attribute__((always_inline)) {
  CD_COMMAND;
  swrite8(c);
}
void writedata8_cont(uint8_t c) __attribute__((always_inline)) {
  CD_DATA;
  swrite8(c);
  delayMicroseconds(SWTFT_SHORTDELAY);
}
void writedata16_cont(uint16_t d) __attribute__((always_inline)) {
  uint8_t hi = d >> 8,
		  lo = d;
  CD_DATA;
  swrite8(hi);
  delayMicroseconds(SWTFT_SHORTDELAY);
  swrite8(lo);
  /*
  if (hi != lo)
  {write8(hi); }
  else {WR_STROBE;}
  */
  delayMicroseconds(SWTFT_SHORTDELAY);
}
void writecommand_last(uint8_t c) __attribute__((always_inline)) {
  CD_COMMAND;
  swrite8(c);
  CS_IDLE;
}
void writedata8_last(uint8_t c) __attribute__((always_inline)) {
  CD_DATA;
  swrite8(c);
  CS_IDLE;
}
void writedata16_last(uint16_t d) __attribute__((always_inline)) {
	/*
  uint8_t hi = d >> 8,
		  lo = d;
  CD_DATA;
  write8(lo);
  delayMicroseconds(SWTFT_SHORTDELAY);
  if (hi!=lo) write8(hi);
  delayMicroseconds(SWTFT_SHORTDELAY);
  */
  CD_DATA;
  writedata16_cont(d);
  CS_IDLE;
}
void HLine(int16_t x, int16_t y, int16_t w, uint16_t color)
  __attribute__((always_inline)) {
	setAddr(x, y, x+w-1, y);
	writecommand_cont(ILI9341_RAMWR);
	//CD_DATA;
	do { writedata16_cont(color); } while (--w > 0);
}
void VLine(int16_t x, int16_t y, int16_t h, uint16_t color)
  __attribute__((always_inline)) {
	setAddr(x, y, x, y+h-1);
	//CD_DATA;
	writecommand_cont(ILI9341_RAMWR);
	do { writedata16_cont(color); } while (--h > 0);
}
void Pixel(int16_t x, int16_t y, uint16_t color)
  __attribute__((always_inline)) {
	setAddr(x, y, x, y);
	//CD_DATA;
	writecommand_cont(ILI9341_RAMWR);
	writedata16_cont(color);
}
#ifndef USE_ADAFRUIT_SHIELD_PINOUT

  #ifdef __AVR__
    volatile uint8_t *csPort    , *cdPort    , *wrPort    , *rdPort;
	uint8_t           csPinSet  ,  cdPinSet  ,  wrPinSet  ,  rdPinSet  ,
					  csPinUnset,  cdPinUnset,  wrPinUnset,  rdPinUnset,
					  _reset;
  #endif
  #if defined(__SAM3X8E__)
    Pio *csPort    , *cdPort    , *wrPort    , *rdPort;
	uint32_t          csPinSet  ,  cdPinSet  ,  wrPinSet  ,  rdPinSet  ,
					  csPinUnset,  cdPinUnset,  wrPinUnset,  rdPinUnset,
					  _reset;
  #endif
  
#endif
};

// For compatibility with sketches written for older versions of library.
// Color function name was changed to 'color565' for parity with 2.2" LCD
// library.
#define Color565 color565

#endif //_SWTFT_H_
