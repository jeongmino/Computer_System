#ifndef CACHE_HPP
# define CACHE_HPP

#include <iostream>
#include "data.h"

class Cache{

    protected :
        int size_;
        // temp_data *temp_data_;
        set *set_;
    
    public :
        Cache(void);
        Cache(int size);
        virtual ~Cache(void);
    
    public :
        int getSize(void) const;
        // temp_data* getTempData(void);
        set* getSet(void);
};

# endif 