#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
string binary(double k, int s){
string e, ee;
string m;
int kk=int(k);
if(kk<0){
kk*=(-1);
m='-';
}
if(kk==0){
e='0';
}
else{
int z;
while(kk!=0){
z=kk%s;
kk/=s;
ee=to_string(z);
if(z>9){
ee=char(z+55);
}
e=ee+e;
}
if(int(k)!=k){
e=e+'.';
double drch=k-int(k);
while(drch!=0){
drch*=s;
z=int(drch);
drch=drch-z;
ee=to_string(z);
if(z>9){
ee=char(z+55);
}
e=e+ee;
}
}
}
return e;
}
double bbinary(int k[], int w, int s, int x){
double z, y;
int j=x+1;
y=0;
for(int h=0; h<x; h++){
z=k[h]*pow(s, (x-h-1));
y+=z;
}
for(x=-1; j<w; x--){
z=k[j]*pow(s, x);
y+=z;
j++;
}
return y;
}
double ibinary(string n, int s){
int q;
double l;
q=n.length();
int x=q;
if(n[0]=='-'){
q--;
x--;
}
char pp[q];
if(n[0]!='-'){
for(int k=0; k<q; k++){
pp[k]=n[k];
}
}
else{
for(int k=0; k<q; k++){
pp[k]=n[k+1];
}
}
int ch[q];
for(int k=0; k<q; k++){
if(int(pp[k])>64 and int(pp[k])<55+s){
ch[k]=int(pp[k])-55;
}
if(int(pp[k])>96 and int(pp[k])<87+s){
ch[k]=int(pp[k])-87;
}
if(pp[k]=='.' or pp[k]==','){
x=k;
if((q-1)!=k){
ch[k]=-1;
}
else{ch[k]=0;}
}
if(int(pp[k])>47 and int(pp[k])<58){
ch[k]=pp[k]-'0';
}
}
l=bbinary(ch, q, s, x);
if(n[0]=='-'){
l*=(-1);
}
return l;
}
int main(){
int s;
double m, l;
string n, j;
start:
cout<<"Введите систему счисления: ";
cin>>s;
if(s>16 or s<2){
cout<<"Введено некорректное значение."<<endl;
goto start;
}
cout<<"Введите 1 число в "<<s<<" системе счисления: ";
cin>>n;
if(s<=10){
for(int z=0; z<(n.length()); z++){
if(not(int(n[z])>47 and int(n[z])<s+48 or (n[z]=='.' or n[z]==','))){
cout<<"Введено некорректное значение."<<endl;
goto start;
}
}
}
if(s>10){
for(int z=0; z<(n.length()); z++){
if(not((int(n[z])>64 and int(n[z])<s+55) or (int(n[z])>96 and int(n[z])<s+87) or (int(n[z])>47 and int(n[z])<s+48) or (n[z]=='.' or n[z]==','))){
cout<<"Введено некорректное значение."<<endl;
goto start;
}
}
}
cout<<"Введите 2 число в 10 cистеме счисления: ";
cin>>m;
l=ibinary(n, s);
string sss=to_string(l);
while(sss.back()=='0'){
sss.erase(sss.length()-1, 1);
}
if(sss.back()=='.'){
sss.erase(sss.length()-1, 1);
}
cout<<"1 число в 10 системе счисления:"<<endl<<sss<<endl;
j=binary(m, s);
cout<<"2 число в "<<s<<" системе счисления:"<<endl<<j;
return 0;
}