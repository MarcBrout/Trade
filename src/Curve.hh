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
        typedef std::pair<size_t const, double> pair_t;
        typedef std::pair<size_t const, avg_t> pairExpo_t;
        typedef std::map<size_t, avg_t > expo_t;

    public:
        ~Curve(){};
        Curve(){};
        double getAverage(size_t period);
        double getRSI(size_t period);
        double getExponential(size_t period, size_t pow);
        void feed(double value);

    private:
        avg_t averages;
        avg_t rsi;
        expo_t exponentials;
        std::deque<double> values;

    private:
        double updateAverage(size_t period);
        double updateRSI(size_t period);
        double updateExponential(size_t period, size_t pow);
        Curve(Curve const& curve) = delete;
        Curve &operator=(Curve const&  curve) = delete;
    };
}

#endif //TRADE_CURVE_HH
