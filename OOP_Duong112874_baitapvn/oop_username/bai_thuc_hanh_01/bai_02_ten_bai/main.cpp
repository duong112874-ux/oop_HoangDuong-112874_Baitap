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

class phuong_tien {
private:
    int ma_xe;
    string loai_xe;
    int gio_vao;
    int tg_do;
    double phi_do_xe;

public:
    phuong_tien();
    phuong_tien(int ma, string loai, int gio, int tg);

    int lay_ma_xe() const;
    string lay_loai_xe() const;
    int lay_gio_vao() const;
    int lay_tg_do() const;
    double lay_phi_do_xe() const;

    void dat_ma_xe(int ma);
    void dat_loai_xe(string loai);
    void dat_gio_vao(int gio);
    void dat_tg_do(int tg);

    double tinh_phi() const;
    void hien_thi() const;
};

phuong_tien::phuong_tien() : ma_xe(0), loai_xe(""), gio_vao(0), tg_do(0), phi_do_xe(0.0) {}

phuong_tien::phuong_tien(int ma, string loai, int gio, int tg)
    : ma_xe(ma), loai_xe(loai), gio_vao(gio), tg_do(tg) {
    phi_do_xe = tinh_phi();
}

int phuong_tien::lay_ma_xe() const { return ma_xe; }
string phuong_tien::lay_loai_xe() const { return loai_xe; }
int phuong_tien::lay_gio_vao() const { return gio_vao; }
int phuong_tien::lay_tg_do() const { return tg_do; }
double phuong_tien::lay_phi_do_xe() const { return phi_do_xe; }

void phuong_tien::dat_ma_xe(int ma) { ma_xe = ma; }
void phuong_tien::dat_loai_xe(string loai) { loai_xe = loai; phi_do_xe = tinh_phi(); }
void phuong_tien::dat_gio_vao(int gio) { gio_vao = gio; phi_do_xe = tinh_phi(); }
void phuong_tien::dat_tg_do(int tg) { tg_do = tg; phi_do_xe = tinh_phi(); }

double phuong_tien::tinh_phi() const {
    double gia = (loai_xe == "Car") ? 6.0 : (loai_xe == "Motorcycle") ? 4.0 : 2.0;
    bool cao_diem = (gio_vao >= 6 && gio_vao <= 9) || (gio_vao >= 15 && gio_vao <= 18);
    double tong = 0;
    for (int h = 0; h < tg_do; ++h) {
        if (h < 2) tong += gia * (cao_diem ? 1.30 : 0.95);
        else       tong += gia * 0.90;
    }
    return tong;
}

void phuong_tien::hien_thi() const {
    cout << "  ID: " << ma_xe << " | " << loai_xe
         << " | " << gio_vao << "h | " << tg_do << "h"
         << " | Phi: $" << fixed << setprecision(2) << phi_do_xe << "\n";
}


class bai_xe {
private:
    int ma_bai;
    char kich_thuoc;
    static const int SO_XE_TOI_DA = 3; 
    phuong_tien ds_xe[SO_XE_TOI_DA];   
    int so_xe_hien_tai;                

public:
    bai_xe();
    bai_xe(int ma, char kt);

    int lay_ma_bai() const;
    char lay_kich_thuoc() const;
    int lay_so_xe_hien_tai() const;
    int lay_suc_chua_toi_da() const;

    bool da_day() const;
    bool them_xe(const phuong_tien& xe);
    bool xoa_xe(int ma_xe);
    int tim_vi_tri_xe(int ma_xe) const;
    void hien_thi_thong_tin_bai() const;

    void liet_ke_theo_loai(const string& loai, bool& tim_thay) const;
    void thong_ke_loai(const string& loai, int& dem, double& tong_phi) const;
};

bai_xe::bai_xe() : ma_bai(0), kich_thuoc('S'), so_xe_hien_tai(0) {}

bai_xe::bai_xe(int ma, char kt) : ma_bai(ma), kich_thuoc(kt), so_xe_hien_tai(0) {}

int bai_xe::lay_ma_bai() const { return ma_bai; }
char bai_xe::lay_kich_thuoc() const { return kich_thuoc; }
int bai_xe::lay_so_xe_hien_tai() const { return so_xe_hien_tai; }

