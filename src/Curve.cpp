//
// Created by brout_m on 11/03/17.
//

#include "Curve.hh"

double trade::Curve::getAverage(size_t period) {

}

void trade::Curve::feed(double value) {
    values.push_front(value);

    for(std::map<size_t, double>::iterator it = averages.begin();
        it != averages.end(); ++it)
    {
        updateAverage(it->first, it->second);
    }
}

void trade::Curve::updateAverage(size_t period, double &average) {
    
}
