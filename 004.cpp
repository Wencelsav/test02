#include <iostream>
#include <iomanip> 
#include <sstream>

using namespace std;

int** create_(int row, int col)
{
	int ** a = new int*[row];
	for (int i = 0; i < row; i++)
	{
		a[i] = new int[col];
	}
	return a;
}
void delete_ (int **a, int row) {
	for (int i = 0; i < row; i++)
		delete[] a[i];
	delete a;
}
void spiral(int **a, int row, int column ) {
	int i = 0, j, k = 0, p = 1;

	while (i < row*column)
	{
		k++;
		for (j = k - 1; j<column - k + 1; j++)
		{
			a[k - 1][j] = p++;
			i++;
		}

		for (j = k; j<row - k + 1; j++)
		{
			a[j][column - k] = p++;
			i++;
		}

		for (j = column - k - 1; j >= k - 1; j--)
		{
			a[row - k][j] = p++;
			i++;
		}

		for (j = row - k - 1; j >= k; j--)
		{
			a[j][k - 1] = p++;
			i++;
		}

	}

}
bool get_size(int& columns,int& rows)
{
	string header;
	int nrows;
	int ncolumns;
	char op;
	getline(cin, header);
	istringstream str(header);

	if ((str >> nrows) && (str >> op) && (str >> ncolumns) && (op == ',') && (nrows>0) && (ncolumns>0))
	{
		rows = nrows;
		columns = ncolumns;
		return true;
	}
	return false;
}
void cout_(int** matrix,
	int ncolumns,
	int nrows)
{

	for (int j = 0; j < nrows; j++) {
		for (int i = 0; i < ncolumns; i++) {
			if (matrix[j][i] == -0) {
				matrix[j][i] = 0;
			}
			cout << matrix[j][i] << "\t";
		}
		cout << "\n";
	}
}
int main()
{
	int** a;
	int columns, rows;


	if (get_size(columns, rows))
	{
		a = create_(columns, rows);
		spiral(a, columns, rows);
		cout_(a, columns, rows);
		delete_(a, rows);
	}
	else {
		cout << "An error has occured while reading input data";
		exit(0);
	}

}