int bai_xe::lay_suc_chua_toi_da() const {
    if (kich_thuoc == 'S' || kich_thuoc == 's') return 1;
    if (kich_thuoc == 'M' || kich_thuoc == 'm') return 2;
    return 3; 
}

bool bai_xe::da_day() const {
    return so_xe_hien_tai >= lay_suc_chua_toi_da();
}

bool bai_xe::them_xe(const phuong_tien& xe) {
    if (da_day()) return false;
    ds_xe[so_xe_hien_tai] = xe;
    so_xe_hien_tai++;
    return true;
}

int bai_xe::tim_vi_tri_xe(int ma_xe) const {
    for (int i = 0; i < so_xe_hien_tai; ++i) {
        if (ds_xe[i].lay_ma_xe() == ma_xe) {
            return i;
        }
    }
    return -1;
}

bool bai_xe::xoa_xe(int ma_xe) {
    int vi_tri = tim_vi_tri_xe(ma_xe);
    if (vi_tri == -1) return false;

   
    for (int i = vi_tri; i < so_xe_hien_tai - 1; ++i) {
        ds_xe[i] = ds_xe[i + 1];
    }
    so_xe_hien_tai--;
    return true;
}

void bai_xe::hien_thi_thong_tin_bai() const {
    cout << "Bai " << ma_bai << " [" << kich_thuoc << "] "
         << so_xe_hien_tai << "/" << lay_suc_chua_toi_da() << " xe\n";
    for (int i = 0; i < so_xe_hien_tai; ++i) {
        ds_xe[i].hien_thi();
    }
}

void bai_xe::liet_ke_theo_loai(const string& loai, bool& tim_thay) const {
    for (int i = 0; i < so_xe_hien_tai; ++i) {
        if (ds_xe[i].lay_loai_xe() == loai) {
            cout << "[Bai " << ma_bai << "] ";
            ds_xe[i].hien_thi();
            tim_thay = true;
        }
    }
}

void bai_xe::thong_ke_loai(const string& loai, int& dem, double& tong_phi) const {
    dem = 0;
    tong_phi = 0.0;
    for (int i = 0; i < so_xe_hien_tai; ++i) {
        if (ds_xe[i].lay_loai_xe() == loai) {
            dem++;
            tong_phi += ds_xe[i].lay_phi_do_xe();
        }
    }
}


class he_thong_quan_ly {
private:
    static const int SO_BAI_TOI_DA = 10; 
    bai_xe ds_bai[SO_BAI_TOI_DA];        
    int so_bai_hien_tai;                 

public:
    he_thong_quan_ly();

    void chay_menu();
    bool ton_tai_ma_bai(int ma_bai) const;
    bool ton_tai_ma_xe(int ma_xe) const;
    int sinh_ma_ngau_nhien() const;
};

he_thong_quan_ly::he_thong_quan_ly() : so_bai_hien_tai(0) {}

bool he_thong_quan_ly::ton_tai_ma_bai(int ma_bai) const {
    for (int i = 0; i < so_bai_hien_tai; ++i) {
        if (ds_bai[i].lay_ma_bai() == ma_bai) return true;
    }
    return false;
}

bool he_thong_quan_ly::ton_tai_ma_xe(int ma_xe) const {
    for (int i = 0; i < so_bai_hien_tai; ++i) {
        if (ds_bai[i].tim_vi_tri_xe(ma_xe) != -1) return true;
    }
    return false;
}

int he_thong_quan_ly::sinh_ma_ngau_nhien() const {
    return 1000 + rand() % 9000; 
}

