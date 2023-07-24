#include <iostream>
#include "Operators.h"
#include "Tokens.h"
#include "Evaluate.h"
#include "calculator.h"
#include "Operators.cpp"
#include "Tokens.cpp"
#include "Evaluate.cpp"
#include "calculator.cpp"

int main()
{
    calculator x;

    std::string s;

    cout << "Enter the Equation to be computed" << endl;

    getline(std::cin, s);

    cout << x.calculate(s);

    return 0;
}
