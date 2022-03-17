#include "array.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>
#include <stdlib.h>

using namespace std;


int main()
{
    int a[MAX][MAX];
    initialize(a);
    config(a);
    cout<<"[S]SAVE\t\t[L]LOAD\n[C]CLEAR\t[R]RANDOM\n[N]NEXT\t\t[X]EXIT\n[M]MENU\n\n";
    cout<<"===================="<<endl;
    print(a);
    cout<<"===================="<<endl;
    char x;
    string s;
    do{
        cin>>x;
        if(x=='r'||x=='R'){
            random30(a);
            step(a);
            print(a);
        }
        else if(x=='c'||x=='C'){
            clear(a);
            print(a);
        }
        else if(x=='s'||x=='S'){
            cout<<"ENTER FILE NAME:\n";
            cin>>s;
            s+=".txt";
            SaveArray(s.c_str(),a);
            //SaveArray("arrayfile.txt",a);
        }
        else if(x=='l'||x=='L'){
            cout<<"ENTER FILE NAME:\n";
            cin>>s;
            s+=".txt";
            LoadArray(s.c_str(),a);
            //LoadArray("arrayfile.txt",a);
            print(a);
        }
        else if(x=='m'||x=='M'){
            print(a);
            cout<<"[S]SAVE\t\t[L]LOAD\n[C]CLEAR\t[R]RANDOM\n[N]NEXT\t\t[X]EXIT\n[M]MENU\n\n";
        }
        else if(x=='n'||x=='N'){
            step(a);
            print(a);
        }
        cout<<endl<<"===================="<<endl;
    }while(!(x=='X'||x=='x'));

//    while(true){
//        step(a);
//        print(a);
//        cin.get();
//    }
}
