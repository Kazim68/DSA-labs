#include <iostream>
#include <stack>
#include <ctype.h>
#include <string>
using namespace std;

int precedence(char symbol)
{
    if (symbol == '*' || symbol == '/' || symbol == '%')
        return 2;
    else if (symbol == '+' || symbol == '-')
        return 1;
    return 0;
}

// infix to postfix
string infixToPostfix(string expression)
{

    stack<char> operators;
    string result = "";

    for (int i = 0; i < expression.length(); i++)
    {

        if (isdigit(expression[i]))
        {
            result += expression[i];
        }

        else if (expression[i] == ')')
        {

            while (operators.top() != '(')
            {
                result += operators.top();
                operators.pop();
            }
            operators.pop();

            while (!operators.empty() && precedence(operators.top()) >= precedence(result[result.length() - 1]))
            {
                result += operators.top();
                operators.pop();
            }
        }

        else
        {
            operators.push(expression[i]);
        }
    }

    while (!operators.empty())
    {
        result += operators.top();
        operators.pop();
    }

    return result;
}

// solving the postfix
int evaluatePostfix(string expression)
{

    stack<int> numbers;
    int val1, val2;

    for (int i = 0; i < expression.length(); i++)
    {

        if (isdigit(expression[i]))
        {
            numbers.push(expression[i] - '0');
        }

        else if (expression[i] == ' ')
        {
            continue;
        }

        else
        {
            val2 = numbers.top();
            numbers.pop();
            val1 = numbers.top();
            numbers.pop();

            if (expression[i] == '+')
                numbers.push(val1 + val2);
            else if (expression[i] == '-')
                numbers.push(val1 - val2);
            else if (expression[i] == '*')
                numbers.push(val1 * val2);
            else if (expression[i] == '/')
                numbers.push(val1 / val2);
        }
    }
    return numbers.top();
}

// infix to prefix
string infixToPrefix(string expression)
{

    stack<char> operators;
    string result = "";

    for (int i = expression.length() - 1; i >= 0; i--)
    {

        if (isdigit(expression[i]))
        {
            result = expression[i] + result;
        }

        else if (expression[i] == '(')
        {

            while (operators.top() != ')')
            {
                result = operators.top() + result;
                operators.pop();
            }
            operators.pop();

            while (!operators.empty() && precedence(operators.top()) < precedence(result[0]))
            {
                result = operators.top() + result;
                operators.pop();
            }
        }

        else
            operators.push(expression[i]);
    }

    while (!operators.empty())
    {
        result = operators.top() + result;
        operators.pop();
    }

    return result;
}

// prefix evaluator
int prefixEvaluator(string expression)
{

    stack<int> numbers;
    int val1, val2;

    for (int i = expression.length() - 1; i >= 0; i--)
    {

        if (isdigit(expression[i]))
        {
            numbers.push(expression[i] - '0');
        }

        else
        {
            val1 = numbers.top();
            numbers.pop();
            val2 = numbers.top();
            numbers.pop();

            if (expression[i] == '+')
                numbers.push(val1 + val2);
            else if (expression[i] == '-')
                numbers.push(val1 - val2);
            else if (expression[i] == '*')
                numbers.push(val1 * val2);
            else if (expression[i] == '/')
                numbers.push(val1 / val2);
        }
    }
    return numbers.top();
}

main()
{
    string evaluate = "1*(5+3)/(3-1)-7";
    cout << infixToPostfix(evaluate) << endl;
    cout << evaluatePostfix("562+*4/") << endl;
    cout << infixToPrefix("5*(2+33)/6") << endl;
    cout << prefixEvaluator("/*5+624") << endl;
}