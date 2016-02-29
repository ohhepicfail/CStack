#include <stdio.h>
#include "CStack.h"
#include "CFuncMonitor.h"


#define $       CFuncMonitor monitor (__FILE__, __LINE__, __PRETTY_FUNCTION__);

int main ()
{
    $
    CStack cs;
    printf ("%lu\n", cs.size ());
    try
    {
        cs.push_back (10);
    }
    catch (...)
    {
        fprintf (stderr, "elem doesn't added\n");
    }

    try
    {
        printf ("%d\n", cs.pop_back ());
        printf ("%d\n", cs.pop_back ());
    }
    catch (...)
    {
        fprintf (stderr, "I pop too much!\n");
    }
    return 0;
}