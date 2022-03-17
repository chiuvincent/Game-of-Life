#include "array.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>
#include <stdlib.h>

using namespace std;

void initialize(int a[][MAX]){
    for(int row=0; row<MAX; row++){
        for(int col=0; col<MAX; col++){
            a[row][col] = 0;
        }
    }
}

void clear(int a[][MAX]){
    initialize(a);
}

void config(int a[][MAX], int row, int col){
    a[row][col] = 1;
}

int getRandom(int low, int hi){
    return rand()%(hi-low+1)+low;
}

void config(int a[][MAX]){
    config(a,3,4);
    config(a,4,5);
    config(a,5,5);
    config(a,5,3);
    config(a,5,4);
}

void random(int a[][MAX], int n){
    srand(time(0));
    int lim = MAX-2;
    for(int i=0; i<n; i++){
        config(a,getRandom(1,lim),getRandom(1,lim));
    }
}

void random30(int a[][MAX]){
    srand(time(0));
    int row;
    int col;
    int num = 30;
    int lim = MAX-2;
    while(num!=0){
        row = getRandom(1,lim);
        col = getRandom(1,lim);
        if(a[row][col]==0){
            a[row][col] = 1;
            num--;
        }
    }
}

void copy(int first[][MAX], int second[][MAX]){//second copies the first
    for(int row=0; row<MAX; row++){
        for(int col=0; col<MAX; col++){
            second[row][col] = first[row][col];
        }
    }
}

void margin(int a[][MAX]){
    for(int row=0; row<MAX; row++){
        a[row][0] = a[row][MAX-2];
        a[row][MAX-1] = a[row][1];
    }
    for(int col=0; col<MAX; col++){
        a[0][col] = a[MAX-2][col];
        a[MAX-1][col] = a[1][col];
    }
}

void print(int a[][MAX]){
    //cout<<"  0  1  2  3  4  5  6  7  8  9 "<<endl;
    //cout<<"--------------------"<<endl;
    for(int row=0; row<MAX; row++){
        //cout<<row%10<<" ";
        for(int col=0; col<MAX; col++){
            if(a[row][col]==0){
                //cout<<"-  ";
                cout<<" ";
            }
            else
                cout<<".";
                //cout<<"O  ";
        }
        cout<<endl;
        //cout<<endl;
    }
    cout<<endl;
}

int count(int a[][MAX], int row, int col){
    int count = 0;
    if(a[row][col]!=0){
        count--;
    }
    for(int r=row-1; r<=row+1; r++){
        for(int c=col-1; c<=col+1; c++){
            if(a[r][c]!=0){
                count++;
            }
        }
    }
    return count;
}

void step(int a[][MAX]){
    int b[MAX][MAX];
    initialize(b);
    margin(a);
    for(int row=1; row<MAX-1; row++){
        for(int col=1; col<MAX-1; col++){
            b[row][col] = count(a,row,col);
        }
    }
    for(int row=0; row<MAX; row++){
        for(int col=0; col<MAX; col++){
            if(b[row][col]<2){
                b[row][col] = 0;
            }
            else if(b[row][col]==2){
                b[row][col] = a[row][col];
            }
            else if(b[row][col]==3){
                b[row][col] = 1;
            }
            else if(b[row][col]>3){
                b[row][col] = 0;
            }
        }
    }
    copy(b,a);
}

void SaveArray(const char fileName[], int a[][MAX]){
    ofstream outFile;
    outFile.open(fileName);
    if(outFile.fail()){
        cout<<endl<<"SAVE FAILED."<<endl;
        exit(0);
    }
    else{
        cout<<endl<<"SAVE SUCCESS"<<endl;
    }

    for(int row=0; row<MAX; row++){
        for(int col=0; col<MAX; col++){
            if(a[row][col]==0){
                outFile<<"-";
            }
            else
                outFile<<"o";
        }
        outFile<<endl;
    }
    outFile<<endl;

    outFile.close();
}

void LoadArray(const char fileName[], int a[][MAX]){
    ifstream inFile;
    inFile.open(fileName);
    if(inFile.fail()){
        cout<<endl<<"LOAD FAILED."<<endl;
        exit(0);
    }
    else{
        cout<<endl<<"LOAD SUCCESS."<<endl;
    }
    char c;
    for(int row=0; row<MAX; row++){
        for(int col=0; col<MAX; col++){
            inFile>>c;
            if(c=='-'){
                a[row][col]=0;
            }
            else
                a[row][col]=1;
        }
    }

    inFile.close();

}
