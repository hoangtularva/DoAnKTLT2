#include "PHIEUMUON.h"

int PHIEUMUON::stt = 1;

int PHIEUMUON::trangay(int thang, int nam)
{
	if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12)
	{
		return 31;
	}
	else
	{
		if (thang == 2)
		{
			if (nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0)
			{
				return 29;
			}
			else
			{
				return 28;
			}
		}
		return 30;
	}
	return 0;
}

void PHIEUMUON::setNgayMuon(int &ngay, int &thang, int &nam)
{
	time_t hientai = time(0);
	tm* ltm = localtime(&hientai);
	ngay = ltm->tm_mday;
	thang = 1 + ltm->tm_mon;
	nam = 1900 + ltm->tm_year;
}

void PHIEUMUON::setNgayTra(int& ngay, int& thang, int& nam, int& ngayt, int& thangt, int& namt)
{
	namt = nam;
	if (thang != 12)
	{
		if (ngay + 7 > trangay(thang, nam))
		{
			thangt = thang + 1;
			ngayt = ngay + 7 - trangay(thang, nam);
		}
		else
		{
			ngayt = ngay + 7;
		}
	}
	else
	{
		if (ngay + 7 > trangay(thang, nam))
		{
			thangt = 1;
			ngayt = ngay + 7 - trangay(thang, nam);
			namt = nam + 1;
		}
		else
		{
			ngayt = ngay + 7;
		}
	}
}

PHIEUMUON::~PHIEUMUON()
{
}
