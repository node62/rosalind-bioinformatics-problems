#include<iostream>
#include<fstream>
using namespace std;

char convert(string s, int i){
    string temp = s.substr(i, 3);
    string arr[] = {"UUU","F","CUU","L","AUU","I","GUU","V","UUC","F","CUC","L","AUC","I","GUC","V","UUA","L","CUA","L","AUA","I","GUA","V","UUG","L","CUG","L","AUG","M","GUG","V","UCU","S","CCU","P","ACU","T","GCU","A","UCC","S","CCC","P","ACC","T","GCC","A","UCA","S","CCA","P","ACA","T","GCA","A","UCG","S","CCG","P","ACG","T","GCG","A","UAU","Y","CAU","H","AAU","N","GAU","D","UAC","Y","CAC","H","AAC","N","GAC","D","UAA","\0","CAA","Q","AAA","K","GAA","E","UAG","\0","CAG","Q","AAG","K","GAG","E","UGU","C","CGU","R","AGU","S","GGU","G","UGC","C","CGC","R","AGC","S","GGC","G","UGA","\0","CGA","R","AGA","R","GGA","G","UGG","W","CGG","R","AGG","R","GGG","G"};
    for(int j = 0; j < sizeof(arr)/sizeof(arr[0]); j += 2){
        if(arr[j] == temp){
            return arr[j+1][0];
        }
    }
    return '\0';
}

int main(){
    string path=R"(C:\Users\Theodore Regimon\Desktop\rosalind\rosalind_prot.txt)";
    ifstream file(path);
    string s;

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            s += line;
        }
        cout<<s;
        file.close();
    } else {
        cout << "Unable to open file";
        return 1;
    }

    int len=s.length();
    cout<<"\n\n\n";
    for(int i=0; i+2<len; i=i+3){
        char temp=convert(s, i);
        if(temp=='\0')
            break;
        cout<<temp;
    }
    return 0;
}