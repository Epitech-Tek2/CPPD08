/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD08-clement.muth
** File description:
** Droid
*/

#ifndef DROID_HPP_
#define DROID_HPP_

#include <iostream>
#include <string>
#include <fstream>

#define TAKE_ENERGY(tmp, this, energy) ({tmp = std::min(100 - this->_energy, energy); this->_energy += tmp; energy -= tmp;})

class Droid
{
    public:
        Droid(std::string id = "") noexcept;
        Droid(const Droid& droid) noexcept;
        ~Droid();

        bool operator!=(Droid const& droid) const noexcept;
        bool operator==(Droid const& droid) const noexcept;

        std::string getId() const noexcept;
        std::string *getStatus() const noexcept;

        Droid& operator<<(size_t& energy) noexcept;
        Droid& operator=(Droid const& droid) noexcept;

        size_t getAttack() const noexcept;
        size_t getEnergy() const noexcept;
        size_t getToughness() const noexcept;

        void setEnergy(size_t energy) noexcept;
        void setId(std::string id) noexcept;
        void setStatus(std::string *status) noexcept;
    private:
        const size_t _attack;
        const size_t _toughness;
        size_t _energy;
        std::string _id;
        std::string *_status;
};

std::ostream& operator<<(std::ostream& stream, Droid const& droid) noexcept;

#endif /* !DROID_HPP_ */