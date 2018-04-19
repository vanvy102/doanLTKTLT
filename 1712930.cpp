#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <fcntl.h>
#include <io.h> 
struct SV
{
	char mssv[10];
	char ten[30];
	char khoa[30];
	int k;
	char mail[100];
	char day[10];
	char hinh[20];
	char mt[1000];
	char sth[1000];
};

void main()
{
	_setmode(_fileno(stdout), _O_U16TEXT); //needed for output
	_setmode(_fileno(stdin), _O_U16TEXT); //needed for input
	FILE*fp;
	FILE *fp1;
	SV A[10];
	 _wfopen_s(&fp,L"D:\thongtinsv.csv",L"r, ccs=UTF-8");
	 _wfopen_s(&fp1, L"D:\print.txt", L"w+, ccs=UTF-8");
	 if (fp != NULL)
	 {
		 fwscanf_s(fp, L"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%f", &A[0].mssv, &A[0].ten, &A[0].khoa, &A[0].k, &A[0].day, &A[0].mail, &A[0].mt, &A[0].sth);
	 }
	 fwprintf(fp1,L"%c,%c,%c,%c,%d,%c,%c,%c,%c", A[0].mssv, A[0].ten, A[0].khoa, A[0].k, A[0].day, A[0].mail, A[0].mt, A[0].sth);
	 fclose(fp);
	 fclose(fp1);
	_getch();
	
}