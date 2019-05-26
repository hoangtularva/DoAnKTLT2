#include "Admin.h"

string Admin::getTaiKhoan()
{
	return this->sTaiKhoan;
}
string Admin::getMatKhau()
{
	return this->sMatKhau;
}
void Admin::setTaiKhoan(string sTaiKhoan)
{
	this->sTaiKhoan = sTaiKhoan;
}
void Admin::setMatKhau(string sMatKhau)
{
	this->sMatKhau = sMatKhau;
}
void Admin::setDangNhap(string sTaiKhoan, string sMatKhau)
{
	this->sTaiKhoan = sTaiKhoan;
	this->sMatKhau = sMatKhau;
}
void Admin::docAd(ifstream &fcin)
{
	rewind(stdin);
	getline(fcin, sTaiKhoan, '#');
	rewind(stdin);
	getline(fcin, sMatKhau);
}
ostream& operator << (ostream &os, Admin &xAd)
{
	os << "Tai Khoan: " << xAd.sTaiKhoan << endl;
	os << "Mat Khau: " << xAd.sMatKhau << endl;
	return os;
}
