#ifndef BANDOC_h
#define BANDOC_h
#include <string>
#include <iostream>
using namespace std;
#include <fstream>
#include <windows.h>
#include "Date.h"
#pragma once
//class PHIEUMUON;
class BANDOC
{
protected:
	string sHoTen, sKhoa, sMaBanDoc;
	Date nNgayThamGia;
public:
	/*friend PHIEUMUON;*/
	BANDOC()
	{
		this->sHoTen = "";
		this->sKhoa = "";
		this->sMaBanDoc = "";
	}
	BANDOC(string sMaBanDoc) {
		this->sHoTen = "";
		this->sKhoa = "";
		this->sMaBanDoc = sMaBanDoc;
	}
	BANDOC(string sMaBanDoc, string sHoTen, string sKhoa, int nNgay, int nThang, int nNam) : nNgayThamGia(nNgay, nThang, nNam)
	{
		this->sHoTen = sHoTen;
		this->sKhoa = sKhoa;
		this->sMaBanDoc = sMaBanDoc;
	}
	string getHovaten();
	string getKhoa();
	string getMaBanDoc();
	void setHovaten(string sHoTen);
	void setKhoa(string sKhoa);
	void setMaBanDoc(string sMaBanDoc);
	void setBandoc(string sHoTen, string sKhoa, string sMaBanDoc);

	virtual void inputBanDoc() {}
	virtual void ouputBanDoc() {};
	virtual void readBanDoc(ifstream &file) {};
	virtual void writeBanDoc(ofstream &file) {};
	/*void xuatBanDoc();*/
	virtual ~BANDOC() {};
};
#endif // !BANDOC_h
