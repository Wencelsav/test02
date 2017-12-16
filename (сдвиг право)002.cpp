#include <iostream>
#include <sstream>
using namespace std;
int reverse(int *a, int n) {
	for (int i = 0, j = n - 1; i < j; ++i, --j) {
		swap(a[i], a[j]);
	}
	return 0;
}
void  seconfd_reverse(int *& a, int number_shift, int n) {
	for (int j = 0; j<number_shift / 2; j++) {
		swap(a[j], a[number_shift - j - 1]);
	}
	for (int i = 0; i<(n - number_shift) / 2; i++) {
		swap(a[number_shift + i], a[n - i - 1]);
	}
}

bool read(int * a, int n)
{
	string mas;
	int array_count = 0;
	getline(cin, mas);
	istringstream stream(mas);
	for (int i = 0; i < n; i++)
	{
		if (stream >> a[i])
		{
			array_count++;
		}
	}
	if (array_count == n && stream.eof()) return true;
	else return false;
}

int main() {
	int n = 0, number_shift;
	if ((cin >> n) && (n > 1)) {
		string s;
		getline(cin, s);
		istringstream stream(s);
		int * a = new int[n];
		if (read(a, n)) {
			cin >> number_shift;
			reverse(a, n);
			seconfd_reverse(a, number_shift, n);
			for (int i = 0; i < n; ++i)
				cout << " " << a[i];
		}
		else { cout << "An error has occured while reading input data." << endl; }
		delete[] a;
	}
	else { cout << "An error has occured while reading input data." << endl; }
	return 0;
}