void he_thong_quan_ly::chay_menu() {
    int lua_chon;
    while (true) {
        cout << "\n===== QUAN LY BAI DO XE (GIAI DOAN 2) =====\n";
        cout << "1. Tao bai do xe moi\n";
        cout << "2. Them xe vao bai do\n";
        cout << "3. Xoa mot bai do xe\n";
        cout << "4. Lay xe ra khoi bai do\n";
        cout << "5. Hien thi danh sach tat ca cac bai do xe\n";
        cout << "6. Hien thi danh sach xe theo bai cu the\n";
        cout << "7. Liet ke xe theo loai phuong tien\n";
        cout << "8. Tom tat phi do xe trung binh\n";
        cout << "9. Thoat chuong trinh\n";
        
        lua_chon = nhap_so_nguyen("Chon chuc nang (1-9): ");

        switch (lua_chon) {
            case 1: { 
                if (so_bai_hien_tai >= SO_BAI_TOI_DA) {
                    cout << "Canh bao: He thong da dat toi da " << SO_BAI_TOI_DA << " bai do!\n";
                    break;
                }
                int ma_bai = nhap_so_nguyen("Nhap ma bai do: ");
                if (ton_tai_ma_bai(ma_bai)) {
                    do {
                        ma_bai = sinh_ma_ngau_nhien();
                    } while (ton_tai_ma_bai(ma_bai));
                    cout << "Canh bao: Ma bai da ton tai! He thong tu dong cap ma moi: " << ma_bai << "\n";
                }

                char kt;
                while (true) {
                    cout << "Nhap kich thuoc bai (S/M/L): ";
                    cin >> kt;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    kt = toupper(kt);
                    if (kt == 'S' || kt == 'M' || kt == 'L') break;
                    cout << "Loi: Chi chap nhan S, M hoac L!\n";
                }

                ds_bai[so_bai_hien_tai] = bai_xe(ma_bai, kt);
                so_bai_hien_tai++;
                cout << "Da tao thanh cong bai do " << ma_bai << " [" << kt << "]\n";
                break;
            }

            case 2: {
                if (so_bai_hien_tai == 0) {
                    cout << "Canh bao: Chua co bai do nao trong he thong!\n";
                    break;
                }

                int ma_xe = nhap_so_nguyen("Nhap ma xe: ");
                if (ton_tai_ma_xe(ma_xe)) {
                    do {
                        ma_xe = sinh_ma_ngau_nhien();
                    } while (ton_tai_ma_xe(ma_xe));
                    cout << "Canh bao: Ma xe da ton tai! He thong tu dong cap ma moi: " << ma_xe << "\n";
                }

                string loai;
                while (true) {
                    cout << "Nhap loai xe (Car/Motorcycle/Bicycle): ";
                    cin >> loai;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (loai == "Car" || loai == "Motorcycle" || loai == "Bicycle") break;
                    cout << "Loi: Loai xe phai la Car, Motorcycle hoac Bicycle!\n";
                }

                int gio;
                while (true) {
                    gio = nhap_so_nguyen("Nhap gio vao (0-23): ");
                    if (gio >= 0 && gio <= 23) break;
                    cout << "Loi: Gio vao phai tu 0 den 23!\n";
                }

                int tg;
                while (true) {
                    tg = nhap_so_nguyen("Nhap thoi luong do (1-23 gio): ");
                    if (tg >= 1 && tg <= 23) break;
                    cout << "Loi: Thoi luong do phai tu 1 den 23!\n";
                }

                phuong_tien xe_moi(ma_xe, loai, gio, tg);
                bool da_xep = false;
                for (int i = 0; i < so_bai_hien_tai; ++i) {
                    if (!ds_bai[i].da_day()) {
                        ds_bai[i].them_xe(xe_moi);
                        cout << "Da xep xe " << ma_xe << " vao Bai " << ds_bai[i].lay_ma_bai()
                             << " | Phi du kien: $" << fixed << setprecision(2) << xe_moi.lay_phi_do_xe() << "\n";
                        da_xep = true;
                        break;
                    }
                }
                if (!da_xep) {
                    cout << "Canh bao: Tat ca cac bai do hien co deu da day!\n";
                }
                break;
            }

            case 3: {
                if (so_bai_hien_tai == 0) {
                    cout << "He thong chua co bai do nao!\n";
                    break;
                }
                int ma_bai = nhap_so_nguyen("Nhap ma bai can xoa: ");
                int vi_tri = -1;
                for (int i = 0; i < so_bai_hien_tai; ++i) {
                    if (ds_bai[i].lay_ma_bai() == ma_bai) {
                        vi_tri = i;
                        break;
                    }
                }

                if (vi_tri == -1) {
                    cout << "Khong tim thay bai do co ma " << ma_bai << "\n";
                } else {
                    for (int i = vi_tri; i < so_bai_hien_tai - 1; ++i) {
                        ds_bai[i] = ds_bai[i + 1];
                    }
                    so_bai_hien_tai--;
                    cout << "Da xoa bai do " << ma_bai << "\n";
                }
                break;
            }

            case 4: { 
                if (so_bai_hien_tai == 0) {
                    cout << "He thong chua co bai do nao!\n";
                    break;
                }
                int ma_xe = nhap_so_nguyen("Nhap ma xe can lay ra: ");
                bool da_xoa = false;
                for (int i = 0; i < so_bai_hien_tai; ++i) {
                    if (ds_bai[i].xoa_xe(ma_xe)) {
                        cout << "Da lay xe " << ma_xe << " ra khoi Bai " << ds_bai[i].lay_ma_bai() << "\n";
                        da_xoa = true;
                        break;
                    }
                }
                if (!da_xoa) {
                    cout << "Khong tim thay xe co ma " << ma_xe << " trong he thong!\n";
                }
                break;
            }

            case 5: { 
                if (so_bai_hien_tai == 0) {
                    cout << "Chua co bai do nao trong he thong.\n";
                    break;
                }
                for (int i = 0; i < so_bai_hien_tai; ++i) {
                    ds_bai[i].hien_thi_thong_tin_bai();
                }
                break;
            }

            case 6: {
                int ma_bai = nhap_so_nguyen("Nhap ma bai can xem: ");
                bool tim_thay = false;
                for (int i = 0; i < so_bai_hien_tai; ++i) {
                    if (ds_bai[i].lay_ma_bai() == ma_bai) {
                        ds_bai[i].hien_thi_thong_tin_bai();
                        tim_thay = true;
                        break;
                    }
                }
                if (!tim_thay) {
                    cout << "Khong tim thay bai do " << ma_bai << "\n";
                }
                break;
            }

            case 7: {
                string loai;
                cout << "Nhap loai xe can loc (Car/Motorcycle/Bicycle): ";
                cin >> loai;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                bool tim_thay = false;
                for (int i = 0; i < so_bai_hien_tai; ++i) {
                    ds_bai[i].liet_ke_theo_loai(loai, tim_thay);
                }
                if (!tim_thay) {
                    cout << "Khong co xe loai " << loai << " nao dang do.\n";
                }
                break;
            }

            case 8: { 
                if (so_bai_hien_tai == 0) {
                    cout << "Chua co du lieu bai do de thong ke.\n";
                    break;
                }
                string ds_loai[3] = {"Car", "Motorcycle", "Bicycle"};

                cout << "\n--- BAO CAO PHI TRUNG BINH TOAN HE THONG ---\n";
                for (int t = 0; t < 3; ++t) {
                    int tong_so_xe = 0;
                    double tong_tien = 0.0;
                    for (int i = 0; i < so_bai_hien_tai; ++i) {
                        int d = 0; double s = 0.0;
                        ds_bai[i].thong_ke_loai(ds_loai[t], d, s);
                        tong_so_xe += d;
                        tong_tien += s;
                    }
                    cout << ds_loai[t] << ": ";
                    if (tong_so_xe == 0) cout << "khong co xe\n";
                    else cout << tong_so_xe << " xe | Phi TB: $" << fixed << setprecision(2) << (tong_tien / tong_so_xe) << "\n";
                }

                cout << "\n--- CHI TIET PHI TRUNG BINH THEO TUNG BAI ---\n";
                for (int i = 0; i < so_bai_hien_tai; ++i) {
                    cout << "Bai " << ds_bai[i].lay_ma_bai() << ":\n";
                    for (int t = 0; t < 3; ++t) {
                        int d = 0; double s = 0.0;
                        ds_bai[i].thong_ke_loai(ds_loai[t], d, s);
                        cout << "  - " << ds_loai[t] << ": ";
                        if (d == 0) cout << "0 xe\n";
                        else cout << d << " xe | Phi TB: $" << fixed << setprecision(2) << (s / d) << "\n";
                    }
                }
                break;
            }

            case 9:
                cout << "Da thoat chuong trinh!\n";
                return;

            default:
                cout << "Lua chon khong hop le! Vui long chon tu 1 den 9.\n";
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); 
    he_thong_quan_ly he_thong;
    he_thong.chay_menu();
    return 0;
}
