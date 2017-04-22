//
// Created by brout_m on 11/03/17.
//

#include <iostream>
#include <fstream>
#include "Com.hh"
#include "Curve.hh"
#include "Core.hpp"

int main()
{
    trade::Com com;
    trade::Curve curve;
    size_t moyMax;
    size_t moyMin;
    double value;
    double capital;
    int totalDay;

    capital = com.get();
    totalDay = static_cast<int>(com.get());
    trade::Core core(capital, totalDay);
    moyMax = core.moyMax();
    moyMin = core.moyMin();
    while ((value = com.get()) >= 0)
    {
        curve.feed(value);
        core.feedValue(value);
        core.feedAverage(curve.getAverage(9));
        core.feedAverageMax(curve.getAverage(moyMax));
        core.feedAverageMin(curve.getAverage(moyMin));
        com.put(core.calc());
    }
    return (0);
}