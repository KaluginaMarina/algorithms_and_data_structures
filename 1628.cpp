#include <iostream>
#include <bits/stdc++.h>

/**
 * Отсортируем все точки с левого верхнего угла по правый нижний: сначала строки, потом столбцы.
 * Каждую полосу, длиной больше 1 добавим в результат, каждую полосу, длиной 1 сохраним на будущее в вектор sq.
 *
 * Аналогично отсортируем все точки снова, только теперь сначала столбцы, потом строки.
 *
 * Теперь у нас есть количество вертикальных и горизонтальных полос. Осталось проверить только полосы 1х1.
 * Если полоса 1х1 встречается в векторе sq 2 раза, значит - квадрат 1х1 максимальен и по вертикали и по горизонтали
 * => его следует добавить в результат
 */

bool comp1(std::pair<int, int> a, std::pair<int, int> b) {
    if (a.first != b.first) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}

bool comp2(std::pair<int, int> a, std::pair<int, int> b) {
    if (a.second != b.second) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

int main() {
    int m, n, k, res = 0;

    std::cin >> m >> n >> k;

    std::vector<std::pair<int, int>> point;
    std::vector<std::pair<int, int>> sq;

    for (int i = 0; i < k; ++i) {
        std::pair<int, int> p;
        std::cin >> p.first >> p.second;
        p.first--;
        p.second--;
        point.push_back(p);
    }

    for (int i = 0; i < m; ++i) {
        std::pair<int, int> p = {i, -1};
        std::pair<int, int> p2 = {i, n};
        point.push_back(p2);
        point.push_back(p);
    }

    for (int i = 0; i < n; ++i) {
        std::pair<int, int> p = {-1, i};
        std::pair<int, int> p2 = {m, i};
        point.push_back(p2);
        point.push_back(p);
    }

    sort(point.begin(), point.end(), comp1);

    for (int i = 0; i < point.size() - 1; ++i) {
        if (point[i].first == point[i + 1].first) {
            if (point[i + 1].second - point[i].second - 1 > 1) {
                res++;
            } else if (point[i + 1].second - point[i].second - 1 == 1) {
                std::pair<int, int> p(point[i].first, point[i].second + 1);
                sq.push_back(p);
            }
        }
    }

    sort(point.begin(), point.end(), comp2);
    sort(sq.begin(), sq.end(), comp2);

    for (int i = 0; i < point.size() - 1; ++i) {
        if (point[i].second == point[i + 1].second) {
            if (point[i + 1].first - point[i].first - 1 > 1) {
                res++;
            } else if (point[i + 1].first - point[i].first - 1 == 1) {
                std::pair<int, int> p(point[i].first + 1, point[i].second);
                sq.push_back(p);
            }
        }
    }

    sort(sq.begin(), sq.end(), comp1);

    if (sq.size() > 1) {
        int i = 0;
        while (i < sq.size() - 1) {
            if (sq[i] == sq[i + 1]) {
                res++;
                i++;
            }
            i++;
        }
    }

    std::cout << "\n\n" << res;

    return 0;
}