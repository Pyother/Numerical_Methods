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
	for (int i = 0; i < n; i++) //Pêtla for wykonuje siê n razy.
	{
		value[i] = 1; //Przypisujemy i-temu elementowi wartoœæ 1.
		for (int j = 0; j < n; j++) //Pêtla for wykonuje siê n razy.
		{
			if (j != i) 
			{
				value[i] = value[i]*(point - points[j].x) / (points[i].x - points[j].x);
				//Zgodnie ze wzorem, wyznaczamy iloczyn, przypisujac tablicy kolejne mno¿one przez siebie u³amki.
				cout << value[i]<<" ";
			}
			else if (j == i)
			{
				//Szczególny przypadek, gdy nie mno¿ymy przez siebie u³amków. 
			}
		}
	}
	return (value); //funkcja zwraca tablicê obliczonych wartoœci wielomianów dla wszystkich punktów. 
}

double interpolation(int n, double point)
{
	Point* points = new Point[n]; //Deklaracja tablicy obiektów przechowuj¹cej argumenty. 
	for (int i = 0; i < n; i++)
	{
		cout << "Point " << i + 1 << ":"<<endl<<"x:";
		cin >> points[i].x;
		cout << "y:";
		cin >> points[i].y;
	}//Przypisywanie wartoœci argumentom. 

	double* factors = new double [n];  //Deklaracja tablicy dynamicznej.
	factors=factor(n,  point, points);  //Przypisanie jej wyniku funkcji factor dla podanych punktów.
	double value_in_point=0;
	for (int i = 0; i < n; i++)
	{
		value_in_point = value_in_point + points[i].y * factors[i];
		cout << value_in_point << " ";
	}//Dodawanie i wyœwietlanie ka¿dej wartoœci wielomianu pomno¿onej przez wartoœci funkcji w punktach. 

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