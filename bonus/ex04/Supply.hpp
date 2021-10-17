/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD08-clement.muth
** File description:
** Supply
*/

#ifndef SUPPLY_HPP_
#define SUPPLY_HPP_

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Droid.hpp"

enum Types
{
    IRON,
    SILICON,
    WRECK
};

class Supply {
    public:
        Supply(Types type, size_t amount) noexcept;
        Supply(Types type, size_t amount, Droid **droids) noexcept;
        ~Supply() = default;

        Droid *operator*()
    private:
        Types _type;
        size_t _amount;
        std::vector<Droid **> _wrecks;
        size_t _index;
};

#endif /* !SUPPLY_HPP_ */