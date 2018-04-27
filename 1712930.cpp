#include <stdio.h>
#include <conio.h>
#include <fcntl.h>
#include <io.h> 
#include<string.h>
#include <wchar.h>
struct SV
{

	wchar_t mssv[10];
	wchar_t ten[30];
	wchar_t khoa[30];
	int k;
	wchar_t mail[100];
	wchar_t day[10];
	wchar_t hinh[20];
	wchar_t mt[1000];
	wchar_t sth[1000];
};
void main()

{
	FILE *fp;
	FILE*fp2;
	SV	A[20];
	wchar_t so[10];
	wchar_t *pp;
	int k = 0;
	wint_t c;
	_wfopen_s(&fp, L"thongtinsv.csv", L"r,ccs=UTF-8");
	_wfopen_s(&fp2, L"tao.txt", L"w,ccs=UTF-8");
	if (fp != NULL){
		do{
			c = fgetwc(fp);
			if (c == '\n') k++;
		} while (c != WEOF);
		fseek(fp, 0, SEEK_SET);
		for (int i = 0; i < k; i++)
		{
			fwscanf(fp, L"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s", &A[i].mssv, &A[i].ten, &A[i].khoa, &so, &A[i].day, &A[i].mail, &A[i].mt, &A[i].sth, &A[i].hinh);
			A[i].k = wcstol(so, &pp, 10);
			fwprintf(fp2, L"%s\n%s\n%s\n%d\n%s\n%s\n%s\n%s\n%s\n", A[i].mssv, A[i].ten, A[i].khoa, A[i].k, A[i].day, A[i].mail, A[i].mt, A[i].sth, A[i].hinh);
			wchar_t ta[10];
			wcscpy(ta, A[i].mssv);
			wprintf(L"%s", ta);
			wchar_t *file = wcscat(ta, L".html");
			FILE*fp1 = _wfopen(L"tap.html", L"a+t,ccs=UTF-8");
			fwprintf(fp1, L"<!DOCTYPE html PUBLIC\"-//W3C//DTD XHTML 1.0 Transitional//EN\"\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
			fwprintf(fp1, L"<html xmlns=\"http://www.w3.org/1999/xhtml \">\n ");
			fwprintf(fp1, L"<head>");
			fwprintf(fp1, L"<meta http-equiv=\"Content - Type\"content=\"text/html; charset = utf - 8\"/>\n");
			fwprintf(fp1, L"<link rel=\"stylesheet\"type=\"text/css\"href=\"personal.css\"/>\n");
			fwprintf(fp1, L"<title>HCMUS - %s</title>\n", A[i].ten);
			fwprintf(fp1, L"</head>\n");
			fwprintf(fp1, L"<body>\n");
			fwprintf(fp1, L"<div class=\"Layout_container\">\n");
			fwprintf(fp1, L"<!-- Begin Layout Banner Region -->\n");
			fwprintf(fp1, L"<div class=\"Layout_Banner\" >\n");
			fwprintf(fp1, L"<div><img id=\"logo\"src=\"Images/logo.jpg\"height=\"105\"/></div>\n");
			fwprintf(fp1, L"		<div class=\"Header_Title\">TRƯỜNG ĐẠI HỌC KHOA HỌC TỰ NHIÊN </div>\n");
			fwprintf(fp1, L"</div>");
			fwprintf(fp1, L"<!-- End Layout Banner Region -->");
			fwprintf(fp1, L"<!-- Begin Layout MainContents Region -->");
			fwprintf(fp1, L"<div class=\"Layout_MainContents\">\n");
			fwprintf(fp1, L"<!-- Begin Below Banner Region -->\n");
			fwprintf(fp1, L"<div class=\"Personal_Main_Information\">\n");
			fwprintf(fp1, L"<!-- Begin Thông tin cá nhân c?a th?y cô ----------------------------------------------------------------------------------------- -->\n");
			fwprintf(fp1, L"<div class=\"Personal_Location\">\n");
			fwprintf(fp1, L"<img src=\"Images/LogoFooter.jpg\"width=\"27\"height=\"33\"/>\n");
			fwprintf(fp1, L"<span class=\"Personal_FullName\">%s - %s</span>\n", A[i].ten, A[i].mssv);
			fwprintf(fp1, L"<div class=\"Personal_Department\">KHOA CÔNG NGHỆ THÔNG TIN</div>\n");
			fwprintf(fp1, L"<br />");
			fwprintf(fp1, L"<div class=\"Personal_Phone\">\n");
			fwprintf(fp1, L"Email:%s\n", A[i].mail);
			fwprintf(fp1, L"</div>\n");
			fwprintf(fp1, L"<br />\n");
			fwprintf(fp1, L"<br />\n");
			fwprintf(fp1, L"</div>\n");
			fwprintf(fp1, L"<!-- End Thông tin cá nhân c?a th?y cô ----------------------------------------------------------------------------------------- -->\n");
			fwprintf(fp1, L"<div class=\"Personal_HinhcanhanKhung\">\n");
			fwprintf(fp1, L"<img src=\"Images/%s\"class=\"Personal_Hinhcanhan\"/>\n", A[i].hinh);
			fwprintf(fp1, L"</div>\n");
			fwprintf(fp1, L"</div>\n");
			fwprintf(fp1, L"<!-- End Below Banner Region -->\n");
			fwprintf(fp1, L"<!-- Begin MainContents Region -->\n");
			fwprintf(fp1, L"<div class=\"MainContain\">\n");
			fwprintf(fp1, L"<!-- Begin Top Region -->\n");
			fwprintf(fp1, L"<div class=\"MainContain_Top\">\n");
			fwprintf(fp1, L"<div class=\"InfoGroup\">Thông tin cá nhân</div>\n");
			fwprintf(fp1, L"<div>\n");
			fwprintf(fp1, L"<ul class=\"TextInList\">\n");
			fwprintf(fp1, L"<li>Họ và tên: %s</li>\n", A[i].ten);
			fwprintf(fp1, L"<li>MSSV:%s</li>\n", A[i].mssv);
			fwprintf(fp1, L"<li>Sinh viên khoa %s</li>\n", A[i].khoa);
			fwprintf(fp1, L"<li>Ngày sinh: %s</li>\n", A[i].day);
			fwprintf(fp1, L"<li>Email: %s</li>\n", A[i].mail);
			fwprintf(fp1, L"</ul>\n");
			fwprintf(fp1, L"</div>\n");
			fwprintf(fp1, L"<div class=\"InfoGroup\">Sở thích</div>\n");
			fwprintf(fp1, L"<div>\n");
			fwprintf(fp1, L" <ul class=\"TextInList\">\n");
			fwprintf(fp1, L"<li> %s</li>\n", A[i].sth);
			fwprintf(fp1, L"</ul>\n");
			fwprintf(fp1, L"</div>\n");
			fwprintf(fp1, L"<div class=\"InfoGroup\">Mô tả</div>\n");
			fwprintf(fp1, L"<div class=\"Description\">\n");
			fwprintf(fp1, L"%s\n", A[i].mt);
			fwprintf(fp1, L"</div>\n");
			fwprintf(fp1, L"</div>\n");
			fwprintf(fp1, L"</div>\n");
			fwprintf(fp1, L"</div>\n");
			fwprintf(fp1, L"<!-- Begin Layout Footer -->\n");
			fwprintf(fp1, L"<div class=\"Layout_Footer\">\n");
			fwprintf(fp1, L"<div class=\"divCopyright\">\n");
			fwprintf(fp1, L"<br />\n");
			fwprintf(fp1, L"<img src=\"Images/LogoFooter_gray.jpg\"width=\"34\"height=\"41\"/><br/>\n");
			fwprintf(fp1, L"<br />\n");
			fwprintf(fp1, L"@2018</br>\n");
			fwprintf(fp1, L"Đồ án giữ kỳ</br>\n");
			fwprintf(fp1, L"Kỹ thuật lập trình</br>\n");
			fwprintf(fp1, L"TH208/04</br>\n");
			fwprintf(fp1, L"MSSV:1712930 - TRẦN VĂN VỸ </br>\n");
			fwprintf(fp1, L"</div>\n");
			fwprintf(fp1, L"</div>\n");
			fwprintf(fp1, L"<!-- End Layout Footer -->\n");
			fwprintf(fp1, L"</div>\n");
			fwprintf(fp1, L"</body>\n");
			fwprintf(fp1, L"</html>\n");
			fwprintf(fp1, L"\n");
			fwprintf(fp1, L"\n");
			fclose(fp1);
		}
		for (int i = 0; i < k; i++)
		{	
			FILE*fp1= _wfopen(L"tap.html", L"a+t,ccs=UTF-8");
			fwprintf(fp1, L"<!DOCTYPE html PUBLIC\"-//W3C//DTD XHTML 1.0 Transitional//EN\"\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
			fwprintf(fp1, L"<html xmlns=\"http://www.w3.org/1999/xhtml \">\n ");
			fwprintf(fp1, L"<head>");
			fwprintf(fp1, L"<meta http-equiv=\"Content - Type\"content=\"text/html; charset = utf - 8\"/>\n");
			fwprintf(fp1, L"<link rel=\"stylesheet\"type=\"text/css\"href=\"personal.css\"/>\n");
			fwprintf(fp1, L"<title>HCMUS - %s</title>\n",A[i].ten);
			fwprintf(fp1, L"</head>\n");
			fwprintf(fp1, L"<body>\n");
			fwprintf(fp1, L"<div class=\"Layout_container\">\n");
			fwprintf(fp1, L"<!-- Begin Layout Banner Region -->\n");
			fwprintf(fp1, L"<div class=\"Layout_Banner\" >\n");
			fwprintf(fp1, L"<div><img id=\"logo\"src=\"Images/logo.jpg\"height=\"105\"/></div>\n");
			fwprintf(fp1, L"		<div class=\"Header_Title\">TRƯỜNG ĐẠI HỌC KHOA HỌC TỰ NHIÊN </div>\n");
			fwprintf(fp1, L"</div>");
			fwprintf(fp1, L"<!-- End Layout Banner Region -->");
			fwprintf(fp1, L"<!-- Begin Layout MainContents Region -->");
			fwprintf(fp1, L"<div class=\"Layout_MainContents\">\n");
			fwprintf(fp1, L"<!-- Begin Below Banner Region -->\n");
			fwprintf(fp1, L"<div class=\"Personal_Main_Information\">\n");
			fwprintf(fp1, L"<!-- Begin Thông tin cá nhân c?a th?y cô ----------------------------------------------------------------------------------------- -->\n");
			fwprintf(fp1, L"<div class=\"Personal_Location\">\n");
			fwprintf(fp1, L"<img src=\"Images/LogoFooter.jpg\"width=\"27\"height=\"33\"/>\n");
			fwprintf(fp1, L"<span class=\"Personal_FullName\">%s - %s</span>\n", A[i].ten,A[i].mssv);
			fwprintf(fp1, L"<div class=\"Personal_Department\">KHOA CÔNG NGHỆ THÔNG TIN</div>\n");
			fwprintf(fp1, L"<br />");
			fwprintf(fp1, L"<div class=\"Personal_Phone\">\n");
			fwprintf(fp1, L"Email:%s\n", A[i].mail);
			fwprintf(fp1, L"</div>\n");
			fwprintf(fp1, L"<br />\n");
			fwprintf(fp1, L"<br />\n");
			fwprintf(fp1, L"</div>\n");
			fwprintf(fp1, L"<!-- End Thông tin cá nhân c?a th?y cô ----------------------------------------------------------------------------------------- -->\n");
			fwprintf(fp1, L"<div class=\"Personal_HinhcanhanKhung\">\n");
			fwprintf(fp1, L"<img src=\"Images/%s\"class=\"Personal_Hinhcanhan\"/>\n", A[i].hinh);
			fwprintf(fp1, L"</div>\n");
			fwprintf(fp1, L"</div>\n");
			fwprintf(fp1, L"<!-- End Below Banner Region -->\n");
			fwprintf(fp1, L"<!-- Begin MainContents Region -->\n");
			fwprintf(fp1, L"<div class=\"MainContain\">\n");
			fwprintf(fp1, L"<!-- Begin Top Region -->\n");
			fwprintf(fp1, L"<div class=\"MainContain_Top\">\n");
			fwprintf(fp1, L"<div class=\"InfoGroup\">Thông tin cá nhân</div>\n");
			fwprintf(fp1, L"<div>\n");
			fwprintf(fp1, L"<ul class=\"TextInList\">\n");
			fwprintf(fp1, L"<li>Họ và tên: %s</li>\n", A[i].ten);
			fwprintf(fp1, L"<li>MSSV:%s</li>\n", A[i].mssv);
			fwprintf(fp1, L"<li>Sinh viên khoa %s</li>\n", A[i].khoa);
			fwprintf(fp1, L"<li>Ngày sinh: %s</li>\n", A[i].day);
			fwprintf(fp1, L"<li>Email: %s</li>\n", A[i].mail);
			fwprintf(fp1, L"</ul>\n");
			fwprintf(fp1, L"</div>\n");
			fwprintf(fp1, L"<div class=\"InfoGroup\">Sở thích</div>\n");
			fwprintf(fp1, L"<div>\n");
			fwprintf(fp1, L" <ul class=\"TextInList\">\n");
			fwprintf(fp1, L"<li> %s</li>\n", A[i].sth);
			fwprintf(fp1, L"</ul>\n");
			fwprintf(fp1, L"</div>\n");
			fwprintf(fp1, L"<div class=\"InfoGroup\">Mô tả</div>\n");
			fwprintf(fp1, L"<div class=\"Description\">\n");
			fwprintf(fp1, L"%s\n", A[i].mt);
			fwprintf(fp1, L"</div>\n");
			fwprintf(fp1, L"</div>\n");
			fwprintf(fp1, L"</div>\n");
			fwprintf(fp1, L"</div>\n");
			fwprintf(fp1, L"<!-- Begin Layout Footer -->\n");
			fwprintf(fp1, L"<div class=\"Layout_Footer\">\n");
			fwprintf(fp1, L"<div class=\"divCopyright\">\n");
			fwprintf(fp1, L"<br />\n");
			fwprintf(fp1, L"<img src=\"Images/LogoFooter_gray.jpg\"width=\"34\"height=\"41\"/><br/>\n");
			fwprintf(fp1, L"<br />\n");
			fwprintf(fp1, L"@2018</br>\n");
			fwprintf(fp1, L"Đồ án giữ kỳ</br>\n");
			fwprintf(fp1, L"Kỹ thuật lập trình</br>\n");
			fwprintf(fp1, L"TH208/04</br>\n");
			fwprintf(fp1, L"MSSV:1712930 - TRẦN VĂN VỸ </br>\n");
			fwprintf(fp1, L"</div>\n");
			fwprintf(fp1, L"</div>\n");
			fwprintf(fp1, L"<!-- End Layout Footer -->\n");
			fwprintf(fp1, L"</div>\n");
		
			fwprintf(fp1, L"</body>\n");
			fwprintf(fp1, L"</html>\n");
			fwprintf(fp1, L"\n");
			fwprintf(fp1, L"\n");
			fclose(fp1);
		}
	}
	else wprintf( L"không có file thông tin sinh viên");
	fclose(fp);
	fclose(fp2);
	
	_getch();
}