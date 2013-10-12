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
void tap(unsigned char p);

/* A byte describes the pattern to tap.
 * Low 4 bits are the tap count for this character: 1 -> 4.
 *   0 & 5 -> 15 are unused.
 * High 4 bits are the taps: 0 for dot, 1 for dash.
 * Tap order is least significant -> most significant.
 * X - Don't care.
 */
unsigned char morse[] = {
	//       "taps" len  char
	0x12 ,// "XX.-" 2  - A -  0
	0x84 ,// "-..." 4  - B -  1
	0xA4 ,// "-.-." 4  - C -  2
	0x43 ,// "X-.." 3  - D -  3
	0x01 ,// "XXX." 1  - E -  4
	0x24 ,// "..-." 4  - F -  5
	0x63 ,// "X--." 3  - G -  6
	0x04 ,// "...." 4  - H -  7
	0x02 ,// "XX.." 2  - I -  8
	0x74 ,// ".---" 4  - J -  9
	0x53 ,// "X-.-" 3  - K - 10
	0x44 ,// ".-.." 4  - L - 11
	0x32 ,// "XX--" 2  - M - 12
	0x22 ,// "XX-." 2  - N - 13
	0x73 ,// "X---" 4  - O - 14
	0x64 ,// ".--." 4  - P - 15
	0xD4 ,// "--.-" 4  - Q - 16
	0x23 ,// "X.-." 3  - R - 17
	0x03 ,// "X..." 3  - S - 18
	0x11 ,// "XXX-" 1  - T - 19
	0x13 ,// "X..-" 3  - U - 20
	0x14 ,// "...-" 4  - V - 21
	0x33 ,// "X.--" 3  - W - 22
	0x94 ,// "-..-" 4  - X - 23
	0xB4 ,// "-.--" 4  - Y - 24
	0xC4 ,// "--.." 4  - Z - 25
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

void tap(unsigned char p)
{
	short len = 0xF & p;
	short mask = 0x8 << len;

	while(len--)
	{
		if (p & mask)
		{
			dash();
		}
		else
		{
			dot();
		}
		mask = mask >> 1;
	}

	shortbreak();
}

