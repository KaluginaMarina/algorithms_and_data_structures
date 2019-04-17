#include <iostream>
#include <vector>
#include <algorithm>

/**
 * Воспользуемся алгоритмом Краскала
 * Отсортируем ребра по возрастанию. Добавляем в граф ребра, начиная с минимального.
 * Если при добавлении следующего ребора получается цикл, то это ребро не нужно))
 * В итоге получаем остовное дерево, связанное проводами с минимальными длинами.
 */

struct e {
    int a, b, l;
};

int r[1010], t[1010];
int max = 0;

bool cmp(e a, e b) {
    return a.l < b.l;
}

int find(int x) {
    if (x != t[x]) t[x] = find(t[x]);
    return t[x];
}

int main() {
    int n, m;

    std::cin >> n >> m;
    std::vector<e> v;

    for (int i = 0; i < m; ++i) {
        int a, b, l;
        std::cin >> a >> b >> l;
        v.push_back({a - 1, b - 1, l});
    }

    std::sort(v.begin(), v.end(), cmp);

    for (int i = 1; i <= n; i++) {
        r[i] = 0;
        t[i] = i;
    }

    for (int i = 0; i < m; ++i) {
        int n1 = v[i].a;
        int n2 = v[i].b;

        if (find(n1) != find(n2)) {
            if (v[i].l > max) {
                max = v[i].l;
            }
            v[i].l *= -1;

            int x = find(n1);
            int y = find(n2);
            if (r[x] > r[y]) t[y] = x;
            else {
                t[x] = y;
                if (r[x] == r[y]) r[y]++;
            }
        }
    }

    std::cout << max << "\n" << n - 1 << "\n";

    for (int j = 0; j < m; ++j){
        if (v[j].l < 0){
            std::cout << v[j].a + 1 << " " << v[j].b + 1 << "\n";
        }
    }
    return 0;
}