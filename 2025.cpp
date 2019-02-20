#include <iostream>

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        long int n, k;
        std::cin >> n >> k;
        long c = n/k; // количество людей в команде
        long ost = n % k; // остаток людей
        long res = (k - ost) * c * ((k - ost - 1) * c + ost * (c + 1));
        res += ost * (c + 1) * ((k - ost) * c + (ost == 0 ? 0 : (ost - 1) * (c + 1)));
        res /= 2;
        std::cout << res << std::endl;
    }
    return 0;
}