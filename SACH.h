#include "Date.h"
#include <string>
using namespace std;
#pragma once
class SACH
{
private:
	string sMaSach, sTieuDe, sTacGia, sNhaXuatBan;
	float fGiaBan;
	int nNamPhatHanh, nSoTrang;
	Date ngayNhapKho;
	int nTinhTrang;
public:
	/*friend PHIEUMUON;*/
	SACH()
	{
		this->sMaSach = "";
		this->sTieuDe = "";
		this->sTacGia = "";
		this->sNhaXuatBan = "";
		this->fGiaBan = 0;
		this->nNamPhatHanh = 0;
		this->nSoTrang = 0;
		this->nTinhTrang = 0;
	}
	SACH(string sMaSach) :ngayNhapKho()
	{
		this->sMaSach = sMaSach;
		this->sTieuDe = "";
		this->sTacGia = "";
		this->sNhaXuatBan = "";
		this->fGiaBan = 0;
		this->nNamPhatHanh = 0;
		this->nSoTrang = 0;
		this->nTinhTrang = 0;
	}
	SACH(string sMaSach, string sTieuDe, string sTacGia, string sNhaXuatBan, float fGiaBan, int nNamPhatHanh, int nSoTrang, int nNgay, int nThang, int nNam, int nTinhTrang)
		:ngayNhapKho(nNgay, nThang, nNam)
	{
		this->sMaSach = sMaSach;
		this->sTieuDe = sTieuDe;
		this->sTacGia = sTacGia;
		this->sNhaXuatBan = sNhaXuatBan;
		this->fGiaBan = fGiaBan;
		this->nNamPhatHanh = nNamPhatHanh;
		this->nSoTrang = nSoTrang;
		this->nTinhTrang = 0;
	}
	SACH(string sMaSach, string sTieuDe, string sTacGia, string sNhaXuatBan, float fGiaBan, int nNamPhatHanh, int nSoTrang, int nTinhTrang)
	{
		this->sMaSach = sMaSach;
		this->sTieuDe = sTieuDe;
		this->sTacGia = sTacGia;
		this->sNhaXuatBan = sNhaXuatBan;
		this->fGiaBan = fGiaBan;
		this->nNamPhatHanh = nNamPhatHanh;
		this->nSoTrang = nSoTrang;
		this->nTinhTrang = 0;
	}
	string getMaSach()
	{
		return this->sMaSach;
	}
	string getTieuDe()
	{
		return this->sTieuDe;
	}
	string getTacGia()
	{
		return this->sTacGia;
	}
	string getNXB()
	{
		return this->sNhaXuatBan;
	}
	float getGiaBan()
	{
		return this->fGiaBan;
	}
	int getNamPhatHanh()
	{
		return this->nNamPhatHanh;
	}
	int getSoTrang()
	{
		return this->nSoTrang;
	}
	Date getNgayNhapKho()
	{
		return this->ngayNhapKho;
	}
	int getTinhTrang()
	{
		return this->nTinhTrang;
	}
	void setTinhTrangSach(int nTinhTrang)
	{
		this->nTinhTrang = nTinhTrang;
	}
	friend ostream& operator<<(ostream& os, SACH& sach);
	void outputSach();
	void writeSach(ofstream& file);
	void readSach(ifstream& file);
	void nhapSachMoi();
	~SACH() {};
};




