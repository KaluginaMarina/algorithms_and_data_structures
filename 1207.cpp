#include <iostream>
#include <cmath>

#define PI 3.141592653589793238462643383279502884197169399375105820974

/**
 * Для того, чтобы разделить на 2 части плоскость найдем самую правую точку.
 * Узнаем угол до каждой из оставшихся точкек и отсортируем эти значения.
 * В таком случае мы сможем найти ту точку через которую можно провести прямую, чтобы
 * разделятсь плоскость на точки, которые выше прямой и точки, которые ниже.
 */

struct point {
    long long int x;
    long long int y;
    double angle;
    int num;
};
int min_i;

int comp(const void *v1, const void *v2) {
    const point *p1 = (point *) v1;
    const point *p2 = (point *) v2;
    return p1->angle > p2->angle ? 1 : -1;

}

int main() {
    int n;
    std::cin >> n;
    point p[n];
    long long int min_x = INT64_MAX;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        p[i].x = x;
        if (x < min_x) {
            min_x = x;
            min_i = i;
        }
        std::cin >> p[i].y;
        p[i].num = i;
    }

    for (point &pn: p) {
        if (pn.num == min_i) {
            pn.angle = INT32_MIN;
            continue;
        }
        if (pn.x - p[min_i].x == 0) {
            pn.angle = (pn.y > p[min_i].y) ? 90 : -90;
            continue;
        }
        pn.angle = atan((double) (pn.y - p[min_i].y) / (pn.x - p[min_i].x)) * 180.0 / PI;
    }

    std::qsort(p, n, sizeof(point), comp);

//    for (point &pn: p) {
//        std::cout << "x: " << pn.x << " y: " << pn.y << " angle: " << pn.angle << "# " << pn.num << std::endl;
//    }

    std::cout << p[0].num + 1 << " " << p[n / 2].num + 1;
    return 0;
}