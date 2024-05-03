#include<iostream>
using namespace std;

float pow(float a, int p){
    float ans=1.0;
    for(int i=0; i<p; i++)
        ans*=a;
    return ans;
}

long double choose(int n, int m){
    if(m > n)
        cout<<"choose error"<<endl;

    long double tempf = 1.0;
    for(int i=1; i<=m; i++)
        tempf *= (float)(n - i + 1) / (float)i; 
    return tempf;
}

long double fun(int n, int m, float a){
    long double ans = choose(n, m)*pow(a, m)*pow(1-a, n-m);
    return ans;
}

int main(){
    int N, k;
    cout<<"Enter the value of k and N: ";
    cin>>k>>N;;
    
    float prob=0.25;
    int total=pow(2,k);

    if(N>total){
        cout<<"Invalid input";
        return 0;
    }

    float ans=0;

    for(int i=N; i<=total; i++){
        ans+=fun(total, i, prob);
    }

    cout<<"Ans: "<<ans;

    return 0;
}
