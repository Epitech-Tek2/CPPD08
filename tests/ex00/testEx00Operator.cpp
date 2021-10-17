/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD08-clement.muth
** File description:
** testEx00
*/

#include <iostream>
#include <string>
#include <fstream>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../ex00/Droid.hpp"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

void testConstDroidInitSimple(){const Droid d{"1"};d == d;}
Test(test_const_droid_init_simple, ex00test, .init=redirect_all_stdout)
{
    testConstDroidInitSimple();
    cr_assert_stdout_eq_str("Droid '1' Activated\nDroid '1' Destroyed\n");
}

void testDroidInitSimple(){Droid d{"1"};d == d;}
Test(test_droid_init_simple, ex00test, .init=redirect_all_stdout)
{
    testDroidInitSimple();
    cr_assert_stdout_eq_str("Droid '1' Activated\nDroid '1' Destroyed\n");
}

void testConstDroidOperatorAssign(){const Droid d{"1"}; const Droid d1 = d;}
Test(test_const_droid_operator_assign, ex00test, .init=redirect_all_stdout)
{
    testConstDroidOperatorAssign();
    cr_assert_stdout_eq_str("Droid '1' Activated\n" \
                            "Droid '1' Activated, Memory Dumped\n" \
                            "Droid '1' Destroyed\n" \
                            "Droid '1' Destroyed\n");
}

void testDroidOperatorAssign(){Droid d{"1"}; Droid d1 = d;}
Test(test_droid_operator_assign, ex00test, .init=redirect_all_stdout)
{
    testDroidOperatorAssign();
    cr_assert_stdout_eq_str("Droid '1' Activated\n" \
                            "Droid '1' Activated, Memory Dumped\n" \
                            "Droid '1' Destroyed\n" \
                            "Droid '1' Destroyed\n");
}

void testConstDroidOperatorNeq(){const Droid d{"1"};d!=d;}
Test(test_const_droid_operator_neq, ex00test, .init=redirect_all_stdout)
{
    testConstDroidOperatorNeq();
    cr_assert_stdout_eq_str("Droid '1' Activated\n" \
                            "Droid '1' Destroyed\n");
}

void testDroidOperatorNeq(){Droid d{"1"};d!=d;}
Test(test_droid_operator_neq, ex00test, .init=redirect_all_stdout)
{
    testDroidOperatorNeq();
    cr_assert_stdout_eq_str("Droid '1' Activated\n" \
                            "Droid '1' Destroyed\n");
}

void testConstDroidOperatorArrow(){const Droid d{"1"};std::cout << d << std::endl;}
Test(test_const_droid_operator_arrow, ex00test, .init=redirect_all_stdout)
{
    testConstDroidOperatorArrow();
    cr_assert_stdout_eq_str("Droid '1' Activated\n" \
                            "Droid '1', Standing by, 50\n" \
                            "Droid '1' Destroyed\n");
}

void testDroidOperatorArrow(){Droid d{"1"};std::cout << d << std::endl;}
Test(test_droid_operator_arrow, ex00test, .init=redirect_all_stdout)
{
    testDroidOperatorArrow();
    cr_assert_stdout_eq_str("Droid '1' Activated\n" \
                            "Droid '1', Standing by, 50\n" \
                            "Droid '1' Destroyed\n");
}