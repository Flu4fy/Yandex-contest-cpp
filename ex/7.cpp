#include <iostream>
#include <cmath>
#include <random>

using namespace std;


void F(int*& A1, int& Size)
{
    int* NA = new int[Size + 2];

    for (int i = 0; i < Size; i++)
    {
        NA[i] = A1[i];
    }

    Size += 2;
    delete[] A1;
    A1 = NA;
}

int main() {
    int Size, element, K;
    cin >> Size;
    K = Size;
    int* A1 = new int[Size];
    for (int i = 0; i < Size; i++)
    {
        cin >> element;
        A1[i] = element;
    }

    int c;
    cin >> c;
    while (c != 6)
    {
        switch (c)
        {
        case 0:
        {

            int New;
            cin >> New;
            if (K < Size)
            {
                A1[K] = New;
                K += 1;
            }
            else
            {
                F(A1, Size);
                A1[K] = New;
                K += 1;
            }

            break;
        }
        case 1:
        {
            unsigned int Rand;
            random_device dev;
            mt19937 rng(dev());
            uniform_int_distribution<mt19937::result_type> range(0, 1024);
            Rand = range(rng);
            if (K < Size)
            {
                A1[K] = Rand;
                K += 1;
            }
            else
            {
                F(A1, Size);
                A1[K] = Rand;
                K += 1;
            }
            break;
        }
        case 2:
        {
            int Nom, New;
            cin >> Nom >> New;
            A1[Nom] = New;
            break;
        }
        case 3:
        {
            for (int i = 0; i < K; i++)
            {
                cout << A1[i] << " ";
            }
            cout << endl;
            break;
        }
        case 4:
        {
            for (int i = 0; i < K; i++)
            {
                for (int j = i + 1; j < K; j++)
                {
                    if (A1[i] >= A1[j])
                    {
                        int z;
                        z = A1[i];
                        A1[i] = A1[j];
                        A1[j] = z;
                    }
                }
            }
            break;
        }
        case 5:
        {
            long long int sum = 0;
            for (int i = 0; i < K; i++)
            {
                sum += A1[i];
            }
            double mean = sum / K;
            cout << mean << endl;
        }
        }
        cin >> c;
    }

}