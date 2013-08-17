/****************************************************************************
 *   $Id:: timer32.h 7146 2011-04-19 19:48:01Z nxp28548                     $
 *   Project: NXP LPC11xx software example
 *
 *   Description:
 *     This file contains definition and prototype for 32-bit timer 
 *     configuration.
 *
 ****************************************************************************
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * products. This software is supplied "AS IS" without any warranties.
 * NXP Semiconductors assumes no responsibility or liability for the
 * use of the software, conveys no license or title under any patent,
 * copyright, or mask work right to the product. NXP Semiconductors
 * reserves the right to make changes in the software without
 * notification. NXP Semiconductors also make no representation or
 * warranty that such application will be suitable for the specified
 * use without further testing or modification.
****************************************************************************/
#ifndef __TIMER32_H 
#define __TIMER32_H

/* The test is either MAT_OUT or CAP_IN. Default is CAP_IN. */
#ifndef MATCH
#define MATCH		1
#endif //MATCH
#define CAPTURE 		0
#define EMC0	4
#define EMC1	6
#define EMC2	8
#define EMC3	10

#define MATCH0	(1<<0)
#define MATCH1	(1<<1)
#define MATCH2	(1<<2)
#define MATCH3	(1<<3)

#ifndef TIME_INTERVAL
#define TIME_INTERVAL	(SystemCoreClock/1000 - 1)
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  uint8_t num;
  volatile uint32_t counter[4]; // = {0,0,0,0};
  volatile uint32_t capture[4]; // = {0,0,0,0};
  volatile uint32_t period; // = 0;
} Timer32;

extern Timer32 Timer0, Timer1;

void delay32Ms(uint8_t timer_num, uint32_t delayInMs);
void TIMER32_0_IRQHandler(void);
void TIMER32_1_IRQHandler(void);
void enable_timer32(uint8_t timer_num);
void disable_timer32(uint8_t timer_num);
void reset_timer32(uint8_t timer_num);
void set_timer32_capture(uint8_t timer_num, uint8_t location );
void set_timer32_match(uint8_t timer_num, uint8_t match_enable, uint8_t location);
void init_timer32(uint8_t timer_num, uint32_t timerInterval);
void init_timer32PWM(uint8_t timer_num, uint32_t period, uint8_t match_enable);
void setMatch_timer32PWM (uint8_t timer_num, uint8_t match_nr, uint32_t value);

uint32_t millis(void);

#ifdef __cplusplus
}
#endif

#endif /* end __TIMER32_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/