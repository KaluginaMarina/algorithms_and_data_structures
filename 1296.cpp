#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
 * Всегда сохраняем максимум, если мы его достигли, если ушли в минус, то обнуляемся.
 */

int main() {
    int n;
    cin >> n;
    int s = 0;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        s += a;
        if (s < 0) {
            s = 0;
        }
        if (s > mx) {
            mx = s;
        }
    }
    cout << mx;
    return 0;
}