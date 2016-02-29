#include <stdio.h>
#include <string.h>
#include "CFuncMonitor.h"

#define NTRY         3

int CFuncMonitor::indent__ = 0;
FILE * CFuncMonitor::log_file__ = NULL;

CFuncMonitor::CFuncMonitor (const char * file, int line, const char * func)
{
    for (int i = 0; !is_log_file () && i < NTRY; i++)
        set_log_file ("log.txt");
    if (is_log_file ())
    {
        char * slash = (char *) file;
        for (size_t i = strlen (file) - 1; i > 0; i--)
            if (file[i] == '/') {
                slash = (char *) &file[i];
                break;
            }
        for (int i = 0; i < indent__; i++)
            fprintf (log_file__, "    ");
        fprintf (log_file__, "entry %s %d %s\n", slash, line, func);
        fflush (log_file__);
    }
    else
        fprintf (stderr, "error opening file\n");
    indent__++;
}

CFuncMonitor::~CFuncMonitor ()
{
    indent__--;

    for (int i = 0; i < indent__; i++)
        fprintf (log_file__, "    ");
    fprintf (log_file__, "exit\n");
    if (!indent__)
    {
        fprintf (log_file__, "END!\n");
        close_log_file ();
    }
}

// return 1 if can't open file
int CFuncMonitor::set_log_file (const char * filename)
{
    log_file__ = fopen (filename, "wb");

    if (!CFuncMonitor::log_file__)
        return 1;
    else
        return 0;
}

int CFuncMonitor::close_log_file ()
{
    fclose (log_file__);

    return 0;
}

inline bool CFuncMonitor::is_log_file ()
{
    return (bool) log_file__;
}
