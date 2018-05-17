#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#define __RELATIVE_FILE__ (strrchr("\\" __FILE__, '\\') + 1)
#define ASSERTF(A, F, ...) if (!(A)) {assert_format (__COUNTER__, __RELATIVE_FILE__, __LINE__, __func__, #A, F, ## __VA_ARGS__);}



void assert_format (int id, char const * file, int line, char const * fn, char const * exp, char const * fmt, ...)
{
	va_list list;
	va_start (list, fmt);
	fprintf	
	(
		stderr,
		"ASSERT %04i (%s:%04i in %s) (%s)\n",
		id, 
		file, 
		line, 
		fn, 
		exp
	);
	fprintf (stderr, "errno %04i:%s\n", errno, strerror (errno));
	vfprintf (stderr, fmt, list);
	fprintf (stderr, "\n\n");
	va_end (list);
	abort ();
}