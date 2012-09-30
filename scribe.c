/**********************************************************************

  scribe.c - record/replay engine

  $Author: mame $
  created at: Fri Sep 21 14:50:06 EDT 2012

  Copyright (C) 2012 Nicolas Viennot

**********************************************************************/

#include "/usr/include/scribe.h" /* FIXME This is really gross */
#include "scribe.h"
#include <sys/syscall.h>

void scribe_bootstrap(void)
{
	int i;

	scribe_disable_syscall(__NR_scribe_filter_syscall);
	scribe_disable_syscall(__NR_get_scribe_flags);
	scribe_disable_syscall(__NR_set_scribe_flags);
	scribe_disable_syscall(__NR_scribe_send_event);
	scribe_disable_syscall(__NR_scribe_recv_event);

	scribe_disable_syscall(__NR_mmap);
	scribe_disable_syscall(__NR_mmap2);
	scribe_disable_syscall(__NR_madvise);
	scribe_disable_syscall(__NR_mprotect);
	scribe_disable_syscall(__NR_mprotect);
	scribe_disable_syscall(__NR_brk);

	scribe_disable_syscall(__NR_set_robust_list);
	for (i = SCRIBE_FUTEX_FIRST; i <= SCRIBE_FUTEX_LAST; i++)
		scribe_disable_syscall(i);

	scribe_end();
}

void scribe_begin(void)
{
	set_scribe_flags(0, SCRIBE_PS_ENABLE_ALL & ~SCRIBE_PS_ENABLE_MM, SCRIBE_PERMANANT);
}

void scribe_end(void)
{
	set_scribe_flags(0, SCRIBE_PS_ENABLE_SIGNAL, SCRIBE_PERMANANT);
}
