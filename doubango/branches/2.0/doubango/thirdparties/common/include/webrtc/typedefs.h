/*
 *  Copyright (c) 2012 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

// This file contains platform-specific typedefs and defines.
// Much of it is derived from Chromium's build/build_config.h.
/*
#ifndef WEBRTC_TYPEDEFS_H_
#define WEBRTC_TYPEDEFS_H_

// For access to standard POSIXish features, use WEBRTC_POSIX instead of a
// more specific macro.
#if defined(WEBRTC_MAC) || defined(WEBRTC_LINUX) || \
    defined(WEBRTC_ANDROID)
#define WEBRTC_POSIX
#endif

// Processor architecture detection.  For more info on what's defined, see:
//   http://msdn.microsoft.com/en-us/library/b0084kay.aspx
//   http://www.agner.org/optimize/calling_conventions.pdf
//   or with gcc, run: "echo | gcc -E -dM -"
#if defined(_M_X64) || defined(__x86_64__)
#define WEBRTC_ARCH_X86_FAMILY
#define WEBRTC_ARCH_X86_64
#define WEBRTC_ARCH_64_BITS
#define WEBRTC_ARCH_LITTLE_ENDIAN
#elif defined(_M_IX86) || defined(__i386__)
#define WEBRTC_ARCH_X86_FAMILY
#define WEBRTC_ARCH_X86
#define WEBRTC_ARCH_32_BITS
#define WEBRTC_ARCH_LITTLE_ENDIAN
#elif defined(__ARMEL__)
// TODO(andrew): We'd prefer to control platform defines here, but this is
// currently provided by the Android makefiles. Commented to avoid duplicate
// definition warnings.
//#define WEBRTC_ARCH_ARM
// TODO(andrew): Chromium uses the following two defines. Should we switch?
//#define WEBRTC_ARCH_ARM_FAMILY
//#define WEBRTC_ARCH_ARMEL
#define WEBRTC_ARCH_32_BITS
#define WEBRTC_ARCH_LITTLE_ENDIAN
#elif defined(__MIPSEL__)
#define WEBRTC_ARCH_32_BITS
#define WEBRTC_ARCH_LITTLE_ENDIAN
#else
#error Please add support for your architecture in typedefs.h
#endif

#if defined(__SSE2__) || defined(_MSC_VER)
#define WEBRTC_USE_SSE2
#endif

#if !defined(_MSC_VER)
#include <stdint.h>
#else
// Define C99 equivalent types, since MSVC doesn't provide stdint.h.
typedef signed char         int8_t;
typedef signed short        int16_t;
typedef signed int          int32_t;
typedef __int64             int64_t;
typedef unsigned char       uint8_t;
typedef unsigned short      uint16_t;
typedef unsigned int        uint32_t;
typedef unsigned __int64    uint64_t;
#endif

// TODO(andrew): remove WebRtc_ types:
// http://code.google.com/p/webrtc/issues/detail?id=314
typedef int8_t              WebRtc_Word8;
typedef int16_t             WebRtc_Word16;
typedef int32_t             WebRtc_Word32;
typedef int64_t             WebRtc_Word64;
typedef uint8_t             WebRtc_UWord8;
typedef uint16_t            WebRtc_UWord16;
typedef uint32_t            WebRtc_UWord32;
typedef uint64_t            WebRtc_UWord64;

#endif  // WEBRTC_TYPEDEFS_H_
*/

/*
 *  Copyright (c) 2011 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

/*
 *
 * This file contains type definitions used in all WebRtc APIs.
 *
 */

/* Reserved words definitions */
#define WEBRTC_EXTERN extern
#define G_CONST const
#define WEBRTC_INLINE extern __inline

#ifndef WEBRTC_TYPEDEFS_H
#define WEBRTC_TYPEDEFS_H

/* Define WebRtc preprocessor identifiers based on the current build platform */
#if defined(WIN32)
// Windows & Windows Mobile
#if !defined(WEBRTC_TARGET_PC)
#define WEBRTC_TARGET_PC
#endif
#elif defined(__APPLE__)
// Mac OS X
#if defined(__LITTLE_ENDIAN__ ) //TODO: is this used?
#if !defined(WEBRTC_TARGET_MAC_INTEL)
#define WEBRTC_TARGET_MAC_INTEL
#endif
#else
#if !defined(WEBRTC_TARGET_MAC)
#define WEBRTC_TARGET_MAC
#endif
#endif
#else
// Linux etc.
#if !defined(WEBRTC_TARGET_PC)
#define WEBRTC_TARGET_PC
#endif
#endif

#if defined(WEBRTC_TARGET_PC)

#if !defined(_MSC_VER)
#include <stdint.h>
#else
// Define C99 equivalent types.
// Since MSVC doesn't include these headers, we have to write our own
// version to provide a compatibility layer between MSVC and the WebRTC
// headers.
typedef signed char         int8_t;
typedef signed short        int16_t;
typedef signed int          int32_t;
typedef signed long long    int64_t;
typedef unsigned char       uint8_t;
typedef unsigned short      uint16_t;
typedef unsigned int        uint32_t;
typedef unsigned long long  uint64_t;
#endif

#if defined(WIN32)
typedef __int64             WebRtc_Word64;
typedef unsigned __int64    WebRtc_UWord64;
#else
typedef int64_t             WebRtc_Word64;
typedef uint64_t            WebRtc_UWord64;
#endif
typedef int32_t             WebRtc_Word32;
typedef uint32_t            WebRtc_UWord32;
typedef int16_t             WebRtc_Word16;
typedef uint16_t            WebRtc_UWord16;
typedef char                WebRtc_Word8;
typedef uint8_t             WebRtc_UWord8;

/* Define endian for the platform */
#define WEBRTC_LITTLE_ENDIAN

#elif defined(WEBRTC_TARGET_MAC_INTEL)
#include <stdint.h>

typedef int64_t             WebRtc_Word64;
typedef uint64_t            WebRtc_UWord64;
typedef int32_t             WebRtc_Word32;
typedef uint32_t            WebRtc_UWord32;
typedef int16_t             WebRtc_Word16;
typedef char                WebRtc_Word8;
typedef uint16_t            WebRtc_UWord16;
typedef uint8_t             WebRtc_UWord8;

/* Define endian for the platform */
#define WEBRTC_LITTLE_ENDIAN

#else

#error "No platform defined for WebRtc type definitions (webrtc_typedefs.h)"

#endif


#endif // WEBRTC_TYPEDEFS_H