/*
 * alloc.c -- Useful allocation function/defintions
 *
 * Copyright (C)1999-2006 Mark Simpson <damned@world.std.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, you can either send email to this
 * program's maintainer or write to: The Free Software Foundation,
 * Inc.; 59 Temple Place, Suite 330; Boston, MA 02111-1307, USA.
 *
 */
#include "alloc.h"
#include <stdio.h>
#include <errno.h>

extern int tnef_error;

void*
xmalloc (size_t size)
{
    void *ptr = malloc (size);
    tnef_error = errno;
    return ptr;
}

/* xmallocs memory and clears it out */
void*
xcalloc (size_t num, size_t size)
{
    void *ptr = malloc(num * size);
    tnef_error = errno;
    if (ptr)
    {
        memset (ptr, '\0', (num * size));
    }
    return ptr;
}


