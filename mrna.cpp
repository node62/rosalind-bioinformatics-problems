#include<iostream>
#include<map>
using namespace std;

int mod(int a){
    return a%1000000;
}

int main(){
    map<char, int> codon;
    string arr[] = {"UUU","F","CUU","L","AUU","I","GUU","V","UUC","F","CUC","L","AUC","I","GUC","V","UUA","L","CUA","L","AUA","I","GUA","V","UUG","L","CUG","L","AUG","M","GUG","V","UCU","S","CCU","P","ACU","T","GCU","A","UCC","S","CCC","P","ACC","T","GCC","A","UCA","S","CCA","P","ACA","T","GCA","A","UCG","S","CCG","P","ACG","T","GCG","A","UAU","Y","CAU","H","AAU","N","GAU","D","UAC","Y","CAC","H","AAC","N","GAC","D","UAA","*","CAA","Q","AAA","K","GAA","E","UAG","*","CAG","Q","AAG","K","GAG","E","UGU","C","CGU","R","AGU","S","GGU","G","UGC","C","CGC","R","AGC","S","GGC","G","UGA","*","CGA","R","AGA","R","GGA","G","UGG","W","CGG","R","AGG","R","GGG","G"};
    for(int i=1; i<sizeof(arr)/ sizeof(arr[0]); i+=2){
        codon[arr[i][0]]++;
    }

    string s;
    cout<<"Enter: \n";
    cin>>s;
    int ans = 1;
    for(int i=0; i<s.length(); i++){
        ans = mod(ans)*mod(codon[s[i]]);
    }
    ans = mod(ans)*mod(codon['*']);
    cout<<"ans: "<<mod(ans);
    return 0;
}