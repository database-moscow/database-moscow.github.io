#include <string>
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
        if(z==10){
        ee='A';
        }
        if(z==11){
        ee='B';
        }
        if(z==12){
        ee='C';
        }
        if(z==13){
        ee='D';
        }
        if(z==14){
        ee='E';
        }
        if(z==15){
        ee='F';
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
        if(z==10){
        ee='A';
        }
        if(z==11){
        ee='B';
        }
        if(z==12){
        ee='C';
        }
        if(z==13){
        ee='D';
        }
        if(z==14){
        ee='E';
        }
        if(z==15){
        ee='F';
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
        if(pp[k]=='A' or pp[k]=='B' or pp[k]=='C' or pp[k]=='D' or pp[k]=='E' or pp[k]=='F' or pp[k]=='a' or pp[k]=='b' or pp[k]=='c' or pp[k]=='d' or pp[k]=='e' or pp[k]=='f' or pp[k]==',' or pp[k]=='.'){
        if(pp[k]=='A' or pp[k]=='a'){
            ch[k]=10;
        }
        if(pp[k]=='B' or pp[k]=='b'){
            ch[k]=11;
        }
        if(pp[k]=='C' or pp[k]=='c'){
            ch[k]=12;
        }
        if(pp[k]=='D' or pp[k]=='d'){
            ch[k]=13;
        }
        if(pp[k]=='E' or pp[k]=='e'){
            ch[k]=14;
        }
        if(pp[k]=='F' or pp[k]=='f'){
            ch[k]=15;
        }
        if(pp[k]=='.' or pp[k]==','){
        x=k;
        if((q-1)!=k){
            ch[k]=-1;
        }
        else{ch[k]=0;}
        }
        }
        else{
        ch[k]=pp[k]-'0';
        }
    }
    l=bbinary(ch, q, s, x);
    if(n[0]=='-'){
        l*=(-1);
    }
    return l;
}