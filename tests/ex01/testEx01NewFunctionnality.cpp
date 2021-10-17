/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD08-clement.muth
** File description:
** testEx01Operator
*/

#include <iostream>
#include <string>
#include <fstream>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../ex01/Droid.hpp"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

static void testEx1Function1(){const Droid mem1{"test"};}
Test(test_function1_ex1, test_ex01, .init=redirect_all_stdout) {
    testEx1Function1();
    cr_assert_stdout_eq_str("Droid 'test' Activated\n"\
                            "Droid 'test' Destroyed\n");
}