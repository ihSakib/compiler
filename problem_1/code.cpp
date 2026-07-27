#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    char ch;

    // write to output.txt without spaces
    while (fin.get(ch))
    {
        if (!isspace(ch))
        {
            fout << ch;
        }
    }
    fin.close();
    fout.close();

    //***********************************//
    fin.open("input.txt");
    while (fin.get(ch))
    {
        if (isdigit(ch))
        {
            string num;
            while (isdigit(ch))
            {
                num += ch;
                fin.get(ch);
            }

            cout << num << endl;
        }
    }

    return 0;
}