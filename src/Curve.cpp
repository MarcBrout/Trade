//
// Created by brout_m on 11/03/17.
//

#include "Curve.hh"

double trade::Curve::getAverage(size_t period) {
    avg_t::iterator it;

    if ((it = averages.find(period)) == averages.end())
        averages[period] = updateAverage(period);
    return (it->second);
}

void trade::Curve::feed(double value) {
    values.push_front(value);

    for(avg_t::iterator it = averages.begin();
        it != averages.end(); ++it)
    {
        it->second =  updateAverage(it->first);
    }
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
