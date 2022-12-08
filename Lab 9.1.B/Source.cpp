#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> // забезпечення відображення кирилиці
using namespace std;

enum Fahoviy { PROGRAMUVANNA, CHSLMETOD, PEDAGOGIKA };
string predmetStr[] = { "Програмування  ", "Чисельні методи", "Педагогіка     " };
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
{ // забезпечення відображення кирилиці:
	SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

	int N;
	cout << "Введіть N: "; cin >> N;

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
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

		cout << " прізвище: "; getline(cin, p[i].prizv);
		cout << " курс: "; getline(cin, p[i].kurs);
		//cout << " курс: "; cin >> p[i].kurs;
		//cout << " спеціальність: "; getline(cin, p[i].specialnist);
		//cout << " спеціальність: "; cin >> p[i].specialnist;
		cout << " Бал з фізики: "; cin >> p[i].fizika;
		cout << " Бал з математики: "; cin >> p[i].matematika;
		cout << " посада (0 - програмування, 1 - чисельні методи, 2 - педагогіка): ";
		cin >> Predmet;
		p[i].specialnist = (Fahoviy)Predmet;
		switch (p[i].specialnist)
		{
		case PROGRAMUVANNA:
			cout << " Бал з програмування : "; cin >> p[i].programuvanna;
			break;
		case CHSLMETOD:
			cout << " Бал з чисельних методів : "; cin >> p[i].chslmetod;
			break;
		case PEDAGOGIKA:
			cout << " Бал з педагогіки : "; cin >> p[i].pedagogika;
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
	cout << "Середній бал з фізики : " << resf << endl;

	for (int i = 0; i < N; i++)
	{
		if (true)
		{
			nlocm += p[i].matematika;
			numm++;
		}
	}
	double resm = nlocm / numm;
	cout << "Середній бал з математики : " << resm << endl;

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
		cout << "Середній бал з програмування : " << resp << endl;
	}
	else
		cout << "Середній бал з програмування невказаний" << endl;
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
		cout << "Середній бал з чисельних методів : " << reschm << endl;
	}
	else
	cout << "Середній бал з чисельних методів невказаний" << endl;
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
		cout << "Середній бал з педагогіки : " << respd << endl;
	}
	else
	cout << "Середній бал з педагогіки невказаний" << endl;
}
double Amount(Student* p, const int N)
{
	cout << "Кількість студентів, які отримали з фізики оцінки “5” або “4”" << endl;

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
	cout << "__________________________________________|                               Бали                                     |"
		<< endl;
	cout << "|  №  |  Прізвище  | Курс | Спеціальність |  Фізика  |  Математика  | Програмування | Чисельні методи | Педагогіка |"
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