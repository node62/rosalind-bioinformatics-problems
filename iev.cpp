#include<iostream>
using namespace std;

int main(){
    float a[6];
    cout<<"Enter:\n";
    for(int i=0; i<6; i++)
        cin>>a[i];
    float Ex = 2*(a[0] +
            a[1] + 
            a[2] +
            0.75*a[3] +
            0.5*a[4] +
            0*a[5]);   
            
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "Ex = " << Ex;
    return 0;
}