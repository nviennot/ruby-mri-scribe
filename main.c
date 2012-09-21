/**********************************************************************

  main.c -

  $Author$
  created at: Fri Aug 19 13:19:58 JST 1994

  Copyright (C) 1993-2007 Yukihiro Matsumoto

**********************************************************************/

#undef RUBY_EXPORT
#include "ruby.h"
#include "debug.h"
#ifdef HAVE_LOCALE_H
#include <locale.h>
#endif
#ifdef RUBY_DEBUG_ENV
#include <stdlib.h>
#endif

#include <scribe.h>
#include <sys/syscall.h>

RUBY_GLOBAL_SETUP

static void hook_scribe(void)
{
	int i;

	scribe_disable_syscall(__NR_scribe_filter_syscall);
	scribe_disable_syscall(__NR_get_scribe_flags);
	scribe_disable_syscall(__NR_set_scribe_flags);
	scribe_disable_syscall(__NR_scribe_send_event);
	scribe_disable_syscall(__NR_scribe_recv_event);

	set_scribe_flags(0, SCRIBE_PS_ENABLE_ALL & ~SCRIBE_PS_ENABLE_MM, SCRIBE_PERMANANT);
	for (i = SCRIBE_FUTEX_FIRST; i <= SCRIBE_FUTEX_LAST; i++)
		scribe_disable_syscall(i);
}

int
main(int argc, char **argv)
{
#ifdef RUBY_DEBUG_ENV
    ruby_set_debug_option(getenv("RUBY_DEBUG"));
#endif
#ifdef HAVE_LOCALE_H
    setlocale(LC_CTYPE, "");
#endif

    hook_scribe();

    ruby_sysinit(&argc, &argv);
    {
	RUBY_INIT_STACK;
	ruby_init();
	return ruby_run_node(ruby_options(argc, argv));
    }
}
