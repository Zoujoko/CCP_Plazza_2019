/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** main
*/

#include <iostream>
#include <string>
#include <string.h>
#include "Error.hpp"
#include "./Reception/Reception.hpp"

using namespace std;

// Display help
static void help()
{
    cout << "USAGE" << endl;
    cout << "\t./plazza cooking_time cooks time" << endl;
    cout << "DESCRIPTION" << endl;
    cout << "  cooking_time\tmultiplier for the cooking time of the pizzas" << endl;
    cout << "  cooks\t\tnumber of cooks per kitchen" << endl;
    cout << "  time\t\ttime used by the kitchen stock to replace ingredients (in milliseconds)" << endl;
    exit (0);
}

// Returns true if the string is a number
static bool isNumber(string str)
{
    for (size_t i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return (false);

    return (true);
}

// Arguments error management
static void manageArguments(int ac, const char **av)
{
    if (ac == 2 && strcmp(av[1], "-h") == 0)
        help();
    if (ac != 4)
        throw Error("Managing Arguments", "Invalid argument number");
    if (isNumber(av[1]) == false || isNumber(av[2]) == false || isNumber(av[3]) == false)
        throw Error("Managing Arguments", "All arguments must be numbers");
}

int main(int ac, const char **av)
{
    try {
        manageArguments(ac, av);
        Reception recep = Reception(av[1], av[2], av[3]);
        recep.loop();
    } catch (Error const &err) {
        std::cerr << err.getType() << ": " << err.what() << std::endl;
        exit (84);
    } catch (std::exception const &err) {
        std::cerr << err.what() << std::endl;
        exit (84);
    }
    return 0;
}