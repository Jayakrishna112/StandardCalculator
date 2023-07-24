#include <iostream>
#include "Calculator.h"
#include "Evaluate.h"
#include <exception>

int calculator::calculate(std::string s)
{
    int res;

    Tokens T;

    T = Token::Convertor(s);

    res = Eval::Evaluate(T);

    return res;
}