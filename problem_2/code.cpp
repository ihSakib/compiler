#include<bits/stdc++.h>
using namespace std;
bool checkKeyword(const string& str)
{
    string keywords[] =
    {
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if",
        "int", "long", "register", "return", "short", "signed", "sizeof", "static",
        "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while",
        "FILE", "fopen", "getc", "putc"
    };
    for(const string&kw: keywords)
    {
        if(str==kw)
        {
            return true;
        }
    }
    return false;
};

int main()
{
    ifstream file("input.txt");
    if(!file.is_open())
    {
        cout<<"Error in opening"<<endl;
        return 0;
    }
    char ch;
    while(file.get(ch))
    {
        if(!isspace(ch))
        {
            cout<<ch;
        }
    }
    file.clear();
    file.seekg(0);

    cout<<setw(15)<<left<<"tokens"<<"token value as attributes"<<endl;
    while(file.get(ch))
    {
        if(isspace(ch)) continue;
        if(isalpha(ch)|| ch=='_')
        {
            string alp="";
            while(isalnum(ch)||ch=='_')
            {
                alp+=ch;
                if(!file.get(ch)) break;
            }
            if(!file.eof()) file.unget();
            if(checkKeyword(alp))
            {
                cout<<setw(15)<<left<<alp<<alp<<endl;
            }
            else
            {
                cout<<setw(15)<<left<<"id"<<alp<<endl;
            }
        }
        else if(isdigit(ch))
        {
            string num="";
            bool flag=false;
            while(isdigit(ch)|| (ch=='.' && !flag))
            {
                if(ch=='.')
                {
                    flag = true;
                }
                num+=ch;
                if(!file.get(ch))
                {
                    break;
                }
            }
            if (!file.eof()) file.unget();
            cout << setw(15) << left << "NUMBER" << num << endl;
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '<' || ch == '>')
        {
            string op = "";
            op += ch;
            cout << setw(15) << left << "Operator" << op << endl;
        }
        else
        {
            string punct = "";
            punct += ch;
            cout << setw(15) << left << "Punctuation" << punct << endl;
        }

    }
    file.close();
    return 0;
}