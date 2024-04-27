#include<iostream>
#include<fstream>
using namespace std;

int main(){
    string path=R"(C:\Users\Theodore Regimon\Desktop\rosalind\rosalind_subs.txt)";
    ifstream file(path);
    string s, t;

    cout<<"Enter the strings: ";
    cin>>s>>t;
    for(int i=0; i<s.length(); i++){
        if(s.substr(i, t.length())==t){
            cout<<i+1<<" ";
        }
    }
    return 0;
}