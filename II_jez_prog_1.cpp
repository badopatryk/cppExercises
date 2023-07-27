#include <iostream>
#include <fstream>
#include <stdio.h>
#include <ctime>
using namespace std;

struct Vector
{
	int size;
	double *val;
};
void Create(Vector *w, int n)
{
	w->size = n; 
	w->val = new double[n];
}
void Destroy(Vector *w)
{
	delete[] w->val;
	w->size = 0;
}
void Show(Vector *w)
{
	cout << "(";
	for (int i = 0; i < w->size; i++)
	{
		if (i != w->size - 1)
			cout << w->val[i] << ", ";
		else
			cout << w->val[i] << ")";
	}
	cout << endl;
}
void Write1(Vector *w, char *nameout)
{
	ofstream file(nameout);
	file << w->size << endl;
	for (int i = 0; i < w->size; i++)
		file << w->val[i] << " ";
	file << endl;
	file.close();
}
Vector *ReadIn1(char *namein)
{
	ifstream file(namein);
	int n;
	file >> n;
	Vector *w = new Vector;
	Create(w, n);
	for (int i = 0; i < n; i++)
		file >> w->val[i];
	file.close();
	return w;
}
void Write2(Vector *w, char *nameout)
{
	FILE *file = fopen(nameout, "w");
	fprintf(file, "%i\n", w->size);
	for (int i = 0; i < w->size; i++)
	{
		if (i < w->size - 1)
			fprintf(file, "%f", w->val[i]);
		else
			fprintf(file, "%f\n", w->val[i]);
	}
	fclose(file);
}
Vector *ReadIn2(char *namein)
{
	FILE *file = fopen(namein, "r");
	int n;
	fscanf(file, "%i\n", &n);
	Vector *w = new Vector;
	Create(w, n);
	for (int i = 0; i < n; i++)
		fscanf(file, "%lf", &(w->val[i]));
	fclose(file);
	return w;
}
int main(int argc, const char *argv[])
{

	// zad1

	Vector v1, v2;

	int n1 = 5;

	int n2 = 10;

	Create(&v1, n1);

	Create(&v2, n2);

	// zad2

	for (int i = 0; i < v1.size; i++)
	{

		v1.val[i] = i * 2;
	}

	for (int i = 0; i < v2.size; i++)
	{

		v2.val[i] = i * 3;
	}

	// zad3

	Show(&v1);

	Show(&v2);

	// zad4

	Write1(&v1, "vector1.txt");

	Write2(&v2, "vector2.txt");

	// zad5

	Destroy(&v1);

	Destroy(&v2);

	// zad6

	Show(&v1);

	Show(&v2);

	// zad7

	Vector *w1 = new Vector;

	Vector *w2 = new Vector;

	Create(w1, 5);

	Create(w2, 10);

	w1 = ReadIn1("vector1.txt");

	w2 = ReadIn2("vector2.txt");

	// zad8

	Show(w1);

	Show(w2);

	// zad9

	Destroy(w1);

	Destroy(w2);

	// zad10

	Show(w1);

	Show(w2);

	return 0;
}
