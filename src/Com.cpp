//
// Created by brout_m on 11/03/17.
//

#include <iostream>
#include <algorithm>
#include "Com.hh"

double trade::Com::get() const {
    std::string input;

    std::cin >> input;
    std::cin.ignore();

    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    if (!input.compare("--end--"))
        return (-1);
    return (std::stod(input));
}

void trade::Com::put(std::string const &string) const {
    std::cout << string << std::endl;
}
