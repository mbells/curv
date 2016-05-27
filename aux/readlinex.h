// Copyright Doug Moen 2016.
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENCE.md or http://www.boost.org/LICENSE_1_0.txt

#ifndef AUX_READLINEX_H
#define AUX_READLINEX_H

#ifdef __cplusplus
extern "C" {
#endif

enum RLXResult { rlx_okay, rlx_eof, rlx_interrupt };

/// A wrapper around GNU readline() which flushes its state and input
/// and returns immediately if a keyboard interrupt is sent.
///
/// If the line has any text in it, save it on the history.
///
/// This matches the behaviour of bash and many other programs that use
/// readline. The necessary code is arcane, hence the wrapper.
char *readlinex(const char* prompt, enum RLXResult* result);

#ifdef __cplusplus
}
#endif
#endif // header guard
