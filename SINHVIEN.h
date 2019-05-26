#pragma once
#include "BANDOC.h"
class SINHVIEN :
	public BANDOC
{
private:
	string sKhoaHoc;
public:
	SINHVIEN()
	{
		sKhoaHoc = "";
	}
	SINHVIEN(string sKhoaHoc)
	{
		this->sKhoaHoc = sKhoaHoc;
	}
	SINHVIEN(string sMaBanDoc, string sHoTen, string sKhoa, string sKhoaHoc, int nNgay, int nThang, int nNam)
		:BANDOC(sMaBanDoc, sHoTen, sKhoa, nNgay, nThang, nNam)
	{
		this->sKhoaHoc = sKhoaHoc;
	}
	string getKhoaHoc();
	void setKhoaHoc(string sKhoaHoc);
	/*void inputBanDoc();*/
	void ouputBanDoc();
	friend ostream& operator<<(ostream& os, SINHVIEN &sv);
	void nhapSinhVienMoi();
	void readBanDoc(ifstream &file);
	void writeBanDoc(ofstream &file);
	~SINHVIEN() {};
};

