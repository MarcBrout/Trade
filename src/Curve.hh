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
        ~Curve(){};
        double getAverage(size_t period);
        void feed(double value);

    private:
        std::map<size_t, double > averages;
        std::deque<double> values;

    private:
        void updateAverage(size_t period, double &average);
    };
}

#endif //TRADE_CURVE_HH
