#include <iostream>
#include <map>

/**
 * все до безобразия просто -- строим дерево
 */

struct tree {
    tree() {
        this->name = "";
        this->child = {};
    }

    tree(std::string name) {
        this->name = name;
        this->child = {};
    }

    tree(std::string name, std::map< std::string, tree *> child) {
        this->name = name;
        this->child = child;
    }

    std::string name;
    std::map< std::string, tree *> child;
};

void print_tr(tree *tr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        std::cout << " ";
    }
    if (tr->name != "") {
        std::cout << tr->name << std::endl;
    }
    ++n;
    for (auto &j : tr->child) {
        print_tr(j.second, n);
    }
}

int main() {
    int n;
    std::cin >> n;

    tree *tr_root = new tree();

    for (int i = 0; i < n; ++i) {
        std::string patch;
        std::cin >> patch;
        std::string dir = "";

        tree *tr = tr_root;
        for (int j = 0; j <= patch.size(); ++j) {
            if (patch[j] == '\\' || patch[j] == '\0') {
                auto dir_tr = tr->child.find(dir);
                if (dir_tr == tr->child.end()){
                    tree *new_tree = new tree(dir);
                    tr->child[dir] = new_tree;
                    tr = tr->child.find(dir)->second;
                } else {
                    tr = dir_tr->second;
                }
                dir = "";
            } else {
                dir += patch[j];
            }
        }

    }
    print_tr(tr_root, 0);
    return 0;
}