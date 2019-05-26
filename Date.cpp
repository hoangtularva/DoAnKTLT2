#include "Date.h"
int Date::getNgay()
{
	return this->nNgay;
}
int Date::getThang()
{
	return this->nThang;
}
int Date::getNam()
{
	return this->nNam;
}
void Date::setNgay(int nNgay)
{
	this->nNgay = nNgay;
}
void Date::setThang(int nThang)
{
	this->nThang = nThang;
}
void Date::setNam(int nNam)
{
	this->nNam = nNam;
}
void Date::setDate(int nNgay, int nThang, int nNam)
{
	this->nNgay = nNgay;
	this->nThang = nThang;
	this->nNam = nNam;
}
void Date::outputNgay()
{
	cout << this->nNgay << "," << this->nThang << "," << this->nNam << endl;
}
istream& operator >> (istream &is, Date &d)
{
	cout << "Nhap ngay: ";
	is >> d.nNgay;
	cout << "Nhap thang: ";
	is >> d.nThang;
	cout << "Nhap nam: ";
	is >> d.nNam;
	return is;
}
ostream& operator << (ostream &os, Date &d)
{
	os << d.nNgay << "," << d.nThang << "," << d.nNam << endl;
	return os;
}


