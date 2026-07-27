#include <iostream>
#include <fstream>
using namespace std;

bool isKeyword(string token)
{
    string keywords[] = {
        "auto", "break", "case", "char", "const",
        "continue", "default", "do", "double", "else",
        "enum", "extern", "float", "for", "goto",
        "if", "int", "long", "register", "return",
        "short", "signed", "sizeof", "static", "struct",
        "switch", "typedef", "union", "unsigned", "void",
        "volatile", "while"};

    for (string key : keywords)
    {
        if (token == key)
            return true;
    }

    return false;
}

int main()
{
    ifstream fin("input.txt");

    if (!fin)
    {
        cout << "Cannot open file!" << endl;
        return 1;
    }

    string token;

    while (fin >> token)
    {
        // Remove common punctuation
        while (!token.empty() &&
               (token.back() == ';' || token.back() == ',' ||
                token.back() == '(' || token.back() == ')' ||
                token.back() == '{' || token.back() == '}'))
        {
            token.pop_back();
        }

        if (isKeyword(token))
        {
            cout << token << " --> Keyword" << endl;
        }
    }

    fin.close();
    return 0;
}