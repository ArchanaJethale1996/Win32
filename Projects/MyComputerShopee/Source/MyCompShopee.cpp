#include <windows.h>
#include <stdio.h>
#include "resource.h"
#include<Windowsx.h>
#include"Items.h"
#include<Commctrl.h>
bool g_proceed = false;
bool g_bill = false;
bool g_receipt = false;
bool g_again = false;
int price;
TCHAR str[255];
HWND ghwnd = NULL;
int i;
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK MyDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK MyDlgProc_Details(HWND hDlg1, UINT iMsg, WPARAM wParam, LPARAM lParam);
bool LoadMyBitmap(LPCWSTR, HDC, LONG, LONG, LONG width, LONG Bottom);
void initialize_data();
int sum;
//Final Reciept value will be stored iin this struct
struct Final_Input {
	int cpu_company;			TCHAR cpu_company1[20];
	int cpu_generation; 		TCHAR cpu_generation1[20];
	int cpu_architecture;		TCHAR cpu_architecture1[20];
	int cpu_price;				int cpu_price1;
	int ram_company;			TCHAR ram_company1[20];
	int ram_size;				TCHAR ram_size1[20];
	int ram_price;				int ram_price1;
	int mother_company;			TCHAR mother_company1[20];
	int mother_type;		TCHAR mother_type1[20];
	int mother_price;			int mother_price1;
	int graphics_company;		TCHAR graphics_company1[20];
	int	graphics_size;			TCHAR graphics_size1[20];
	int	graphics_type;			TCHAR graphics_type1[20];
	int	graphics_price;			int graphics_price1;
	int key_company;			TCHAR key_company1[20];
	int key_type;			TCHAR key_type1[20];
	int key_price;				int key_price1;
	int mouse_company;			TCHAR mouse_company1[20];
	int mouse_type;			TCHAR mouse_type1[20];
	int mouse_price;			int mouse_price1;
	int cd_company;				TCHAR cd_company1[20];
	int cd_type;				TCHAR cd_type1[20];
	int cd_price;				int cd_price1;
	int smps_company;			TCHAR smps_company1[20];
	int smps_powerout;			TCHAR smps_powerout1[20];
	int smps_color;			TCHAR smps_color1[20];
	int smps_price;				int smps_price1;
	int monitor_company;		TCHAR monitor_company1[20];
	int monitor_size;		TCHAR monitor_size1[20];
	int monitor_type;			TCHAR monitor_type1[20];
	int monitor_price;			int monitor_price1;
	int cabinet_company;		TCHAR cabinet_company1[20];
	int cabinet_type;			TCHAR cabinet_type1[20];
	int cabinet_price;			int cabinet_price1;
	int harddisk_company;		TCHAR harddisk_company1[20];
	int harddisk_size;			TCHAR harddisk_size1[20];
	int harddisk_price;			int harddisk_price1;
	int pen_company;		TCHAR pen_company1[20];
	int pen_size;			TCHAR pen_size1[20];
	int pen_price;			int pen_price1;
}inn;


