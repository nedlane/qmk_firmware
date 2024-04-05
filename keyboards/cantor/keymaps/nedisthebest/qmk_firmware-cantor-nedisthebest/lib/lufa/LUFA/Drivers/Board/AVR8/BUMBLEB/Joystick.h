/*
             LUFA Library
     Copyright (C) Dean Camera, 2021.

  dean [at] fourwalledcubicle [dot] com
           www.lufa-lib.org
*/

/*
  Copyright 2021  Dean Camera (dean [at] fourwalledcubicle [dot] com)

  Permission to use, copy, modify, distribute, and sell this
  software and its documentation for any purpose is hereby granted
  without fee, provided that the above copyright notice appear in
  all copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting
  documentation, and that the name of the author not be used in
  advertising or publicity pertaining to distribution of the
  software without specific, written prior permission.

  The author disclaims all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/

/** \file
 *  \brief Board specific joystick driver header for the Fletchtronics BUMBLEB.
 *  \copydetails Group_Joystick_BUMBLEB
 *
 *  \note This file should not be included directly. It is automatically included as needed by the joystick driver
 *        dispatch header located in LUFA/Drivers/Board/Joystick.h.
 */

/** \ingroup Group_Joystick
 *  \defgroup Group_Joystick_BUMBLEB BUMBLEB
 *  \brief Board specific joystick driver header for the Fletchtronics BUMBLEB.
 *
 *  Board specific joystick driver header for the Fletchtronics BUMBLEB (http://fletchtronics.net/bumble-b). The BUMBLEB
 *  third-party board does not include any on-board peripherals, but does have an officially recommended external peripheral
 *  layout for buttons, LEDs and a Joystick.
 *
 *  <table>
 *    <tr><th>Left Port Pin</th><th>Up Port Pin</th><th>Right Port Pin</th><th>Down Port Pin</th><th>Press Port Pin</th></tr>
 *    <tr><td>PORTD.2</td><td>PORTD.3</td><td>PORTD.0</td><td>PORTD.1</td><td>PORTD.4</td></tr>
 *  </table>
 *
 *  @{
 */

#ifndef __JOYSTICK_BUMBLEB_H__
#define __JOYSTICK_BUMBLEB_H__

	/* Includes: */
		#include "../../../../Common/Common.h"

	/* Enable C linkage for C++ Compilers: */
		#if defined(__cplusplus)
			extern "C" {
		#endif

	/* Preprocessor Checks: */
		#if !defined(__INCLUDE_FROM_JOYSTICK_H)
			#error Do not include this file directly. Include LUFA/Drivers/Board/Joystick.h instead.
		#endif

	/* Private Interface - For use in library only: */
	#if !defined(__DOXYGEN__)
		/* Macros: */
			#define JOY_MASK                 ((1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4))
	#endif

	/* Public Interface - May be used in end-application: */
		/* Macros: */
			/** Mask for the joystick being pushed in the left direction. */
			#define JOY_LEFT                  (1 << 2)

			/** Mask for the joystick being pushed in the upward direction. */
			#define JOY_UP                    (1 << 3)

			/** Mask for the joystick being pushed in the right direction. */
			#define JOY_RIGHT                 (1 << 0)

			/** Mask for the joystick being pushed in the downward direction. */
			#define JOY_DOWN                  (1 << 1)

			/** Mask for the joystick being pushed inward. */
			#define JOY_PRESS                 (1 << 4)

		/* Inline Functions: */
		#if !defined(__DOXYGEN__)
			static inline void Joystick_Init(void)
			{
				DDRD  &= ~JOY_MASK;
				PORTD |=  JOY_MASK;
			}

			static inline void Joystick_Disable(void)
			{
				DDRD  &= ~JOY_MASK;
				PORTD &= ~JOY_MASK;
			}

			static inline uint8_t Joystick_GetStatus(void) ATTR_WARN_UNUSED_RESULT;
			static inline uint8_t Joystick_GetStatus(void)
			{
				return (uint8_t)(~PIND & JOY_MASK);
			}
		#endif

	/* Disable C linkage for C++ Compilers: */
		#if defined(__cplusplus)
			}
		#endif

#endif

/** @} */

