#include<iostream>
using namespace std;

string rev(string s){
    string rev = "";
    auto comp= [](char c){
        if(c == 'A') return 'T';
        else if(c == 'T') return 'A';
        else if(c == 'C') return 'G';
        else if(c == 'G') return 'C';
        else return c;
    };
    for(int i = s.length()-1; i >= 0; i--){
        rev += comp(s[i]);
    }
    return rev;
}

string slice(string s, int j, int i){
    string rev = "";
    for(int m=0; m<j; m++, i++){
        if(s[i] == '\0') return "";
        rev += s[i];
    }
    // cout<<"slice: "<<rev<<"\t"<<rev.size()<<"\n";
    return rev;
}

int main(){
    cout<<"Enter the string: \n";
    string s; 
    getline(cin, s, '$');
    int key=0;
    string temp = "";

    for(int i=0; i<s.length(); i++){
        if(s[i] == '\n'){
            key = 1;
            continue;
        }
        if(key == 1){
            if(s[i]=='\n') continue;
            temp += s[i];
        }
    }
    
    for(int i=0 ; i<temp.length(); i++){
        for(int j=4; j<=12; j++){
            if(slice(temp, j, i) == rev(slice(temp, j, i)) && slice(temp, j, i)!= "")
                cout << i+1 << " " << j << endl;
            }
    }

return 0;
}