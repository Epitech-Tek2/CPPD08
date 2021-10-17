/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD08-clement.muth
** File description:
** testEx00MainPdf
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

static void testMain(){Droid d;Droid d1("Avenger");size_t Durasel=200;
std::cout<<d<<std::endl;std::cout<<d1<<std::endl;d=d1;d.setStatus(new std::string("Kill Kill Kill!"));
d<<Durasel;std::cout<<d<<"--"<<Durasel<<std::endl;Droid d2=d;d.setId("Rex");std::cout<<(d2!=d)<<std::endl;}
Test(test_main, test_ex00, .init=redirect_all_stdout) {
    testMain();
    cr_assert_stdout_eq_str("Droid '' Activated\n"\
                            "Droid 'Avenger' Activated\n"\
                            "Droid '', Standing by, 50\n"\
                            "Droid 'Avenger', Standing by, 50\n"\
                            "Droid 'Avenger', Kill Kill Kill!, 100--150\n"\
                            "Droid 'Avenger' Activated, Memory Dumped\n"\
                            "1\n"\
                            "Droid 'Avenger' Destroyed\n"\
                            "Droid 'Avenger' Destroyed\n"\
                            "Droid 'Rex' Destroyed\n");
}