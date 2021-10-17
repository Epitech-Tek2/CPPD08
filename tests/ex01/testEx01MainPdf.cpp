/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD08-clement.muth
** File description:
** testEx01MainPdf
*/

#include <iostream>
#include <string>
#include <fstream>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../ex01/DroidMemory.hpp"
#include "../../ex01/Droid.hpp"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

static void testMainEx1(){DroidMemory mem1;mem1+=42;DroidMemory mem2=mem1;
std::cout<<mem1<<std::endl;DroidMemory mem3;mem3<<mem1;mem3>>mem1;mem3<<mem1;
std::cout<<mem3<<std::endl;std::cout<<mem1<<std::endl;}
Test(test_main_ex1, test_ex01, .init=redirect_all_stdout) {
    testMainEx1();
    cr_assert_stdout_eq_str("DroidMemory ‘1804289357’, 42\n"\
                            "DroidMemory ‘1804289357’, 126\n"\
                            "DroidMemory ‘846930886’, 84\n");
}