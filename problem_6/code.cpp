#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    string input;
    string temp = "";
    vector<string> prod;

    cout << "Productions: ";
    cin >> input;

    // split by |
    for (size_t i = 0; i < input.size(); i++)
    {
        if (input[i] == '|')
        {
            prod.push_back(temp);
            temp = "";
        }
        else
        {
            temp += input[i];
        }
    }
    prod.push_back(temp);

    // logest common prefix
    string prefix = prod[0];
    for (size_t i = 1; i < prod.size(); i++)
    {
        int j = 0;

        while (j < prefix.size() && j < prod[i].size() && prefix[j] == prod[i][j])
        {
            j++;
        }

        prefix = prefix.substr(0, j);
    }

    if (prefix.empty())
    {
        cout << "No left factoring possible" << endl;
        return 0;
    }

    // output
    cout << "A -> " << prefix << "A'" << endl;
    cout << "A' -> ";

    for (size_t i = 0; i < prod.size(); i++)
    {
        string remain = prod[i].substr(prefix.size());

        if (remain.empty())
        {
            remain = "#";
        }

        cout << remain;

        if (i != prod.size() - 1)
        {
            cout << " | ";
        }
    }

    return 0;
}
