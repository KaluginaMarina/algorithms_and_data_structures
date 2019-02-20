#include <iostream>

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        long int n, k;
        std::cin >> n >> k;
        long c = n/k; // количество людей в команде
        long ost = n % k; // остаток людей
        long res = (k - ost) * c * (n - c) + ost * (c + 1) * (n - (c + 1)); // каждый человек дерется с каждым, кроме своего сокомандника
        std::cout << res/2 << std::endl;
    }
    return 0;
}