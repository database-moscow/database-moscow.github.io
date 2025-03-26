#include <iostream>
#include <binary.h>

using namespace std;
int main(){
    int m, l, s;
    string n, j;
    cout<<"Введите систему счисления: ";
    cin>>s;
    cout<<"Введите число из: ";
    cin>>n;
    cout<<"Введите число в: ";
    cin>>m;
    l=ibinary(n, s);
    cout<<l<<" ";
    j=binary(m, s);
    cout<<j;
    return 0;
}