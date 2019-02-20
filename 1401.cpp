#include <iostream>
#include <cmath>

using namespace std;



int main() {
    int n, x, y;
    cin >> n >> y >> x;
    if (((int)pow(2, n) - 1) % 3 != 0) {
        cout << -1;
        return 0;
    }

    int arr[n][n];

}