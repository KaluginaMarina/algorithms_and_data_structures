#include <iostream>
#include <bits/stdc++.h>

/**
 * Решение можно разделить на 2 логические части -
 * построение графа и поммск кратчайщего пути.
 *
 * Для построения графа при добавлении нового телеграфа проверяем все возможные комбинации для
 * определения всех связей(меняем каждую цифру на другую и пробуем переставить каждую пару чисел в номере телеграфа).
 * Если получился номер уже существующего телеграфа, то добавляем связь между вершинами (с весом -- длинной общего префикса)
 *
 * После построения графа воспользуемся алгоритмом Дейкстры для поиска кратчайшего пути.
 */

const int N = 50005;
const int M = 20000005;
const int max_ = 0x3f3f3f3f;

int n;
int val[15]; // значение для перехода
std::string ch[N]; // номера телеграфов
std::map<long long, int> mp; // мапа всех вершин
struct edge { // все связи в графе
    int v, w, next;
} edge[M];
int head[N], ec;

int dis[N], par[N];
bool vis[N];
std::vector<int> vec;
struct pp{
    int d, u;
    bool operator < (const pp &cmp) const {
        return d > cmp.d;
    }
};


void add_edge(int u, int v, int w) {
    edge[ec] = {v, w, head[u]};
    head[u] = ec++;
};

std::vector<long long> py;


//для определения всех связей между телеграфами
void deal(int id) {
    long long tmp = 0;
    // восстановление номера телеграфа
    for (int i = 0; i < 10; ++i) {
        tmp = tmp * 10 + ch[id][i] - '0';
    }
    const long long tt = tmp;
    //поиск связи при замене одной цифры
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            tmp = tmp - (ch[id][i] - '0' - j) * py[i];
            auto it = mp.find(tmp);
            if (it != mp.end()) {
                int len = 0;
                int idx = it->second;
                while (len < 9 && ch[id][len] == ch[idx][len]) {
                    len++;
                }
                add_edge(id, idx, val[len]);
                add_edge(idx, id, val[len]);
            }
            tmp = tt;
        }
    }
    //поиск связи при смене 2-х цифр местами
    for (int i = 0; i < 10; ++i) {
        for (int j = i + 1; j < 10; ++j) {
            int t1 = ch[id][i] - '0';
            int t2 = ch[id][j] - '0';
            tmp = tmp - (t1 - t2) * py[i] - (t2 - t1) * py[j];
            auto it = mp.find(tmp);
            if (it != mp.end()){
                int len = 0;
                int idx = it->second;
                while (len < 9 && ch[id][len] == ch[idx][len]){
                    len++;
                }
                add_edge(id, idx, val[len]);
                add_edge(idx, id, val[len]);
            }
            tmp = tt;
        }
    }
    mp.insert({tt, id});
}

// Алгоритм Дейкстры для поиска кратчайшего маршрута
void dcstr(int x){
    std::priority_queue<pp> pq;
    dis[x] = 0;
    pq.push({dis[x], x});
    while (!pq.empty()){
        int u = pq.top().u;
        pq.pop();
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        for (int i = head[u]; i != -1 ; i = edge[i].next) {
            int v = edge[i].v;
            if (dis[v] > dis[u] + edge[i].w){
                par[v] = u;
                dis[v] = dis[u] + edge[i].w;
                pq.push({dis[v], v});
            }
        }
    }
}


int main() {

    long long tmp = 1;

    for (int i = 0; i < 10; ++i) {
        py.push_back(tmp);
        tmp *= 10;
    }

    std::reverse(py.begin(), py.end());

    std::cin >> n;

    memset(head, -1, sizeof(head));
    ec = 0;                             // счетчик узлов

    for (int i = 0; i < 10; ++i) {
        std::cin >> val[i];
    }

    for (int i = 1; i <= n; ++i) {
        std::cin >> ch[i];
        deal(i);
    }

    memset(dis, max_, sizeof(dis));
    par[1] = -1;


    dcstr(1);

    if (dis[n] == max_){
        std::cout << "-1";
        return 0;
    }

    std::cout << dis[n] << "\n";

    int x = n;
    while(x != -1){
        vec.push_back(x);
        x = par[x];
    }
    reverse(vec.begin(), vec.end());
    std::cout << vec.size() << "\n";
    for (int i = 0; i < vec.size(); ++i){
        std::cout << vec[i] << (i == vec.size() - 1? "\n" : " ");
    }

    return 0;
}