#include <iostream>
#include <cmath>

#define PI 3.141592653589793238462643383279502884197169399375105820974

struct point {
    long long int x;
    long long int y;
    double angle;
    int num;
};
int min_i;
point p0;

int comp(const void *v1, const void *v2) {
    const point *p1 = (point *) v1;
    const point *p2 = (point *) v2;
    if (p1->angle - p2->angle > 1e-10) {
        return 1;
    } else if (p1->angle - p2->angle < -1e-10) {
        return -1;
    } else {
        if ((p1->x - p0.x) * (p1->x - p0.x) + (p1->y - p0.y) * (p1->y - p0.y) >
            (p2->x - p0.x) * (p2->x - p0.x) + (p2->y - p0.y) * (p2->y - p0.y)){
            return 1;
        } else {
            return -1;
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    point p[n];
    long long int min_x = INT64_MAX;
    long long int min_y = INT64_MAX;
    for (int i = 0; i < n; ++i) {
        long long int x;
        long long int y;
        std::cin >> x;
        std::cin >> y;
        p[i].x = x;
        if (x < min_x || (x == min_x && y < min_y)) {
            min_x = x;
            min_y = y;
            min_i = i;
        }
        p[i].y = y;
        p[i].num = i;
    }
    p0 = p[min_i];

    for (point &pn: p) {
        if (pn.num == min_i) {
            pn.angle = 0;
            continue;
        }
        if (pn.x - p[min_i].x == 0) {
            pn.angle = (pn.y > p[min_i].y) ? 0 : 180;
            continue;
        }
        pn.angle = atan((double) (pn.y - p[min_i].y) / (pn.x - p[min_i].x)) * 180.0 / PI + 90;
    }

    std::qsort(p, n, sizeof(point), comp);

    for (point &pn: p) {
        std::cout << "x: " << pn.x << " y: " << pn.y << " angle: " << pn.angle << " #" << pn.num << std::endl;
    }

    int k = 0;
    while (p[k].num != 0) {
        ++k;
    }

    std::cout << n << std::endl;

    for (int i = 0; i < n; ++i) {
        std::cout << p[k].num + 1 << std::endl;
        ++k;
        if (k == n) {
            k = 0;
        }
    }
    return 0;
}