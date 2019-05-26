#include "SINHVIEN.h"

string SINHVIEN::getKhoaHoc()
{
	return this->sKhoaHoc;
}
void SINHVIEN::setKhoaHoc(string sKhoaHoc)
{
	this->sKhoaHoc = sKhoaHoc;
}
void SINHVIEN::ouputBanDoc()
{
	cout << this->sMaBanDoc << "," << this->sHoTen << "," <<
		this->sKhoa << "," << this->sKhoaHoc << "," << this->nNgayThamGia.nNgay << "," << this->nNgayThamGia.nThang << ","
		<< this->nNgayThamGia.nNam << "\n";
}
ostream& operator<<(ostream& os, SINHVIEN &sv)
{
	os << sv.sMaBanDoc << "," << sv.sHoTen << "," << sv.sKhoa << "," << sv.sKhoaHoc << "," << sv.nNgayThamGia.getNgay()
		<< "/" << sv.nNgayThamGia.getThang() << "/" << sv.nNgayThamGia.getNam()<<"\n";
	return os;
}
void SINHVIEN::nhapSinhVienMoi()
{
	cout << "Nhap ma sinh vien: ";
	rewind(stdin);
	getline(cin, sMaBanDoc);
	cout << "Nhap hoten sinh vien: ";
	rewind(stdin);
	getline(cin, sHoTen);
	cout << "Nhap khoa sinh vien: ";
	rewind(stdin);
	getline(cin, sKhoa);
	cout << "Nhap Khoa hoc sinh vien: ";
	rewind(stdin);
	getline(cin, sKhoaHoc);
	cout << "nhap ngay: ";
	cin >> nNgayThamGia.nNgay;
	cout << "nhap thang: ";
	cin >> nNgayThamGia.nThang;
	cout << "nhap nam: ";
	cin >> nNgayThamGia.nNam;
	cout << endl;
	ofstream fcout;
	fcout.open("SinhVien.txt", ios::app);
	fcout << "" << sMaBanDoc << "," << sHoTen
		<< "," << sKhoa << "," 
		<< "," << nNgayThamGia.nNgay << "/" << nNgayThamGia.nThang
		<< "/" << nNgayThamGia.nNam << endl;
	fcout.close();
}
void SINHVIEN::readBanDoc(ifstream &file)
{
	rewind(stdin);
	getline(file, this->sMaBanDoc, ',');
	rewind(stdin);
	getline(file, this->sHoTen, ',');
	rewind(stdin);
	getline(file, this->sKhoa, ',');
	rewind(stdin);
	getline(file, this->sKhoaHoc, ',');
	file >> nNgayThamGia.nNgay;
	file.ignore(1);
	file >> nNgayThamGia.nThang;
	file.ignore(1);
	file >> nNgayThamGia.nNam;
	file.ignore(1);
}
void SINHVIEN::writeBanDoc(ofstream &file)
{
	file << this->sMaBanDoc << "," << this->sHoTen << "," <<
		this->sKhoa << "," << this->sKhoaHoc << "," << this->nNgayThamGia.nNgay << "," << this->nNgayThamGia.nThang << ","
		<< this->nNgayThamGia.nNam;
}
