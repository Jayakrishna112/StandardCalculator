#include <iostream>
#include <vector>
#include "Tokens.h"
#include "Operators.h"

// using namespace std;

Token::Token() : op(Operators::NULL1), value(0){};

Token::Token(Operators Op, int x) : op(Op), value(x){};

typedef vector<Token> Tokens;

inline bool is_Whitespace(const char &s)
{
    return s == ' ';
}

int Token::get_val()
{
    return this->value;
}

Operators Token::get_op()
{
    return this->op;
}

Tokens Token::Convertor(string s)
{
    Tokens Sequence(0);
    for (int i = 0; i < s.length(); i++)
    {
        if (is_Whitespace(s[i]))
        {
            i++;
            while (i < s.length() && is_Whitespace(s[i]))
                i++;
            if (i < s.length())
                i--;
        }

        else if (isdigit(s[i]))
        {
            string num = string(1, s[i]);
            i++;
            while (i < s.length() && isdigit(s[i]))
            {
                num += string(1, s[i]);
                i++;
            }
            if (i < s.length())
                i--;
            Sequence.push_back(Token(Operators::NUM, stoi(num)));
        }

        else if (s[i] == '+')
            Sequence.push_back(Token(Operators::PLUS));
        else if (s[i] == '*')
            Sequence.push_back(Token(Operators::MUL));
        else if (s[i] == '-')
        {
            if ((Sequence.size() == 0) || is_Operator(Sequence[Sequence.size() - 1].get_op()) ||
                Sequence[Sequence.size() - 1].get_op() == Operators::LEFT_P)
            {
                Sequence.push_back(Token(Operators::UNARY_MINUS));
            }
            else
            {
                Sequence.push_back(Token(Operators::BINARY_MINUS));
            }
        }
        else if (s[i] == '/')
            Sequence.push_back(Token(Operators::DIV));
        else if (s[i] == '(')
            Sequence.push_back(Token(Operators::LEFT_P));
        else if (s[i] == ')')
            Sequence.push_back(Token(Operators::RIGHT_P));
        else
        {
            cout << "An operator is not defined in your sequence.";
            exit(1);
        }
    }

    return Sequence;
}