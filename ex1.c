//******************************************************************************
//  Based on MSP430F20xx Demo - Software Toggle P1.0
//
//  Description; Sends characters by morse
//  ACLK = n/a, MCLK = SMCLK = default DCO
//
//                MSP430F20xx
//             -----------------
//         /|\|              XIN|-
//          | |                 |
//          --|RST          XOUT|-
//            |                 |
//            |             P1.0|-->LED
//
//******************************************************************************

//#include  <msp430G2231.h>

#include "library.c"
void tap_string(char* s);
void tap_char(char c);
void tap(char* p);

char* morse[] = {
	".-"   ,// A -  0
	"-..." ,// B -  1
	"-.-." ,// C -  2
	"-.."  ,// D -  3
	"."    ,// E -  4
	"..-." ,// F -  5
	"--."  ,// G -  6
	"...." ,// H -  7
	".."   ,// I -  8
	".---" ,// J -  9
	"-.-"  ,// K - 10
	".-.." ,// L - 11
	"--"   ,// M - 12
	"-."   ,// N - 13
	"---"  ,// O - 14
	".--." ,// P - 15
	"--.-" ,// Q - 16
	".-."  ,// R - 17
	"..."  ,// S - 18
	"-"    ,// T - 19
	"..-"  ,// U - 20
	"...-" ,// V - 21
	".--"  ,// W - 22
	"-..-" ,// X - 23
	"-.--" ,// Y - 24
	"--.." ,// Z - 25
};

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
  P1DIR |= 0x01;                            // Set P1.0 to output direction

  for (;;)
  {
  	tap_string("THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG");
  }
}


void tap_string(char* s)
{
	while (*s)
	{
		tap_char(*s++);
	}

	longbreak();
	longbreak();
	longbreak();
}

void tap_char(char c)
{
	if ((c >= 'A') && (c <= 'Z')) {
		tap(morse[c - 'A']);
	} else {
		longbreak(); // space or undefined
	}
}

void tap(char* p)
{
	while(*p)
	{
		if (*p++ == '.')
		{
			dot();
		}
		else
		{
			dash();
		}
	}

	shortbreak();
}

