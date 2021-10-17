/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD08-clement.muth
** File description:
** droidMemory
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory() : _exp(0)
{
    _fingerPrint = random();
}

size_t DroidMemory::getExp() const noexcept
{
    return (_exp);
}

size_t DroidMemory::getFinderPrint() const noexcept
{
    return (_fingerPrint);
}

void DroidMemory::setXp(size_t exp) noexcept
{
    this->_exp = exp;
}

void DroidMemory::setFingerPrint(size_t fingerPrint) noexcept
{
    this->_fingerPrint = fingerPrint;
}

DroidMemory const& DroidMemory::operator>>(DroidMemory& memory) const noexcept
{
    DroidMemory::xorAdd(memory, *this, memory);
    return (*this);
}

DroidMemory& DroidMemory::operator+(DroidMemory const& memory) const noexcept
{
    DroidMemory *tmp = new DroidMemory();

    DroidMemory::xorAdd(*tmp, *this, memory);
    return (*tmp);
}

DroidMemory& DroidMemory::operator+(size_t exp) const noexcept
{
    DroidMemory *tmp = new DroidMemory();

    tmp->_exp = this->_exp;
    tmp->_fingerPrint = this->_fingerPrint;
    tmp->_exp += exp;
    tmp->_fingerPrint ^= exp;
    return (*tmp);
}

DroidMemory& DroidMemory::operator+=(size_t exp) noexcept
{
    this->_exp += exp;
    this->_fingerPrint ^= exp;
    return (*this);
}

DroidMemory& DroidMemory::operator+=(DroidMemory const& memory) noexcept
{
    this->_exp += memory._exp;
    this->_fingerPrint ^= memory._fingerPrint;
    return (*this);
}

DroidMemory& DroidMemory::operator<<(DroidMemory const& memory) noexcept
{
    this->_exp += memory._exp;
    this->_fingerPrint ^= memory._fingerPrint;
    return (*this);
}

std::ostream& operator<<(std::ostream& stream, DroidMemory const& memory) noexcept
{
    return stream << "DroidMemory '" << memory.getFinderPrint() << "', " << memory.getExp();
}

void DroidMemory::xorAdd(DroidMemory &ptr1, DroidMemory const& ptr2, DroidMemory const& ptr3) noexcept
{
    ptr1._exp = ptr2._exp + ptr3._exp;
    ptr1._fingerPrint = XOR(ptr2._fingerPrint, ptr3._fingerPrint);
}