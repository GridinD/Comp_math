#include<bits/stdc++.h>
using namespace std;
#define EPSILON 0.001

double func(double x)
{
	return x*x*x + 4*x - 3;
}

void bisection(double a, double b)
{
	if (func(a) * func(b) >= 0)
	{
		cout << "wrong a and b\n";
		return;
	}

	double c = a;
	while ((b-a) >= EPSILON)
	{
		c = (a+b)/2;

		if (func(c) == 0.0)
			break;
		else if (func(c)*func(a) < 0)
			b = c;
		else
			a = c;
	}
	cout << "The value of root is : " << c << endl;
}

int main()
{
	double a = 0, b = 1;
	bisection(a, b);
	return 0;
}
