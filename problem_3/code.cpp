#include <iostream>
#include <fstream>
using namespace std;

bool check(string token)
{
    string keywords[] = {
        "int", "float", "char", "double",
        "long", "signed", "unsigned", "string"};

    for (string key : keywords)
    {
        if (key == token)
            return true;
    }

    return false;
}

int main()
{
    ifstream fin("input.txt");

    string token;

    while (fin >> token)
    {

        if (check(token))
        {
            string id = "";
            while (check(token))
            {
                id += token + " ";
                fin >> token;
            }

            // Don't print if it is a function (e.g. main())
            if (token.find("()") != string::npos)
                continue;

            // Remove ';' or '=' if present
            if (token.back() == ';' || token.back() == '=')
                token.pop_back();

            cout << id << ": " << token << endl;
        }
    }

    fin.close();
    return 0;
}