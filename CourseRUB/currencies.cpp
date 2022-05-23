#include <iostream>
#include "currencies.h"

const std::string Currencies::curr_names[Currencies::curr_size]{ "USD/RUB", "EUR/RUB", "GBP/RUB", "CNY/RUB", "JPY/RUB", "CHF/RUB" };

 Currencies::Currencies()
{
    for (size_t itter = 0; itter < curr_size; ++itter)
    {
        std::string curr_name = curr_names[itter];
        std::string curr_bid;

        tree<htmlcxx::HTML::Node>::iterator it = dom.begin();
        tree<htmlcxx::HTML::Node>::iterator end = dom.end();

        bool curr_check = 1;
        if (curr_name == "USD/RUB" || curr_name == "EUR/RUB")
            curr_check = 0;

        for (; it != end; ++it)
        {
            if (it->tagName() == curr_name && curr_check == 1)
            {
                it += 6;
                curr_bid = it->tagName();
                if (curr_bid[1] == ',') curr_bid = "0" + curr_bid;
                curr_bid.resize(7);
                break;
            }
            if (it->tagName() == curr_name && curr_check == 0)
                curr_check = 1;
        }

        curr_bids[itter] = curr_bid;
    }
}

std::string Currencies::getCurr(std::string bit_name) const
{
    for (size_t itter = 0; itter < curr_size; ++itter)
    {
        if (bit_name == curr_names[itter])
        return curr_bids[itter];
    }
    return "ERROR";
}