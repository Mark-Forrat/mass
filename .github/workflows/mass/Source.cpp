#include <iostream>
#include <random>
using namespace std;

int** make_mass(int n,int m)
{
	int** mass;
	int i, j;
	mass = new int* [n];
	for (i = 0; i < n; i++)
	{
		mass[i] = new int[m];
		for (j = 0; j < m; j++)
			mass[i][j] = rand()%10;
	}
	return mass;
}

void print(int **k, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << k[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

int** del(int** k, int n, int m, int z)
{
	
	bool flag = 1;
	int a = m-1;
	int** l = make_mass(n, a);
	for (int i = 0; i < n; i++)
	{
		int g = 0;
		for (int j = 0; j < m; j++)
		{

			if (j != z)
			{
				l[i][g] = k[i][j];
				g++;
			}
		}
	}
	return l;
}
void main ()
{
	setlocale(0, "rus");
	srand(time(0));
	int n;
	int m;
	int z;
	cout << "Введите кол-во строчек:";
	cin >> n;
	cout << "Введите кол-во столбцов:";
	cin >> m;
	cout << endl;
	int **mass = make_mass(n, m);
	print(mass,n,m);
	cout << "Какой столбец удaлить:"; 
	cin >> z;
	--z;
	cout << endl;
	mass = del(mass, n, m, z);
	int a = --m;
	print(mass, n, a);
	delete[]mass;
}