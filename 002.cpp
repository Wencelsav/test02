#include <iostream>
#include <utility>
#include <string>
#include <sstream>
#include <limits>
using namespace std;



bool read_numbers(int *a, int n)
{
	string string;
	getline(cin, string);
	istringstream stream(string);
	bool success = true;
	for (int i = 0; i < n; ++i) {
		if (!(stream >> a[i])) {
			success = false;
			break;
		}
	}

	return success;
}

int main() {
	 
    int n,k; 
    cin >> n;
    cin.get()
    int *a = new int[n];
    cin >>k;
    if (n>0){
    int b = new int[n];
    for (int i = n-1; i >= 0; i--) {
        if(i+k >= n){
            b[i+k-n] = a[i];
        }
        else{
            b[i+n] = a[i];
        }
    }
   
		}
	
	else {
		cout << "An error has occured while reading input data.";
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return 0;
}
