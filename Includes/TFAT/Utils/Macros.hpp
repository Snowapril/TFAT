/*************************************************************************
> File Name: Macros.hpp
> Project Name: TFAT
> This code is based on baba-is-auto that was created by Chris Ohk
> References: https://github.com/utilforever/baba-is-auto
> Purpose: Base class of the TFAT pieces.
> Created Time: 2020/04/15
> Copyright (c) 2020, Ji-Hong snowapril
*************************************************************************/

#ifndef TFAT_MACROS_H
#define TFAT_MACROS_H

#if defined(_WIN32) || defined(_WIN64)
#   define TFAT_WINDOWS
#elif defined(__APPLE__)
#   define TFAT_APPLE
#   ifndef TFAT_IOS
#       define TFAT_MACOSX
#   endif
#elif defined(linux) || defined(__linux__)
#   define TFAT_LINUX
#endif

#ifdef TFAT_WINDOWS
#include <BaseTsd.h>
typedef SSIZE_T ssize_t;
#else
#include <sys/types.h>
#endif

#ifndef UNUSED_VARIABLE
#	define UNUSED_VARIABLE(x) ((void)x)
#endif

#endif