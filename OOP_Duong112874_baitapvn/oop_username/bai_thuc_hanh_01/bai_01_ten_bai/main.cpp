#include<iosream>
#include<string>
class phuong_tien{
	private:
		int ma_xe;
		string loai_xe;
		int gio_vao:
		int tg_do;
		
	public:
		phuong_tien();
		phuong_tien(int ma, string loai, int gio, int tg);
		
		int lay_ma_xe()const;
		string lay_loai_xe()const;
		double tinh_phi()const;
		void hien_thi()const;
};
phuong_tien::phuong_tien(){
	ma_xe = 0;
    loai_xe = "";
    gio_vao = 0;
	tg_do = 0;
}
phuong_tien::phuong_tien(int ma, string loai, int gio, int tg){
	ma_xe = ma;
	loai_xe = loai;
	gio_vao = gio;
	tg_do = tg;
}
phuong_tien::lay_ma_xe() const{return ma_xe;}
phuong_tien::lay_loai_xe() const{return loai_xe;}
phuong_tien::hien_thi() const{
	cout<< "Ma xe: " << ma_xe <<endl
	   	<< "Loai xe: " << loai_xe << endl
	   	<< "Gio vao: " << gio_vao << endl
	   	<< "Thoi gian do: " << tg_do << endl;
}
double phuong_tien :: tinh_phi() cons{
	double tien = 0;
	if(loai_xe == "Car"){
		tien += 6;
	}
	else if(loai_xe == "Motorcycle"){
		tien += 4;
	}
	else if(loai_xe == "Bicycle"){
		tien += 3;
	}
}
bool caodiem = (tg_vao >= 6 && entryTime <= 9) || (tg_vao >= 15 && tg_vao <= 18);
int gioDau = (tg_do < 2) ? tg_do : 2;
double giaDau = caoDiem ? tien * 1,3 : tien * 0.95;
int gioSau = tg_Do - gioDau;
double giaSau = tien * 0.9;
parking.

class bai_xe{
	private:
		int ma_bai:
		char kich_thuoc;
		phuong_tien pt1, pt2, pt3;
		bool co1, co2, co3;
		
	public:
		bai_xe();
		bai_xe(int ma, char kt);
		
		int lay_ma()const;
		bool them(phuong_tien v);
		bool chua(int ma_xe)const;
		void hien_thi()const;
		bool co_loai(string loai, int& dem, double& tong)const;
		
};
class SystemInterface{
	private:
		bai_xe bai1, bai2, bai3;
		bool co1, co2, co3;
	public:
		SystemInterface();
		void runMenu();
};
