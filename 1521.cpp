#include <iostream>

/**
 * дерево Fенвика (потом как-нить надо написать описание)
 */

int maxn = 1 << 17; // рандомные константы наше все) нам просто надо, чтобы туда все вошло
int t[2 << 18];

void update(int x, int amount) {
    for (x += maxn; x > 0; x /= 2)
        t[x] += amount;
}

int find_kth(int x, int kth) {
    while (x < maxn){
        x *= 2;
        if (kth > t[x]) {
            kth -= t[x];
            x++;
        }
    }
    return x - maxn;
}

int main() {

    int n, k;
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        update(i, 1);
//        for(int &item : t){
//            std::cout << item << " ";
//        }
//        std::cout << "\n";
    }
    int currPos = k - 1;
//    std::cout << "====================\n";

    for (int i = 0; i < n; ++i) {
        int pos = find_kth(1, currPos + 1);
        update(pos, -1);
//        for(int &item : t){
//            std::cout << item << " ";
//        }
//        std::cout << "\n";
        std::cout << pos + 1 << " ";
        if (i < n - 1)
            currPos = (currPos - 1 + k) % (n - i - 1);
    }
    return 0;
}