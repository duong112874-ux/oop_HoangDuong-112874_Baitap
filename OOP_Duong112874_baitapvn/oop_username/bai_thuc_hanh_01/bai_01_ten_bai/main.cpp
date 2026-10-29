#include <iostream>
using namespace std;

int main() {
    class Xe {
private:
    int maXe;
    string loaiXe;      
    int gioVao;        
    int thoiGianDo;    
    double phiDoXe;
    bool dangChiemCho;
public:
    Xe() {
        maXe = 0;
        loaiXe = "Car";
        gioVao = 0;
        thoiGianDo = 1;
        phiDoXe = 0;
        dangChiemCho = false;
    }
    Xe(int ma, string loai, int gio, int thoiLuong) {
        maXe = ma;
        loaiXe = loai;
        gioVao = gio;
        thoiGianDo = thoiLuong;
        dangChiemCho = true;
        tinhPhiDoXe();
    }
    int layMaXe() const { return maXe; }
    string layLoaiXe() const { return loaiXe; }
    int layGioVao() const { return gioVao; }
    int layThoiGianDo() const { return thoiGianDo; }
    double layPhiDoXe() const { return phiDoXe; }
    bool layDangChiemCho() const { return dangChiemCho; }
    
    void ganMaXe(int ma) { maXe = ma; }
    void ganLoaiXe(const string& loai) { loaiXe = chuanHoaLoaiXe(loai); }
    void ganGioVao(int gio) { gioVao = gio; }
    void ganThoiLuongDo(int thoiLuong) { thoiGianDo = thoiLuong; }
    void ganPhiDoXe(double phi) { phiDoXe = phi; }
    void ganDangChiemCho(bool trangThai) { dangChiemCho = trangThai; }

    static string chuanHoaLoaiXe(const string& loai) {
        string chuThuong = "";
        for (char c : loai) {
            chuThuong += static_cast<char>(tolower(static_cast<unsigned char>(c)));
        }
        if (chuThuong == "car") return "Car";
        if (chuThuong == "motorcycle") return "Motorcycle";
        if (chuThuong == "bicycle") return "Bicycle";
        return loai;

        static bool laLoaiXeHopLe(const string& loai) {
        string chuan = chuanHoaLoaiXe(loai);
        return (chuan == "Car" || chuan == "Motorcycle" || chuan == "Bicycle");
        }
    void tinhPhiDoXe() {
        double donGiaCoBan = 0.0;
        string loaiChuan = chuanHoaLoaiXe(loaiXe);
        if (loaiChuan == "Car") {
            donGiaCoBan = 6.0;
        } else if (loaiChuan == "Motorcycle") {
            donGiaCoBan = 4.0;
        } else if (loaiChuan == "Bicycle") {
            donGiaCoBan = 2.0;
        }
        bool laGioCaoDiem = ((gioVao >= 6 && gioVao <= 9) || (gioVao >= 15 && gioVao <= 18));
        int soGioDau = (thoiGianDo <= 2) ? thoiGianDo : 2;
        int soGioTiepTheo = (thoiGianDo > 2) ? (thoiGianDo - 2) : 0;
        double phiHaiGioDau = 0.0;
        if (laGioCaoDiem) {
            phiHaiGioDau = soGioDau * donGiaCoBan * 1.30;
        } else {
            phiHaiGioDau = soGioDau * donGiaCoBan * 0.95;
        }
        double phiCacGioSau = soGioTiepTheo * donGiaCoBan * 0.90;
        phiDoXe = phiHaiGioDau + phiCacGioSau;
    }
        void hienThi() const {
        cout << "   + Ma xe: " << maXe
             << " Loai: " << setw(10) << left << loaiXe
             << " Gio vao: " << setw(2) << right << gioVao << "h"
             << " Thoi gian do: " << setw(2) << thoiGianDo << "h"
             << " Phi do xe: $" << fixed << setprecision(2) << phiDoXe << endl;
    }
};
        
            
    
    return 0;
}
