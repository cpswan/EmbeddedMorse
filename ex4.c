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
	switch(c)
	{
		case 'A':
			dot();
			dash();
			break;
		case 'B':
			dash();
			dot();
			dot();
			dot();
			break;
		case 'C':
			dash();
			dot();
			dash();
			dot();
			break;
		case 'D':
			dash();
			dot();
			dot();
			break;
		case 'E':
			dot();
			break;
		case 'F':
			dot();
			dot();
			dash();
			dot();
			break;
		case 'G':
			dash();
			dash();
			dot();
			break;
		case 'H':
			dot();
			dot();
			dot();
			dot();
			break;
		case 'I':
			dot();
			dot();
			break;
		case 'J':
			dot();
			dash();
			dash();
			dash();
			break;
		case 'K':
			dash();
			dot();
			dash();
			break;
		case 'L':
			dot();
			dash();
			dot();
			dot();
			break;
		case 'M':
			dash();
			dash();
			break;
		case 'N':
			dash();
			dot();
			break;
		case 'O':
			dash();
			dash();
			dash();
			break;
		case 'P':
			dot();
			dash();
			dash();
			dot();
			break;
		case 'Q':
			dash();
			dash();
			dot();
			dash();
			break;
		case 'R':
			dot();
			dash();
			dot();
			break;
		case 'S':
			dot();
			dot();
			dot();
			break;
		case 'T':
			dash();
			break;
		case 'U':
			dot();
			dot();
			dash();
			break;
		case 'V':
			dot();
			dot();
			dot();
			dash();
			break;
		case 'W':
			dot();
			dash();
			dash();
			break;
		case 'X':
			dash();
			dot();
			dot();
			dash();
			break;
		case 'Y':
			dash();
			dot();
			dash();
			dash();
			break;
		case 'Z':
			dash();
			dash();
			dot();
			dot();
			break;
		case ' ':
			longbreak();
			return;
	}
	shortbreak();
}

