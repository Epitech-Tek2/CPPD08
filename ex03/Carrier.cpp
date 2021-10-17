/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD08-clement.muth
** File description:
** Carrier
*/

#include "Carrier.hpp"

Carrier::Carrier(std::string id) noexcept : _id(id), _energy(300),
    _attack(100), _toughness(90), _droids(new Droid*[5])
{
    for (int i = 0; i < 5; i++) _droids[i] = NULL;
}

Carrier::~Carrier()
{
    for (int i = 0; i < 5; i++)
        if (_droids[i]) delete _droids[i];
}

size_t Carrier::getAttack() const noexcept
{
    return (_attack);
}

size_t Carrier::getEnergy() const noexcept
{
    return (_energy);
}

size_t Carrier::getNbDroids() const noexcept
{
    int nDroid = 0;

    for (int i = 0; i < 5; i++)
        nDroid += _droids[i] ?  1 : 0;
    return ((size_t)nDroid);
}

std::string Carrier::getId() const noexcept
{
    return (_id);
}

size_t Carrier::getSpeed() const noexcept
{
    int n = getNbDroids();

    return ((size_t)((n) ? 100 - n * 10 : 0));
}

size_t Carrier::getToughness() const noexcept
{
    return (_toughness);
}

void Carrier::setEnergy(size_t energy) noexcept
{
    this->_energy = energy;
}

void Carrier::setId(std::string id) noexcept
{
    this->_id = id;
}

Droid *&Carrier::operator[](int position) const noexcept
{
    return _droids[position];
}

bool Carrier::operator()(int x, int y) noexcept
{
    size_t i = ABS_COS(x, y);

    if (i < _energy) {
        _energy -= i;
        if (0 != getSpeed()) return (true);
    }
    return (false);
}

Carrier &Carrier::operator<<(size_t& energy) noexcept
{
    int tmp = 0;

    if (600 > this->_energy) TAKE_ENERGY_CAR(tmp, this, energy);
    return (*this);
}

Carrier &Carrier::operator<<(Droid *&droid) noexcept
{
    for (int i = 0; i < 5; i++)
        if (!_droids[i]) {
            _droids[i] = droid;
            droid = nullptr;
            return (*this);
        }
    return (*this);
}

Carrier &Carrier::operator>>(Droid *&droid) noexcept
{
    for (int i = 0; i < 5; i++)
        if (_droids[i]) {
            droid = _droids[i];
            _droids[i] = nullptr;
            return (*this);
        }
    return (*this);
}

Carrier &Carrier::operator~() noexcept
{
    return (*this);
}

std::ostream& operator<<(std::ostream& stream, Carrier const& carrier) noexcept
{
    stream << "Carrier '" << carrier.getId() << "' Droid(s) on-board:" << std::endl;
    for (int i = 0; i < 5; i++) {
        stream << "[" << i << "] : ";
        carrier[i] ? stream << *carrier[i] : stream << "Free";
        stream << std::endl;
    }
    stream << "Speed : " << carrier.getSpeed() << ", Energy " << carrier.getEnergy();
    return (stream);
}