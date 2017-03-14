//
// Created by brout_m on 11/03/17.
//

#include <iostream>
#include "Com.hh"

int main()
{
    trade::Com com;
    double value;
    double capital;
    double totalDay;

    capital = com.get();
    totalDay = com.get();
    while ((value = com.get()) >= 0)
    {
        com.put("wait");
    }
    return (0);
}