//
// Created by brout_m on 11/03/17.
//

#ifndef TRADE_ICOM_HH
# define TRADE_ICOM_HH

# include <string>

namespace trade
{
    class ICom
    {
    public:
        virtual ~ICom(){};
        virtual double get() const = 0;
        virtual void put(std::string const &cmd) const = 0;
    };
}
#endif //TRADE_ICOM_HH