BOOL CALLBACK MyDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HWND aa;
	HDC hdcStatic = NULL;
	HFONT hFont = NULL;
	HDC hdc = NULL;
	RECT rc;
	PAINTSTRUCT ps;
	switch (iMsg)
	{
	case WM_PAINT:
		hdc = BeginPaint(hDlg, &ps);
		GetWindowRect(hDlg, &rc);
		LoadMyBitmap(TEXT("aa.bmp"), hdc, 0, 0, rc.right, rc.bottom);
		SetBkMode(hdc, TRANSPARENT);
		EndPaint(hDlg, &ps);
		break;
	case WM_INITDIALOG:

		//CPU COMPANY NAME
		for (i = 0; i < 2; i++)
			SendDlgItemMessage(hDlg, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)cpu_name[i]);

		//RAM COMPANY
		for (i = 0; i < 3; i++)
			SendDlgItemMessage(hDlg, IDC_COMBO4, CB_ADDSTRING, 0, (LPARAM)ram_company[i]);
		//MOTHERBOARD COMPANY
		for (i = 0; i < 3; i++)
			SendDlgItemMessage(hDlg, IDC_COMBO6, CB_ADDSTRING, 0, (LPARAM)mother_company[i]);
		//GRAPHICS COMPANY
		for (i = 0; i < 2; i++)
			SendDlgItemMessage(hDlg, IDC_COMBO7, CB_ADDSTRING, 0, (LPARAM)graphics_company[i]);
		//HARDDISK COMPANY
		for (i = 0; i < 2; i++)
			SendDlgItemMessage(hDlg, IDC_COMBO9, CB_ADDSTRING, 0, (LPARAM)harddisk_company[i]);
		//KEYBOARD COMPANY
		for (i = 0; i < 3; i++)
			SendDlgItemMessage(hDlg, IDC_COMBO11, CB_ADDSTRING, 0, (LPARAM)key_company[i]);
		//MOUSE COMPANY
		for (i = 0; i < 2; i++)
			SendDlgItemMessage(hDlg, IDC_COMBO12, CB_ADDSTRING, 0, (LPARAM)mouse_company[i]);
		//CD/DVD COMPANY
		for (i = 0; i < 2; i++)
			SendDlgItemMessage(hDlg, IDC_COMBO13, CB_ADDSTRING, 0, (LPARAM)cd_company[i]);
		//SMPS COMPANY
		for (i = 0; i < 2; i++)
			SendDlgItemMessage(hDlg, IDC_COMBO14, CB_ADDSTRING, 0, (LPARAM)smps_company[i]);
		//CABINET COMPANY
		for (i = 0; i < 4; i++)
			SendDlgItemMessage(hDlg, IDC_COMBO15, CB_ADDSTRING, 0, (LPARAM)cabinet_company[i]);
		//MONITOR COMPANY
		for (i = 0; i < 3; i++)
			SendDlgItemMessage(hDlg, IDC_COMBO16, CB_ADDSTRING, 0, (LPARAM)monitor_company[i]);
		//PENDRIVE COMPANY
		for (i = 0; i < 3; i++)
			SendDlgItemMessage(hDlg, IDC_COMBO17, CB_ADDSTRING, 0, (LPARAM)pen_company[i]);
		aa = GetDlgItem(hDlg, IDC_COMBO18);
		ShowWindow(aa, SW_HIDE);

		//CPU GENERATION
		aa = GetDlgItem(hDlg, IDC_COMBO2);
		ShowWindow(aa, SW_HIDE);
		//CPU ARCHITECTURE
		aa = GetDlgItem(hDlg, IDC_COMBO3);
		ShowWindow(aa, SW_HIDE);
		//RAM SIZE
		aa = GetDlgItem(hDlg, IDC_COMBO5);
		ShowWindow(aa, SW_HIDE);
		//GRAPHICS CARD 
		aa = GetDlgItem(hDlg, IDC_COMBO8);
		ShowWindow(aa, SW_HIDE);

		aa = GetDlgItem(hDlg, IDC_COMBO13_1);
		ShowWindow(aa, SW_HIDE);
		aa = GetDlgItem(hDlg, IDC_COMBO8_1);
		ShowWindow(aa, SW_HIDE);

		//HARDDISK SIZE
		aa = GetDlgItem(hDlg, IDC_COMBO10);
		ShowWindow(aa, SW_HIDE);


		aa = GetDlgItem(hDlg, IDC_COMBO11_1);
		ShowWindow(aa, SW_HIDE);
		aa = GetDlgItem(hDlg, IDC_COMBO6_1);
		ShowWindow(aa, SW_HIDE);
		aa = GetDlgItem(hDlg, IDC_COMBO12_1);
		ShowWindow(aa, SW_HIDE);
		aa = GetDlgItem(hDlg, IDC_COMBO16_1);
		ShowWindow(aa, SW_HIDE);
		aa = GetDlgItem(hDlg, IDC_COMBO16_2);
		ShowWindow(aa, SW_HIDE);
		aa = GetDlgItem(hDlg, IDC_COMBO14_1);
		ShowWindow(aa, SW_HIDE);
		aa = GetDlgItem(hDlg, IDC_COMBO14_2);
		ShowWindow(aa, SW_HIDE);

		//PRICE TEXTBOX HIDE
		aa = GetDlgItem(hDlg, ID_CPU);
		ShowWindow(aa, SW_HIDE);
		aa = GetDlgItem(hDlg, ID_RAM);
		ShowWindow(aa, SW_HIDE);
		aa = GetDlgItem(hDlg, ID_MOTHER);
		ShowWindow(aa, SW_HIDE);
		aa = GetDlgItem(hDlg, ID_GRAPHICS);
		ShowWindow(aa, SW_HIDE);
		aa = GetDlgItem(hDlg, ID_HARD);
		ShowWindow(aa, SW_HIDE);
		aa = GetDlgItem(hDlg, ID_KEY);
		ShowWindow(aa, SW_HIDE);
		aa = GetDlgItem(hDlg, ID_MOUSE);
		ShowWindow(aa, SW_HIDE);
		aa = GetDlgItem(hDlg, ID_CD);
		ShowWindow(aa, SW_HIDE);
		aa = GetDlgItem(hDlg, ID_SMPS);
		ShowWindow(aa, SW_HIDE);
		aa = GetDlgItem(hDlg, ID_CABINET);
		ShowWindow(aa, SW_HIDE);

		aa = GetDlgItem(hDlg, IDC_COMBO15_1);
		ShowWindow(aa, SW_HIDE);

		aa = GetDlgItem(hDlg, ID_MONITOR);
		ShowWindow(aa, SW_HIDE);
		aa = GetDlgItem(hDlg, ID_PEN);
		ShowWindow(aa, SW_HIDE);

		//RS TEXT BOX HIDE
		aa = GetDlgItem(hDlg, ID_CPU_RS);
		ShowWindow(aa, SW_HIDE);
		aa = GetDlgItem(hDlg, ID_RAM_RS);
		ShowWindow(aa, SW_HIDE);
		aa = GetDlgItem(hDlg, ID_MOTHER_RS);
		ShowWindow(aa, SW_HIDE);
		aa = GetDlgItem(hDlg, ID_GRAPHICS_RS);
		ShowWindow(aa, SW_HIDE);
		aa = GetDlgItem(hDlg, ID_HARD_RS);
		ShowWindow(aa, SW_HIDE);
		aa = GetDlgItem(hDlg, ID_KEY_RS);
		ShowWindow(aa, SW_HIDE);
		aa = GetDlgItem(hDlg, ID_MOUSE_RS);
		ShowWindow(aa, SW_HIDE);
		aa = GetDlgItem(hDlg, ID_CD_RS);
		ShowWindow(aa, SW_HIDE);
		aa = GetDlgItem(hDlg, ID_SMPS_RS);
		ShowWindow(aa, SW_HIDE);
		aa = GetDlgItem(hDlg, ID_CABINET_RS);
		ShowWindow(aa, SW_HIDE);
		aa = GetDlgItem(hDlg, ID_MONITOR_RS);
		ShowWindow(aa, SW_HIDE);
		aa = GetDlgItem(hDlg, ID_PEN_RS);
		ShowWindow(aa, SW_HIDE);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_OK_D:
			//FINAL VALUES EVEN AFTER CHANGES
			g_bill = true;
			//MAKING NULL
			initialize_data();

			//TAKE THE SELECTED ITEM AND ITEM NAME IN STRUCT FOR FINAL INPUTS
			//CPU
			aa = GetDlgItem(hDlg, IDC_COMBO1);
			inn.cpu_company = SendMessage(aa, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(aa, (UINT)CB_GETLBTEXT, (WPARAM)inn.cpu_company, (LPARAM)inn.cpu_company1);
			//MessageBox(hDlg, (LPCWSTR)inn.cpu_company1, TEXT(""), MB_OK);

			aa = GetDlgItem(hDlg, IDC_COMBO2);
			inn.cpu_generation = SendMessage(aa, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(aa, (UINT)CB_GETLBTEXT, (WPARAM)inn.cpu_generation, (LPARAM)inn.cpu_generation1);

			aa = GetDlgItem(hDlg, IDC_COMBO3);
			inn.cpu_architecture = SendMessage(aa, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(aa, (UINT)CB_GETLBTEXT, (WPARAM)inn.cpu_architecture, (LPARAM)inn.cpu_architecture1);

			inn.cpu_price1 = GetDlgItemInt(hDlg, ID_CPU, NULL, TRUE);


			//RAM
			aa = GetDlgItem(hDlg, IDC_COMBO4);
			inn.ram_company = SendMessage(aa, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(aa, (UINT)CB_GETLBTEXT, (WPARAM)inn.ram_company, (LPARAM)inn.ram_company1);

			aa = GetDlgItem(hDlg, IDC_COMBO5);
			inn.ram_size = SendMessage(aa, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(aa, (UINT)CB_GETLBTEXT, (WPARAM)inn.ram_size, (LPARAM)inn.ram_size1);

			inn.ram_price1 = GetDlgItemInt(hDlg, ID_RAM, NULL, TRUE);

			//MOTHERBOARD
			aa = GetDlgItem(hDlg, IDC_COMBO6);
			inn.mother_company = SendMessage(aa, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(aa, (UINT)CB_GETLBTEXT, (WPARAM)inn.mother_company, (LPARAM)inn.mother_company1);

			aa = GetDlgItem(hDlg, IDC_COMBO6_1);
			inn.mother_type = SendMessage(aa, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(aa, (UINT)CB_GETLBTEXT, (WPARAM)inn.mother_type, (LPARAM)inn.mother_type1);

			inn.mother_price1 = GetDlgItemInt(hDlg, ID_MOTHER, NULL, TRUE);

			//GRAPHICS CARD
			aa = GetDlgItem(hDlg, IDC_COMBO7);
			inn.graphics_company = SendMessage(aa, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(aa, (UINT)CB_GETLBTEXT, (WPARAM)inn.graphics_company, (LPARAM)inn.graphics_company1);

			aa = GetDlgItem(hDlg, IDC_COMBO8);
			inn.graphics_size = SendMessage(aa, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(aa, (UINT)CB_GETLBTEXT, (WPARAM)inn.graphics_size, (LPARAM)inn.graphics_size1);

			aa = GetDlgItem(hDlg, IDC_COMBO8_1);
			inn.graphics_type = SendMessage(aa, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(aa, (UINT)CB_GETLBTEXT, (WPARAM)inn.graphics_type, (LPARAM)inn.graphics_type1);

			inn.graphics_price1 = GetDlgItemInt(hDlg, ID_GRAPHICS, NULL, TRUE);


			//HARDDISK
			aa = GetDlgItem(hDlg, IDC_COMBO9);
			inn.harddisk_company = SendMessage(aa, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(aa, (UINT)CB_GETLBTEXT, (WPARAM)inn.harddisk_company, (LPARAM)inn.harddisk_company1);

			aa = GetDlgItem(hDlg, IDC_COMBO10);
			inn.harddisk_size = SendMessage(aa, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(aa, (UINT)CB_GETLBTEXT, (WPARAM)inn.harddisk_size, (LPARAM)inn.harddisk_size1);

			inn.harddisk_price1 = GetDlgItemInt(hDlg, ID_HARD, NULL, TRUE);

			//KEYBOARD
			aa = GetDlgItem(hDlg, IDC_COMBO11);
			inn.key_company = SendMessage(aa, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(aa, (UINT)CB_GETLBTEXT, (WPARAM)inn.key_company, (LPARAM)inn.key_company1);

			aa = GetDlgItem(hDlg, IDC_COMBO11_1);
			inn.key_type = SendMessage(aa, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(aa, (UINT)CB_GETLBTEXT, (WPARAM)inn.key_type, (LPARAM)inn.key_type1);

			inn.key_price1 = GetDlgItemInt(hDlg, ID_KEY, NULL, TRUE);


			//MOUSE
			aa = GetDlgItem(hDlg, IDC_COMBO12);
			inn.mouse_company = SendMessage(aa, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(aa, (UINT)CB_GETLBTEXT, (WPARAM)inn.mouse_company, (LPARAM)inn.mouse_company1);

			aa = GetDlgItem(hDlg, IDC_COMBO12_1);
			inn.mouse_type = SendMessage(aa, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(aa, (UINT)CB_GETLBTEXT, (WPARAM)inn.mouse_type, (LPARAM)inn.mouse_type1);

			inn.mouse_price1 = GetDlgItemInt(hDlg, ID_MOUSE, NULL, TRUE);


			//CD/DVD
			aa = GetDlgItem(hDlg, IDC_COMBO13);
			inn.cd_company = SendMessage(aa, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(aa, (UINT)CB_GETLBTEXT, (WPARAM)inn.cd_company, (LPARAM)inn.cd_company1);

			aa = GetDlgItem(hDlg, IDC_COMBO13_1);
			inn.cd_type = SendMessage(aa, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(aa, (UINT)CB_GETLBTEXT, (WPARAM)inn.cd_type, (LPARAM)inn.cd_type1);
			inn.cd_price1 = GetDlgItemInt(hDlg, ID_CD, NULL, TRUE);


			//SMPS
			aa = GetDlgItem(hDlg, IDC_COMBO14);
			inn.smps_company = SendMessage(aa, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(aa, (UINT)CB_GETLBTEXT, (WPARAM)inn.smps_company, (LPARAM)inn.smps_company1);
			aa = GetDlgItem(hDlg, IDC_COMBO14_1);
			inn.smps_powerout = SendMessage(aa, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(aa, (UINT)CB_GETLBTEXT, (WPARAM)inn.smps_powerout, (LPARAM)inn.smps_powerout1);
			aa = GetDlgItem(hDlg, IDC_COMBO14_2);
			inn.smps_color = SendMessage(aa, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(aa, (UINT)CB_GETLBTEXT, (WPARAM)inn.smps_color, (LPARAM)inn.smps_color1);
			inn.smps_price1 = GetDlgItemInt(hDlg, ID_SMPS, NULL, TRUE);


			//CABINET
			aa = GetDlgItem(hDlg, IDC_COMBO15);
			inn.cabinet_company = SendMessage(aa, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(aa, (UINT)CB_GETLBTEXT, (WPARAM)inn.cabinet_company, (LPARAM)inn.cabinet_company1);

			aa = GetDlgItem(hDlg, IDC_COMBO15_1);
			inn.cabinet_type = SendMessage(aa, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(aa, (UINT)CB_GETLBTEXT, (WPARAM)inn.cabinet_type, (LPARAM)inn.cabinet_type1);

			inn.cabinet_price1 = GetDlgItemInt(hDlg, ID_CABINET, NULL, TRUE);

			//MONITOR
			aa = GetDlgItem(hDlg, IDC_COMBO16);
			inn.monitor_company = SendMessage(aa, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(aa, (UINT)CB_GETLBTEXT, (WPARAM)inn.monitor_company, (LPARAM)inn.monitor_company1);
			aa = GetDlgItem(hDlg, IDC_COMBO16_1);
			inn.monitor_size = SendMessage(aa, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(aa, (UINT)CB_GETLBTEXT, (WPARAM)inn.monitor_size, (LPARAM)inn.monitor_size1);
			aa = GetDlgItem(hDlg, IDC_COMBO16_2);
			inn.monitor_type = SendMessage(aa, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(aa, (UINT)CB_GETLBTEXT, (WPARAM)inn.monitor_type, (LPARAM)inn.monitor_type1);
			inn.monitor_price1 = GetDlgItemInt(hDlg, ID_MONITOR, NULL, TRUE);

			//PENDRIVE
			aa = GetDlgItem(hDlg, IDC_COMBO17);
			inn.pen_company = SendMessage(aa, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(aa, (UINT)CB_GETLBTEXT, (WPARAM)inn.pen_company, (LPARAM)inn.pen_company1);

			aa = GetDlgItem(hDlg, IDC_COMBO18);
			inn.pen_size = SendMessage(aa, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(aa, (UINT)CB_GETLBTEXT, (WPARAM)inn.pen_size, (LPARAM)inn.pen_size1);

			inn.pen_price1 = GetDlgItemInt(hDlg, ID_PEN, NULL, TRUE);

			InvalidateRect(ghwnd, NULL, TRUE);
			EndDialog(hDlg, 0);
			break;
		case IDC_COMBO1:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				aa = GetDlgItem(hDlg, ID_CPU);
				(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)TEXT(""));
				aa = GetDlgItem(hDlg, IDC_COMBO2);
				ShowWindow(aa, SW_SHOW);
				inn.cpu_company = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				SendDlgItemMessage(hDlg, IDC_COMBO2, CB_RESETCONTENT, 0, 0);
				SendDlgItemMessage(hDlg, IDC_COMBO3, CB_RESETCONTENT, 0, 0);
				if (inn.cpu_company == 0)
				{
					for (i = 0; i < 3; i++)
						SendDlgItemMessage(hDlg, IDC_COMBO2, CB_ADDSTRING, 0, (LPARAM)intel_generation[i]);
				}
				else if (inn.cpu_company == 1)
				{
					for (i = 0; i < 3; i++)
						SendDlgItemMessage(hDlg, IDC_COMBO2, CB_ADDSTRING, 0, (LPARAM)amd_generation[i]);
				}
			}
			break;
		case IDC_COMBO2:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				aa = GetDlgItem(hDlg, ID_CPU);
				(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)TEXT(""));
				aa = GetDlgItem(hDlg, IDC_COMBO3);
				ShowWindow(aa, SW_SHOW);

				inn.cpu_generation = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL,
					(WPARAM)0, (LPARAM)0);
				SendDlgItemMessage(hDlg, IDC_COMBO3, CB_RESETCONTENT, 0, 0);

				if (inn.cpu_company == 0)
				{
					for (i = 0; i < 6; i++)
						SendDlgItemMessage(hDlg, IDC_COMBO3, CB_ADDSTRING, 0, (LPARAM)i3_architecture[i]);
				}
				else if (inn.cpu_company == 1)
				{
					for (i = 0; i < 6; i++)
						SendDlgItemMessage(hDlg, IDC_COMBO3, CB_ADDSTRING, 0, (LPARAM)a4_architecture[i]);
				}
			}
			break;
		case IDC_COMBO3:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				aa = GetDlgItem(hDlg, ID_CPU_RS);
				ShowWindow(aa, SW_SHOW);
				EnableWindow(aa, FALSE);
				wsprintf(str, TEXT(" %c "), 0x000020B9);
				(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)str);
				aa = GetDlgItem(hDlg, ID_CPU);
				ShowWindow(aa, SW_SHOW);
				inn.cpu_architecture = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				if (inn.cpu_company == 0)
				{
					switch (inn.cpu_generation)
					{
					case 0:
						(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)i3_architecture_price[inn.cpu_architecture]);
						break;
					case 1:
						(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)i5_architecture_price[inn.cpu_architecture]);
						break;
					case 2:
						(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)i7_architecture_price[inn.cpu_architecture]);
						break;
					}
				}
				else
				{
					switch (inn.cpu_generation)
					{
					case 0:
						(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)a4_architecture_price[inn.cpu_architecture]);
						break;
					case 1:
						(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)am3_architecture_price[inn.cpu_architecture]);
						break;
					case 2:
						(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)fx_architecture_price[inn.cpu_architecture]);
						break;
					}
				}

				EnableWindow(aa, FALSE);
			}
			break;
		case IDC_COMBO4:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{

				aa = GetDlgItem(hDlg, ID_RAM);
				(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)TEXT(""));
				aa = GetDlgItem(hDlg, IDC_COMBO5);
				ShowWindow(aa, SW_SHOW);
				inn.ram_company = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL,
					(WPARAM)0, (LPARAM)0);
				SendDlgItemMessage(hDlg, IDC_COMBO5, CB_RESETCONTENT, 0, 0);

				if (inn.ram_company == 0)
				{
					for (i = 0; i < 3; i++)
						SendDlgItemMessage(hDlg, IDC_COMBO5, CB_ADDSTRING, 0, (LPARAM)gskill_size[i]);
				}
				else if (inn.ram_company == 1)
				{
					for (i = 0; i < 3; i++)
						SendDlgItemMessage(hDlg, IDC_COMBO5, CB_ADDSTRING, 0, (LPARAM)samsung_size[i]);
				}
				else if (inn.ram_company == 2)
				{
					for (i = 0; i < 3; i++)
						SendDlgItemMessage(hDlg, IDC_COMBO5, CB_ADDSTRING, 0, (LPARAM)transcend_size[i]);
				}
				//	MessageBox(hDlg, (LPCWSTR)ListItem, TEXT("Item Selected"), MB_OK);
			}
			break;
		case IDC_COMBO5:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				aa = GetDlgItem(hDlg, ID_RAM_RS);
				ShowWindow(aa, SW_SHOW);
				wsprintf(str, TEXT(" %c "), 0x000020B9);
				(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)str);
				EnableWindow(aa, FALSE);
				aa = GetDlgItem(hDlg, ID_RAM);
				ShowWindow(aa, SW_SHOW);
				inn.ram_size = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				if (inn.ram_company == 0)
				{
					(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)gskill_price[inn.ram_size]);
				}
				else if (inn.ram_company == 1)
				{
					(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)samsumg_price[inn.ram_size]);
				}
				else if (inn.ram_company == 2)
				{
					(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)transcend_price[inn.ram_size]);
				}

				EnableWindow(aa, FALSE);
			}
			break;

		case IDC_COMBO6:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				aa = GetDlgItem(hDlg, ID_MOTHER);
				(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)TEXT(""));
				aa = GetDlgItem(hDlg, IDC_COMBO6_1);
				ShowWindow(aa, SW_SHOW);
				inn.mother_company = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				SendDlgItemMessage(hDlg, IDC_COMBO6_1, CB_RESETCONTENT, 0, 0);

				for (i = 0; i < 2; i++)
					SendDlgItemMessage(hDlg, IDC_COMBO6_1, CB_ADDSTRING, 0, (LPARAM)mother_type[i]);

			}
			break;
		case IDC_COMBO6_1:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				aa = GetDlgItem(hDlg, ID_MOTHER_RS);
				ShowWindow(aa, SW_SHOW);
				wsprintf(str, TEXT(" %c "), 0x000020B9);
				(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)str);
				EnableWindow(aa, FALSE);
				aa = GetDlgItem(hDlg, ID_MOTHER);
				ShowWindow(aa, SW_SHOW);
				inn.mother_type = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				if (inn.mother_type == 0)
				{
					(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)mother_price1[inn.mother_company]);
				}
				else if (inn.mother_type == 1)
				{
					(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)mother_price2[inn.mother_company]);
				}

				EnableWindow(aa, FALSE);
			}

			break;
		case IDC_COMBO7:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				aa = GetDlgItem(hDlg, ID_GRAPHICS);
				(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)TEXT(""));
				aa = GetDlgItem(hDlg, IDC_COMBO8);
				ShowWindow(aa, SW_SHOW);
				inn.graphics_company = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				SendDlgItemMessage(hDlg, IDC_COMBO8, CB_RESETCONTENT, 0, 0);
				SendDlgItemMessage(hDlg, IDC_COMBO8_1, CB_RESETCONTENT, 0, 0);
				if (inn.graphics_company == 0)
				{
					for (i = 0; i < 3; i++)
						SendDlgItemMessage(hDlg, IDC_COMBO8, CB_ADDSTRING, 0, (LPARAM)nvidia_size[i]);
				}
				else if (inn.graphics_company == 1)
				{
					for (i = 0; i < 2; i++)
						SendDlgItemMessage(hDlg, IDC_COMBO8, CB_ADDSTRING, 0, (LPARAM)amd_size[i]);
				}
			}
			break;
		case IDC_COMBO8:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				aa = GetDlgItem(hDlg, ID_GRAPHICS);
				(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)TEXT(""));

				aa = GetDlgItem(hDlg, IDC_COMBO8_1);
				ShowWindow(aa, SW_SHOW);
				inn.graphics_size = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				SendDlgItemMessage(hDlg, IDC_COMBO8_1, CB_RESETCONTENT, 0, 0);
				for (i = 0; i < 2; i++)
					SendDlgItemMessage(hDlg, IDC_COMBO8_1, CB_ADDSTRING, 0, (LPARAM)nvidia_type[i]);
			}
			break;
		case IDC_COMBO8_1:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				aa = GetDlgItem(hDlg, ID_GRAPHICS_RS);
				ShowWindow(aa, SW_SHOW);
				wsprintf(str, TEXT(" %c "), 0x000020B9);
				(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)str);
				EnableWindow(aa, FALSE);
				aa = GetDlgItem(hDlg, ID_GRAPHICS);
				ShowWindow(aa, SW_SHOW);
				EnableWindow(aa, FALSE);
				inn.graphics_type = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				if (inn.graphics_company == 0)
				{
					if (inn.graphics_size == 0)
					{
						if (inn.graphics_type == 0)
						{
							(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)nvidia_ddr3_price[inn.graphics_size]);
						}
						else if (inn.graphics_type == 1)
						{
							(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)nvidia_ddr5_price[inn.graphics_size]);
						}
					}
					else if (inn.graphics_size == 1)
					{

						if (inn.graphics_type == 0)
						{
							(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)nvidia_ddr3_price[inn.graphics_size]);
						}
						else if (inn.graphics_type == 1)
						{
							(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)nvidia_ddr5_price[inn.graphics_size]);
						}
					}
					else if (inn.graphics_size == 2)
					{

						if (inn.graphics_type == 0)
						{
							(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)nvidia_ddr3_price[inn.graphics_size]);
						}
						else if (inn.graphics_type == 1)
						{
							(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)nvidia_ddr5_price[inn.graphics_size]);
						}
					}
				}
				else
				{
					if (inn.graphics_size == 0)
					{
						if (inn.graphics_type == 0)
						{
							(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)amd_ddr3_price[inn.graphics_size]);
						}
						else if (inn.graphics_type == 1)
						{
							(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)amd_ddr5_price[inn.graphics_size]);
						}
					}
					else if (inn.graphics_size == 1)
					{

						if (inn.graphics_type == 0)
						{
							(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)amd_ddr3_price[inn.graphics_size]);
						}
						else if (inn.graphics_type == 1)
						{
							(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)amd_ddr5_price[inn.graphics_size]);
						}
					}

				}

			}
			break;
		case IDC_COMBO9:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				aa = GetDlgItem(hDlg, ID_HARD);
				(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)TEXT(""));
				aa = GetDlgItem(hDlg, IDC_COMBO10);
				ShowWindow(aa, SW_SHOW);
				inn.harddisk_company = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				SendDlgItemMessage(hDlg, IDC_COMBO10, CB_RESETCONTENT, 0, 0);

				if (inn.harddisk_company == 0)
				{
					for (i = 0; i < 4; i++)
						SendDlgItemMessage(hDlg, IDC_COMBO10, CB_ADDSTRING, 0, (LPARAM)sea_size[i]);
				}
				else if (inn.harddisk_company == 1)
				{
					for (i = 0; i < 2; i++)
						SendDlgItemMessage(hDlg, IDC_COMBO10, CB_ADDSTRING, 0, (LPARAM)to_size[i]);
				}
			}
			break;
		case IDC_COMBO10:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				aa = GetDlgItem(hDlg, ID_HARD_RS);
				ShowWindow(aa, SW_SHOW);
				wsprintf(str, TEXT(" %c "), 0x000020B9);
				(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)str);
				EnableWindow(aa, FALSE);
				aa = GetDlgItem(hDlg, ID_HARD);
				ShowWindow(aa, SW_SHOW);
				inn.harddisk_size = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				if (inn.harddisk_company == 0)
				{
					(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)sea_price[inn.harddisk_size]);
				}
				else if (inn.harddisk_company == 1)
				{
					(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)sea_price[inn.harddisk_size]);
				}

				EnableWindow(aa, FALSE);
			}

			break;
		case IDC_COMBO11:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				aa = GetDlgItem(hDlg, ID_KEY);
				(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)TEXT(""));
				aa = GetDlgItem(hDlg, IDC_COMBO11_1);
				ShowWindow(aa, SW_SHOW);
				inn.key_company = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				SendDlgItemMessage(hDlg, IDC_COMBO11_1, CB_RESETCONTENT, 0, 0);

				for (i = 0; i < 2; i++)
					SendDlgItemMessage(hDlg, IDC_COMBO11_1, CB_ADDSTRING, 0, (LPARAM)key_type[i]);

			}
			break;
		case IDC_COMBO11_1:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				aa = GetDlgItem(hDlg, ID_KEY_RS);
				ShowWindow(aa, SW_SHOW);
				wsprintf(str, TEXT(" %c "), 0x000020B9);
				(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)str);
				EnableWindow(aa, FALSE);
				aa = GetDlgItem(hDlg, ID_KEY);
				ShowWindow(aa, SW_SHOW);
				inn.key_type = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				if (inn.key_type == 0)
				{
					(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)pen_2_price[inn.key_company]);
				}
				else if (inn.key_type == 1)
				{
					(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)pen_4_price[inn.key_company]);
				}

				EnableWindow(aa, FALSE);
			}
			break;
		case IDC_COMBO12:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				aa = GetDlgItem(hDlg, ID_MOUSE);
				(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)TEXT(""));
				aa = GetDlgItem(hDlg, IDC_COMBO12_1);
				ShowWindow(aa, SW_SHOW);
				inn.mouse_company = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				SendDlgItemMessage(hDlg, IDC_COMBO12_1, CB_RESETCONTENT, 0, 0);

				for (i = 0; i < 2; i++)
					SendDlgItemMessage(hDlg, IDC_COMBO12_1, CB_ADDSTRING, 0, (LPARAM)mouse_type[i]);
			}
			break;
		case IDC_COMBO12_1:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				aa = GetDlgItem(hDlg, ID_MOUSE_RS);
				ShowWindow(aa, SW_SHOW);
				wsprintf(str, TEXT(" %c "), 0x000020B9);
				(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)str);
				EnableWindow(aa, FALSE);
				aa = GetDlgItem(hDlg, ID_MOUSE);
				ShowWindow(aa, SW_SHOW);
				inn.mouse_type = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				if (inn.mouse_type == 0)
				{
					(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)pen_2_price[inn.mouse_company]);
				}
				else if (inn.mouse_type == 1)
				{
					(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)pen_4_price[inn.mouse_company]);
				}

				EnableWindow(aa, FALSE);
			}

			break;

		case IDC_COMBO13:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				aa = GetDlgItem(hDlg, ID_CD);
				(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)TEXT(""));
				aa = GetDlgItem(hDlg, IDC_COMBO13_1);
				ShowWindow(aa, SW_SHOW);
				inn.cd_company = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				SendDlgItemMessage(hDlg, IDC_COMBO13_1, CB_RESETCONTENT, 0, 0);

				for (i = 0; i < 3; i++)
					SendDlgItemMessage(hDlg, IDC_COMBO13_1, CB_ADDSTRING, 0, (LPARAM)cd_type[i]);

			}
			break;
		case IDC_COMBO13_1:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				aa = GetDlgItem(hDlg, ID_CD_RS);
				ShowWindow(aa, SW_SHOW);
				wsprintf(str, TEXT(" %c "), 0x000020B9);
				(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)str);
				EnableWindow(aa, FALSE);
				aa = GetDlgItem(hDlg, ID_CD);
				ShowWindow(aa, SW_SHOW);
				inn.cd_type = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				if (inn.cd_type == 0)
				{
					(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)cd_price1[inn.cd_company]);
				}
				else if (inn.cd_type == 1)
				{
					(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)cd_price2[inn.cd_company]);
				}
				else if (inn.cd_type == 2)
				{
					(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)cd_price3[inn.cd_company]);
				}
				EnableWindow(aa, FALSE);
			}

			break;
		case IDC_COMBO14:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				aa = GetDlgItem(hDlg, ID_SMPS);
				(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)TEXT(""));
				aa = GetDlgItem(hDlg, IDC_COMBO14_1);
				ShowWindow(aa, SW_SHOW);
				inn.smps_company = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				SendDlgItemMessage(hDlg, IDC_COMBO14_1, CB_RESETCONTENT, 0, 0);
				SendDlgItemMessage(hDlg, IDC_COMBO14_2, CB_RESETCONTENT, 0, 0);
				for (i = 0; i < 2; i++)
					SendDlgItemMessage(hDlg, IDC_COMBO14_1, CB_ADDSTRING, 0, (LPARAM)smps_powerout[i]);

			}
			break;
		case IDC_COMBO14_1:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				aa = GetDlgItem(hDlg, ID_SMPS);
				(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)TEXT(""));
				aa = GetDlgItem(hDlg, IDC_COMBO14_2);
				ShowWindow(aa, SW_SHOW);
				SendDlgItemMessage(hDlg, IDC_COMBO14_2, CB_RESETCONTENT, 0, 0);
				for (i = 0; i < 2; i++)
					SendDlgItemMessage(hDlg, IDC_COMBO14_2, CB_ADDSTRING, 0, (LPARAM)smps_color[i]);
				inn.smps_powerout = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			}
			break;
		case IDC_COMBO14_2:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				aa = GetDlgItem(hDlg, ID_SMPS_RS);
				ShowWindow(aa, SW_SHOW);
				wsprintf(str, TEXT(" %c "), 0x000020B9);
				(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)str);
				EnableWindow(aa, FALSE);
				aa = GetDlgItem(hDlg, ID_SMPS);
				ShowWindow(aa, SW_SHOW);
				inn.smps_color = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				if (inn.smps_company == 0)
				{
					if (inn.smps_powerout == 0)
					{
						(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)smps_price11[inn.smps_color]);
					}
					else if (inn.smps_powerout == 1)
					{
						(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)smps_price12[inn.smps_color]);
					}

				}
				else if (inn.smps_company == 1)
				{

					if (inn.smps_powerout == 0)
					{
						(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)smps_price21[inn.smps_color]);
					}
					else if (inn.smps_powerout == 1)
					{
						(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)smps_price22[inn.smps_color]);
					}
				}

				EnableWindow(aa, FALSE);
			}
			break;
			break;
		case IDC_COMBO15:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				aa = GetDlgItem(hDlg, ID_CABINET);
				(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)TEXT(""));
				aa = GetDlgItem(hDlg, IDC_COMBO15_1);
				ShowWindow(aa, SW_SHOW);
				inn.cabinet_company = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				SendDlgItemMessage(hDlg, IDC_COMBO15_1, CB_RESETCONTENT, 0, 0);

				for (i = 0; i < 2; i++)
					SendDlgItemMessage(hDlg, IDC_COMBO15_1, CB_ADDSTRING, 0, (LPARAM)cab_type[i]);

			}
			break;
		case IDC_COMBO15_1:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				aa = GetDlgItem(hDlg, ID_CABINET_RS);
				ShowWindow(aa, SW_SHOW);
				wsprintf(str, TEXT(" %c "), 0x000020B9);
				(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)str);
				EnableWindow(aa, FALSE);
				aa = GetDlgItem(hDlg, ID_CABINET);
				ShowWindow(aa, SW_SHOW);
				inn.cabinet_type = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				if (inn.cabinet_type == 0)
				{
					(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)cabinet_2_price[inn.cabinet_company]);
				}
				else if (inn.cabinet_type == 1)
				{
					(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)cabinet_4_price[inn.cabinet_company]);
				}

				EnableWindow(aa, FALSE);
			}
			break;
		case IDC_COMBO16:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				aa = GetDlgItem(hDlg, ID_MONITOR);
				(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)TEXT(""));
				aa = GetDlgItem(hDlg, IDC_COMBO16_1);
				ShowWindow(aa, SW_SHOW);
				inn.monitor_company = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				SendDlgItemMessage(hDlg, IDC_COMBO16_1, CB_RESETCONTENT, 0, 0);
				SendDlgItemMessage(hDlg, IDC_COMBO16_2, CB_RESETCONTENT, 0, 0);
				for (i = 0; i < 2; i++)
					SendDlgItemMessage(hDlg, IDC_COMBO16_1, CB_ADDSTRING, 0, (LPARAM)monitor_size[i]);

			}
			break;
		case IDC_COMBO16_1:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				aa = GetDlgItem(hDlg, ID_MONITOR);
				(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)TEXT(""));
				aa = GetDlgItem(hDlg, IDC_COMBO16_2);
				ShowWindow(aa, SW_SHOW);
				SendDlgItemMessage(hDlg, IDC_COMBO16_2, CB_RESETCONTENT, 0, 0);
				for (i = 0; i < 3; i++)
					SendDlgItemMessage(hDlg, IDC_COMBO16_2, CB_ADDSTRING, 0, (LPARAM)monitor_type[i]);
				inn.monitor_size = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			}
			break;
		case IDC_COMBO16_2:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				aa = GetDlgItem(hDlg, ID_MONITOR_RS);
				ShowWindow(aa, SW_SHOW);
				wsprintf(str, TEXT(" %c "), 0x000020B9);
				(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)str);
				EnableWindow(aa, FALSE);
				aa = GetDlgItem(hDlg, ID_MONITOR);
				ShowWindow(aa, SW_SHOW);
				inn.monitor_type = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				if (inn.monitor_company == 0)
				{
					if (inn.monitor_size == 0)
					{
						(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)monitor_price11[inn.monitor_type]);
					}
					else if (inn.monitor_size == 1)
					{
						(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)monitor_price12[inn.monitor_type]);
					}

				}
				else if (inn.monitor_company == 1)
				{

					if (inn.monitor_size == 0)
					{
						(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)monitor_price21[inn.monitor_type]);
					}
					else if (inn.monitor_size == 1)
					{
						(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)monitor_price22[inn.monitor_type]);
					}
				}
				else if (inn.monitor_company == 2)
				{

					if (inn.monitor_size == 0)
					{
						(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)monitor_price31[inn.monitor_type]);
					}
					else if (inn.monitor_size == 1)
					{
						(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)monitor_price32[inn.monitor_type]);
					}
				}
				EnableWindow(aa, FALSE);
			}
			break;
		case IDC_COMBO17:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				aa = GetDlgItem(hDlg, ID_PEN);
				(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)TEXT(""));
				aa = GetDlgItem(hDlg, IDC_COMBO18);
				ShowWindow(aa, SW_SHOW);
				inn.pen_company = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				SendDlgItemMessage(hDlg, IDC_COMBO18, CB_RESETCONTENT, 0, 0);

				for (i = 0; i < 3; i++)
					SendDlgItemMessage(hDlg, IDC_COMBO18, CB_ADDSTRING, 0, (LPARAM)pen_size[i]);

			}
			break;
		case IDC_COMBO18:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				aa = GetDlgItem(hDlg, ID_PEN_RS);
				ShowWindow(aa, SW_SHOW);
				wsprintf(str, TEXT(" %c "), 0x000020B9);
				(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)str);
				EnableWindow(aa, FALSE);
				aa = GetDlgItem(hDlg, ID_PEN);
				ShowWindow(aa, SW_SHOW);
				inn.pen_size = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				if (inn.pen_size == 0)
				{
					(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)pen_2_price[inn.pen_company]);
				}
				else if (inn.pen_size == 1)
				{
					(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)pen_4_price[inn.pen_company]);
				}
				else if (inn.pen_size == 2)
				{
					(TCHAR)SendMessage(aa, WM_SETTEXT, 0, (LPARAM)pen_8_price[inn.pen_company]);
				}
				EnableWindow(aa, FALSE);
			}

			break;

		case ID_CANCEL:
			EndDialog(hDlg, 0);
			g_proceed = false;
			InvalidateRect(ghwnd, NULL, TRUE);
			break;
		}
		return(TRUE);
	}return(FALSE);
}

