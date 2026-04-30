#ifndef DMD_H_ 					// Dot Matrix Display
#define DMD_H_
				

// Includes 
#include<stdint.h>
#include<stdlib.h>
#include "gpio.h"
#include "pwm.h"

// data types 
#define byte uint8_t
#define boolean uint8_t

// Digital LOGIC 
#define HIGH 1
#define true 1
#define LOW 0
#define false 0

#define OUTPUT 1
#define INPUT 0



// PINs of DMD module
#define DMD_nOE 	1		// GPIO_1 active low output enable
#define DMD_A		2		// GPIO_2
#define DMD_B		3		// GPIO_3
#define DMD_CLK 	4		// GPIO_4	SPI Clock
#define DMD_SCLK	5		// GPIO_5
#define	DMD_R		6		// GPIO_6	MOSI SPI master out
#define spiClk		4000000 // 4 MHz SPI clock

// define macro for digitalWrite and pinMode 
#define digitalWrite( A, B) {gpio_write_pin(A,B);}
#define pinMode( A,  B) { gpio_mode (A,B);}


#define LIGHT_DMD_ROW_01_05_09_13()       	{ digitalWrite( DMD_B,  LOW ); digitalWrite( DMD_A,  LOW ); }
#define LIGHT_DMD_ROW_02_06_10_14()       	{ digitalWrite( DMD_B,  LOW ); digitalWrite( DMD_A, HIGH ); }
#define LIGHT_DMD_ROW_03_07_11_15()       	{ digitalWrite( DMD_B, HIGH ); digitalWrite( DMD_A,  LOW ); }
#define LIGHT_DMD_ROW_04_08_12_16()       	{ digitalWrite( DMD_B, HIGH ); digitalWrite( DMD_A, HIGH ); }
#define LATCH_DMD_SHIFT_REG_TO_OUTPUT()		{ digitalWrite( DMD_SCLK, HIGH ); digitalWrite( DMD_SCLK,  LOW ); }
#define OE_DMD_ROWS_OFF()                 	{ pwm1_stop(); }
#define OE_DMD_ROWS_ON()  					{ pwm1_start(); }



//Pixel/graphics writing modes (bGraphicsMode)
#define GRAPHICS_NORMAL	0
#define GRAPHICS_INVERSE	1
#define GRAPHICS_TOGGLE	2
#define GRAPHICS_OR		3
#define GRAPHICS_NOR	4

//drawTestPattern Patterns
#define PATTERN_ALT_0	0
#define PATTERN_ALT_1	1
#define PATTERN_STRIPE_0	2
#define PATTERN_STRIPE_1	3

//display screen (and subscreen) sizing
#define DMD_PIXELS_ACROSS	32      //pixels across x axis (base 2 size expected)
#define DMD_PIXELS_DOWN	16      //pixels down y axis
#define DMD_BITSPERPIXEL		1      //1 bit per pixel, use more bits to allow for pwm screen brightness control
#define DMD_RAM_SIZE_BYTES	((DMD_PIXELS_ACROSS*DMD_BITSPERPIXEL/8)*DMD_PIXELS_DOWN)
                                  // (32x * 1 / 8) = 4 bytes, * 16y = 64 bytes per screen here.
//lookup table for DMD::writePixel to make the pixel indexing routine faster
static byte bPixelLookupTable[8] =
{
   0x80,   //0, bit 7
   0x40,   //1, bit 6
   0x20,   //2. bit 5
   0x10,   //3, bit 4
   0x08,   //4, bit 3
   0x04,   //5, bit 2
   0x02,   //6, bit 1
   0x01    //7, bit 0
};

// Font Indices
#define FONT_LENGTH			0
#define FONT_FIXED_WIDTH		2
#define FONT_HEIGHT			3
#define FONT_FIRST_CHAR		4
#define FONT_CHAR_COUNT 	5
#define FONT_WIDTH_TABLE	6

// variables 
//Mirror of DMD pixels in RAM, ready to be clocked out by the main loop or high speed timer calls
    byte *bDMDScreenRAM;

    //Marquee values
    char marqueeText[256];
    byte marqueeLength;
    int marqueeWidth;
    int marqueeHeight;
    int marqueeOffsetX;
    int marqueeOffsetY;

    //Pointer to current font
    const uint8_t* Font;
    

    //Display information
    byte DisplaysWide;
    byte DisplaysHigh;
    byte DisplaysTotal;
    int row1, row2, row3;

    //scanning pointer into bDMDScreenRAM, setup init @ 48 for the first valid scan
    volatile byte bDMDByte;


typedef uint8_t (*FontCallback)(const uint8_t*);

// Fucntions Prototypes

	//Instantiate the DMD
	void DMD(byte panelsWide, byte panelsHigh);

	//Set or clear a pixel at the x and y location (0,0 is the top left corner)
	void writePixel( unsigned int bX, unsigned int bY, byte bGraphicsMode, byte bPixel );

	//Draw a string
	void drawString( int bX, int bY, const char* bChars, byte length, byte bGraphicsMode);

	//Select a text font
	void selectFont(const uint8_t* font);

	//Draw a single character
	int drawChar(const int bX, const int bY, const unsigned char letter, byte bGraphicsMode);

	//Find the width of a character
	int charWidth(const unsigned char letter);

	//Draw a scrolling string
	void drawMarquee( const char* bChars, byte length, int left, int top);

	//Move the maquee accross by amount
	boolean stepMarquee( int amountX, int amountY);

	//Clear the screen in DMD RAM
	void clearScreen( byte bNormal );

	//Draw or clear a line from x1,y1 to x2,y2
	void drawLine( int x1, int y1, int x2, int y2, byte bGraphicsMode );

	//Draw or clear a circle of radius r at x,y centre
	void drawCircle( int xCenter, int yCenter, int radius, byte bGraphicsMode );

	//Draw or clear a box(rectangle) with a single pixel border
	void drawBox( int x1, int y1, int x2, int y2, byte bGraphicsMode );

	//Draw or clear a filled box(rectangle) with a single pixel border
	void drawFilledBox( int x1, int y1, int x2, int y2, byte bGraphicsMode );

	//Draw the selected test pattern
	void drawTestPattern( byte bPattern );

	//Scan the dot matrix LED panel display, from the RAM mirror out to the display hardware.
	//Call 4 times to scan the whole display which is made up of 4 interleaved rows within the 16 total rows.
	//Insert the calls to this function into the main loop for the highest call rate, or from a timer interrupt
	void scanDisplayBySPI();
  	

  	void drawCircleSub( int cx, int cy, int x, int y, byte bGraphicsMode );

    boolean stepSplitMarquee(int topRow, int bottomRow);

#endif
