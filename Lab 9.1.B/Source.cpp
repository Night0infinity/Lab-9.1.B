#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> // ������������ ����������� ��������
using namespace std;

enum Fahoviy { PROGRAMUVANNA, CHSLMETOD, PEDAGOGIKA };
string predmetStr[] = { "�������������  ", "������� ������", "���������     " };
struct Student
{
	string prizv;
	string kurs;
	union
	{
		unsigned fizika;
	};
	union
	{
		unsigned matematika;
	};
	Fahoviy specialnist;
	union
	{
		unsigned programuvanna;
		unsigned chslmetod;
		unsigned pedagogika;
	};
};
void Create(Student* p, const int N);
void Print(Student* p, const int N);
double Amount(Student* p, const int N);
void MiddleAverage(Student* p, const int N);
int main()
{ // ������������ ����������� ��������:
	SetConsoleCP(1251); // ������������ ������� win-cp1251 � ���� �����
	SetConsoleOutputCP(1251); // ������������ ������� win-cp1251 � ���� ������

	int N;
	cout << "������ N: "; cin >> N;

	Student* p = new Student[N];
	Create(p, N);
	Print(p, N);
	MiddleAverage(p, N);
	int f = Amount(p, N);
	cout << setw(3) << right
		<< " " << f << endl;
	return 0;
}
void Create(Student* p, const int N)
{
	int Predmet;
	for (int i = 0; i < N; i++)
	{
		int n = 0;
		cout << "������� � " << i + 1 << ":" << endl;
		cin.get(); // ������� ����� ��������� � �� ����������� �������
		cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����

		cout << " �������: "; getline(cin, p[i].prizv);
		cout << " ����: "; getline(cin, p[i].kurs);
		//cout << " ����: "; cin >> p[i].kurs;
		//cout << " ������������: "; getline(cin, p[i].specialnist);
		//cout << " ������������: "; cin >> p[i].specialnist;
		cout << " ��� � ������: "; cin >> p[i].fizika;
		cout << " ��� � ����������: "; cin >> p[i].matematika;
		cout << " ������ (0 - �������������, 1 - ������� ������, 2 - ���������): ";
		cin >> Predmet;
		p[i].specialnist = (Fahoviy)Predmet;
		switch (p[i].specialnist)
		{
		case PROGRAMUVANNA:
			cout << " ��� � ������������� : "; cin >> p[i].programuvanna;
			break;
		case CHSLMETOD:
			cout << " ��� � ��������� ������ : "; cin >> p[i].chslmetod;
			break;
		case PEDAGOGIKA:
			cout << " ��� � ��������� : "; cin >> p[i].pedagogika;
			break;
		}
		cout << endl;
	}
}
void MiddleAverage(Student* p, const int N)
{
	int nlocf = 0, nlocm = 0, nlocp = 0, nlocchm = 0, nlocpd = 0;
	int numf = 0, numm = 0, nump = 0, numchm = 0, numpd = 0;
	double resp, reschm, respd;
	for (int i = 0; i < N; i++)
	{
			nlocf += p[i].fizika;
			numf++;
	}
	double resf = nlocf / numf;
	cout << "������� ��� � ������ : " << resf << endl;

	for (int i = 0; i < N; i++)
	{
		if (true)
		{
			nlocm += p[i].matematika;
			numm++;
		}
	}
	double resm = nlocm / numm;
	cout << "������� ��� � ���������� : " << resm << endl;

	for (int i = 0; i < N; i++)
	{
		if (p[i].specialnist == Fahoviy::PROGRAMUVANNA)
		{
			nlocp += p[i].programuvanna;
			nump++;
		}	
	}
	if (nlocp > 0)
	{
		resp = nlocp / nump;
		cout << "������� ��� � ������������� : " << resp << endl;
	}
	else
		cout << "������� ��� � ������������� ����������" << endl;
	for (int i = 0; i < N; i++)
	{
		if (p[i].specialnist == Fahoviy::CHSLMETOD)
		{
			nlocchm += p[i].chslmetod;
			numchm++;
		}
	}
	if (nlocchm > 0)
	{
		reschm = nlocchm / numchm;
		cout << "������� ��� � ��������� ������ : " << reschm << endl;
	}
	else
	cout << "������� ��� � ��������� ������ ����������" << endl;
	for (int i = 0; i < N; i++)
	{
		if (p[i].specialnist == Fahoviy::PEDAGOGIKA)
		{
			nlocpd += p[i].pedagogika;
			numpd++;
		}
		if (nlocp == 0)
			break;
	}
	if (nlocpd > 0)
	{
		respd = nlocpd / numpd;
		cout << "������� ��� � ��������� : " << respd << endl;
	}
	else
	cout << "������� ��� � ��������� ����������" << endl;
}
double Amount(Student* p, const int N)
{
	cout << "ʳ������ ��������, �� �������� � ������ ������ �5� ��� �4�" << endl;

	int k = 0;
	int n = 0;
	int nloc = 0;
	for (int i = 0; i < N; i++)
	{
		if (true)
		{
			n++;
			if (p[i].fizika == 5 || p[i].fizika == 4)
			{
				k++;
				nloc += k;
			}
		}
	}
	return k;
}

void Print(Student* p, const int N)
{
	cout << "===================================================================================================================="
		<< endl;
	cout << "__________________________________________|                               ����                                     |"
		<< endl;
	cout << "|  �  |  �������  | ���� | ������������ |  Գ����  |  ����������  | ������������� | ������� ������ | ��������� |"
		<< endl;
	cout << "--------------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(3) << right << i + 1 << " ";
		cout << "| " << setw(3) << left << p[i].prizv << " "
			<< "| " << setw(3) << right << p[i].kurs << " "
			<< "| " << setw(11) << left << predmetStr[p[i].specialnist]
			<< "| " << setw(7) << right << p[i].fizika << " "
			<< "| " << setw(10) << right << p[i].matematika << " ";
		switch (p[i].specialnist)
		{
			//PROGRAMUVANNA, CHSLMETOD, PEDAGOGIKA
			//programuvanna;chslmetod;pedagogika
		case PROGRAMUVANNA:
			cout << "| " << setw(9) << setprecision(2) << fixed << right
				<< p[i].programuvanna << " |" << setw(11) << right << "|" << setw(11) << right << "|" << endl;
			break;
		case CHSLMETOD:
			cout << "| " << setw(11) << right << "|" << " " << setw(8) << right
				<< p[i].chslmetod << " |" << setw(11) << right << "|" << endl;
			break;
		case PEDAGOGIKA:
			cout << "| " << setw(11) << right << "|" << " " << setw(11) << right
			<< "| " << " " << setw(7) << right << p[i].pedagogika << " |" << endl;
			break;
		}
	}
	cout << "===================================================================================================================="
		<< endl;
	cout << endl;
}