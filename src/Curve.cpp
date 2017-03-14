//
// Created by brout_m on 11/03/17.
//

#include <vector>
#include <algorithm>
#include "Curve.hh"

double trade::Curve::getAverage(size_t period) {
    if (averages.find(period) == averages.end())
        averages[period] = updateAverage(period);
    return averages[period];
}

double trade::Curve::getRSI(size_t period) {
    if (rsi.find(period) == rsi.end())
        rsi[period] = updateRSI(period);
    return rsi[period];
}

double trade::Curve::getExponential(size_t period, size_t pow) {
    expo_t::iterator it;

    if ((it = exponentials.find(period)) == exponentials.end())
    {
        exponentials[period] = {{pow, updateExponential(period, pow)}};
    }
    else
    {
        if (it->second.find(pow) == it->second.end())
            exponentials[period][pow] = updateExponential(period, pow);
    }

    return exponentials[period][pow];
}

void trade::Curve::feed(double value) {
    values.push_front(value);

    std::for_each(averages.begin(), averages.end(), [this](pair_t &avg){ avg.second = updateAverage(avg.first); });
    std::for_each(rsi.begin(), rsi.end(), [this](pair_t &_rsi){ _rsi.second = updateRSI(_rsi.first); });
    std::for_each(exponentials.begin(), exponentials.end(), [this](pairExpo_t &expo)
    {
        std::for_each(expo.second.begin(), expo.second.end(), [&expo, this](pair_t &exp) {
        exp.second = updateExponential(expo.first, exp.first);
    });
    });
}

double trade::Curve::updateAverage(size_t period) {
    double avg;
    double count;

    avg = count = 0;

    while (count < period && count < values.size())
    {
        avg += values[count];
        ++count;
    }
    return (avg / count);
}

double trade::Curve::updateRSI(size_t period) {
    std::vector<double> low;
    std::vector<double> high;
    double avg, highAvg, lowAvg;
    int count;

    count = 0;
    avg = getAverage(period);
    while (count < period && count < values.size())
    {
        if (values[count] >= avg)
            low.push_back(values[count]);
        else
            high.push_back(values[count]);
        ++count;
    }
    highAvg = lowAvg = 0;
    std::for_each(low.begin(), low.end(), [&lowAvg](double x){ lowAvg += x; });
    std::for_each(high.begin(), high.end(), [&highAvg](double x){ highAvg += x; });
    highAvg /= high.size();
    lowAvg /= low.size();
    return (100.0 - (100.0 / (1.0 + (highAvg / lowAvg))));
}

double trade::Curve::updateExponential(size_t period, size_t pow) {
    double avg;
    double count;

    avg = count = 0;
    while (count < period && count < values.size())
    {
        avg += values[count] * (pow / (count + 1));
        ++count;
    }
    return (avg / count);
}
