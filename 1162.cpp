#include <iostream>
#include <vector>

/**
 * Стратегия задачи похожа на задачу 1450, за исключением того, что теперь максимум ищется по-другому,
 * с учетом того, что за переводы из одной валюты в другую взимается комиссия
 *
 * Т.е. воспользуемся алгоритмом Беллмана-Форда.
 * На каждой итерации рассматриваем все пути возможные из каждой посещенной вершины.
 * При нахождении нового максимального значения - обновляем значение nd
 * В итоге получаем вектор, в котором находятся максимальные значения от начальной
 */

struct e {
    int a, b;
    double r, c;
};

std::vector<e> ve;
double nd[110];

int main() {
    int n, m, s;
    double v;
    std::cin >> n >> m >> s >> v;
    nd[s] = v;
    for (int i = 0; i < m; ++i) {
        int a, b;
        double rab, cab, rba, cba;
        std::cin >> a >> b >> rab >> cab >> rba >> cba;
        ve.push_back({a, b, rab, cab});
        ve.push_back({b, a, rba, cba});
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < ve.size(); ++j) {
            if (nd[ve[j].b] - (nd[ve[j].a] - ve[j].c) * ve[j].r < 0.000001) {
                nd[ve[j].b] = (nd[ve[j].a] - ve[j].c) * ve[j].r;
            }
        }
    }

    for (int i = 0; i < ve.size(); ++i) {
        if ((nd[ve[i].a] - ve[i].c) * ve[i].r - nd[ve[i].b]  > 0.000001) {
            std::cout << "YES";
            return 0;
        }
    };
    std::cout << "NO";
    return 0;
}