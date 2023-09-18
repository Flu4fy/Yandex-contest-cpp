#include <iostream>
#include <cmath>


using namespace std;

bool checkNum_test(int N) {
    cout << "Введите число\n";
    cin >> N;
    
    int counter = 2;
    while (counter < N) {
        if (N % counter == 0) {
            cout << "Составное";
            return false;
        }
        counter++;
    }

    return true;
}

bool checkNum_unopt(int N) {
    int counter = 2;
    while (counter < N) {
        if (N % counter == 0) { return false; }
        counter++;
    }

    return true;
}

bool checkNum_opt1(int N) {
    int counter = 2;
    while (counter <= sqrt(N) + 1) {
        if (N % counter == 0) { return false; }
        counter++;
    }

    return true;
}

bool checkNum_opt2(int N) {
    int counter = 3;
    if (N % 2 == 0) { return false; }

    while (counter <= sqrt(N) + 1) {
        if (N % counter == 0) { return false;}
        counter += 2;
    }

    return true;
}

bool checkNum_opt3(int n) {
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool checkNum_opt4(int n) {
    if (n <= 1) { return false; }
    if (n <= 3) { return true; }
    if (n % 2 == 0 || n % 3 == 0) { return false; }
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    uint32_t endNumber, counter, j = 2;
    cin >> endNumber;
    
    if (endNumber == 1) {
       cout << 2;
       return 0; 
    } else {
        cout << 2;
        counter = 1;
        while (true) {
            j++;
            if (checkNum_opt4(j)) {
                cout  << " " << j;
                counter++;
            }

            if (counter == endNumber) { break; }
        }
    }
    
    return 0;
}