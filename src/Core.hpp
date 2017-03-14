//
// Created by duhieu_b on 14/03/17.
//

#ifndef TRADE_CORE_HPP
#define TRADE_CORE_HPP

#include "ICore.hh"

namespace trade
{
    class Core : public ICore
    {
    private:
        double Capital;
        int DayMax;
        int dayCount;
        size_t nbAction;
        double getAverageMax;
        double getAverageMin;
        double curValue;
        Core() = delete;

        size_t determineNbAction();
    public:
        Core(double capital, int dayMAx);
        const std::string calc();
        void feedValue(double value);
        void feedAverageMax(double value);
        void feedAverageMin(double value);
        size_t moyMax();
        size_t moyMin();
    };
}


#endif //TRADE_CORE_HPP
