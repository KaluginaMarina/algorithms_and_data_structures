#include <iostream>
#include <stack>

int main() {
    int n;
    std::cin >> n;
    std::stack<int> balls;
    int tmp_max = 0;
    for (int i = 0; i < n; ++i) {
        int cur;
        std::cin >> cur;
        if (cur > tmp_max) {
            for (int j = tmp_max + 1; j <= cur - 1; j++) {
                balls.push(j);
            }
            tmp_max = cur;
        } else {
            if (cur == balls.top()){
                balls.pop();
            } else {
                std::cout << "Cheater";
                return 0;
            }
        }
    }
    std::cout << "Not a proof";
    return 0;
}