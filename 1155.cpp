#include <iostream>

using namespace std;

int main(){
    int cube[8] = {};

    for (int &i : cube) {
        cin >> i;
    }

    if (cube[0] + cube[2] + cube[5] + cube[7] != cube[1] + cube[3] + cube[4] + cube[6]){
        cout << "IMPOSSIBLE";
        return 0;
    }

    // обнуляем вершину А (cube[0])
    while(cube[0] > 0){
        while (cube[0] > 0 && cube[1] > 0){
            cout << "AB-" << endl;
            cube[0]--;
            cube[1]--;
        }
        while (cube[0] > 0 && cube[3] > 0){
            cout << "AD-" << endl;
            cube[0]--;
            cube[3]--;
        }
        while (cube[0] > 0 && cube[4] > 0){
            cout << "AE-" << endl;
            cube[0]--;
            cube[4]--;
        }
        for (int i = 0; i < cube[0]; ++i){
            cout << "BF+" << endl;
        }
        cube[1] += cube[0];
        cube[5] += cube[0];
    }

    // обнуляем верину С (cube[2])
    while (cube[2] > 0) {
        while (cube[2] > 0 && cube[1] > 0) {
            cout << "BC-" << endl;
            cube[2]--;
            cube[1]--;
        }
        while (cube[2] > 0 && cube[3] > 0) {
            cout << "CD-" << endl;
            cube[2]--;
            cube[3]--;
        }
        while (cube[2] > 0 && cube[6] > 0) {
            cout << "CG-" << endl;
            cube[2]--;
            cube[6]--;
        }
        for (int i = 0; i < cube[2]; ++i){
            cout << "GH+" << endl;
        }
        cube[6] += cube[2];
        cube[7] += cube[2];
    }

    //обнуляем вершину F (cube[5])
    while (cube[5] > 0) {
        while (cube[5] > 0 && cube[1] > 0){
            cout << "BF-" << endl;
            cube[1]--;
            cube[5]--;
        }
        while (cube[5] > 0 && cube[4] > 0) {
            cout << "EF-" << endl;
            cube[4]--;
            cube[5]--;
        }
        while (cube[5] > 0 && cube[6] > 0) {
            cout << "FG-" << endl;
            cube[5]--;
            cube[6]--;
        }
        for (int i = 0; i < cube[5]; ++i){
            cout << "GH+" << endl;
        }
        cube[6] += cube[5];
        cube[7] += cube[7];
    }

    //обнуляем вершину H (cube[7])
    while (cube[7] > 0) {
        while (cube[7] > 0 && cube[3] > 0) {
            cout << "DH-" << endl;
            cube[7]--;
            cube[3]--;
        }
        while (cube[7] > 0 && cube[4] > 0) {
            cout << "EH-" << endl;
            cube[7]--;
            cube[4]--;
        }
        while (cube[7] > 0 && cube[6] > 0) {
            cout << "GH-" << endl;
            cube[7]--;
            cube[6]--;
        }
    }
}