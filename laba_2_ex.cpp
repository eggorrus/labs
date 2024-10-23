#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main(int argc, char* argv[])
{
	bool interface = false;
	if (argc <= 1 || strcmp(argv[1], "false") != 0)
		interface = true;
	setlocale(LC_CTYPE, "rus");
	string prostie;
	int n, n1, i, sum, krat5 = 0, summa = 0, max=0, min, st2=0, perzn=0, vtorzn=0, sumpred=0;
	if (interface)
		cout << "Введите число N" << endl;
	cin >> n;
	while (n <= 0)
	{
		if(interface)
			cout << "Ваше число отрицательно или равно нулю, а нужно ввести положительное!" << endl;
		cin >> n;
	}
	for (i = 0; i < n; i++)
	{
		if (interface)
			cout << "Введите " << i+1<<" число"<< endl;
		cin >> n1;
		if (i == 0)
		{
			min = n1;
			max = n1;
		}
		else
		{
			if (n1 <= min)
				min = n1;
			if (n1 >= max)
				max = n1;
		}
		sum = 0;
		if (n1 != 1)
		{
			double koren = sqrt(n1);
			if (n1 % 2 != 0)
			{
				for (int chislo = 3; chislo <= koren; chislo+=2)
				{
					if (n1 % chislo == 0)
						sum = 1;
					if (sum != 0)
						break;
				}
				if (sum == 0)
				{
					if (prostie == "")
						prostie = to_string(n1);
					else
						prostie = prostie + "\n" + to_string(n1);
				}
			}
			else
			{
				if(n1==2)
				{
					if (prostie == "")
						prostie = to_string(n1);
					else
						prostie = prostie + "\n" + to_string(n1);
				}
			}
		}
		summa = summa + n1;
		if (n1 % 5 == 0)
			krat5 = krat5 + 1;
		if(floor(log2(n1))==log2(n1))
			st2 = st2 + 1;
		if ((perzn != 0) && (vtorzn != 0) && (n1 > (perzn + vtorzn)))
			sumpred = sumpred + 1;
		if ((i == 0) || (i % 2 == 0))
			perzn = n1;
		else
			vtorzn = n1;
	}
	double arifm = static_cast<double>(summa) / (double)n;
	if (interface)
		cout << "Список простых чисел последовательности:" << endl;
	if(prostie!="")
		cout << prostie << endl;
	if (interface)
		cout << "Среднее арифметическое введенных чисел:" << endl;
	cout << fixed<<setprecision(2)<< arifm << endl;
	if (interface)
		cout << "Разница между максимумом и минимумом:" << endl;
	cout << max - min << endl;
	if (interface)
		cout << "Количество чисел, кратных 5:" << endl;
	cout << krat5 << endl;
	if (interface)
		cout << "Количество чисел, являющихся степенью двойки:" << endl;
	cout << st2 << endl;
	if (interface)
		cout << "Количество чисел, превосходящих сумму двух предыдущих:" << endl;
	cout << sumpred << endl;
}