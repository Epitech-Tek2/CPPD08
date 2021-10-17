/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD08-clement.muth
** File description:
** Supply
*/

#include "Supply.hpp"

Supply::Supply(Types type, size_t amount, Droid **droids) noexcept : _type(type),
    _amount(amount), _index(0) {}

Supply::Supply(Types type, size_t amount) noexcept : _type(type),
    _amount(amount), _index(0) {}

