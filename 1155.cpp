#include <iostream>

using namespace std;

int main() {
    int cube[8] = {};

    for (int &i : cube) {
        cin >> i;
    }

    if (cube[0] + cube[2] + cube[5] + cube[7] != cube[1] + cube[3] + cube[4] + cube[6]) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    // обнуляем вершину А (cube[0])
    if (cube[0] > 0) {
        int min1 = min(cube[0], cube[1]);
        for (int i = 0; i < min1; ++i) {
            cout << "AB-" << endl;
        }
        cube[0] -= min1;
        cube[1] -= min1;

        int min2 = min(cube[0], cube[3]);
        for (int i = 0; i < min2; ++i) {
            cout << "AD-" << endl;
        }
        cube[0] -= min2;
        cube[3] -= min2;

        int min3 = min(cube[0], cube[4]);
        for (int i = 0; i < min3; ++i) {
            cout << "AE-" << endl;
        }
        cube[0] -= min3;
        cube[4] -= min3;

        for (int i = 0; i < cube[0]; ++i) {
            cout << "BF+" << endl;
        }
        cube[1] += cube[0];
        cube[5] += cube[0];

        min1 = min(cube[0], cube[1]);
        for (int i = 0; i < min1; ++i) {
            cout << "AB-" << endl;
        }
        cube[0] -= min1;
        cube[1] -= min1;
    }

    // обнуляем верину С (cube[2])
    if (cube[2] > 0) {
        int min1 = min(cube[2], cube[1]);
        for (int i = 0; i < min1; ++i) {
            cout << "BC-" << endl;
        }
        cube[2] -= min1;
        cube[1] -= min1;

        int min2 = min(cube[2], cube[3]);
        for (int i = 0; i < min2; ++i) {
            cout << "CD-" << endl;
        }
        cube[2] -= min2;
        cube[3] -= min2;

        int min3 = min(cube[2], cube[6]);
        for (int i = 0; i < min3; ++i) {
            cout << "CG-" << endl;
        }
        cube[2] -= min3;
        cube[6] -= min3;

        for (int i = 0; i < cube[2]; ++i) {
            cout << "GH+" << endl;
        }
        cube[6] += cube[2];
        cube[7] += cube[2];

        min3 = min(cube[2], cube[6]);
        for (int i = 0; i < min3; ++i) {
            cout << "CG-" << endl;
        }
        cube[2] -= min3;
        cube[6] -= min3;
    }

    //обнуляем вершину F (cube[5])
    if (cube[5] > 0) {
        int min1 = min(cube[5], cube[1]);
        for (int i = 0; i < min1; ++i) {
            cout << "BF-" << endl;
        }
        cube[1] -= min1;
        cube[5] -= min1;

        int min2 = min(cube[5], cube[4]);
        for (int i = 0; i < min2; ++i) {
            cout << "EF-" << endl;
        }
        cube[4] -= min2;
        cube[5] -= min2;

        int min3 = min(cube[5], cube[6]);
        for (int i = 0; i < min3; ++i) {
            cout << "FG-" << endl;
        }
        cube[5] -= min3;
        cube[6] -= min3;

        for (int i = 0; i < cube[5]; ++i) {
            cout << "GH+" << endl;
        }
        cube[6] += cube[5];
        cube[7] += cube[5];

        min3 = min(cube[5], cube[6]);
        for (int i = 0; i < min3; ++i) {
            cout << "FG-" << endl;
        }
        cube[5] -= min3;
        cube[6] -= min3;
    }

    //обнуляем вершину H (cube[7])
    if (cube[7] > 0) {
        int min1 = min(cube[7], cube[3]);
        for (int i = 0; i < min1; ++i) {
            cout << "DH-" << endl;
        }
        cube[7] -= min1;
        cube[3] -= min1;

        int min2 = min(cube[7], cube[4]);
        for (int i = 0; i < min2; ++i) {
            cout << "EH-" << endl;
        }
        cube[7] -= min2;
        cube[4] -= min2;

        int min3 = min(cube[7], cube[6]);
        for (int i = 0; i < min3; ++i) {
            cout << "GH-" << endl;
        }
//        cube[7] -= min3;
//        cube[6] -= min3;
    }
}