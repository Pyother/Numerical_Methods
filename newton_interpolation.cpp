#include <iostream>
#include <math.h>
using namespace std;

struct Point
{
	double x;
	double y;
};

double newton_interpolation(int n)
{
	Point* points = new Point[n]; 
	for (int i = 0; i < n; i++)
	{
		cout << "Point " << i + 1 << ":" << endl << "x:";
		cin >> points[i].x;
		cout << "y:";
		cin >> points[i].y;
	}

	int k = n;
	int j = 0;
	double* factors = new double[k - 1];
	double* diagonal = new double[n];
	diagonal[0] = points[0].y;
	int counter = 2;
	
	while (k > 1)
	{
		if (k == n)
		{
			for (int i = 0; i < k - 1; i++)
			{
				factors[i] = ( points[i + 1].y - points[i].y )/ (points[i + 1].x- points[i].x );
			}
			diagonal[1] = factors[0];
		}
		else if (k != n)
		{
			double* variable = new double[k];
			for (int i = 0; i < k; i++) variable[i] = factors[i];
			for (int i = 0; i < k - 1; i++)
			{
				factors[i] = (variable[i + 1] - variable[i]) / (points[i + counter].x - points[i].x);
			}
			diagonal[counter] = factors[0];
			delete[] variable;
			counter++;
		}
		cout << j + 1 << ". rank: ";
		for (int i = 0; i < k - 1; i++) cout << factors[i] << " ";
		cout << endl;
		k--;
		j++;
	}
	cout << endl << "Diagonals: ";
	for (int i = 0; i < n; i++) cout << diagonal[i] << " ";
	double argument, value=0, product=1;
	cout << endl << endl << "Enter argument:";
	cin >> argument;
	int c = n-1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i-1; j++)
		{
			product = product * (argument - points[j].x);
		}
		value = value + diagonal[i-1] * product;
		product = 1;
	}
	cout << endl << endl << "Polynomial value: " << value<<endl<<endl;
	
	return 0;
}

int main()
{
	int n;
	cout << "Number of points:";
	cin >> n;

	newton_interpolation(n);
}

