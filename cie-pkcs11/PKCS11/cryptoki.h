/* cryptoki.h include file for PKCS #11. */
/* $Revision: 1.4 $ */

/* License to copy and use this software is granted provided that it is
 * identified as "RSA Security Inc. PKCS #11 Cryptographic Token Interface
 * (Cryptoki)" in all material mentioning or referencing this software.

 * License is also granted to make and use derivative works provided that
 * such works are identified as "derived from the RSA Security Inc. PKCS #11
 * Cryptographic Token Interface (Cryptoki)" in all material mentioning or 
 * referencing the derived work.

 * RSA Security Inc. makes no representations concerning either the 
 * merchantability of this software or the suitability of this software for
 * any particular purpose. It is provided "as is" without express or implied
 * warranty of any kind.
 */

/* This is a sample file containing the top level include directives
 * for building Cryptoki libraries and applications.
 */

#ifndef ___CRYPTOKI_H_INC___
#define ___CRYPTOKI_H_INC___

#if defined(WIN32) || defined(_WIN32) || defined(__clang__)
// For clang see https://releases.llvm.org/3.4/tools/clang/docs/UsersManual.html#microsoft-extensions
#pragma pack(push, cryptoki, 1)
#elif defined(__gcc__)
#pragma pack(push, 1)
#endif

#if !defined(WIN32) && !defined(_WIN32)
#define CK_IMPORT_SPEC
#define CK_EXPORT_SPEC
#define CK_CALL_SPEC

#else // !defined(WIN32) && !defined(_WIN32)

/* Specifies that the function is a DLL entry point. */
#define CK_IMPORT_SPEC __declspec(dllimport)

/* Define CRYPTOKI_EXPORTS during the build of cryptoki libraries. Do
 * not define it in applications.
 */
#ifdef CRYPTOKI_EXPORTS
/* Specified that the function is an exported DLL entry point. */
#	if defined(_WIN32_WCE)
#		define CK_EXPORT_SPEC 
#	else
#		define CK_EXPORT_SPEC __declspec(dllexport) 
#	endif
#else
#define CK_EXPORT_SPEC CK_IMPORT_SPEC 
#endif

/* Ensures the calling convention for Win32 builds */
#define CK_CALL_SPEC __cdecl

#endif // !defined(WIN32) && !defined(_WIN32)


#define CK_PTR *

#define CK_DECLARE_FUNCTION(returnType, name) \
  returnType CK_EXPORT_SPEC CK_CALL_SPEC name

#define CK_DECLARE_FUNCTION_POINTER(returnType, name) \
  returnType CK_IMPORT_SPEC (CK_CALL_SPEC* name)

#define CK_CALLBACK_FUNCTION(returnType, name) \
  returnType (* name)

#ifndef NULL_PTR
#define NULL_PTR 0
#endif

#include "pkcs11.h"

#if defined(_WIN32) || defined(WIN32) || defined(_WIN32) || defined(__clang__)
#pragma pack(pop, cryptoki)
#elif defined(__gcc__)
#pragma pack(pop)
#endif

#endif /* ___CRYPTOKI_H_INC___ */
