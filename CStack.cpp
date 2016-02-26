//
// Created by epicfail on 26.02.16.
//
#include <stdio.h>
#include <stdlib.h>
#include <typeinfo>
#include "CStack.h"


#define ASSERT		if ( ! (this->ok()))                                              		\
                    {                                                                       \
                        fprintf (stderr,    "\n\n********   ERROR   ********\n\n");         \
                        fprintf (stderr,    "ERROR:\t\t %s\n"                               \
                                            "In file:\t%s\n"                                \
                                            "In function:\t%s\n"                            \
                                            "Line:\t\t%d\n"                                 \
                                            , typeid(this).name(), __FILE__                 \
                                            , __PRETTY_FUNCTION__, __LINE__);    	        \
                        fprintf (stderr,    "\n\n***************************\n\n");         \
                        abort ();                                                           \
                    }

static size_t init_size = 2;

CStack::CStack ():
        data_	(new int[init_size]),
        size_	(init_size),
        cur_	(0)
{}

CStack::~CStack ()
{
    delete[] data_;
    data_ = NULL;
    size_ = 0xBADF00D;
    cur_  = 0xBADF00D;
}

size_t CStack::size ()
{
    ASSERT;
    return size_;
}

bool CStack::ok ()
{
    return this && this->data_ && cur_ <= size_;
}

//throw 0 if errors
size_t CStack::resize_()
{
    ASSERT;

    size_ *= 2;
    int * new_data = (int *) realloc (data_, size_ * sizeof (data_));

    if ( ! new_data)
    {
        size_ /= 2;
        size_ += 2;
        new_data = (int *) realloc (data_, size_ * sizeof (data_));
    }

    if ( ! new_data)
    {
        ASSERT;
        throw false;
    }
    else
    {
        data_ = new_data;

        ASSERT;
        return size_;
    }
}

// throw 0 if errors
bool CStack::push_back (int elem)
{
    ASSERT;

    if (cur_ == size_)
        if ( ! resize_ ())
            throw false;

    data_[cur_++] = elem;

    ASSERT;
    return true;
}

//throw 0 if stack is empty
int CStack::pop_back ()
{
    ASSERT;

    if (empty ())
        throw 0;

    int temp = data_[--cur_];

    ASSERT;
    return temp;
}

bool CStack::empty ()
{
    ASSERT;
    return ! (bool) cur_;
}
