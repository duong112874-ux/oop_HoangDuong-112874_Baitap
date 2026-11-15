#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;
int nhap_so_nguyen(const string& thong_bao) {
    int gia_tri;
    while (true) {
        cout << thong_bao;
        cin >> gia_tri;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Loi: Du lieu khong hop le! Vui long nhap so nguyen.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return gia_tri;
        }
    }
}
