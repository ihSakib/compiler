#include <iostream>
#include <string>
#include <cctype>
#include <stack>
using namespace std;

int pre(char op)
{
    if (op == '^')
    {
        return 3;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    else if (op == '+' || op == '-')
    {
        return 1;
    }

    return 0;
}

int main(int argc, char const *argv[])
{

    string infix, postfix;
    cout << "Infix: ";
    cin >> infix;

    stack<char> st;

    for (char ch : infix)
    {
        if (isalnum(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += ch;
                st.pop();
            }

            st.pop();
        }
        else
        {

            while (!st.empty() && pre(st.top()) >= pre(ch))
            {
                postfix += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }


    cout<<"Postfix: "<<postfix<<endl;
    return 0;
}
