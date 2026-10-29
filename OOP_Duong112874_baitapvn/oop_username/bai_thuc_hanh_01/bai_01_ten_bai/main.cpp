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
    class ParkingLot {
private:
    int parkID;
    char size; 
    Vehicle vehicle1, vehicle2, vehicle3;
    bool hasVehicle1, hasVehicle2, hasVehicle3;
public:
    ParkingLot() {
        parkID = 0;
        size = 'S';
        hasVehicle1 = false; hasVehicle2 = false; hasVehicle3 = false;
    }
    ParkingLot(int id, char s) {
        parkID = id;
        size = s;
        hasVehicle1 = false; hasVehicle2 = false; hasVehicle3 = false;
    }
    int layParkID() const { return parkID; }
    char laySize() const { return size; }
    bool layHasVehicle1() const { return hasVehicle1; }
    bool layHasVehicle2() const { return hasVehicle2; }
    bool layHasVehicle3() const { return hasVehicle3; }
    Vehicle layVehicle1() const { return vehicle1; }
    Vehicle layVehicle2() const { return vehicle2; }
    Vehicle layVehicle3() const { return vehicle3; }

    int demSoXe() const {
        int dem = 0;
        if (hasVehicle1) dem++;
        if (hasVehicle2) dem++;
        if (hasVehicle3) dem++;
        return dem;
    }
    bool coMaXe(int vID) const {
        if (hasVehicle1 && vehicle1.layMaXe() == vID) return true;
        if (hasVehicle2 && vehicle2.layMaXe() == vID) return true;
        if (hasVehicle3 && vehicle3.layMaXe() == vID) return true;
        return false;
    }

    bool addVehicle(const Vehicle& v) {
        if (size == 'S') {
            if (!hasVehicle1) { vehicle1 = v; hasVehicle1 = true; return true; }
        } 
        else if (size == 'M') {
            if (!hasVehicle1) { vehicle1 = v; hasVehicle1 = true; return true; }
            else if (!hasVehicle2) { vehicle2 = v; hasVehicle2 = true; return true; }
        } 
        else if (size == 'L') {
            if (!hasVehicle1) { vehicle1 = v; hasVehicle1 = true; return true; }
            else if (!hasVehicle2) { vehicle2 = v; hasVehicle2 = true; return true; }
            else if (!hasVehicle3) { vehicle3 = v; hasVehicle3 = true; return true; }
        }
        return false;
    }
    bool removeVehicle(int vID) {
        if (hasVehicle1 && vehicle1.layMaXe() == vID) { hasVehicle1 = false; return true; }
        if (hasVehicle2 && vehicle2.layMaXe() == vID) { hasVehicle2 = false; return true; }
        if (hasVehicle3 && vehicle3.layMaXe() == vID) { hasVehicle3 = false; return true; }
        return false;
    }
    void displayLotInfo() const {
        cout << "- Bai do ID: " << parkID 
             << " | Kich thuoc (Size): " << size 
             << " | So xe hien tai: " << demSoXe() << endl;
        if (hasVehicle1) vehicle1.hienThi();
        if (hasVehicle2) vehicle2.hienThi();
        if (hasVehicle3) vehicle3.hienThi();
    }
};
        
            
    
    return 0;
}
