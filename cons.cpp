#include<iostream>
#include<fstream>
#define nl '\n'
using namespace std;

class fasta{
    public:
    int count=0;
    string** rosa;
    fasta(const string& s) {
        for(int i=0; s[i]!='\0'; i++){
            if(s[i]=='>') count++;
        }

        rosa = new string*[count];
        for (int i = 0; i < count; ++i){
            rosa[i] = new string[2];
            rosa[i][0] = "";
            rosa[i][1] = "";
        }

        int a=-1, b=0;
        for(int i=0; s[i]!='\0'; i++){
            if(s[i]=='>'){
                a++; b=0;
                continue;
            }
            else if(s[i]=='\n' && b==0){
                b=1;
                continue;
            }
            else if(s[i]=='\n') continue;
            
            rosa[a][b]+=s[i];
        }
    }
    
};

int main(){
    string s;
    cout<<"Enter a string: "; getline(cin, s, '$');
    ofstream of("output.txt");
    if (!of.is_open()) {
        cout << "Failed to open the output file." << endl;
        return 1;
    }
    class fasta cons(s);
    string consensus="";
    int slen = cons.rosa[0][1].length();
    int arr[4][slen];
    for(int i=0; i<4; i++) for(int j=0; j<slen; j++) arr[i][j]=0;

    for(int i=0; i<slen; i++){
        for(int j=0; j<cons.count; j++){
            switch(cons.rosa[j][1][i]){
                case 'A': arr[0][i]++; break;
                case 'C': arr[1][i]++; break;
                case 'G': arr[2][i]++; break;
                case 'T': arr[3][i]++;
            }
        }
        int max=0;
        for(int j=0; j<4; j++){
            if(arr[j][i]>arr[max][i]) max=j;
        }
        switch(max){
            case 0: consensus+='A'; break;
            case 1: consensus+='C'; break;
            case 2: consensus+='G'; break;
            case 3: consensus+='T';
        }
    }
    of<<consensus<<nl;
    for(int i=0; i<4; i++){
        switch(i){
            case 0: of<<"A: "; break;
            case 1: of<<"C: "; break;
            case 2: of<<"G: "; break;
            case 3: of<<"T: ";
        }
        for(int j=0; j<slen; j++){
            of<<arr[i][j]<<" ";
        }
        of<<nl;
    }
    of.close();
    
return 0;
}