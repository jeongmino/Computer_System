#ifndef L3_HPP
# define L3_HPP

#include "Cache.hpp"

class L3 : public Cache{
    
    private :
        set** line_;

    public:
        L3(void);
        L3(int size);
        ~L3(void);
    
    public :
        set** getLine(void);    
        
};
#endif 