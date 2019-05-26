#pragma once
#include "BANDOC.h"
class GIAOVIEN :
	public BANDOC
{
private:
	string sDiaChi, sSoDT;
public:
	GIAOVIEN()
	{
		sDiaChi = "";
		sSoDT = 1;
	}
	GIAOVIEN(string sMaBanDoc, string sHoTen, string sKhoa, string sDiaChi, string sSoDT, int nNgay, int nThang, int nNam)
		:BANDOC(sMaBanDoc, sHoTen, sKhoa, nNgay, nThang, nNam)
	{
		this->sDiaChi = sDiaChi;
		this->sSoDT = sSoDT;
	}
	string getDiachi();
	string getSoDT();
	void setDiaChi(string sDiaChi);
	void setSoDT(string sSoDT);
	void setGiaoVien(string sDiaChi, string sSoDT);
	/*void inputBanDoc();*/
	void ouputBanDoc();
	friend ostream& operator<<(ostream& os, GIAOVIEN &gv);
	void nhapGiaoVienMoi();
	void readBanDoc(ifstream &file);
	void writeBanDoc(ofstream &file);
	~GIAOVIEN() {};
};

