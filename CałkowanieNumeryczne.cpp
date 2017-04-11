// Ca³kowanieNumeryczne.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
using namespace std;

double funkcja(double x)
{
	return sin(x)/(pow(x,2)+x);
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
//----------------------Kwadratura Gausa-Legendre'a-----------------------------------------//
float GausLengd(int n,float tab[][2],int a,int b)
{
	float wynik=0;
	for (int i = 0; i < n; i++)
	{
		wynik += tab[i][0] * funkcja((((float)b - a) / 2)*tab[i][1] + (((float)b + a) / 2));
	}
	return wynik*(((float)b- a) / 2);
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
	//----------------------Kwadratura Gausa-Legendre'a-----------------------------------------//
	cout << "Kwadratuda Gaussa-Legendre'a\n";
	cout << "podaj n\n";
	cin >> n;
	switch (n)
	{
	case 2:
	{
			   float GaussLegeTab[2][2] = { { 1.0f, -0.5773502691896257f }, { 1.0f, 0.5773502691896257f } };
			   cout << GausLengd(n, GaussLegeTab, a, b) << "\n";
	}
		break;
	case 4:
	{
			  float GaussLegeTab[4][2] = { { 0.6521451548625461f, -0.3399810435848563f }, { 0.6521451548625461f, 0.3399810435848563f }, { 0.3478548451374538f, -0.8611363115940526f }, { 0.3478548451374538f, 0.8611363115940526f } };
			  cout << GausLengd(n, GaussLegeTab, a, b) << "\n";
	}
		break;
	case 6:
	{
			  float GaussLegeTab[6][2] = { { 0.3607615730481386f, 0.6612093864662645f }, { 0.3607615730481386f, -0.6612093864662645f }, { 0.4679139345726910f, -0.2386191860831969f }, { 0.4679139345726910f, 0.2386191860831969f }, { 0.1713244923791704f, -0.9324695142031521f }, { 0.1713244923791704f, 0.9324695142031521f } };
			  cout << GausLengd(n, GaussLegeTab, a, b) << "\n";
	}
		break;
	case 8:
	{
			  float GaussLegeTab[8][2] = { { 0.3626837833783620f, -0.1834346424956498f }, { 0.3626837833783620f, 0.1834346424956498f }, { 0.3137066458778873f, -0.5255324099163290f }, { 0.3137066458778873f, 0.5255324099163290f }, { .2223810344533745f, -0.7966664774136267f }, { .2223810344533745f, 0.7966664774136267f }, { 0.1012285362903763f, -0.9602898564975363f }, { 0.1012285362903763f, 0.9602898564975363f } };
			  cout << GausLengd(n, GaussLegeTab, a, b) << "\n";
	}
		break;
	case 10:
	{
			   float GaussLegeTab[10][2] = { { 0.2955242247147529f, -0.1488743389816312f }, { 0.2955242247147529f, 0.1488743389816312f }, { 0.2692667193099963f, -0.4333953941292472f }, { 0.2692667193099963f, 0.4333953941292472f }, { 0.2190863625159820f, -0.6794095682990244f }, { 0.2190863625159820f, 0.6794095682990244f }, { 0.1494513491505806f, -0.8650633666889845f }, { 0.1494513491505806f, 0.8650633666889845f }, { 0.0666713443086881f, -0.9739065285171717f }, { 0.0666713443086881f, 0.9739065285171717f } };
			   cout << GausLengd(n, GaussLegeTab, a, b) << "\n";
	}
		break;
	case 16:
	{
			   float GaussLegeTab[16][2] = { { 0.1894506104550685f,- 0.0950125098376374f }, { 0.1894506104550685f, 0.0950125098376374f }, { 0.1826034150449236f, -0.2816035507792589f }, { 0.1826034150449236f, 0.2816035507792589f }, { 0.1691565193950025f, -0.4580167776572274f }, { 0.1691565193950025f, 0.4580167776572274f }, { 0.1495959888165767f, -0.6178762444026438f }, { 0.1495959888165767f, 0.6178762444026438f }, { 0.1246289712555339f, -0.7554044083550030f }, { 0.1246289712555339f, 0.7554044083550030f }, { 0.0951585116824928f, -0.8656312023878318f }, { 0.0951585116824928f, 0.8656312023878318f }, { 0.0622535239386479f, -0.9445750230732326f }, { 0.0622535239386479f, 0.9445750230732326f }, { 0.0271524594117541f, -0.9894009349916499f }, { 0.0271524594117541f, 0.9894009349916499f } };
			   cout << GausLengd(n, GaussLegeTab, a, b) << "\n";
	}
		break;
	}
	getch();
	return 0;
}