HINSTANCE h1;


BOOL CALLBACK MyDlgProc_can(HWND hDlg1, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	RECT rect;
	PAINTSTRUCT ps;
	HFONT hFont;
	switch (iMsg)
	{

	case WM_PAINT:
		hdc = BeginPaint(hDlg1, &ps);
		GetClientRect(hDlg1, &rect);
		//SetRect(&rect, 0, 110, 1700, 1500);
		HBRUSH hBrush;
		hBrush = CreateSolidBrush(RGB(0, 0, 0));
		SelectObject(hdc, hBrush);
		FillRect(hdc, &rect, hBrush);
		SetBkColor(hdc, RGB(0, 0, 0));
		SetTextColor(hdc, RGB(255, 0, 0));
		hFont = CreateFont(30, 0, 0, 0, FW_DONTCARE, FALSE, TRUE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
			CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Impact"));
		SelectObject(hdc, hFont);
		SetBkColor(hdc, RGB(0, 0, 0));
		SetTextColor(hdc, RGB(255, 0, 0));
		DrawText(hdc, TEXT("My  Computer  Shoppee"), -1, &rect, DT_SINGLELINE | DT_CENTER);
		SetRect(&rect, 30, 60, 500, 100);
		DrawText(hdc, TEXT("A  Project  By     :     ASTROMEDICOMP"), -1, &rect, DT_SINGLELINE | DT_CENTER);
		SetRect(&rect, 30, 100, 500, 300);
		DrawText(hdc, TEXT("Archana  Jethale"), -1, &rect, DT_SINGLELINE | DT_CENTER);

		DeleteObject(hFont);
		GetWindowRect(hDlg1, &rect);
		LoadMyBitmap(TEXT("icon.bmp"), hdc, 10, 10, 80, 80);
		EndPaint(hDlg1, &ps);
		break;
	case WM_INITDIALOG:
		return(TRUE);
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_OK_D2:
			EndDialog(hDlg1, 0);
		}
		return(TRUE);
	}return(FALSE);
}

