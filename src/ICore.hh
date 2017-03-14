//
// Created by brout_m on 11/03/17.
//

#ifndef TRADE_ICORE_HH
#define TRADE_ICORE_HH

#include <string>

namespace trade
{
    class ICore
    {
    public:
        virtual ~ICore(){};
        virtual std::string const calc() = 0;
    };
}

#endif //TRADE_ICORE_HH
