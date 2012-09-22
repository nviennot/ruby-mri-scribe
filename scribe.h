/**********************************************************************

  scribe.h - record/replay engine

  $Author: mame $
  created at: Fri Sep 21 14:50:06 EDT 2012

  Copyright (C) 2012 Nicolas Viennot

**********************************************************************/

#ifndef RUBY_SCRIBE_H
#define RUBY_SCRIBE_H

void scribe_bootstrap(void);

void scribe_begin(void);
void scribe_end(void);

#endif /* RUBY_SCRIBE_H */
