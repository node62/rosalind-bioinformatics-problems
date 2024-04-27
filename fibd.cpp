#include<iostream>
using namespace std;


int main(){ 
    int n, m;
    cout << "Enter: " <<endl;
    cin >> n >> m; 
    long long int birth[n];
    long long int mature[n];

    for(int i=0; i<n; i++){
        birth[i]=0;
        mature[i]=0;
    }

    birth[0]=1;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<i+m; j++)
        if(j<n)
            mature[j]+=birth[i];
        for(int j=i+2; j<i+m+1; j++)
        if(j<n)
            birth[j]+=birth[i];
    }

    cout<<"Ans: "<<birth[n-1]+mature[n-1]<<endl;
    return 0;
}