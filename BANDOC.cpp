#include "BANDOC.h"

string BANDOC::getHovaten()
{
	return this->sHoTen;
}
string BANDOC::getKhoa()
{
	return this->sKhoa;
}
string BANDOC::getMaBanDoc()
{
	return this->sMaBanDoc;
}
void BANDOC::setHovaten(string sHoTen)
{
	this->sHoTen = sHoTen;
}
void BANDOC::setKhoa(string sKhoa)
{
	this->sKhoa = sKhoa;
}
void BANDOC::setMaBanDoc(string sMaBanDoc)
{
	this->sMaBanDoc = sMaBanDoc;
}
void BANDOC::setBandoc(string sHoTen, string sKhoa, string sMaBanDoc)
{
	this->sHoTen = sHoTen;
	this->sKhoa = sKhoa;
	this->sMaBanDoc = sMaBanDoc;
}


