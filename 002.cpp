#include <iostream>
#include <sstream>
using namespace std;
void reverse(int *& a, int n) {
	for (int j = 0; j<n / 2; j++) {

		swap(a[j], a[n - j - 1]);

	}
}
void  doublereverse(int *& a, int pos, int n) {
	for (int j = 0; j<pos / 2; j++) {

		swap(a[j], a[pos - j - 1]);

	}
	for (int i = 0; i<(n - pos) / 2; i++) {

		swap(a[pos + i], a[n - i - 1]);

	}

}

int main() {
	int n;
	char k;
	string line;
	getline(cin, line);
	istringstream nstream(line);
	if (!(nstream >> n) || !(n>0)) {
		cout << "An error has occuried while reading input data.";
		exit(0);
	}

	getline(cin, line);
	istringstream astream(line);
	int *a = new int[n];
	for (unsigned int i = 0; i<n; i++) {
		if (!(astream >> a[i])) {
			cout << "An error has occuried while reading input data.";
			exit(0);
		}

	}
	if (astream >> k) {
		cout << "An error has occuried while reading input data.";
		exit(0);
	}
	int npos;
	getline(cin, line);
	istringstream nposstream(line);
	if (!(nposstream >> npos) || !(npos>0)) {
		cout << "An error has occuried while reading input data.";
		exit(0);
	}
	doublereverse(a, n - npos, n);
	reverse(a, n);



	for (unsigned int i = 0; i<n; i++) 
	{
		cout << a[i] << " ";
	}
	delete[] a;
	return 0;
}
