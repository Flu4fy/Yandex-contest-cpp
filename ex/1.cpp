#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    unsigned long long int N = 0, K = 0, flag = 0, k = 0, _10 = 0;
    char S;
    cin >> N;
    cin >> S;
    while (S != ';')
    {
        if ((int)S >= 48 and (int)S <= 57)
        {
            _10 = (_10 + (int)S - 48) * N;
        }
        else
        {
            _10 = (_10 + (int)S - 55) * N;
        }
        cin >> S;
    }
    _10 = _10 / N;

    cin >> K;
    cout << _10 << endl;

    long long int M = 1, b = 0;
    while (M <= _10)
    {
        M = M * K;
    }

    M = M / K;
    while (M > 0)
    {
        b = _10 / M;
        if (b >= 10)
        {
            cout << (char)(55 + b);
        }
        else
        {
            cout << b;
        }
        _10 = _10 - b * M;
        M = M / K;
    }
}
