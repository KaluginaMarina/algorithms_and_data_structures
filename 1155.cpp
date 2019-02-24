#include <iostream>

int main() {
    int cube[8] = {};

    for (int &i : cube) {
        std::cin >> i;
    }

    if (cube[0] + cube[2] + cube[5] + cube[7] != cube[1] + cube[3] + cube[4] + cube[6]) {
        std::cout << "IMPOSSIBLE";
        return 0;
    }

    // обнуляем вершину А (cube[0])
    if (cube[0] > 0) {
        int min1 = std::min(cube[0], cube[1]);
        for (int i = 0; i < min1; ++i) {
            std::cout << "AB-" << std::endl;
        }
        cube[0] -= min1;
        cube[1] -= min1;

        int min2 = std::min(cube[0], cube[3]);
        for (int i = 0; i < min2; ++i) {
            std::cout << "AD-" << std::endl;
        }
        cube[0] -= min2;
        cube[3] -= min2;

        int min3 = std::min(cube[0], cube[4]);
        for (int i = 0; i < min3; ++i) {
            std::cout << "AE-" << std::endl;
        }
        cube[0] -= min3;
        cube[4] -= min3;

        for (int i = 0; i < cube[0]; ++i) {
            std::cout << "BF+" << std::endl;
        }
        cube[1] += cube[0];
        cube[5] += cube[0];

        min1 = std::min(cube[0], cube[1]);
        for (int i = 0; i < min1; ++i) {
            std::cout << "AB-" << std::endl;
        }
        cube[0] -= min1;
        cube[1] -= min1;
    }

    // обнуляем верину С (cube[2])
    if (cube[2] > 0) {
        int min1 = std::min(cube[2], cube[1]);
        for (int i = 0; i < min1; ++i) {
            std::cout << "BC-" << std::endl;
        }
        cube[2] -= min1;
        cube[1] -= min1;

        int min2 = std::min(cube[2], cube[3]);
        for (int i = 0; i < min2; ++i) {
            std::cout << "CD-" << std::endl;
        }
        cube[2] -= min2;
        cube[3] -= min2;

        int min3 = std::min(cube[2], cube[6]);
        for (int i = 0; i < min3; ++i) {
            std::cout << "CG-" << std::endl;
        }
        cube[2] -= min3;
        cube[6] -= min3;

        for (int i = 0; i < cube[2]; ++i) {
            std::cout << "GH+" << std::endl;
        }
        cube[6] += cube[2];
        cube[7] += cube[2];

        min3 = std::min(cube[2], cube[6]);
        for (int i = 0; i < min3; ++i) {
            std::cout << "CG-" << std::endl;
        }
        cube[2] -= min3;
        cube[6] -= min3;
    }

    //обнуляем вершину F (cube[5])
    if (cube[5] > 0) {
        int min1 = std::min(cube[5], cube[1]);
        for (int i = 0; i < min1; ++i) {
            std::cout << "BF-" << std::endl;
        }
        cube[1] -= min1;
        cube[5] -= min1;

        int min2 = std::min(cube[5], cube[4]);
        for (int i = 0; i < min2; ++i) {
            std::cout << "EF-" << std::endl;
        }
        cube[4] -= min2;
        cube[5] -= min2;

        int min3 = std::min(cube[5], cube[6]);
        for (int i = 0; i < min3; ++i) {
            std::cout << "FG-" << std::endl;
        }
        cube[5] -= min3;
        cube[6] -= min3;

        for (int i = 0; i < cube[5]; ++i) {
            std::cout << "GH+" << std::endl;
        }
        cube[6] += cube[5];
        cube[7] += cube[5];

        min3 = std::min(cube[5], cube[6]);
        for (int i = 0; i < min3; ++i) {
            std::cout << "FG-" << std::endl;
        }
        cube[5] -= min3;
        cube[6] -= min3;
    }

    //обнуляем вершину H (cube[7])
    if (cube[7] > 0) {
        int min1 = std::min(cube[7], cube[3]);
        for (int i = 0; i < min1; ++i) {
            std::cout << "DH-" << std::endl;
        }
        cube[7] -= min1;
        cube[3] -= min1;

        int min2 = std::min(cube[7], cube[4]);
        for (int i = 0; i < min2; ++i) {
            std::cout << "EH-" << std::endl;
        }
        cube[7] -= min2;
        cube[4] -= min2;

        int min3 = std::min(cube[7], cube[6]);
        for (int i = 0; i < min3; ++i) {
            std::cout << "GH-" << std::endl;
        }
        cube[7] -= min3;
        cube[6] -= min3;
    }

    for (int i = 0; i < cube[7]; ++i){
        std::cout << "CD+" << std::endl;
        std::cout << "BC-" << std::endl;
        std::cout << "DH-" << std::endl;
    }
    cube[1] -= cube[7];
    cube[7] = 0;
}