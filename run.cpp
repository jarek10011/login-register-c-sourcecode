#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <math.h>
#include <fstream>
#include <string>
#include <fstream>

using namespace std;

void PrzyznajDostep()
{
	DWORD pid;
	HWND window = FindWindow(NULL, "Google Chrome");
	GetWindowThreadProcessId(window, &pid);
	HANDLE pHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
}

void OdczytKursor()
{
	// przyznaj dostep do zmiennych z kursora
	POINT pos; // zmienna POINT okreœla zmienn¹ u¿ywan¹ w komendzie 
	GetCursorPos(&pos);
	pos.x; // zmienna x X = PRAWO/LEWO
	pos.y; // zmienna y Y = GÓR/DÓ£
}


int main()
{
	int wybierz;
	string reghaslo,reguser;
	string username2, haslo2;
	string haslo, user;
	CreateDirectoryA("local", NULL);
	fstream hasla;
	hasla.open("local\\hasla.txt", ios::out | ios::in | ios::app);
	fstream usernames;
	usernames.open("local\\usernames.txt", ios::out | ios::in | ios::app);

	SetConsoleTitle("Login Panel External Test");
	HWND consolewindow = GetConsoleWindow();
	OdczytKursor();

run:
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
	cout << "made by Judasz"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	cout << "PANEL UZYTKOWNIKA" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout << "DATA:" << __DATE__ << endl;
	cout << " " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	cout << "1.Rejestracja" << endl;
	cout << "2.Logowanie" << endl;
	cout << "3.Test   /// dziala tylko z zarejestrowanym uzytkownikiem" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << "wybierz:";
	cin >> wybierz;
	switch (wybierz)
	{
	case 1:
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		cout << "PANEL UZYTYKOWNIKA / REJESTRACJA" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
		cout << "Podaj username:";
		cin >> reguser;
		cout << "Podaj haslo:";
		cin >> reghaslo;

		usernames << reguser << endl;
		hasla << reghaslo << endl;
		MessageBoxA(NULL, "Konto utworzone!", "Test", MB_OK | MB_ICONINFORMATION);
		system("cls");
		MessageBoxA(NULL, "Uruchom ponownie aplikacje", "Test", MB_OK | MB_ICONINFORMATION);
		goto run;
		break;
	case 2:
		if (usernames.is_open() && hasla.is_open())
		{
			while (getline(usernames, username2) && getline(hasla, haslo2))		
			{
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			cout << "Podaj username:";
			cin >> user;
			cout << "Podaj haslo:";
			cin >> haslo;
		
				if (haslo == haslo2 && user == username2)
				{
					MessageBoxA(NULL, "Witaj", "Test", MB_OK | MB_ICONINFORMATION);
					exit(1);
				}
				else
				{
					MessageBoxA(NULL, "ERROR", "Test", MB_OK | MB_ICONINFORMATION);
					exit(1);
				}
			}
		}
		else
		{
			MessageBoxA(NULL, "Error!", "test", MB_OK);
		}

	case 3:
		if (usernames.is_open()&& hasla.is_open())
		{
			while (getline(usernames, username2)&&getline(hasla,haslo2))
			{
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9|FOREGROUND_INTENSITY);
				cout << "username:" << username2 << endl;
				cout << "haslo:" << haslo2 << endl;
			}
			system("pause");
		}
		else
		{
			MessageBoxA(NULL, "CRASH SPRAWDZ KOD", "Test", MB_OK | MB_ICONINFORMATION);
			exit(1);
		}
		break;
	default:
		system("cls");
		goto run;
		break;
	}
}