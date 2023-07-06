/*
 * Platform_Types.h
 *
 *  Created on: Jul 5, 2023
 *      Author: Misho
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

#include "stdint.h"
#include "stdbool.h"

//CPU Type
#define CPU_TYPE CPU_TYPE_32
#define CPU_BIT_ORDER LSB_FIRST
#define CPU_BYTE_ORDER LOW_BYTE_FIRST

//boolean
#ifndef _bool
#define _Bool unsinged char

#ifndef FALSE
#define FALSe (boolean)false

#ifndef TRUE
#define TRUE (boolean)true

// signed and unsigned 8,16,32,64 bits
typedef int8_t				sint8;
typedef uint8_t				uint8;
typedef int16_t				sint16;
typedef uint16_t			uint16;
typedef int32_t				sint32;
typedef uint32_t			uint32;
typedef int64_t				sint64;
typedef uint64_t			uint64;

// least signed and unsigned 8,16,32,64 bits
typedef int_least8_t		sint8_least;
typedef uint_least8_t		uint8_least;
typedef int_least16_t		sint16_least;
typedef uint_least16_t		uint16_least;
typedef int_least32_t		sint32_least;
typedef uint_least32_t		uint32_least;
typedef int_least64_t		sint64_least;
typedef uint_least64_t		uint64_least;

// volatile signed and unsigned 8,16,32,64 bits
typedef volatile int_least8_t		vsint8_least;
typedef volatile uint_least8_t		vuint8_least;
typedef volatile int_least16_t		vsint16_least;
typedef volatile uint_least16_t		vuint16_least;
typedef volatile int_least32_t		vsint32_least;
typedef volatile uint_least32_t		vuint32_least;
typedef volatile int_least64_t		vsint64_least;
typedef volatile uint_least64_t		vuint64_least;

// floats
typedef float				float32;
typedef double				float64;

#endif /* PLATFORM_TYPES_H_ */
