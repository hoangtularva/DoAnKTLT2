#include "SACH.h"

void SACH::outputSach()
{
	cout << this->sMaSach << "," << this->sTieuDe << "," << this->sTacGia << "," << this->sNhaXuatBan << "," << this->fGiaBan << "," << this->nNamPhatHanh << ","
		<< this->nSoTrang << "," << this->ngayNhapKho.nNgay << "/" << this->ngayNhapKho.nThang << "/" << this->ngayNhapKho.nNam << "," << this->nTinhTrang << endl;
}

void SACH::writeSach(ofstream & file)
{
	file << this->getMaSach() << "," << this->getTieuDe() << "," << this->getTacGia() << ","
		<< this->getNXB() << "," << this->getGiaBan() << "," << this->getNamPhatHanh() << "," << this->getSoTrang() << ","
		<< this->getNgayNhapKho().getNgay() << "/" << this->getNgayNhapKho().getThang() << "/" << this->getNgayNhapKho().getNam() << ","
		<< this->getTinhTrang() << endl;
}

void SACH::readSach(ifstream & file)
{
	rewind(stdin);
	getline(file, sMaSach, ',');
	rewind(stdin);
	getline(file, sTieuDe, ',');
	rewind(stdin);
	getline(file, sTacGia, ',');
	rewind(stdin);
	getline(file, sNhaXuatBan, ',');
	file >> fGiaBan;
	file.ignore(1);
	file >> nNamPhatHanh;
	file.ignore(1);
	file >> nSoTrang;
	file.ignore(1);
	file >> ngayNhapKho.nNgay;
	file.ignore(1);
	file >> ngayNhapKho.nThang;
	file.ignore(1);
	file >> ngayNhapKho.nNam;
	file.ignore(1);
	file >> nTinhTrang;
	file.ignore(1);
}

ostream& operator<<(ostream& os, SACH& sach)
{
	os << sach.sMaSach << "," << sach.sTieuDe << "," << sach.sTacGia << "," << sach.sNhaXuatBan << "," << sach.fGiaBan << "," << sach.nNamPhatHanh << "," << sach.nSoTrang << ","
		<< sach.ngayNhapKho.getNgay() << "/" << sach.ngayNhapKho.getThang() << "/" << sach.ngayNhapKho.getNam() << "," << sach.nTinhTrang << endl;
	return os;
}

void SACH::nhapSachMoi()
{
	cout << "Nhap ma sach: ";
	rewind(stdin);
	getline(cin, sMaSach);
	cout << "Nhap Tieu de sach: ";
	rewind(stdin);
	getline(cin, sTieuDe);
	cout << "Nhap tac gia: ";
	rewind(stdin);
	getline(cin, sTacGia);
	cout << "Nhap nha xuat ban: ";
	rewind(stdin);
	getline(cin, sNhaXuatBan);
	cout << "Nhap gia ban: ";
	cin >> fGiaBan;
	cout << "nhap nam phat hanh: ";
	cin >> nNamPhatHanh;
	cout << "nhap so trang: ";
	cin >> nSoTrang;
	cout << "nhap ngay nhap kho: ";
	cin >> ngayNhapKho.nNgay;
	cout << "nhap thang nhap kho: ";
	cin >> ngayNhapKho.nThang;
	cout << "nhap nam nhap kho: ";
	cin >> ngayNhapKho.nNam;
	cout << "Nhap tinh trang (0,1): ";
	cin >> nTinhTrang;
	ofstream fcout;
	fcout.open("Sach.txt", ios::app);
	fcout <<""<<sMaSach << "," << sTieuDe
		<< "," << sTacGia << "," << sNhaXuatBan
		<< "," << fGiaBan<<","<< nNamPhatHanh<<","<< nSoTrang
		<< "," << ngayNhapKho.nNgay << "/" << ngayNhapKho.nThang
		<< "/" << ngayNhapKho.nNam <<","<< nTinhTrang<< endl;
	fcout.close();
}
