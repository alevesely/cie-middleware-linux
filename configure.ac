#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([cie-middleware-linux], [1.4.2], [vesely@tana.it])
AC_CONFIG_SRCDIR([cie-pkcs11/keys.h])
AC_CONFIG_HEADERS([config.h])

AC_USE_SYSTEM_EXTENSIONS
AC_CONFIG_MACRO_DIRS([m4])

AM_INIT_AUTOMAKE(subdir-objects)
LT_INIT

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_CPP
PKG_PROG_PKG_CONFIG
if test -z "$PKG_CONFIG"; then
	AC_MSG_ERROR([cannot find pkg-config])
fi

if $PKG_CONFIG --atleast-version=1.9 libpcsclite; then
	PCSC_INC="`$PKG_CONFIG --cflags-only-I libpcsclite`"
	PCSC_LIB="`$PKG_CONFIG --libs-only-l libpcsclite`"
	PCSC_PATH="`$PKG_CONFIG --libs-only-L libpcsclite`"
	AC_SUBST([PCSC_INC])
	AC_SUBST([PCSC_LIB])
	AC_SUBST([PCSC_PATH])
else
	AC_MSG_ERROR([cannot find libpcsclite])
fi

if $PKG_CONFIG --atleast-version=8.4 libcrypto++; then
	CRPP_INC="`$PKG_CONFIG --cflags-only-I libcrypto++`"
	#CRPP_LIB="-Wl,-Bstatic `$PKG_CONFIG --libs-only-l libcrypto++` -Wl,-Bdynamic"
	CRPP_LIB="-l:libcrypto++.a"
	CRPP_PATH="`$PKG_CONFIG --libs-only-L libcrypto++`"
	AC_SUBST([CRPP_INC])
	AC_SUBST([CRPP_LIB])
	AC_SUBST([CRPP_PATH])
else
	AC_MSG_ERROR([cannot find libcrypto++])
fi

if $PKG_CONFIG --atleast-version=1.1 libcrypto; then
	CRY_INC="`$PKG_CONFIG --cflags-only-I libcrypto`"
	CRY_LIB="`$PKG_CONFIG --libs-only-l libcrypto`"
	CRY_PATH="`$PKG_CONFIG --libs-only-L libcrypto`"
	AC_SUBST([CRY_INC])
	AC_SUBST([CRY_LIB])
	AC_SUBST([CRY_PATH])
else
	AC_MSG_ERROR([cannot find libcrypto])
fi

if $PKG_CONFIG --atleast-version=2.9 libxml-2.0; then
	XML_INC="`$PKG_CONFIG --cflags-only-I libxml-2.0`"
	XML_LIB="`$PKG_CONFIG --libs-only-l libxml-2.0`"
	XML_PATH="`$PKG_CONFIG --libs-only-L libxml-2.0`"
	AC_SUBST([XML_INC])
	AC_SUBST([XML_LIB])
	AC_SUBST([XML_PATH])
else
	AC_MSG_ERROR([cannot find libxml-2.0])
fi


# Checks libraries for TestCIE
AC_CHECK_LIB([dl], [dlopen])

# Checks for header files.
AC_CHECK_HEADERS([arpa/inet.h fcntl.h float.h inttypes.h limits.h malloc.h memory.h netdb.h netinet/in.h stddef.h stdint.h stdlib.h string.h sys/param.h sys/socket.h sys/time.h unistd.h wchar.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT64_T
AC_TYPE_INT8_T
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_UINT8_T
AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
AC_FUNC_ALLOCA
AC_FUNC_ERROR_AT_LINE
AC_FUNC_LSTAT_FOLLOWS_SLASHED_SYMLINK
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_FUNC_STRNLEN
AC_CHECK_FUNCS([floor gettimeofday localtime_r memmove memset mkdir pow setlocale socket strcasecmp strerror strncasecmp strrchr strstr strtol])

AC_CONFIG_FILES([Makefile cie-pkcs11/Makefile])
AC_OUTPUT
