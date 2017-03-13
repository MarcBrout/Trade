//
// Created by brout_m on 11/03/17.
//

#ifndef TRADE_COM_HH
#define TRADE_COM_HH

#include "ICom.hh"

namespace trade
{
    class Com : public ICom
    {
    public:
        double get() const;
        void put(std::string const& string) const;
    };
}

#endif //TRADE_COM_HH
