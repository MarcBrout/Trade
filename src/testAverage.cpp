//
// Created by brout_m on 14/03/17.
//

#include <vector>
#include <iostream>
#include "Curve.hh"


int main()
{
    std::vector<double> tab = {
            1234,
            5445,
            3423,
            5343,
            9875,
            6543,
            2342,
            1234,
            9876,
            7654,
            3456,
            1234,
            4321,
            2345,
            3456,
            6543,
            9000,
            1000,
            2000,
            1234,
            1234,
            1234,
            4322
    };

    trade::Curve curve;

    for (size_t i = 0; i < tab.size(); ++i)
    {
        curve.feed(tab[i]);
        std::cout << "------------------------- day " << i << " ---------------------------------------" << std::endl;
        std::cout << "avg(30) = " << curve.getAverage(30) << std::endl;
        std::cout << "avg(20) = " << curve.getAverage(20) << std::endl;
        std::cout << "avg(10) = " << curve.getAverage(10) << std::endl;
        std::cout << "avg(5) = " << curve.getAverage(5) << std::endl;
        std::cout << std::endl;
    }
    return (0);
}
