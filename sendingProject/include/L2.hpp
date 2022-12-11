#ifndef L2_HPP
# define L2_HPP

#include "Cache.hpp"

class L2 : public Cache{
    
    public:
        L2(void);
        L2(int size);
        ~L2(void);
        
};
#endif 