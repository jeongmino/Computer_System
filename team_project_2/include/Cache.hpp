#ifndef CACHE_HPP
# define CACHE_HPP

#include <iostream>
#include "data.h"

class Cache{

    protected :
        int size_;
        // temp_data *temp_data_;
        set *set_;
        int hit_;
        int miss_;
        int acTime_;
        int acNum_;
        float hitRatio_;
        
    
    public :
        static int call_num_;
        static float total_hit_ratio_; // l1 + l2 + l3 의 hit ratio
    public :
        Cache(void);
        Cache(int size);
        virtual ~Cache(void);
    
    public :
        int getSize(void) const;
        int getHit(void) const;
        int getMiss(void) const;
        int getAcTime(void) const;
        float getHitRatio(void) const;
        int getAcNum(void) const;
        
        set* getSet(void);
        void setSet(set* set, int from, int to);
        void setHit(int hit);
        void setMiss(int miss);
        void setAcTime(int acTime);
        void setAcNum(int acNum);
        void setHitRatio(float hit_ratio);
};

# endif 