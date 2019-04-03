#include <iostream>
#include <bits/stdc++.h>
/**
 * Смоделируем ситуацию представленную в задаче.
 *
 * В score_board хранится актуальное отсортированное множество городов. Из него мы можем узнавать город, находящийся в топе за констнту.
 * При каждом перелете изменяем общую сумму денег в городах между которыми совершается перелет миллиардера, текущее положение миллиардера и
 * обновляем score_board (обновление совершается за log).
 *
 * Все миллиардеры и города хранятся в map, для того, чтобы изменения какой-либо информации совершалось за логарифм.
 *
 * Итоговый перфоманс: O(k log k)
 */
struct city {
    std::string name;
    long long money;
    int days;
} ct[10000 + 50000];

struct pers {
    long long money;
    city *location;
} pr[10000];

std::map<std::string, pers *> hum;
std::map<std::string, city *> world;
std::set<std::pair<long long, city *>, std::greater<>> score_board;

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;

    int c = 0;
    for (int i = 0; i < n; ++i) {
        std::string name_p;
        std::string name_c;
        long long mon;
        std::cin >> name_p >> name_c >> mon;
        if (!world[name_c]) {
            ct[c].name = name_c;
            ct[c].money = mon;
            world[name_c] = &ct[c];
            c++;
        } else {
            world[name_c]->money += mon;
        }
        pr[i].money = mon;
        pr[i].location = world[name_c];
        hum[name_p] = &pr[i];
    }

    for (auto &item : world) {
        score_board.insert({item.second->money, item.second});
    }

    int m, k, today = 0;
    std::cin >> m >> k;

    for (int i = 0; i < k; ++i) {
        int day;
        std::string name_p, name_c;
        std::cin >> day >> name_p >> name_c;
        int count = day - today;
        today = day;
        auto it2 = score_board.begin();
        auto it = it2++;
        if (it2 == score_board.end() || it->first > it2->first) {
            it->second->days += count;
        }
        city *to_city = world[name_c];
        pers *which_pers = hum[name_p];
        if (to_city == nullptr) {
            ct[c].name = name_c;
            world[name_c] = &ct[c];
            c++;
            to_city = world[name_c];
        }
        score_board.erase({which_pers->location->money, which_pers->location});
        score_board.erase({to_city->money, to_city});
        which_pers->location->money -= which_pers->money;
        score_board.insert({which_pers->location->money, which_pers->location});
        which_pers->location = to_city;
        to_city->money += hum[name_p]->money;
        score_board.insert({to_city->money, to_city});
    }

    int count = m - today;
    auto it2 = score_board.begin();
    auto it = it2++;
    if (it2 == score_board.end() || it->first > it2->first) {
        it->second->days += count;
    }

    for (auto &item : world) {
        if (item.second->days > 0)
            std::cout << item.first << " " << item.second->days << "\n";
    }
    return 0;
}