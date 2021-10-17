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

void DroidMemory::addExp(size_t exp) noexcept
{
    this->_exp += exp;
}

DroidMemory const& DroidMemory::operator>>(DroidMemory& memory) const noexcept
{
    memory._exp = this->_exp + memory._exp;
    memory._fingerPrint = XOR(this->_fingerPrint, memory._fingerPrint);
    return (*this);
}

DroidMemory& DroidMemory::operator+(DroidMemory const& memory) const noexcept
{
    DroidMemory *tmp = new DroidMemory();

    FUSION_TMP;
    return (*tmp);
}

DroidMemory& DroidMemory::operator+(size_t exp) const noexcept
{
    DroidMemory memory;
    DroidMemory *tmp = new DroidMemory();

    ADD_OPERATOR;
    FUSION_TMP;
    return (*tmp);
}

DroidMemory& DroidMemory::operator+=(size_t exp) noexcept
{
    DroidMemory memory;

    ADD_OPERATOR;
    FUSION_THIS;
    return (*this);
}

DroidMemory& DroidMemory::operator+=(DroidMemory const& memory) noexcept
{
    FUSION_THIS;
    return (*this);
}

DroidMemory& DroidMemory::operator<<(DroidMemory const& memory) noexcept
{
    FUSION_THIS;
    return (*this);
}

bool DroidMemory::operator==(DroidMemory const& memory) const noexcept
{
    return (_exp == memory._exp && _fingerPrint == memory._fingerPrint);
}

bool DroidMemory::operator!=(DroidMemory const& memory) const noexcept
{
    return !(*this == memory);
}

bool DroidMemory::operator<(DroidMemory const& memory) const noexcept
{
    return (_exp < memory._exp);
}

bool DroidMemory::operator<=(DroidMemory const& memory) const noexcept
{
    return (_exp <= memory._exp);
}

bool DroidMemory::operator>(DroidMemory const& memory) const noexcept
{
    return (_exp > memory._exp);
}

bool DroidMemory::operator>=(DroidMemory const& memory) const noexcept
{
    return (_exp >= memory._exp);
}

bool DroidMemory::operator<(size_t memory) const noexcept
{
    return (_exp < memory);
}

bool DroidMemory::operator<=(size_t memory) const noexcept
{
    return (_exp <= memory);
}

bool DroidMemory::operator>(size_t memory) const noexcept
{
    return (_exp > memory);
}

bool DroidMemory::operator>=(size_t memory) const noexcept
{
    return (_exp >= memory);
}

std::ostream& operator<<(std::ostream& stream, DroidMemory const& memory) noexcept
{
    return stream << "Droid Memory '" << memory.getFinderPrint() << "', " << memory.getExp();
}