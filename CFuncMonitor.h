//
// Created by epicfail on 25.02.16.
//

#ifndef CFUNCMONITOR_CFUNCMONITOR_H
#define CFUNCMONITOR_CFUNCMONITOR_H


#include <stdio.h>

class CFuncMonitor
{
public:
    CFuncMonitor (const char * file, int line, const char * func);
    ~CFuncMonitor ();
    inline bool is_log_file ();
private:
    static int indent__;
    static FILE * log_file__;
    int set_log_file (const char * filename);
    int close_log_file ();
};


#endif //CFUNCMONITOR_CFUNCMONITOR_H
