/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD08-clement.muth
** File description:
** Droid
*/

#include "Droid.hpp"

Droid::Droid(std::string id) noexcept :
    _attack(25), _toughness(15), _energy(50), _id(id),
    _status(new std::string("Standing by")), _battleData(new DroidMemory())
{
    std::cout << "Droid '" + _id + "' " + "Activated" << std::endl;
}

Droid::Droid(const Droid& droid) noexcept :
    _attack(droid._attack), _toughness(droid._toughness), _energy(droid._energy),
    _id(droid._id), _status(new std::string((droid._status) ? (*(droid._status)) : "Standing by"))
{
    std::cout << "Droid '" + _id + "' " + "Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    if (_status) delete _status;
    std::cout << "Droid '" + _id + "' " + "Destroyed" << std::endl;
}

std::string Droid::getId() const noexcept
{
    return (_id);
}

std::string *Droid::getStatus() const noexcept
{
    return (_status);
}

size_t Droid::getAttack() const noexcept
{
    return (_attack);
}

size_t Droid::getEnergy() const noexcept
{
    return (_energy);
}

size_t Droid::getToughness() const noexcept
{
    return (_toughness);
}

DroidMemory *Droid::getBattleData() const noexcept
{
    return (_battleData);
}

void Droid::setEnergy(size_t energy) noexcept
{
    this->_energy = (energy > 100) ? 100 : energy;
}

void Droid::setId(std::string id) noexcept
{
    this->_id = id;
}

void Droid::setStatus(std::string *status) noexcept
{
    if (this->_status) delete this->_status;
    this->_status = status;
}

bool Droid::operator !=(Droid const& droid) const noexcept
{
    return !(*this == droid);
}

bool Droid::operator ==(Droid const& droid) const noexcept
{
    bool isEqual = droid._attack == _attack && droid._energy == _energy &&
    droid._id == _id && *(droid._status) == *_status && droid._toughness == _toughness;

    return (isEqual);
}

void Droid::setBattleData(DroidMemory *memory) noexcept
{
    delete _battleData;
    _battleData = memory;
}

Droid& Droid::operator =(Droid const& droid) noexcept
{
    _id = droid._id;
    _energy = droid._energy;
    delete _status;
    _status = new std::string(*droid._status);
    return (*this);
}

Droid& Droid::operator<<(size_t& energy) noexcept
{
    int tmp = 0;

    if (100 > this->_energy) TAKE_ENERGY(tmp, this, energy);
    return (*this);
}

std::ostream& operator<<(std::ostream& stream, Droid const& droid) noexcept
{
    return (stream << "Droid '" + droid.getId() << "', " << (*(droid.getStatus())) << ", " << droid.getEnergy());
}