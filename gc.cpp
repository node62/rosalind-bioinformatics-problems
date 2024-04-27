#include<iostream>
using namespace std;

string to_string(string s, int i){
    string str;
    for(int j=0; j<4; j++){
        str += s[i+j];
    }
    return str;
}

int main(){
    string s;
    cout<<"Enter string:\n";
    getline(cin, s, '$');
    int len=s.length();
    string temp;
    string end;
    int gc=0;
    int count=1;
    float gc_count;
    float max_gc=0;

    for(int i=0; i<len+1; i++){
        if(s[i]=='\0'){
            gc_count=float(gc*100)/count;
            if(gc_count>max_gc){
                max_gc=gc_count;
                end = temp;
                break;
            }
        }
        if(s[i]=='>'){
            gc_count=float(gc*100)/count;
            if(gc_count>max_gc){
                max_gc=gc_count;
                end = temp;
            }
            gc=0;
            count=0;
            i=i+10;
            temp=to_string(s, i);
            i=i+4;
            continue;
        }
        if(s[i]=='G' || s[i]=='C'){
            gc++;
            count++;
        }
        else if(s[i]=='T' || s[i]=='A'){
            count++;
        }
    }
    cout<<"Rosalind_"<<end<<"\n"<<max_gc;
    return 0;
}