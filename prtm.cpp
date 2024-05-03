#include<iostream>
#include<map>
#include <iomanip>
#include <string>
using namespace std;

void store(map<char, double> &dict){
    dict['A']=71.03711;
    dict['C']=103.00919;
    dict['D']=115.02694;
    dict['E']=129.04259;
    dict['F']=147.06841;
    dict['G']=57.02146;
    dict['H']=137.05891;
    dict['I']=113.08406;
    dict['K']=128.09496;
    dict['L']=113.08406;
    dict['M']=131.04049;
    dict['N']=114.04293;
    dict['P']=97.05276;
    dict['Q']=128.05858;
    dict['R']=156.10111;
    dict['S']=87.03203;
    dict['T']=101.04768;
    dict['V']=99.06841;
    dict['W']=186.07931;
    dict['Y']=163.06333;
}


int main() {
    map<char, double> dict;
    store(dict);

    string s;
    cout << "Enter string: ";
    cin >> s;
    double sum = 0;
    for (int i = 0; i < s.size(); i++) {
        sum += dict[s[i]];
    }

    cout << "ans: " << fixed << setprecision(6) << sum << endl;
    return 0;
}