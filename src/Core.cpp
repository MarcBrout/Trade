//
// Created by duhieu_b on 14/03/17.
//

#include "Core.hpp"

#include <iostream>
#include <sstream>

const std::string trade::Core::calc()
{
    size_t nbAction;
    std::string nbstr;
    std::stringstream ss;

    nbAction = determineNbAction();
    ss << nbAction;
    nbstr = ss.str();
    if (getAverageMax == getAverageMin || !nbAction)
        return "wait";
    else if (getAverageMin < getAverageMax)
    {
        if (isSell)
            return "wait";
        isSell = true;
        isBuy = false;
        Capital += nbAction * curValue - ((nbAction * curValue * 0.15) / 100.0);
        return "sell " + nbstr;
    }
    else
    {
        if (isBuy)
            return "wait";
        isSell = false;
        isBuy = true;
        Capital -= nbAction * curValue + ((nbAction * curValue * 0.15) / 100.0);
        return "buy " + nbstr;
    }
}

trade::Core::Core()
{
}

trade::Core::Core(double capital, int dayMAx) : Capital(capital), DayMax(dayMAx)
{
    isSell = false;
    isBuy = false;
}

void trade::Core::feedValue(double value)
{
    curValue = value;
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
    return (static_cast<size_t>((DayMax / 10) * 3) <= 30) ? static_cast<size_t>((DayMax / 10) * 3) : 30;
}

size_t trade::Core::moyMin()
{
    return (static_cast<size_t>(DayMax / 10) <= 10) ? static_cast<size_t>(DayMax / 10) : 10;
}

size_t trade::Core::determineNbAction()
{
    size_t nb;

    if (curValue > Capital + ((curValue * 0.15) / 100.0))
    {
        return (0);
    }
    else if (curValue > ((Capital / 10.0) * 2.0) + ((2.0 * curValue * 0.15) / 100.0))
    {
        return (1);
    }
    else
    {
        nb = 1;
        while (curValue * nb < ((Capital / 10.0) * 2.0) + ((nb * curValue * 0.15) / 100.0))
            nb++;
        return (nb);
    }
}
