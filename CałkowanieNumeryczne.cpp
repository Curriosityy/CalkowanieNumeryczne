// Ca³kowanieNumeryczne.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
using namespace std;

double funkcja(double x)
{
	return (pow(x, 2)*sqrt(1 + x)) / (1 + pow(x, 2));
}
void tablicaXi(int a, int b,double* xTab,int n)
{
	for (int  i = 0; i <=n; i++)
	{
		xTab[i] = a + ((double)i / n)*(b - a);
	}
}
void tablicaTi(double* xTab, double* tTab, int n)
{
	for (int i = 0; i < n; i++)
	{
		tTab[i] = (xTab[i] + xTab[i + 1]) / 2;
	}
}
double metodaTrapezow(double* xTab,double h,int n)
{
	double wynik = 0;
	for (int i = 0; i <= n; i++)
	{
		if (i == 0 && i==n)
		{
			wynik += (funkcja(xTab[i]) / 2);
		}
		else 
		{
			wynik += funkcja(xTab[i]);
		}
	}
	wynik *= h;
	return wynik;
}
double metodaSimpsona(double* xTab, double* tTab, double h, int n)
{
	double wynik = 0;
	for (int i = 0; i <= n; i++)
	{
		if (i == 0)
		{
			wynik += funkcja(xTab[i]);
			wynik += funkcja(tTab[i]) * 4;
		}
		else if (i==n)
		{
			wynik += funkcja(xTab[i]);
		}
		else
		{
			wynik += funkcja( tTab[i]) * 4;
			wynik += funkcja(xTab[i]) * 2;
		}

	}
	wynik *= h / 6;
	return wynik;
}
int main()
{
	int a, b, n;
	double h;
	cout << "podaj a i b\n";
	cin >> a >> b;
	cout << "podaj n\n";
	cin >> n;

	h = ((double)b - a) / n;
	double* xTab = new double[n+1];
	double* tTab = new double[n];
	tablicaXi(a, b, xTab, n);
	tablicaTi(xTab, tTab, n);
	cout << metodaTrapezow(xTab, h, n) << "\n";
	cout << metodaSimpsona(xTab, tTab, h, n);
	getch();
	return 0;
}

