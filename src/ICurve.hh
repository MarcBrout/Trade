//
// Created by brout_m on 11/03/17.
//

#ifndef TRADE_ICURVE_HH
#define TRADE_ICURVE_HH

#include <cstddef>

namespace trade
{
    class ICurve
    {
    public:
        virtual ~ICurve(){};
        virtual double getAverage(size_t period) = 0;
        virtual void feed(double value) = 0;
    };
}

#endif //TRADE_ICURVE_HH
