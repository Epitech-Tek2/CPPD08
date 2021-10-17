/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD08-clement.muth
** File description:
** testEx00GetterSetter
*/

#include <iostream>
#include <string>
#include <fstream>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../ex00/Droid.hpp"

Test(test_get_const_attack, ex00test)
{
    const Droid d{"1"};
    cr_assert_eq(d.getAttack(), 25);
}

Test(test_get_const_energy, ex00test)
{
    const Droid d{"1"};
    cr_assert_eq(d.getEnergy(), 50);
}

Test(test_get_const_status, ex00test)
{
    const Droid d{"1"};
    cr_assert_str_eq((*(d.getStatus())).data(), "Standing by");
}

Test(test_get_const_toughness, ex00test)
{
    const Droid d{"1"};
    cr_assert_eq(d.getToughness(), 15);
}

// No const

Test(test_get_attack, ex00test)
{
    const Droid d2{"1"};
    cr_assert_eq(d2.getAttack(), 25);
}

Test(test_get_energy, ex00test)
{
    const Droid d2{"1"};
    cr_assert_eq(d2.getEnergy(), 50);
}

Test(test_get_status, ex00test)
{
    const Droid d2{"1"};
    cr_assert_str_eq((*(d2.getStatus())).data(), "Standing by");
}

Test(test_get_toughness, ex00test)
{
    const Droid d2{"1"};
    cr_assert_eq(d2.getToughness(), 15);
}

// setter

Test(test_set_const_energy, ex00test)
{
    Droid d{"1"};
    d.setEnergy(15);
    cr_assert_eq(d.getEnergy(), 15);
}