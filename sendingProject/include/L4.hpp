#ifndef L4_HPP
# define L4_HPP

#include "Cache.hpp"

class L4 : public Cache{
    
    public:
        L4(void);
        L4(int size);
        ~L4(void);
        
};
#endif 