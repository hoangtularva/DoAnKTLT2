#include "Admin.h"
#include "Date.h"
#include "SACH.h"
#include "GIAOVIEN.h"
#include "SINHVIEN.h"
#include "PHIEUMUON.h"
#include <vector>
#include <conio.h>
#include <windows.h>

//Loại bỏ lỗi cảnh báo khi chạy chương trình
#pragma warning(disable: 4996)
#define _CRT_SECURE_NO_WARNINGS

//Khai bao nguyen mau ham con:
//Set mau:
void SetColor(int ForgC);

//Admin:
void docTKvaMK();
bool kiemTraDN(string sTaikhoan, string sMatkhau);
void login();
string maHoaMK(unsigned int maxLength);

//Menu:
void menuChinh();
void menu();

//Sach:
void docDSSach(vector<SACH> &S);
void xuatDSSach(vector<SACH> S);
void ghiDSSach(vector<SACH> S);
int kTraSach(string sTuaDe);
void timSach();
bool tinhTrangSach(string masach);
void xoaSach();

//Ban doc:
void docDSSV(vector <SINHVIEN> &Sv);
void xuatDSSV(vector <SINHVIEN> Sv);
void docDSGV(vector <GIAOVIEN> &Gv);
void xuatDSGV(vector <GIAOVIEN> Gv);
int kTraBanDocGV(vector<GIAOVIEN> Gv, string sMaBanDoc);
void timBanDocGV();
int kTraBanDocSV(string sMaBanDoc);
void timBanDocSV();
void timBanDoc();

//Chuc nang:
void timKiemThongtin();

//Quan ly:
void quanLyThuVien();
void quanLyBanDoc();
void quanLySach();
void quanLyPhieuMuon();

//Thong Ke
void tongSachMuon();
void tongSachChuaMuon();
void thongKe();

//Khai bao bien:
vector <Admin> Ad;
vector <SACH> S;
vector <GIAOVIEN> Gv;
vector <SINHVIEN> Sv;
vector <PHIEUMUON> Pm;

//Chuong trinh chinh:
void main()
{
	docDSSach(S);
	docTKvaMK();
	docDSGV(Gv);
	docDSSV(Sv);
	//docDSPhieuMuon(PM);
	menuChinh();
	//ghiDSSach(S);
	system("pause");
}

