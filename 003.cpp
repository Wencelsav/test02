#include "stdafx.h"
#include <iostream>
#include <sstream>
using namespace std;
void destroy(float ** mat,
	unsigned int b)
{
	for (unsigned int i = 0; i < b; ++i) {
		delete[] mat[i];
	}
	delete[] mat;
}

float** create_matrix(unsigned int a,
	unsigned int b)
{
	float** matrix;
	matrix = new float*[b];
	for (unsigned int i = 0; i < b; ++i) {
		matrix[i] = new float[a];
		for (unsigned int j = 0; j < a; ++j) {
			matrix[i][j] = 0.0f;
		}
	}
	return matrix;
}


bool get_matrix(float**& mat,
	unsigned int na,
	unsigned int nb)
{
	mat = create_matrix(na, nb);

	for (unsigned int j = 0; j < nb; j++) {
		string new_row;
		getline(cin, new_row);
		istringstream stream(new_row);
		for (unsigned int i = 0; i < na; i++) {
			if (!(stream >> mat[j][i])) {

				return false;
			}
		}
	}
	return true;
}

void cout_matrix(float** mat,
	unsigned int na,
	unsigned int nb)
{

	for (unsigned int j = 0; j < nb; j++) {
		for (unsigned int i = 0; i < na; i++) {
			if (mat[j][i] == -0) {
				mat[j][i] = 0;
			}
			cout << mat[j][i] << "\t";
		}
		cout << "\n";
	}
}
bool get_size(unsigned int& a,
	unsigned int& b)
{
	string header;
	int nb;
	int na;
	char razdel;
	getline(cin, header);
	istringstream str(header);

	if ((str >> nb) && (str >> razdel) && (str >> na) && (razdel == ',') && (nb>0) && (na>0))
	{
		b = nb;
		a = na;
		return true;
	}
	return false;
}
bool get_shift(unsigned int &sdvig)
{
	string header;


	getline(cin, header);
	istringstream str(header);
	int nsdvig;
	if (str >> nsdvig&&nsdvig>0) {
		sdvig = nsdvig;
		return true;
	}
	return false;
}
void shiting(float **&mat,
	int a,
	int b,
	int shift) {
	float hp, hp1;
	for (int s = 0; s<shift; s++) {
		hp = mat[0][0];
		hp1 = 0;
		for (int i = 0; i<a - 1; i++) {
			hp1 = mat[0][i + 1];
			mat[0][i + 1] = hp;
			hp = hp1;

		}
		for (int i = 0; i<b - 1; i++) {
			hp1 = mat[i + 1][a - 1];
			mat[i + 1][a - 1] = hp;
			hp = hp1;

		}
		for (int i = a - 1; i>0; i--) {
			hp1 = mat[b - 1][i - 1];
			mat[b - 1][i - 1] = hp;
			hp = hp1;

		}
		for (int i = b - 1; i>0; i--) {
			hp1 = mat[i - 1][0];
			mat[i - 1][0] = hp;
			hp = hp1;

		}
	}

}
int main()
{
	float** mat;
	unsigned int a, b, shift;


	if (get_size(a, b))
	{
		if (get_matrix(mat, a, b) && get_shift(shift))
		{
			shiting(mat, a, b, shift);
			cout_matrix(mat, a, b);
		}
		else {
			cout << "An error has occured while reading input data";

		}
		destroy(mat, b);
	}
	else {
		cout << "An error has occured while reading input data";
		exit(0);
	}

}
