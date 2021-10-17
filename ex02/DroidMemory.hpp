/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD08-clement.muth
** File description:
** droidMemory
*/

#ifndef DROIDMEMORY_HPP_
#define DROIDMEMORY_HPP_

#include <iostream>
#include <string>
#include <fstream>

#define ADD_OPERATOR ({ memory._exp = exp; memory._fingerPrint = exp; })
#define XOR(x, y) ((x)^(y))

class DroidMemory
{
    public:
        DroidMemory();
        ~DroidMemory() noexcept = default;

        size_t getExp() const noexcept;
        size_t getFinderPrint() const noexcept;
        void setFingerPrint(size_t fingerPrint) noexcept;
        void setXp(size_t exp) noexcept;
        void addExp(size_t exp) noexcept;
        DroidMemory const& operator>>(DroidMemory& memory) const noexcept;
        DroidMemory& operator+(DroidMemory const& memory) const noexcept;
        DroidMemory& operator+(size_t exp) const noexcept;
        DroidMemory& operator+=(DroidMemory const& memory) noexcept;
        DroidMemory& operator+=(size_t exp) noexcept;
        DroidMemory& operator<<(DroidMemory const& memory) noexcept;

        bool operator!=(DroidMemory const& memory) const noexcept;
        bool operator<(DroidMemory const& memory) const noexcept;
        bool operator<(size_t memory) const noexcept;
        bool operator<=(DroidMemory const& memory) const noexcept;
        bool operator<=(size_t memory) const noexcept;
        bool operator==(DroidMemory const& memory) const noexcept;
        bool operator>(DroidMemory const& memory) const noexcept;
        bool operator>(size_t memory) const noexcept;
        bool operator>=(DroidMemory const& memory) const noexcept;
        bool operator>=(size_t memory) const noexcept;
    private:
        static void xorAdd(DroidMemory &ptr1, DroidMemory const& ptr2, DroidMemory const& ptr3) noexcept;
        size_t _fingerPrint;
        size_t _exp;
};

std::ostream& operator<<(std::ostream& stream, DroidMemory const& memory) noexcept;

#endif /* !DROIDMEMORY_HPP_ */