#include <iostream>
#include <vector>

const int MOD = 10000;

int main() {
    int n;
    std::cin >> n;
    std::vector<int> f(n + 1);

    f[1] = 1;
    f[2] = 1;
    f[3] = 1;

    for (int i = 4; i <= n; i++) {
        f[i] = (f[i - 2] % MOD + 2 * f[i / 2] % MOD) % MOD;
    }

    std::cout << f[n] << std::endl;
    return 0;
}