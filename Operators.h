#ifndef OPERATORS_H

#define OPERATORS_H

enum class Operators : char
{
    NULL1 = '0',
    PLUS = '+',
    BINARY_MINUS = 'm',
    UNARY_MINUS = 'u',
    LEFT_P = '(',
    RIGHT_P = ')',
    MUL = '*',
    DIV = '/',
    NUM = 'n'
};

bool is_Operator(Operators);

int Precedence(Operators);

int calculate(Operators, int, int);

#endif // OPERATORS_H
