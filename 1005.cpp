#include <iostream>
#include <bits/stdc++.h>

int min_ = 100000;
std::vector<int> a;
int n;

int f(int i, int s1, int s2) {
    if (i == n) {
        min_ = std::min(min_, abs(s1 - s2));
    } else {
        f(i + 1, s1 + a[i], s2);
        f(i + 1, s1, s2 + a[i]);
    }
    return min_;
}


int main() {
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int q;
        std::cin >> q;
        a.push_back(q);
    }
    f(0, 0, 0);
    std::cout << min_;
    return 0;
}