#include <vector>
#include "Operators.h"
using namespace std;
#ifndef TOKENS_H

#define TOKENS_H

class Token;

typedef vector<Token> Tokens;

class Token
{
    Operators op;
    int value;

public:
    Token();
    Token(Operators, int = 0);
    static Tokens Convertor(string);
    Operators get_op();
    int get_val();
};

#endif // TOKENS_H