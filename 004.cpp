#include <iostream>
#include <sstream>
using namespace std;
void destroy(int ** mat,
	int b)
{
	for (int i = 0; i < b; ++i) {
		delete[] mat[i];
	}
	delete[] mat;
}

int** create_matrix(int a,
	int b)
{
	int** matrix;
	matrix = new int*[b];
	for (int i = 0; i < b; ++i) {
		matrix[i] = new int[a];
		for (int j = 0; j < a; ++j) {
			matrix[i][j];
		}
	}
	return matrix;
}


bool get_matrix(int**& mat,
	int na,
	int nb)
{
	mat = create_matrix(na, nb);

	for (int j = 0; j < nb; j++) {
		string new_row;
		getline(cin, new_row);
		istringstream stream(new_row);
		for (int i = 0; i < na; i++) {
			if (!(stream >> mat[j][i])) {

				return false;
			}
		}
	}
	return true;
}

void cout_matrix(int** mat,
	int na,
	int nb)
{

	for (int j = 0; j < nb; j++) {
		for (int i = 0; i < na; i++) {
			if (mat[j][i] == -0) {
				mat[j][i] = 0;
			}
			cout << mat[j][i] << "\t";
		}
		cout << "\n";
	}
}
bool get_size(int& a,
	int& b)
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
void create_ulitka(int **&mat,
	int a,
	int b,
	int level,
	int startnum
)
{
	if (a == 0 || b == 0) {
		return;
	}
	if (a == 1 || b == 1) {
		int hp = 0;
		for (int i = 0; i<a; i++) {

			mat[0 + level][i + level] = startnum + hp;
			hp++;


		}
		for (int i = 1; i<b; i++) {
			mat[level + i][level + a - 1] = startnum + hp;
			hp++;

		}
		return;
	}

	int hp = 0;
	for (int i = 0; i<a; i++) {

		mat[0 + level][i + level] = startnum + hp;
		hp++;


	}
	for (int i = 1; i<b; i++) {
		mat[level + i][level + a - 1] = startnum + hp;
		hp++;

	}
	for (int i = a - 2; i>-1; i--) {
		mat[level + b - 1][level + i] = startnum + hp;
		hp++;

	}
	for (int i = b - 2; i>0; i--) {
		mat[level + i][0 + level] = startnum + hp;
		hp++;

	}
	if (a - 2<0 || b - 2<0) {
		return;
	}
	create_ulitka(mat, a - 2, b - 2, level + 1, startnum + hp);


}
int main()
{
	int** mat;
	int a, b;


	if (get_size(a, b))
	{
		mat = create_matrix(a, b);
		create_ulitka(mat, a, b, 0, 1);
		cout_matrix(mat, a, b);
		destroy(mat, b);
	}
	else {
		cout << "An error has occured while reading input data";
		exit(0);
	}

}