//Dinh nghia ham con:
void quanLyPhieuMuon()
{
	PHIEUMUON p;
	p.docThongtin();
	int nQuanly = 0;
	do {
		SetColor(11);
		cout << "________________QUAN LY PHIEU MUON______________\n";
		cout << "*********************************************\n";
		SetColor(14);
		cout << "\t 1. XEM DANH SACH PHIEU MUON \t\n";
		cout << "\t 2. TAO PHIEU MUON MOI \t\n";
		cout << "\t 3. TRA SACH \t\n";
		cout << "\t 4. THOAT \t\n";
		SetColor(11);
		cout << "*********************************************\n";
		SetColor(14);
		cout << "Ban hay chon chuc nang can quan ly: ";
		cin >> nQuanly;
		switch (nQuanly)
		{
		case 1:
			system("cls");
			//Xem danh sach phieu muon


			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			p.nhapPhieuMuonMoi();
			system("pause");
			system("cls");
			break;
		case 3:
			//Tra sach

		default:
			cout << "BAN CHON THOAT QUAN LY PHIEU MUON!\n";
			Sleep(1000);
			system("cls");
			quanLyThuVien();
			break;
		}
	} while (nQuanly >= 1 && nQuanly <= 3);
}
//kiem tra tinh trang sach
bool tinhTrangSach(string masach)
{
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getMaSach() == masach && S[i].getTinhTrang() == 0)
		{
			return true;
		}
	}
	return false;
}
//ham xoa sach
void xoaSach()
{
	string masach = "";
	do
	{
		cout << "Nhap ma sach: ";
		rewind(stdin);
		getline(cin, masach);
	} while (tinhTrangSach(masach) == 0);
	for (int i = 0; i < S.size(); i++)
	{
		if (masach == S[i].getMaSach())
		{
			S.erase(S.begin() + i);
			ghiDSSach(S);
			break;
		}
	}
	cout << "Xoa thanh cong" << endl;
}
//ham quan li sach
void quanLySach()
{
	SACH s;
	ofstream fcout;
	ifstream fcin;
	int nN = 0;
	fcin.open("Sach.txt");
	fcin >> nN;
	fcin.ignore(1);
	int nQuanly = 0;
	do {
		SetColor(11);
		cout << "__________________QUAN LY SACH_______________\n";
		cout << "*********************************************\n";
		SetColor(14);
		cout << "\t 1. XEM DANH SACH SACH \t\n";
		cout << "\t 2. THEM SACH MOI \t\n";
		cout << "\t 3. XOA SACH \t\n";
		cout << "\t 4. THOAT \t\n";
		SetColor(11);
		cout << "*********************************************\n";
		SetColor(14);
		cout << "Ban hay chon chuc nang can quan ly: ";
		cin >> nQuanly;
		switch (nQuanly)
		{
		case 1:
			system("cls");
			xuatDSSach(S);
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			s.nhapSachMoi();
			system("pause");
			system("cls");
			break;
		case 3:
			xoaSach();
			break;
		default:
			cout << "BAN CHON THOAT QUAN LY SACH!\n";
			Sleep(1000);
			system("cls");
			quanLyThuVien();
			break;
		}
	} while (nQuanly >= 1 && nQuanly <= 3);
}
//ham quan li ban doc
void quanLyBanDoc()
{
	GIAOVIEN giaovien;
	SINHVIEN sinhvien;
	ofstream fcout;
	ifstream fcin;
	int nN = 0;
	fcin.open("SinhVien.txt");
	fcin >> nN;
	fcin.ignore(1);
	string maBD, hotenBD, khoaHocBD, ngay, thang, nam, diaChi;
	int soDT, soluong;
	int nQuanly = 0;
	do {
		SetColor(11);
		cout << "________________QUAN LY BAN DOC______________\n";
		cout << "*********************************************\n";
		SetColor(14);
		cout << "\t 1. XEM BAN DOC GIAO VIEN \t\n";
		cout << "\t 2. XEM BAN DOC SINH VIEN \t\n";
		cout << "\t 3. THEM BAN DOC GIAO VIEN \t\n";
		cout << "\t 4. THEM BAN DOC SINH VIEN \t\n";
		cout << "\t 5. THOAT \t\n";
		SetColor(11);
		cout << "*********************************************\n";
		SetColor(14);
		cout << "Ban hay chon chuc nang can quan ly: ";
		cin >> nQuanly;
		switch (nQuanly)
		{
		case 1:
			system("cls");
			xuatDSGV(Gv);
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			xuatDSSV(Sv);
			system("pause");
			system("cls");
			break;
		case 3:
			giaovien.nhapGiaoVienMoi();
			cout << "THEM GIAO VIEN THANH CONG!";
			system("pause");
			system("cls");
			break;
		case 4:
			sinhvien.nhapSinhVienMoi();
			cout << "THEM SINH VIEN THANH CONG!";
			system("pause");
			system("cls");
			break;
		default:
			cout << "BAN CHON THOAT QUAN LY BAN DOC!\n";
			Sleep(1000);
			system("cls");
			quanLyThuVien();
			break;
		}
	} while (nQuanly >= 1 && nQuanly <= 4);
}
//quan ly thu vien sau khi dang nhap
void quanLyThuVien()
{
	int nQuanly = 0;
	do
	{
		system("cls");
		SetColor(11);
		cout << "_______________QUAN LY THU VIEN______________\n";
		cout << "*********************************************\n";
		SetColor(14);
		cout << "\t 1. QUAN LY PHIEU MUON \t\n"; //BUG ALL
		cout << "\t 2. QUAN LY SACH \t\n"; //BUG THEM SACH
		cout << "\t 3. QUAN LY BAN DOC \t\n"; //BUG THEM SINH VIEN
		cout << "\t 4. THONG KE \t\n";
		cout << "\t 5. THOAT \t\n";
		SetColor(11);
		cout << "*********************************************\n";
		SetColor(14);
		cout << "Ban hay chon chuc nang can quan ly: ";
		cin >> nQuanly;
		switch (nQuanly)
		{
		case 1:
			system("cls");
			quanLyPhieuMuon();	//Xem danh sach phieu muon, tao phieu muon moi, tra sach, thoat
			system("cls");
			break;
		case 2:
			system("cls");
			quanLySach(); //Xem danh sach sach, them sach, xoa sach, thoat
			system("cls");
			break;
		case 3:
			system("cls");
			quanLyBanDoc();
			system("cls");
			break;
		case 4:
			thongKe();
			break;
		default:
			cout << "BAN CHON THOAT QUAN LY!\n";
			Sleep(1000);
			system("cls");
			menu();
			menuChinh();
			break;
		}
	} while (nQuanly >= 1 && nQuanly <= 4);
}
//tinh tong cac sach da duoc muon
void tongSachMuon()
{
	int nTONG = 0;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getTinhTrang() == 1)
		{
			nTONG += 1;
		}
	}
	cout << "Tong so luong sach da muon la: " << nTONG << endl;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getTinhTrang() == 1)
		{
			cout << S[i];
		}
	}
}
//tong sach chua muon
void tongSachChuaMuon()
{
	int nTONG = 0;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getTinhTrang() == 0)
		{
			nTONG += 1;
		}
	}
	cout << "Tong so luong sach chua muon la: " << nTONG << endl<<endl;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getTinhTrang() == 0)
		{
			cout << S[i];
		}
	}
}
//ham thong ke sach
void thongKe() {
	int nQuanly = 0;
	do {
		system("cls");
		SetColor(11);
		cout << "__________________THONG KE_______________\n";
		cout << "*********************************************\n";
		SetColor(14);
		cout << "\t 1. TONG SACH DA MUON \t\n";
		cout << "\t 2. TONG SACH CHUA MUON \t\n";
		cout << "\t 3. THOAT \t\n";
		SetColor(11);
		cout << "*********************************************\n";
		SetColor(14);
		cout << "Ban hay chon chuc nang can quan ly: ";
		cin >> nQuanly;
		switch (nQuanly)
		{
		case 1:
			system("cls");
			tongSachMuon();
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			tongSachChuaMuon();
			system("pause");
			system("cls");
			break;
		default:
			cout << "BAN CHON THOAT THONG KE!\n";
			Sleep(1000);
			system("cls");
			quanLyThuVien();
			break;
		}
	} while (nQuanly >= 1 && nQuanly <= 3);
}
//ham menu lua chon chinh
void menuChinh()
{
	int nChon = 0;
	do {
		system("cls");
		menu();
		SetColor(10);
		cout << "\tBan hay chon chuc nang: ";
		cin >> nChon;
		switch (nChon)
		{
		case 1:
			system("cls");
			xuatDSSach(S);
			system("pause");
			break;
		case 2:
			system("cls");
			xuatDSGV(Gv);
			cout << endl;
			xuatDSSV(Sv);
			cout << endl;
			system("pause");
			break;
		case 3:
			system("cls");
			timKiemThongtin();
			break;
		case 4:
			system("cls");
			login();
			break;
		default:
			SetColor(14);
			cout << "BAN DA CHON THOAT CHUONG TRINH!\n";
			Sleep(1000);
			exit(0);
		}
	} while (nChon >= 1 && nChon <= 4);
}
//giao dien menu
void menu()
{
	SetColor(11);
	cout << "______________________MENU___________________\n";
	cout << "*********************************************\n";
	SetColor(14);
	cout << "\t 1. HIEN THI THONG TIN SACH \t\n";
	cout << "\t 2. HIEN THI THONG TIN BAN DOC \t\n";
	cout << "\t 3. TIM KIEM THONG TIN \t\n";
	cout << "\t 4. QUAN LY \t\n";
	cout << "\t 5. THOAT! \t\n";
	SetColor(11);
	cout << "*********************************************\n";
}
//tim kiem thong tin sach va ban doc
void timKiemThongtin()
{
	int timKiem = 0;
	do {
		SetColor(11);
		cout << "___________________TIM KIEM__________________\n";
		cout << "*********************************************\n";
		SetColor(14);
		cout << "\t 1. TIM KIEM SACH \t\n";
		cout << "\t 2. TIM KIEM BAN DOC \t\n";
		cout << "\t 3. THOAT! \t\n";
		SetColor(11);
		cout << "*********************************************\n";
		cout << "Chon chuc nang can tim: ";
		cin >> timKiem;
		switch (timKiem)
		{
		case 1:
			timSach();
		case 2:
			system("cls");
			timBanDoc();
		default:
			cout << "BAN CHON THOAT TIM KIEM!\n";
			Sleep(1000);
			system("cls");
			menu();
			menuChinh();
			break;
		}
	} while (timKiem >= 1 && timKiem >= 3);
}
//tim kiem ban doc
void timBanDoc()
{
	int timKiem = 0;
	SetColor(11);
	cout << "_______________TIM KIEM BAN DOC______________\n";
	cout << "*********************************************\n";
	SetColor(14);
	cout << "\t 1. BAN DOC GIAO VIEN \t\n";
	cout << "\t 2. BAN DOC SINH VIEN \t\n";
	cout << "\t 3. THOAT \t\n";
	SetColor(11);
	cout << "*********************************************\n";
	cout << "Chon ban doc can tim: ";
	cin >> timKiem;
	switch (timKiem)
	{
	case 1:
		timBanDocGV();
	case 2:
		timBanDocSV();
	case 3:
		cout << "BAN CHON THOAT TIM KIEM BAN DOC\n";
		Sleep(1000);
		system("cls");
		timKiemThongtin();
		break;
	default:
		system("cls");
		timBanDoc();
	}
}
//tim kiem sinh vien
void timBanDocSV()
{
	string sMaBanDoc = "";
	SetColor(11);
	cout << "\tNHAP MA BAN DOC SINH VIEN: ";
	rewind(stdin);
	getline(cin, sMaBanDoc);
	for (int i = 0; i < Sv.size(); i++)
	{
		if (Sv[i].getMaBanDoc() == sMaBanDoc)
		{
			SetColor(14);
			cout << Sv[i];
			cout << endl;
			break;
		}
	}
	if (kTraBanDocSV(sMaBanDoc) == -1)
	{
		SetColor(12);
		cout << "MA BAN DOC NHAP SAI HOAC BAN DOC KHONG TON TAI TRONG HE THONG !!!\nNHAN ENTER DE QUAY LAI MAN HINH TIM KIEM THONG TIN\n";
	}
	system("pause");
	system("cls");
	timBanDoc();
}
//kiem tra sinh vien truoc khi tim kiem
int kTraBanDocSV(string sMaBanDoc)
{
	for (int i = 0; i < Sv.size(); i++)
	{
		if (Sv[i].getMaBanDoc() == sMaBanDoc)
		{
			return i;
		}
	}
	return -1;
}
//tim kiem giao vien
void timBanDocGV()
{
	string sMaBanDoc = "";
	SetColor(11);
	cout << "\tNHAP MA BAN DOC GIAO VIEN: ";
	rewind(stdin);
	getline(cin, sMaBanDoc);
	for (int i = 0; i < Gv.size(); i++)
	{
		if (Gv[i].getMaBanDoc() == sMaBanDoc)
		{
			SetColor(14);
			cout << Gv[i];
			cout << endl;
			break;
		}
	}
	if (kTraBanDocGV(Gv, sMaBanDoc) == -1)
	{
		SetColor(12);
		cout << "MA BAN DOC NHAP SAI HOAC BAN DOC KHONG TON TAI TRONG HE THONG !!!\nNHAN ENTER DE QUAY LAI MAN HINH TIM KIEM THONG TIN\n";
	}
	system("pause");
	system("cls");
	timBanDoc();
}
//kiem tra giao vien truoc khi tim kiem
int kTraBanDocGV(vector<GIAOVIEN> Gv, string sMaBanDoc)
{
	for (int i = 0; i < Gv.size(); i++)
	{
		if (Gv[i].getMaBanDoc() == sMaBanDoc)
		{
			return i;
		}
	}
	return -1;
}
//tim kiem sach
void timSach()
{
	string sTuaDe = "";
	SetColor(11);
	cout << "\tNHAP TUA DE SACH: ";
	rewind(stdin);
	getline(cin, sTuaDe);
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getTieuDe() == sTuaDe)
		{
			SetColor(14);
			cout << S[i];
			cout << endl;
			break;
		}
	}
	if (kTraSach(sTuaDe) == -1)
	{
		SetColor(12);
		cout << "TUA DE SACH NHAP SAI HOAC SACH KHONG TON TAI TRONG HE THONG !!!\nNHAN ENTER DE QUAY LAI MAN HINH TIM KIEM THONG TIN\n";
	}
	system("pause");
	system("cls");
	timKiemThongtin();
}
//kiem tra sach truoc khi tim kiem
int kTraSach(string sTuaDe)
{
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getTieuDe() == sTuaDe)
		{
			return i;
		}
	}
	return -1;
}
//xuat danh sach sinh vien
void xuatDSSV(vector <SINHVIEN> Sv)
{
	SetColor(11);
	SINHVIEN sv;
	cout << "----------DANH SACH BAN DOC LA SINH VIEN----------\n";
	for (int i = 0; i < Sv.size(); i++)
	{
		cout << Sv[i];
	}
}
//doc file sinhvien.txt
void docDSSV(vector <SINHVIEN> &Sv)
{
	ifstream fcin;
	int nN = 0;
	fcin.open("SinhVien.txt");
	fcin >> nN;
	fcin.ignore(1);
	SINHVIEN sv;
	for (int i = 0; i < nN; i++)
	{
		sv.readBanDoc(fcin);
		Sv.push_back(sv);
	}
}
//xuat danh sach giao vien
void xuatDSGV(vector <GIAOVIEN> Gv)
{
	SetColor(11);
	SINHVIEN sv;
	cout << "----------DANH SACH BAN DOC LA GIAO VIEN----------\n";
	for (int i = 0; i < Gv.size(); i++)
	{
		cout << Gv[i];
	}
}
//doc file giaovien.txt
void docDSGV(vector <GIAOVIEN> &Gv)
{
	ifstream fcin;
	int nN = 0;
	fcin.open("GiaoVien.txt");
	fcin >> nN;
	fcin.ignore(1);
	GIAOVIEN gv;
	for (int i = 0; i < nN; i++)
	{
		gv.readBanDoc(fcin);
		Gv.push_back(gv);
	}
}
//ghi sach
void ghiDSSach(vector<SACH> S)
{
	ofstream fcout;
	fcout.open("Sach.txt");
	fcout << S.size() << endl;
	for (int i = 0; i < S.size(); i++)
	{
		S[i].writeSach(fcout);
	}
	fcout.close();
}
//xuat sach
void xuatDSSach(vector<SACH> S)
{
	SetColor(11);
	cout << "----------DANH SACH CAC LOAI SACH CO TRONG THU VIEN----------\n";
	for (int i = 0; i < S.size(); i++)
	{
		cout << S[i];
	}
}
//ham doc file thong tin sach
void docDSSach(vector<SACH> &S)
{
	ifstream fcin;
	int nN = 0;
	fcin.open("Sach.txt");
	//Khai bao cac bien:
	SACH s;
	fcin >> nN;
	fcin.ignore(1);
	for (int i = 0; i < nN; i++)
	{
		s.readSach(fcin);
		S.push_back(s);
	}
	fcin.close();
}
//ham dang nhap
void login()
{
	int dem = 0;
	while (dem < 3)
	{
		string sTaiKhoan = "", sMatKhau = "";
		SetColor(11);
		cout << "*********************************\n";
		SetColor(11);
		cout << "*";
		SetColor(14);
		cout << "\tDANG NHAP QUAN LY\t";
		SetColor(11);
		cout << "*\n";
		SetColor(11);
		cout << "*********************************\n";
		SetColor(14);
		cout << "Nhap tai khoan: ";
		rewind(stdin);
		getline(cin, sTaiKhoan);
		//Ma hoa mat khau:
		cout << "Nhap mat khau: ";
		sMatKhau = maHoaMK(6);
		if (kiemTraDN(sTaiKhoan, sMatKhau) == true)
		{
			cout << "\nDANG NHAP THANH CONG!\n";
			Sleep(1000);
			quanLyThuVien();
		}
		else
		{
			SetColor(12);
			cout << "\nBAN DA NHAP SAI! VUI LONG NHAP LAI!!\n";
			dem++;
			if (dem == 3)
			{
				cout << "\nBAN DA NHAP SAI QUA 3 LAN! XIN VUI LONG THU LAI SAU!\n" << endl;
				Sleep(1000);
				system("cls");
				menu();
				menuChinh();
			}
			system("pause");
			system("cls");
		}
	}
}
//ma hoa mat khau
string maHoaMK(unsigned int maxLength)
{
	string pw = "";
	for (char c; (c = _getch()); )
	{
		if (c == '\n' || c == '\r')
		{
			cout << "\n";
			break;
		}
		else if (c == '\b')
		{
			cout << "\b \b";
			if (!pw.empty())
				pw.erase(pw.size() - 1);
		}
		else if (c == -32)
		{
			_getch();
		}
		else if (isprint(c) && pw.size() < maxLength)
		{
			cout << '*';
			pw += c;
		}
	}
	return pw;
}
//kiem tra thong tin de dang nhap
bool kiemTraDN(string sTaikhoan, string sMatkhau)
{
	for (int i = 0; i < Ad.size(); i++)
	{
		if (Ad[i].getTaiKhoan() == sTaikhoan && Ad[i].getMatKhau() == sMatkhau)
		{
			return true;
		}
	}
	return false;
}
//doc file admin.txt
void docTKvaMK()
{
	ifstream fcin;
	int nN = 0;
	fcin.open("Admin.txt");
	//Khai bao cac bien:
	Admin Admin;
	fcin >> nN;
	fcin.ignore(1);
	for (int i = 0; i < nN; i++)
	{
		Admin.docAd(fcin);
		Ad.push_back(Admin);
	}
	fcin.close();
}
//ham tao color
void SetColor(int ForgC)
{
	WORD wColor;

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	//We use csbi for the wAttributes word.
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		//Mask out all but the background attribute, and add in the forgournd color
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
	return;
}