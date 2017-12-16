#include <iostream>
#include <sstream>
using namespace std;
int reverse (int *a, int n){
	for (int i = 0, j = n - 1; i < j; ++i, --j) {

		int t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	return 0;
}
bool read(int * a, unsigned int size) {
	string stroka;
	getline(cin, stroka);
	istringstream stream(stroka);
	for (unsigned int i = 0; i < size; ++i) {
		if (!(stream >> a[i])) {
			return false;
		}
	}
	return true;
}
int main() {
	int n = 0;
		if ((cin >> n) && (n > 1)) {
			string s;
			getline(cin, s);
			istringstream stream(s);
			int * a = new int[n];
			if (read(a, n)) {
				reverse(a, n);
				for (int i = 0; i < n; ++i)
					cout << " " << a[i];
			}
			else { cout << "An error has occured while reading input data." << endl; }
			delete[] a;
		}
		else { cout << "An error has occured while reading input data." << endl; }
		return 0;
	}
