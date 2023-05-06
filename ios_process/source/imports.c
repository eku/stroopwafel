#include "imports.h"

#include "ios/svc.h"

#include <stdio.h>
#include <stdarg.h>

void usleep(u32 time)
{
	((void (*const)(u32))0x050564E4)(time);
}

void ios_abort(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    static char buffer[0x100];

    vsnprintf(buffer, 0xFF, format, args);
    svc_sys_write(buffer);

    va_end(args);

    crash_and_burn();
}