#include <iostream>
using namespace std;

int main(){
    string s, t;
    cout<<"Enter the strings: ";
    cin>>s>>t;
    int hamm=0;
    int len;
    if(s.length()>t.length())
        len=s.length();
    else
        len=t.length();
    for(int i=0; i<len; i++)
        if(s[i]!=t[i])
            hamm++;
    cout<<"hamm: "<<hamm;
    return 0;
}