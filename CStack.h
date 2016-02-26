//
// Created by epicfail on 26.02.16.
//

#ifndef CSTACK_CSTACK_H
#define CSTACK_CSTACK_H

class CStack
{
private:
    int *	data_;
    size_t	size_;
    size_t	cur_;
    size_t	resize_();
public:
    CStack	();
    ~CStack	();
    CStack	(const CStack &);
    const CStack & 	operator = 	(const CStack &);
    size_t	size	    ();
    bool    empty       ();
    bool	push_back   (int elem);
    int		pop_back	();
    bool	ok	();
};


#endif //CSTACK_CSTACK_H
