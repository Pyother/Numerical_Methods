#include <iostream>
using namespace std;

struct Point
{
	double x;
	double y;
};

double* factor(int n, double point, Point* points)
{
	double* value=new double[n]; //Deklaracja tablicy dynamicznej.
	for (int i = 0; i < n; i++) //P�tla for wykonuje si� n razy.
	{
		value[i] = 1; //Przypisujemy i-temu elementowi warto�� 1.
		for (int j = 0; j < n; j++) //P�tla for wykonuje si� n razy.
		{
			if (j != i) 
			{
				value[i] = value[i]*(point - points[j].x) / (points[i].x - points[j].x);
				//Zgodnie ze wzorem, wyznaczamy iloczyn, przypisujac tablicy kolejne mno�one przez siebie u�amki.
				cout << value[i]<<" ";
			}
			else if (j == i)
			{
				//Szczeg�lny przypadek, gdy nie mno�ymy przez siebie u�amk�w. 
			}
		}
	}
	return (value); //funkcja zwraca tablic� obliczonych warto�ci wielomian�w dla wszystkich punkt�w. 
}

double interpolation(int n, double point)
{
	Point* points = new Point[n]; //Deklaracja tablicy obiekt�w przechowuj�cej argumenty. 
	for (int i = 0; i < n; i++)
	{
		cout << "Point " << i + 1 << ":"<<endl<<"x:";
		cin >> points[i].x;
		cout << "y:";
		cin >> points[i].y;
	}//Przypisywanie warto�ci argumentom. 

	double* factors = new double [n];  //Deklaracja tablicy dynamicznej.
	factors=factor(n,  point, points);  //Przypisanie jej wyniku funkcji factor dla podanych punkt�w.
	double value_in_point=0;
	for (int i = 0; i < n; i++)
	{
		value_in_point = value_in_point + points[i].y * factors[i];
		cout << value_in_point << " ";
	}//Dodawanie i wy�wietlanie ka�dej warto�ci wielomianu pomno�onej przez warto�ci funkcji w punktach. 

	return value_in_point;//Zwrot wyniku do funkcji main.
}

int main()
{
	int n;
	double point;
	cout << "Number of points: ";
	cin >> n;
	cout << "Point, we want to calculate value: ";
	cin >> point;
	cout <<"Value in point:"<< interpolation(n, point);


}