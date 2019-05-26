#ifndef _PHIEUMUON_
#define _PHIEUMUON_

#include "SINHVIEN.h"
#include "SACH.h"
#include "GIAOVIEN.h"
class PHIEUMUON
{
private:
	static int stt;
	int STT = 0;
	Date xDate;
	BANDOC xBandoc;
	SACH xSach;
	int tinhtrang = 1;
	string mabandoc;
	string masach;
	int ngaymuon = 0;
	int thangmuon = 0;
	int nammuon = 0;
	int ngaytra = 0;
	int thangtra = 0;
	int namtra = 0;
public:
	friend BANDOC;
	friend SACH;
	PHIEUMUON() = default;
	PHIEUMUON(string sMaBanDoc, string sMaSach, int ngay, int thang, int nam)
		:xDate(ngay, thang, nam), xBandoc(sMaBanDoc), xSach(sMaSach)
	{
		tinhtrang = 1;
		this->stt++;
	}
	int trangay(int thang, int nam);
	void setNgayMuon(int& ngay, int& thang, int& nam);
	void setNgayTra(int& ngay, int& thang, int& nam, int& ngayt, int& thangt, int& namt);
	bool searchMaSach(string s);
	void nhapPhieuMuonMoi()
	{
		this->stt++;
		cout << "Nhap phieu muon thu: " << stt << endl;
		cout << "Nhap ma sach ";
		getline(cin, masach);
		cout << "Nhap ma ban doc: ";
		getline(cin, mabandoc);
		setNgayMuon(ngaymuon, thangmuon, nammuon);
		setNgayTra(ngaymuon, thangmuon, nammuon, ngaytra, thangtra, namtra);
		cout << ngaytra << "," << thangtra << "," << namtra << endl;
		ofstream fcout;
		fcout.open("phieumuon.txt", ios::app);
		fcout << stt << "#" << masach << "#" << mabandoc
			<< "#" << ngaymuon << "#" << thangmuon
			<< "#" << nammuon << "#" << ngaytra
			<< "#" << thangtra << "#" << namtra << "#" << tinhtrang << endl;
		fcout.close();
	}
	void docThongtin()
	{
		int STT = 0;

		ifstream fcin;
		fcin.open("phieumuon.txt");

		fcin >> STT;
		fcin.ignore(1);
		getline(fcin, masach, '#');
		getline(fcin, mabandoc, '#');
		fcin.ignore(1);
		fcin >> ngaymuon;
		fcin.close();
	}
	void readPhieuMuon(ifstream& file)
	{
		file >> STT;
		file.ignore(1);
		rewind(stdin);
		getline(file, masach, '#');
		getline(file, mabandoc, '#');
		rewind(stdin);
		file >> ngaymuon;
		file.ignore(1);
		file >> thangmuon;
		file.ignore(1);
		file >> nammuon;
		file.ignore(1);
		file >> ngaytra;
		file.ignore(1);
		file >> thangtra;
		file.ignore(1);
		file >> namtra;
		file.ignore(1);
		file >> tinhtrang;
		file.ignore(1);
	}
	~PHIEUMUON();
};

#endif