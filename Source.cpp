#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <fcntl.h>
#include <io.h> 
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
	_setmode(_fileno(stdout), _O_U16TEXT); //needed for output
	_setmode(_fileno(stdin), _O_U16TEXT); //needed for input
	FILE*fp;
	FILE *fp1;
	FILE *fp2;
	SV A[20];
	
	int k = 0;
	_wfopen_s(&fp, L"D:\in.txt", L"r, ccs=UTF-8");
	_wfopen_s(&fp1, L"D:\print.txt", L"w, ccs=UTF-8");
	_wfopen_s(&fp2, L"d:\doc.txt", L"w,ccs=UTF-8");
	if (fp != NULL)
	{
		char c;
		do
		{
			c = fgetc(fp);
			if (c == '\n')
				k++;
		} while (c != EOF);
		printf("%d", k);
		fclose(fp);
		_wfopen_s(&fp, L"D:\input.txt", L"r, ccs=UTF-8");
		for (int i = 0; i < k; i++)
		{
			fwscanf(fp, L"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d", &A[i].mssv, &A[i].ten, &A[i].khoa, &A[i].day, &A[i].mail, &A[i].mt, &A[i].sth, &A[i].k);
			fwprintf(fp1, L"%s\n%s\n%s\n%d\n%s\n%s\n%s\n%s\n", A[i].mssv, A[i].ten, A[i].khoa, A[i].k, A[i].day, A[i].mail, A[i].mt, A[i].sth);
		}
	}
	else printf("khong co file");
	
	fclose(fp1);
	fclose(fp);
	fclose(fp2);
	_getch();

}