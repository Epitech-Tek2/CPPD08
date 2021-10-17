/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD08-clement.muth
** File description:
** Carrier
*/

#ifndef CARRIER_HPP_
#define CARRIER_HPP_

#include <iostream>
#include <string>
#include <fstream>
#include "Droid.hpp"

#define ABS_COS(x, y) ((std::abs(x) + std::abs(y)) * (10 + getNbDroids()))

class Carrier
{
    public:
        Carrier(std::string id) noexcept;
        ~Carrier();

        size_t getAttack() const noexcept;
        size_t getEnergy() const noexcept;
        size_t getNbDroids() const noexcept;
        size_t getSpeed() const noexcept;
        size_t getToughness() const noexcept;
        std::string getId() const noexcept;

        void setEnergy(size_t energy) noexcept;
        void setId(std::string id) noexcept;

        bool operator()(int x, int y) noexcept;
        Carrier & operator~() noexcept;
        Carrier &operator<<(Droid *&droid) noexcept;
        Carrier &operator<<(size_t &energy) noexcept;
        Carrier &operator>>(Droid *&droid) noexcept;
        Droid *&operator[](int position) const noexcept;
    private:
        std::string _id;
        size_t _energy;
        size_t const _attack;
        size_t const _toughness;
        Droid **_droids;
};

std::ostream& operator<<(std::ostream& stream, Carrier const& carrier) noexcept;

#endif /* !CARRIER_HPP_ */