#include <iostream>
#include <vector>

/**
 * Воспользуемся алгоритмом Беллмана-Форда.
 * Создадим матрицу res, res[i] -- максимальная газопроводность от s до i на дрнную итерацию
 * На каждой итерации рассматриваем все пути возможные из каждой посещенной вершины.
 * При нахождении нового максимального значения газопроводности в вершину i - обновляем значение res[i]
 *
 * В итоге получаем вектор res, в котором находятся максимальные значения от s
 * Если значение res[f] == -1, то эта вершина оказалась не посещенной => такого пути не существует
 */

struct e {
    int a, b, w;
};

std::vector<e> v;

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> res(510, -1);
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        std::cin >> a >> b >> w;
        v.push_back({a - 1, b - 1, w});
    }
    int s, f;
    std::cin >> s >> f;
    s--;
    f--;
    res[s] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            if (res[v[j].a] != -1 && res[v[j].b] < res[v[j].a] + v[j].w) {
                res[v[j].b] = res[v[j].a] + v[j].w;
            }
        }
    }
    if (res[f] != -1) {
        std::cout << res[f];
    } else {
        std::cout << "No solution";
    }

    return 0;
}