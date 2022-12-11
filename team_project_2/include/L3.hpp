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
        void setLine(set** line, int f_i, int f_j, int t_i, int t_j);
    
};
#endif 