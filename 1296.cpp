#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int s = 0;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        s += a;
        if (s < 0) {
            s = 0;
        }
        if (s > mx) {
            mx = s;
        }
    }
    std::cout << mx;
    return 0;
}