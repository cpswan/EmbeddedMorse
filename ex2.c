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
void tap_A(void);
void tap_B(void);
void tap_C(void);
void tap_D(void);
void tap_E(void);
void tap_F(void);
void tap_G(void);
void tap_H(void);
void tap_I(void);
void tap_J(void);
void tap_K(void);
void tap_L(void);
void tap_M(void);
void tap_N(void);
void tap_O(void);
void tap_P(void);
void tap_Q(void);
void tap_R(void);
void tap_S(void);
void tap_T(void);
void tap_U(void);
void tap_V(void);
void tap_W(void);
void tap_X(void);
void tap_Y(void);
void tap_Z(void);

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
  P1DIR |= 0x01;                            // Set P1.0 to output direction

  for (;;)
  {
  	tap_T();
  	tap_H();
  	tap_E();
  	longbreak();
  	tap_Q();
  	tap_U();
  	tap_I();
  	tap_C();
  	tap_K();
  	longbreak();
  	tap_B();
  	tap_R();
  	tap_O();
  	tap_W();
  	tap_N();
  	longbreak();
  	tap_F();
  	tap_O();
  	tap_X();
  	longbreak();
  	tap_J();
  	tap_U();
  	tap_M();
  	tap_P();
  	tap_S();
  	longbreak();
  	tap_O();
  	tap_V();
  	tap_E();
  	tap_R();
  	longbreak();
  	tap_T();
  	tap_H();
  	tap_E();
  	longbreak();
  	tap_L();
  	tap_A();
  	tap_Z();
  	tap_Y();
  	longbreak();
  	tap_D();
  	tap_O();
  	tap_G();
  	longbreak();
  	longbreak();
  	longbreak();
  }
}

void tap_A(void)
{
	dot();
	dash();
	shortbreak();
}


void tap_B(void)
{
	dash();
	dot();
	dot();
	dot();
	shortbreak();
}

void tap_C(void)
{
	dash();
	dot();
	dash();
	dot();
	shortbreak();
}

void tap_D(void)
{
	dash();
	dot();
	dot();
	shortbreak();
}

void tap_E(void)
{
	dot();
	shortbreak();
}

void tap_F(void)
{
	dot();
	dot();
	dash();
	dot();
	shortbreak();
}

void tap_G(void)
{
	dash();
	dash();
	dot();
	shortbreak();
}

void tap_H(void)
{
	dot();
	dot();
	dot();
	dot();
	shortbreak();
}

void tap_I(void)
{
	dot();
	dot();
	shortbreak();
}

void tap_J(void)
{
	dot();
	dash();
	dash();
	dash();
	shortbreak();
}

void tap_K(void)
{
	dash();
	dot();
	dash();
	shortbreak();
}

void tap_L(void)
{
	dot();
	dash();
	dot();
	dot();
	shortbreak();
}

void tap_M(void)
{
	dash();
	dash();
	shortbreak();
}

void tap_N(void)
{
	dash();
	dot();
	shortbreak();
}

void tap_O(void)
{
	dash();
	dash();
	dash();
	shortbreak();
}

void tap_P(void)
{
	dot();
	dash();
	dash();
	dot();
	shortbreak();
}


void tap_Q(void)
{
	dash();
	dash();
	dot();
	dash();
	shortbreak();
}

void tap_R(void)
{
	dot();
	dash();
	dot();
	shortbreak();
}

void tap_S(void)
{
	dot();
	dot();
	dot();
	shortbreak();
}

void tap_T(void)
{
	dash();
	shortbreak();
}

void tap_U(void)
{
	dot();
	dot();
	dash();
	shortbreak();
}

void tap_V(void)
{
	dot();
	dot();
	dot();
	dash();
	shortbreak();
}

void tap_W(void)
{
	dot();
	dash();
	dash();
	shortbreak();
}

void tap_X(void)
{
	dash();
	dot();
	dot();
	dash();
	shortbreak();
}

void tap_Y(void)
{
	dash();
	dot();
	dash();
	dash();
	shortbreak();
}

void tap_Z(void)
{
	dash();
	dash();
	dot();
	dot();
	shortbreak();
}
