#include "Operators.h"
#include <iostream>

bool is_Operator(Operators t)
{
    switch (t)
    {
    case Operators::LEFT_P:
        return false;
        break;
    case Operators::RIGHT_P:
        return false;
        break;
    case Operators::NUM:
        return false;
        break;
    default:
        return true;
    }
}
int Precedence(Operators t)
{
    switch (t)
    {
    case Operators::UNARY_MINUS:
        return 4;
        break;
    case Operators::MUL:
        return 3;
        break;
    case Operators::DIV:
        return 3;
        break;
    case Operators::BINARY_MINUS:
        return 2;
        break;
    case Operators::PLUS:
        return 2;
        break;
        // error definition
    }
    return -1;
}

int calculate(Operators x, int a, int b)
{
    switch (x)
    {
    case Operators::PLUS:
        return a + b;
        break;
    case Operators::BINARY_MINUS:
        return b - a;
        break;
    case Operators::MUL:
        return a * b;
        break;
    case Operators::DIV:
        if (a == 0)
        {
            std::cout << "ERROR : Divided by zero is not posiible";
            exit(-1);
        }
        return b / a;
        break;
    }
    return 0;
}