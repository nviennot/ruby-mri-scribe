/**********************************************************************

  scribe.h - record/replay engine

  $Author: mame $
  created at: Fri Sep 21 14:50:06 EDT 2012

  Copyright (C) 2012 Nicolas Viennot

**********************************************************************/

#ifndef RUBY_SCRIBE_H
#define RUBY_SCRIBE_H

#if defined(__cplusplus)
extern "C" {
#endif

void scribe_bootstrap(void);

#if defined __GNUC__ && __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif

void scribe_begin(void);
void scribe_end(void);

void scribe_begin_restore(unsigned long *flags);
void scribe_end_save(unsigned long *flags);

#if defined __GNUC__ && __GNUC__ >= 4
#pragma GCC visibility pop
#endif


#if defined(__cplusplus)
}  /* extern "C" { */
#endif

#endif /* RUBY_SCRIBE_H */
