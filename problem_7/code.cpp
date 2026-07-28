#include <iostream>
using namespace std;

bool check(string str)
{
    int i = 0, j = str.length() - 1;

    while (i < j)
    {
        if (str[i] != 'a' || str[j] != 'b')
            return false;

        i++;
        j--;
    }

    return i > j; // Valid if all pairs matched
}

int main()
{ 

    string str;
    cout << "Grammar: S → aSb | ε" << endl;
    cout << "Enter String: ";
    cin >> str;

    if (check(str))
        cout << "String belongs to the grammar.";
    else
        cout << "String does not belong to the grammar.";

    return 0;
}