#ifndef Admin_h
#define Admin_h
#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#pragma once
class Admin
{
private:
	string sTaiKhoan, sMatKhau;
public:
	Admin()
	{
		sTaiKhoan = "";
		sMatKhau = "";
	}
	Admin(string sTaiKhoan, string sMatKhau)
	{
		this->sTaiKhoan = sTaiKhoan;
		this->sMatKhau = sMatKhau;
	}
	string getTaiKhoan();
	string getMatKhau();
	void setTaiKhoan(string sTaiKhoan);
	void setMatKhau(string sMatKhau);
	void setDangNhap(string sTaiKhoan, string sMatKhau);
	void docAd(ifstream &fcin);
	friend ostream& operator << (ostream &os, Admin &xAd);
	~Admin() {};
};
#endif // !Admin_h
