/**
 *
 * \file
 *
 * \brief Platform timer interface
 *
 * Copyright (c) 2014-2016 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

#ifndef MQTT_TIMER_INTERFACE_H_INCLUDED
#define MQTT_TIMER_INTERFACE_H_INCLUDED

#include <sys/types.h>
#include <sys/time.h>


/**
 * \defgroup Real-time Timer Definition
 *
 * @{
 */
 
#define	timeradd(tvp, uvp, vvp)								\
	do {													\
		(vvp)->tv_sec = (tvp)->tv_sec + (uvp)->tv_sec;		\
		(vvp)->tv_usec = (tvp)->tv_usec + (uvp)->tv_usec;	\
		if ((vvp)->tv_usec >= 1000000) {					\
			(vvp)->tv_sec++;								\
			(vvp)->tv_usec -= 1000000;						\
		}													\
	} while (0)
#define	timersub(tvp, uvp, vvp)								\
	do {													\
		(vvp)->tv_sec = (tvp)->tv_sec - (uvp)->tv_sec;		\
		(vvp)->tv_usec = (tvp)->tv_usec - (uvp)->tv_usec;	\
		if ((vvp)->tv_usec < 0) {							\
			(vvp)->tv_sec--;								\
			(vvp)->tv_usec += 1000000;						\
		}													\
	} while (0)


typedef struct mqtt_timer {
	struct timeval end_time;
} Timer;


void configure_rtt(void);
int _gettimeofday(struct timeval* tv, void* tzvp);

void TimerInit(Timer *timer);
char TimerIsExpired(Timer *timer);
void TimerCountdownMS(Timer *timer, unsigned int timeout_ms);
void TimerCountdown(Timer *timer, unsigned int timeout);
int TimerLeftMS(Timer *timer);

/** @} */

#endif // MQTT_TIMER_INTERFACE_H_INCLUDED