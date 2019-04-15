#include <iostream>
#include <bits/stdc++.h>

/**
 * Обойдем граф в ширину. Если можно покрасить следующий город в синий или красный, не нарушив условие,
 * то красим вершину и переходим к следующей. Если условие нарушается (встречаются 2 города одинакового цвета) - 
 * это значит, что покрасить карту в 2 цвета нельзя. 
 * 
 * Если после покраски графа остались непосещенное вершины, то это значит, что граф несвязный и обойдем эти
 * вершины в ширину отдельно
 */

int colors[100];
std::vector<int> edge[100];
int n;

void btf(int st) {
    std::queue<int> q;
    q.push(st);
    colors[st] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < edge[v].size(); ++i) {
            int to = edge[v][i];
            if (colors[v] == colors[to]) {
                std::cout << "-1";
                exit(0);
            }
            if (colors[to] == -1) {
                colors[to] = colors[v] == 0 ? 1 : 0;
                q.push(to);
            }
        }
    }
}

int main(){
    std::cin >> n;

    std::fill_n(colors, 100, -1); // -1 -- не посещен, 0 -- красный, 1 -- синий

    for (int i = 0; i < n; ++i) {
        int e = -1;
        while (e != 0) {
            std::cin >> e;
            if (e != 0) {
                edge[i].push_back(e - 1);
                edge[e - 1].push_back(i);
            }
        }
    }

    btf(0);

    for(int i = 0; i < n; ++i){
        if(colors[i] == -1) {
            btf(i);
        }
        std::cout << colors[i];
    }

    return 0;
}