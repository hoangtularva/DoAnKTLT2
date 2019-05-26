#ifndef Date_h
#define Date_h

#include <iostream>
#include <iomanip>
#include <vector>
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNING
#include <ctime>
#include <time.h>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
using namespace std;
#pragma once
class SACH;
class BANDOC;
class SINHVIEN;
class GIAOVIEN;
class Date
{
private:
	int nNgay, nThang, nNam;
public:
	friend SACH;
	friend BANDOC;
	friend GIAOVIEN;
	friend SINHVIEN;
	
	Date()
	{
		time_t rawtime;
		struct tm *info;
		char buffer[80];
		time(&rawtime);
		info = localtime(&rawtime);
		this->nNgay = (info->tm_mday);
		this->nThang = (info->tm_mon + 1);
		this->nNam = (info->tm_year + 1900);
	}
	Date(int nNgay, int nThang, int nNam)
	{
		this->nNgay = nNgay;
		this->nThang = nThang;
		this->nNam = nNam;
	}
	int getNgay();
	int getThang();
	int getNam();
	void setNgay(int nNgay);
	void setThang(int nThang);
	void setNam(int nNam);
	void setDate(int nNgay, int nThang, int nNam);
	void outputNgay();
	friend istream& operator >> (istream &is, Date &d);
	friend ostream& operator << (ostream &os, Date &d);
	virtual ~Date() {};
};

#endif // !Date_h