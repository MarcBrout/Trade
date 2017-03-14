//
// Created by brout_m on 11/03/17.
//

#ifndef TRADE_CURVE_HH
#define TRADE_CURVE_HH

#include <map>
#include <deque>
#include "ICurve.hh"

namespace trade
{
    class Curve : public ICurve
    {
    public:
        typedef std::map<size_t, double> avg_t;

    public:
        ~Curve(){};
        double getAverage(size_t period);
        void feed(double value);

    private:
        avg_t averages;
        std::deque<double> values;

    private:
        double updateAverage(size_t period);
    };
}

#endif //TRADE_CURVE_HH
