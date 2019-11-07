#include <iostream>

#include "bearsplate.hpp"

int main()
{
    const auto [result, value] = run_application();

    std::clog << "value: " << value << '\n';

    return result;
}
