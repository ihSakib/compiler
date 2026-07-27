#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// Function to return precedence of operators
int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

int main()
{
    string infix, postfix = "";

    cout << "Enter Infix Expression: ";
    cin >> infix;

    stack<char> st;

    for (char ch : infix)
    {
        // Operand
        if (isalnum(ch))
        {
            postfix += ch;
        }
        // Left Parenthesis
        else if (ch == '(')
        {
            st.push(ch);
        }
        // Right Parenthesis
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }

            if (!st.empty())
                st.pop(); // Remove '('
        }
        // Operator
        else
        {
            while (!st.empty() &&
                   precedence(st.top()) >= precedence(ch))
            {
                if (st.top() == '(')
                    break;

                postfix += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    // Pop remaining operators
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}