BOOL CALLBACK MyDlgProc_Details(HWND hDlg1, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{

	case WM_PAINT:
		break;
	case WM_INITDIALOG:
		SetFocus(GetDlgItem(hDlg1, ID_ETNAME_D1));
		return(TRUE);
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_OK_D1:
			char str1[255];
			size_t i;
			GetDlgItemText(hDlg1, ID_ETNAME_D1, (LPWSTR)str1, 50);
			//MessageBoxW(NULL,(LPCWSTR)str1,TEXT(""),MB_OK);
			g_receipt = true;
			wsprintf(str, TEXT("%s-Receipt.txt"), str1);
			FILE *fp;

			wcstombs_s(&i, str1, (size_t)(100), str, (size_t)(100));
			fopen_s(&fp, str1, "w");
			wsprintf(str, TEXT("%c"), 0x000020B9);
			TCHAR dash[3] = TEXT("--"), cap1[7][15] = { TEXT("Device"), TEXT("Company"), TEXT("Subtype"), TEXT("Generation"), TEXT("Size/Feature"),TEXT("Price (Rs)") }, devices[12][20] = { TEXT("CPU"),TEXT("RAM"),TEXT("Motherboard"),TEXT("Graphics Card"),TEXT("HardDisk"),TEXT("Keyboard"),TEXT("Mouse"),TEXT("CD / DVD Drive"),TEXT("SMPS"),TEXT("Cabinet"),TEXT("Monitor"),TEXT("Pen Drive") };
			fprintf_s(fp, "****************************************************************************************************************************************************\n");
			fprintf_s(fp, "                                         My Computer Shopee    \n");
			fprintf_s(fp, "****************************************************************************************************************************************************\n");
			fprintf_s(fp, "%20S%20S%20S%20S%20S%20S\n", cap1[0], cap1[1], cap1[2], cap1[3], cap1[4], cap1[5]);
			fprintf_s(fp, "****************************************************************************************************************************************************\n");
			fprintf_s(fp, "%20S%20S%20S%20S%20S%20d\n", devices[0], inn.cpu_company1, inn.cpu_generation1, inn.cpu_architecture1, dash, inn.cpu_price1);
			fprintf_s(fp, "%20S%20S%20S%20S%20S%20d\n", devices[1], inn.ram_company1, dash, dash, inn.ram_size1, inn.ram_price1);
			fprintf_s(fp, "%20S%20S%20S%20S%20S%20d\n", devices[2], inn.mother_company1, inn.mother_type1, dash, dash, inn.mother_price1);
			fprintf_s(fp, "%20S%20S%20S%20S%20S%20d\n", devices[3], inn.graphics_company1, inn.graphics_type1, dash, inn.graphics_size1, inn.graphics_price1);
			fprintf_s(fp, "%20S%20S%20S%20S%20S%20d\n", devices[4], inn.harddisk_company1, dash, dash, inn.harddisk_size1, inn.harddisk_price1);
			fprintf_s(fp, "%20S%20S%20S%20S%20S%20d\n", devices[5], inn.key_company1, inn.key_type1, dash, dash, inn.key_price1);
			fprintf_s(fp, "%20S%20S%20S%20S%20S%20d\n", devices[6], inn.mouse_company1, inn.mouse_type1, dash, dash, inn.mouse_price1);
			fprintf_s(fp, "%20S%20S%20S%20S%20S%20d\n", devices[7], inn.cd_company1, inn.cd_type1, dash, dash, inn.cd_price1);
			fprintf_s(fp, "%20S%20S%20S%20S%20S%20d\n", devices[8], inn.smps_company1, inn.smps_powerout1, dash, inn.smps_color1, inn.smps_price1);
			fprintf_s(fp, "%20S%20S%20S%20S%20S%20d\n", devices[9], inn.cabinet_company1, dash, dash, inn.cabinet_type1, inn.cabinet_price1);
			fprintf_s(fp, "%20S%20S%20S%20S%20S%20d\n", devices[10], inn.monitor_company1, inn.monitor_type1, dash, inn.monitor_size1, inn.monitor_price1);
			fprintf_s(fp, "%20S%20S%20S%20S%20S%20d\n", devices[11], inn.pen_company1, dash, dash, inn.pen_size1, inn.pen_price1);
			fprintf_s(fp, "****************************************************************************************************************************************************\n");

			fprintf_s(fp, "                                         Amount    =    Rs   %d    \n", sum);
			fprintf_s(fp, "****************************************************************************************************************************************************\n");

			fprintf_s(fp, "                                         Thank you for Visiting   \n");
			fprintf_s(fp, "****************************************************************************************************************************************************\n");

			fclose(fp);
			fp = NULL;
			EndDialog(hDlg1, 0);
			InvalidateRect(ghwnd, NULL, TRUE);
			wsprintf(str, TEXT("Your Receipt file Has Saved in current Directory with name %S"), str1);
			MessageBox(ghwnd, str, TEXT("File"), MB_OK);

			break;
		}
		return(TRUE);
	}return(FALSE);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdcWindow;
	static int  cxClient, cyClient, cxSource, cySource;
	switch (iMsg)
	{
	case WM_CREATE:
		cxSource = GetSystemMetrics(SM_CXSIZEFRAME) + GetSystemMetrics(SM_CXSIZE);
		cySource = GetSystemMetrics(SM_CYSIZEFRAME) + GetSystemMetrics(SM_CYCAPTION);
		break;
	case WM_SIZE:          
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);
		break;
	case WM_KEYDOWN:
		switch (LOWORD(wParam))
		{
		case VK_ESCAPE:
			DestroyWindow(hwnd);
			break;
		case VK_SPACE:
			if (g_proceed == false)
			{
				g_proceed = true;
				InvalidateRect(hwnd, NULL, TRUE);
				h1 = (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE);
				DialogBox(h1, MAKEINTRESOURCE(IDD_DIALOG1), hwnd, &MyDlgProc);
			}
			break;
		case 'R':
		case 'r':

			if (g_bill == true)
				if (g_receipt == false)
				{
					h1 = (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE);
					DialogBox(h1, MAKEINTRESOURCE(IDD_DETAILS), hwnd, &MyDlgProc_Details);
				}
			break;
		case 'C':
		case 'c':
			if (g_again == true)
			{
				g_bill = false;
				g_receipt = false;
				g_proceed = false;
				InvalidateRect(ghwnd, NULL, TRUE);
				//MessageBox(NULL, TEXT("C"), TEXT(""), MB_OK);
			}
			break;
		}
		break;
	case WM_PAINT:
		HDC hdc;
		RECT rect;
		PAINTSTRUCT ps;
		HFONT hFont;
		if (g_proceed == false)
		{
			hdc = BeginPaint(hwnd, &ps);
			GetWindowRect(hwnd, &rect);
			hdcWindow = GetWindowDC(hwnd);
			HBITMAP hBitmap;
			hBitmap = (HBITMAP)LoadImage(NULL, TEXT("Arc1.bmp"), IMAGE_BITMAP, 0, 0,LR_LOADFROMFILE);

			if (hBitmap == NULL) {
				MessageBox(NULL, TEXT("LoadImage Failed"), TEXT("Error"), MB_OK);
				return false;
			}
			HDC hLocalDC;
			hLocalDC = ::CreateCompatibleDC(hdc);
			if (hLocalDC == NULL) {
				MessageBox(NULL, TEXT("CreateCompatibleDC Failed"), TEXT("Error"), MB_OK);
				return false;
			}

			BITMAP qBitmap;
			int iReturn = GetObject(reinterpret_cast<HGDIOBJ>(hBitmap), sizeof(BITMAP),reinterpret_cast<LPVOID>(&qBitmap));
			if (!iReturn) {
				MessageBox(NULL, TEXT("GetObject Failed"), TEXT("Error"), MB_OK);
			
			}

			HBITMAP hOldBmp = (HBITMAP)::SelectObject(hLocalDC, hBitmap);
			if (hOldBmp == NULL) {
				MessageBox(NULL, TEXT("SelectObject Failed"), TEXT("Error"), MB_OK);
			}
			
			StretchBlt(hdc,0, 0, cxClient, cyClient, hLocalDC, 0, 0, 1290, 647, SRCCOPY);
			ReleaseDC(hwnd, hdcWindow);         
			
			::SelectObject(hLocalDC, hOldBmp);
			::DeleteDC(hLocalDC);
			::DeleteObject(hBitmap);
			
			GetClientRect(hwnd, &rect);
			hFont = CreateFont(30, 0, 0, 0, FW_DONTCARE, FALSE, TRUE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
				CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Impact"));
			SelectObject(hdc, hFont);
			SetBkMode(hdc, TRANSPARENT);
			SetTextColor(hdc, RGB(255, 255, 0));

			DrawText(hdc, TEXT("    Press  Spacebar  to  Continue    "), -1, &rect, DT_SINGLELINE | DT_BOTTOM | DT_CENTER);
			DeleteObject(hFont);
			hFont = NULL;

			hFont = CreateFont(60, 0, 0, 0, FW_DONTCARE, FALSE, TRUE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
				CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Impact"));
			SelectObject(hdc, hFont);
			SetBkMode(hdc, TRANSPARENT);
			SetTextColor(hdc, RGB(255, 255, 0));
			DrawText(hdc, TEXT("My  Computer  Shoppee"), -1, &rect, DT_SINGLELINE | DT_CENTER);
			DeleteObject(hFont);
			hFont = NULL;


			DeleteObject(hFont);
			hFont = NULL;

			EndPaint(hwnd, &ps);
		}
		else
		{
			if (g_bill == false)
			{

				hdc = BeginPaint(hwnd, &ps);
				GetClientRect(hwnd, &rect);
				HBRUSH hBrush;
				hBrush = CreateSolidBrush(RGB(0, 0, 0));
				SelectObject(hdc, hBrush);
				FillRect(hdc, &rect, hBrush);
				EndPaint(hwnd, &ps);
			}
			else if (g_bill == true)
			{

				hdc = BeginPaint(hwnd, &ps);
				//GetClientRect(hwnd, &rect);
				SetBkColor(hdc, RGB(0, 0, 0));
				SetTextColor(hdc, RGB(0, 255, 0));
				SetRect(&rect, 0, 60, 1700, 1500);
				DrawText(hdc, TEXT("==============================================================================================================================================================================="), -1, &rect, DT_SINGLELINE);
				SetTextColor(hdc, RGB(0, 255, 0));
				SetRect(&rect, 0, 110, 1700, 1500);

				DrawText(hdc, TEXT("==============================================================================================================================================================================="), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 0, 550, 1700, 1500);

				DrawText(hdc, TEXT("==============================================================================================================================================================================="), -1, &rect, DT_SINGLELINE);
				hFont = CreateFont(40, 0, 0, 0, FW_DONTCARE, FALSE, TRUE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
					CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Impact"));
				SelectObject(hdc, hFont);
				SetTextColor(hdc, RGB(0, 150, 255));
				SetRect(&rect, 500, 20, 800, 200);
				DrawText(hdc, TEXT("My Computer Shopee "), -1, &rect, DT_SINGLELINE | DT_CENTER);
				DeleteFont(hFont);
				hFont = NULL;
				hFont = CreateFont(25, 0, 0, 0, FW_DONTCARE, FALSE, TRUE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
					CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Impact"));
				SelectObject(hdc, hFont);
				SetTextColor(hdc, RGB(255, 0, 0));
				SetRect(&rect, 50, 80, 250, 150);
				DrawText(hdc, TEXT("Device"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 300, 80, 475, 150);
				DrawText(hdc, TEXT("Company"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 505, 80, 750, 150);
				DrawText(hdc, TEXT("Subtype"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 725, 80, 900, 150);
				DrawText(hdc, TEXT("Generation"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 945, 80, 1050, 150);
				DrawText(hdc, TEXT("Size/Feature"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 1120, 80, 1350, 150);
				DrawText(hdc, TEXT("Price"), -1, &rect, DT_SINGLELINE);
				DeleteFont(hFont);
				hFont = NULL;
				hFont = CreateFont(23, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
					CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Arial"));
				SelectObject(hdc, hFont);
				SetTextColor(hdc, RGB(0, 150, 255));
				SetRect(&rect, 50, 130, 250, 170);
				//cpu
				DrawText(hdc, TEXT("CPU"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 300, 130, 475, 170);
				DrawText(hdc, inn.cpu_company1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 505, 130, 750, 170);
				DrawText(hdc, inn.cpu_generation1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 725, 130, 900, 170);
				DrawText(hdc, inn.cpu_architecture1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 945, 130, 1050, 170);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 1120, 130, 1350, 170);

				wsprintf(str, TEXT("%c %d.00"), 0x000020B9, inn.cpu_price1);
				DrawText(hdc, str, -1, &rect, DT_SINGLELINE);

				//ram
				SetRect(&rect, 50, 165, 250, 270);
				DrawText(hdc, TEXT("RAM"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 300, 165, 475, 270);
				DrawText(hdc, inn.ram_company1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 505, 165, 750, 270);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 725, 165, 900, 270);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 945, 165, 1050, 270);
				DrawText(hdc, inn.ram_size1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 1120, 165, 1350, 270);

				wsprintf(str, TEXT("%c %d.00"), 0x000020B9, inn.ram_price1);
				DrawText(hdc, str, -1, &rect, DT_SINGLELINE);

				//motherboard
				SetRect(&rect, 50, 200, 350, 350);
				DrawText(hdc, TEXT("MotherBoard"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 300, 200, 475, 350);
				DrawText(hdc, inn.mother_company1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 505, 200, 750, 350);
				DrawText(hdc, inn.mother_type1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 725, 200, 900, 350);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 945, 200, 1050, 350);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 1120, 200, 1350, 350);

				wsprintf(str, TEXT("%c %d.00"), 0x000020B9, inn.mother_price1);
				DrawText(hdc, str, -1, &rect, DT_SINGLELINE);

				//graphics card
				SetRect(&rect, 50, 235, 450, 420);
				DrawText(hdc, TEXT("Graphics Card"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 300, 235, 475, 420);
				DrawText(hdc, inn.graphics_company1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 505, 235, 750, 420);
				DrawText(hdc, inn.graphics_type1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 725, 235, 900, 420);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 945, 235, 1050, 420);
				DrawText(hdc, inn.graphics_size1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 1120, 235, 1350, 420);

				wsprintf(str, TEXT("%c %d.00"), 0x000020B9, inn.graphics_price1);
				DrawText(hdc, str, -1, &rect, DT_SINGLELINE);

				//hard disk
				SetRect(&rect, 50, 270, 520, 470);
				DrawText(hdc, TEXT("Hard Disk"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 300, 270, 475, 470);
				DrawText(hdc, inn.harddisk_company1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 505, 270, 750, 470);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 725, 270, 900, 470);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 945, 270, 1050, 470);
				DrawText(hdc, inn.harddisk_size1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 1120, 270, 1350, 470);

				wsprintf(str, TEXT("%c %d.00"), 0x000020B9, inn.harddisk_price1);
				DrawText(hdc, str, -1, &rect, DT_SINGLELINE);

				//cd Drive
				SetRect(&rect, 50, 305, 580, 500);
				DrawText(hdc, TEXT("CD / DVD Drive"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 300, 305, 475, 500);
				DrawText(hdc, inn.cd_company1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 505, 305, 750, 500);
				DrawText(hdc, inn.cd_type1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 725, 305, 900, 500);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 945, 305, 1050, 500);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 1120, 305, 1350, 500);

				wsprintf(str, TEXT("%c %d.00"), 0x000020B9, inn.cd_price1);
				DrawText(hdc, str, -1, &rect, DT_SINGLELINE);

				//SMPS
				SetRect(&rect, 50, 340, 620, 540);
				DrawText(hdc, TEXT("SMPS"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 300, 340, 475, 540);
				DrawText(hdc, inn.smps_company1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 505, 340, 750, 540);
				DrawText(hdc, inn.smps_powerout1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 725, 340, 900, 540);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 945, 340, 1050, 540);
				DrawText(hdc, inn.smps_color1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 1120, 340, 1350, 540);

				wsprintf(str, TEXT("%c %d.00"), 0x000020B9, inn.smps_price1);
				DrawText(hdc, str, -1, &rect, DT_SINGLELINE);

				//Cabinet
				SetRect(&rect, 50, 375, 680, 580);
				DrawText(hdc, TEXT("Cabinet"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 300, 375, 475, 580);
				DrawText(hdc, inn.cabinet_company1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 505, 375, 750, 580);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 725, 375, 900, 580);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 945, 375, 1050, 580);
				DrawText(hdc, inn.cabinet_type1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 1120, 375, 1350, 580);

				wsprintf(str, TEXT("%c %d.00"), 0x000020B9, inn.cabinet_price1);
				DrawText(hdc, str, -1, &rect, DT_SINGLELINE);

				//keyboard
				SetRect(&rect, 50, 410, 720, 620);
				DrawText(hdc, TEXT("Keyboard"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 300, 410, 475, 620);
				DrawText(hdc, inn.key_company1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 505, 410, 750, 620);
				DrawText(hdc, inn.key_type1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 725, 410, 900, 620);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 945, 410, 1050, 620);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 1120, 410, 1350, 620);

				wsprintf(str, TEXT("%c %d.00"), 0x000020B9, inn.key_price1);
				DrawText(hdc, str, -1, &rect, DT_SINGLELINE);

				//mouse
				SetRect(&rect, 50, 445, 760, 650);
				DrawText(hdc, TEXT("Mouse"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 300, 445, 475, 650);
				DrawText(hdc, inn.mouse_company1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 505, 445, 750, 650);
				DrawText(hdc, inn.mouse_type1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 725, 445, 900, 650);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 945, 445, 1050, 650);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 1120, 445, 1350, 650);

				wsprintf(str, TEXT("%c %d.00"), 0x000020B9, inn.mouse_price1);
				DrawText(hdc, str, -1, &rect, DT_SINGLELINE);

				//monitor
				SetRect(&rect, 50, 480, 800, 660);
				DrawText(hdc, TEXT("Monitor"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 300, 480, 475, 660);
				DrawText(hdc, inn.monitor_company1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 505, 480, 750, 660);
				DrawText(hdc, inn.monitor_type1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 725, 480, 900, 660);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 945, 480, 1050, 660);
				DrawText(hdc, inn.monitor_size1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 1120, 480, 1350, 660);

				wsprintf(str, TEXT("%c %d.00"), 0x000020B9, inn.monitor_price1);
				DrawText(hdc, str, -1, &rect, DT_SINGLELINE);

				//pendrive
				SetRect(&rect, 50, 515, 800, 660);
				DrawText(hdc, TEXT("Pen Drive"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 300, 515, 475, 660);
				DrawText(hdc, inn.pen_company1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 505, 515, 750, 660);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 725, 515, 900, 660);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 945, 515, 1050, 660);
				DrawText(hdc, inn.pen_size1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 1120, 515, 1350, 660);

				wsprintf(str, TEXT("%c %d.00"), 0x000020B9, inn.pen_price1);
				DrawText(hdc, str, -1, &rect, DT_SINGLELINE);

				//amt
				SetRect(&rect, 50, 570, 900, 700);
				DrawText(hdc, TEXT("Amount To Be Paid"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 1120, 570, 1350, 700);

				sum = inn.cpu_price1 + inn.ram_price1 + inn.mother_price1 + inn.graphics_price1 + inn.harddisk_price1 + inn.key_price1 + inn.mouse_price1 + inn.cd_price1 + inn.smps_price1 + inn.cabinet_price1 + inn.monitor_price1 + inn.pen_price1;

				wsprintf(str, TEXT("%c %d.00"), 0x000020B9, sum);
				DrawText(hdc, str, -1, &rect, DT_SINGLELINE);
				if (g_receipt == false)
				{
					SetTextColor(hdc, RGB(255, 0, 0));
					SetRect(&rect, 300, 610, 1200, 720);
					g_again = true;
					DrawText(hdc, TEXT("Press R to get the receipt or C to continue Shoping once again or Esc to Exit !!"), -1, &rect, DT_SINGLELINE);
				}
				else
				{
					SetTextColor(hdc, RGB(255, 0, 0));
					SetRect(&rect, 300, 610, 1200, 720);
					g_again = true;
					DrawText(hdc, TEXT("Press C to continue Shoping once again or Press Esc to Exit ... Thank You for visiting ...!!"), -1, &rect, DT_SINGLELINE);

				}

				DeleteFont(hFont);
				hFont = NULL;
				EndPaint(hwnd, &ps);
			}
		}
		break;
	case WM_DESTROY:
		ShowWindow(hwnd, SW_HIDE);
		h1 = (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE);
		DialogBox(h1, MAKEINTRESOURCE(IDD_QUITWIN), hwnd, &MyDlgProc_can);
		ShowWindow(hwnd, SW_SHOW);
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}
/* main entry point. */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int) {
	//	void initialize_data();
	initialize_data();
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR AppName[] = TEXT("My Computer Shopee Windows");
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpszClassName = AppName;
	wndclass.lpszMenuName = NULL;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);

	RegisterClassEx(&wndclass);
	hwnd = CreateWindow(AppName, TEXT("My Computer Shopee"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	if (hwnd == NULL)
	{
		MessageBox(NULL, TEXT("Window not created"), TEXT("Error..."), 0);
		exit(0);
	}
	h1 = hInstance;
	ghwnd = hwnd;
	//ghwnd = hwnd;
	ShowWindow(hwnd, SW_MAXIMIZE);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return((int)msg.wParam);
}



bool LoadMyBitmap(LPCWSTR szFileName, HDC hdc, LONG x, LONG y, LONG width, LONG Bottom)
{
	HBITMAP hBitmap;
	hBitmap = (HBITMAP)LoadImage(NULL, szFileName, IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE);

	if (hBitmap == NULL) {
		MessageBox(NULL, TEXT("LoadImage Failed"), TEXT("Error"), MB_OK);
		return false;
	}
	HDC hLocalDC;
	hLocalDC = ::CreateCompatibleDC(hdc);
	if (hLocalDC == NULL) {
		MessageBox(NULL, TEXT("CreateCompatibleDC Failed"), TEXT("Error"), MB_OK);
		return false;
	}

	BITMAP qBitmap;
	int iReturn = GetObject(reinterpret_cast<HGDIOBJ>(hBitmap), sizeof(BITMAP),
		reinterpret_cast<LPVOID>(&qBitmap));
	if (!iReturn) {
		MessageBox(NULL, TEXT("GetObject Failed"), TEXT("Error"), MB_OK);
		return false;
	}

	HBITMAP hOldBmp = (HBITMAP)::SelectObject(hLocalDC, hBitmap);
	if (hOldBmp == NULL) {
		MessageBox(NULL, TEXT("SelectObject Failed"), TEXT("Error"), MB_OK);
		return false;
	}

	BOOL qRetBlit = StretchBlt(hdc, x, y, width, Bottom, hLocalDC, 0, 0, width, Bottom, SRCCOPY);
	if (!qRetBlit) {
		MessageBox(NULL, TEXT("Blit Failed"), TEXT("Error"), MB_OK);
		return false;
	}

	::SelectObject(hLocalDC, hOldBmp);
	::DeleteDC(hLocalDC);
	::DeleteObject(hBitmap);
	return true;
}

void initialize_data() {
	inn.cpu_company = -1;
	inn.cpu_company1[0] = '\0';
	inn.cpu_generation = -1;
	inn.cpu_generation1[0] = '\0';
	inn.cpu_architecture = -1; inn.cpu_architecture1[0] = '\0';
	inn.cpu_price = -1;	inn.cpu_price1 = 0;
	inn.ram_company = -1; inn.ram_company1[0] = '\0';
	inn.ram_size = -1; inn.ram_size1[0] = '\0';
	inn.ram_price = -1; inn.ram_price1 = 0;
	inn.mother_company = -1;  inn.mother_company1[0] = '\0';
	inn.mother_price = -1;  inn.mother_price1 = 0;
	inn.graphics_company = -1;  inn.graphics_company1[0] = '\0';
	inn.graphics_size = -1; inn.graphics_size1[0] = '\0';
	inn.graphics_type = -1; inn.graphics_type1[0] = '\0';
	inn.graphics_price = -1; inn.graphics_price1 = 0;
	inn.key_company = -1; inn.key_company1[0] = '\0';
	inn.key_price = -1;		inn.key_price1 = 0;
	inn.mouse_company = -1; inn.mouse_company1[0] = '\0';
	inn.mouse_price = -1;  inn.mouse_price1 = 0;
	inn.cd_company = -1;   	inn.cd_company1[0] = '\0';
	inn.cd_price = -1;    inn.cd_price = 0;
	inn.smps_company = -1;   	inn.smps_company1[0] = '\0';
	inn.smps_price = -1;	 inn.smps_price1 = 0;
	inn.monitor_company = -1;    inn.monitor_company1[0] = '\0';
	inn.monitor_price = -1; inn.monitor_price1 = 0;
	inn.cabinet_company = -1;	inn.cabinet_company1[0] = '\0';
	inn.cabinet_price = -1; inn.cabinet_price1 = 0;
	inn.harddisk_company = -1;  inn.harddisk_company1[0] = '\0';
	inn.harddisk_size = -1; inn.harddisk_size1[0] = '\0';
	inn.harddisk_price = -1; 	inn.harddisk_price1 = 0;

	inn.pen_company = -1;  inn.pen_company1[0] = '\0';
	inn.pen_size = -1; inn.pen_size1[0] = '\0';
	inn.pen_price = -1; 	inn.pen_price1 = 0;
	inn.cabinet_type = -1;   inn.cabinet_type1[0] = '\0';
}

