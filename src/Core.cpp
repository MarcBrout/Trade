//
// Created by duhieu_b on 14/03/17.
//

#include "Core.hpp"

#include <iostream>
#include <sstream>

const std::string trade::Core::calc()
{
    std::string nbstr;
    std::stringstream ss;
    size_t newAction;

    if (dayCount == DayMax)
    {
        if (nbAction)
        {
            ss << nbAction;
            nbstr = ss.str();
            Capital += nbAction * curValue - ((nbAction * curValue * 0.15) / 100.0);
            return "sell " + nbstr;
        }
        return "wait";
    }
    if (getAverageMax == getAverageMin)
        return "wait";
    else if (getAverageMin > getAverageMax || curValue < maxValue * (0.75 + (((dayLow > 20) ? 20.0 :
                                                                             static_cast<double>(dayLow)) / 100.0)))
    {
        dayLow++;
        if (!nbAction)
            return "wait";
        ss << nbAction;
        nbstr = ss.str();
        Capital += nbAction * curValue - ((nbAction * curValue * 0.15) / 100.0);
        nbAction = 0;
        maxValue = 0;
        return "sell " + nbstr;
    }
    else
    {
        newAction = determineNbAction();
        dayLow -= 3;
        if (!newAction)
            return "wait";
        nbAction += newAction;
        ss << newAction;
        nbstr = ss.str();
        Capital -= newAction * curValue + ((newAction * curValue * 0.15) / 100.0);
        return "buy " + nbstr;
    }
}

trade::Core::Core(double capital, int dayMAx) : Capital(capital), DayMax(dayMAx)
{
    nbAction = 0;
    dayCount = 0;
    maxValue = 0;
    dayLow = 0;
}

void trade::Core::feedValue(double value)
{
    curValue = value;
    if (curValue > maxValue)
        maxValue = curValue;
    dayCount++;
}

void trade::Core::feedAverageMax(double value)
{
    getAverageMax = value;
}

void trade::Core::feedAverageMin(double value)
{
    getAverageMin = value;
}

size_t trade::Core::moyMax()
{
    return (static_cast<size_t>((DayMax / 10) * 3) <= 60) ? static_cast<size_t>((DayMax / 10) * 3) : 60;
}

size_t trade::Core::moyMin()
{
    return (static_cast<size_t>(DayMax / 10) <= 20) ? static_cast<size_t>(DayMax / 10) : 20;
}

size_t trade::Core::determineNbAction()
{
    size_t nb;

    if (curValue > Capital - ((curValue * 0.15) / 100.0))
    {
        return (0);
    }
    else
    {
        nb = 1;
        while (curValue * nb < ((Capital / 10.0) * 6.0) - ((nb * curValue * 0.15) / 100.0))
            nb++;
        if ((Capital - ((nb + 1) * curValue + (((nb + 1) * curValue * 0.15) / 100.0))) <= 0)
            return (0);
        return (nb);
    }
}

void trade::Core::feedAverage(double value)
{
    getAverage = value;
}
