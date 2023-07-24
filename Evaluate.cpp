#include "Evaluate.h"
#include "Operators.h"
#include "Tokens.h"
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef vector<Token> Tokens;

int Eval::Evaluate(Tokens T)
{
    stack<Operators> op;
    stack<int> num;
    int n, m;
    Operators x;

    for (auto i : T)
    {
        x = i.get_op();
        if (x == Operators::RIGHT_P)
        {
            while (op.top() != Operators::LEFT_P)
            {
                if (op.top() == Operators::UNARY_MINUS)
                {
                    n = num.top();
                    num.pop();
                    num.push(-1 * n);
                }
                else
                {
                    m = num.top();
                    num.pop();
                    n = num.top();
                    num.pop();
                    num.push(calculate(op.top(), m, n));
                }
                op.pop();
            }
            op.pop();
        }
        else if (x == Operators::LEFT_P)
        {
            op.push(x);
        }
        else if ((x == Operators::PLUS) || (x == Operators::BINARY_MINUS) || (x == Operators::DIV) ||
                 (x == Operators::MUL) || (x == Operators::LEFT_P) || (x == Operators::UNARY_MINUS))
        {
            if (op.empty() || op.top() == Operators::LEFT_P)
                op.push(x);
            else
            {
                while (!op.empty() && (Precedence(x) <= Precedence(op.top())))
                {
                    if (op.top() == Operators::UNARY_MINUS)
                    {
                        n = num.top();
                        num.pop();
                        num.push(-1 * n);
                    }
                    else
                    {
                        m = num.top();
                        num.pop();
                        n = num.top();
                        num.pop();
                        num.push(calculate(op.top(), m, n));
                    }
                    op.pop();
                }
                op.push(x);
            }
        }
        else
        {
            num.push(i.get_val());
        }
    }
    while (!op.empty())
    {
        if (op.top() == Operators::UNARY_MINUS)
        {
            int n = num.top();
            num.pop();
            num.push(-1 * n);
        }
        else
        {
            m = num.top();
            num.pop();
            n = num.top();
            num.pop();
            num.push(calculate(op.top(), m, n));
        }
        op.pop();
    }
    return num.top();
}