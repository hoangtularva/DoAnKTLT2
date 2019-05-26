#include "GIAOVIEN.h"
#include<string>

string GIAOVIEN::getDiachi()
{
	return this->sDiaChi;
}
string GIAOVIEN::getSoDT()
{
	return this->sSoDT;
}
void GIAOVIEN::setDiaChi(string sDiaChi)
{
	this->sDiaChi = sDiaChi;
}
void GIAOVIEN::setSoDT(string sSoDT)
{
	this->sSoDT = sSoDT;
}
void GIAOVIEN::setGiaoVien(string sDiaChi, string sSoDT)
{
	this->sDiaChi = sDiaChi;
	this->sSoDT = sSoDT;
}
void GIAOVIEN::ouputBanDoc()
{
	cout << this->sMaBanDoc << "," << this->sHoTen << "," <<
		this->sKhoa << "," << this->sDiaChi << "," << this->sSoDT << "," << this->nNgayThamGia.nNgay << "/" << this->nNgayThamGia.nThang << "/"
		<< this->nNgayThamGia.nNam << "\n";
}
ostream& operator<<(ostream& os, GIAOVIEN &gv)
{
	os << gv.sMaBanDoc << "," << gv.sHoTen << "," << gv.sKhoa << "," << gv.sDiaChi << ","
		<< gv.sSoDT << "," << gv.nNgayThamGia.getNgay()
		<< "/" << gv.nNgayThamGia.getThang() << "/" << gv.nNgayThamGia.getNam() << "\n";
	return os;
}
void GIAOVIEN::readBanDoc(ifstream &file)
{
	rewind(stdin);
	getline(file, this->sMaBanDoc, ',');
	rewind(stdin);
	getline(file, this->sHoTen, ',');
	rewind(stdin);
	getline(file, this->sKhoa, ',');
	rewind(stdin);
	getline(file, this->sDiaChi, ',');
	rewind(stdin);
	getline(file, this->sSoDT, ',');
	file >> nNgayThamGia.nNgay;
	file.ignore(1);
	file >> nNgayThamGia.nThang;
	file.ignore(1);
	file >> nNgayThamGia.nNam;
	file.ignore(1);
}
void GIAOVIEN::writeBanDoc(ofstream &file)
{
	file << this->sMaBanDoc << "," << this->sHoTen << "," <<
		this->sKhoa << "," << this->sDiaChi << "," << this->sSoDT << "," << this->nNgayThamGia.nNgay << "/" << this->nNgayThamGia.nThang << "/"
		<< this->nNgayThamGia.nNam;
}

void GIAOVIEN::nhapGiaoVienMoi()
{
	cout << "Nhap ma giao vien: ";
	rewind(stdin);
	getline(cin, sMaBanDoc);
	cout << "Nhap hoten giao vien: ";
	rewind(stdin);
	getline(cin, sHoTen);
	cout << "Nhap khoa giao vien: ";
	rewind(stdin);
	getline(cin, sKhoa);
	cout << "Nhap dia chi: ";
	rewind(stdin);
	getline(cin, sDiaChi);
	cout << "Nhap so dienthoai: ";
	cin >> sSoDT;
	cout << "nhap ngay: ";
	cin >> nNgayThamGia.nNgay;
	cout << "nhap thang: ";
	cin >> nNgayThamGia.nThang;
	cout << "nhap nam: ";
	cin >> nNgayThamGia.nNam;
	cout << endl;
	ofstream fcout;
	fcout.open("GiaoVien.txt", ios::app);
	fcout <<""<<sMaBanDoc << "," << sHoTen
		<< "," << sKhoa << "," << sDiaChi
		<< "," << sSoDT
		<< "," << nNgayThamGia.nNgay << "/" << nNgayThamGia.nThang
		<< "/" << nNgayThamGia.nNam << endl;
	fcout.close();
}