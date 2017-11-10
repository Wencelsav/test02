#include <iostream>
#include <sstream>
using namespace std;
void reverse(int *& ar,unsigned int n){
    for(  unsigned int j=0;j<n/2;j++){

        swap(ar[j],ar[n-j-1]);

    }
}
void  doublereverse(int *& ar,unsigned int position,unsigned int n){
    for( unsigned int j=0;j<position/2;j++){

        swap(ar[j],ar[position-j-1]);

    }
    for(  unsigned int i=0;i<(n-position)/2;i++){

        swap(ar[position+i],ar[n-i-1]);

    }

}
bool read_numbers(int *a, int n)
{ unsigned int n;

    string line;
    getline(cin,line);
    istringstream numstream(line);
    bool success = true;
    if(!(numstream>>n)){
        success = false;
        break;
    }

    getline(cin,line);
    istringstream arrstream(line);
    int *arr=new int[n];
    for(unsigned int i=0;i<n;i++){
        if(!(arrstream>>arr[i])){
           success = false;
           break;
        }

    }
    int npos;
    getline(cin,line);
    istringstream posstream(line);
    if(!(posstream>>npos)){
       success = false;
       break;
    }
    
    }
int main() {
    unsigned int n;

   if (read_numbers(arr, n,npos)) 
   {
    doublereverse(arr,n-npos,n);
    reverse(arr,n);


    for(unsigned int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
   }
    delete[] arr;
    return 0;
}
