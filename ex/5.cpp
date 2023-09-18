#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <vector>
using namespace std;


string f(string inp) {
    char a;
    vector<char> vec;
    for (int i = 0; i <= inp.size(); i++)
    {
        a = inp[i];
        switch (a)
        {
        case '(':
        {
            vec.push_back(a);
            break;
        }
        case '{':
        {
            vec.push_back(a);
            break;
        }
        case '[':
        {
            vec.push_back(a);
            break;
        }
        case ')':
        {
            if (vec.size() != 0 && vec[vec.size() - 1] == '(')
            {
                vec.pop_back();
                break;
            }
            else return "NO";
        }
        case '}':
        {
            if (vec.size() != 0 && vec[vec.size() - 1] == '{')
            {
                vec.pop_back();
                break;
            }
            else return "NO";
        }
        case ']':
        {
            if (vec.size() != 0 && vec[vec.size() - 1] == '[')
            {
                vec.pop_back();
                break;
            }
            else return "NO";
        }
        }
    }

    if (vec.size() != 0) return "NO";
    else return "YES";
}



int main(void)
{
    string code;
    cin >> code;
    cout << f(code);
    return 0;
}
