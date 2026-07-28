#include <iostream>
using namespace std;

bool check(string str)
{
    int i = 0;
    int n = str.length();

    int aCount = 0, bCount = 0;

    while (i < n && str[i] == 'a')
    {
        aCount++;
        i++;
    }

    while (i < n && str[i] == 'b')
    {
        bCount++;
        i++;
    }

    return (i == n && aCount > 0 && bCount > 0);
}
int main()
{
    cout << "The Grammar is:\n";
    cout << "S -> aS\n";
    cout << "S -> Sb\n";
    cout << "S -> ab\n\n";

    string str;
    cout << "Enter String: ";
    cin >> str;

    if (check(str))
        cout << "String belongs to the grammar." << endl;
    else
        cout << "String does not belong to the grammar." << endl;

    return 0;
}