#pragma once

#include "variable.h"
using namespace std;

bool getmission(int x){
    string s=task[x];
    ifstream fin;fin.open(s);
    if(!fin){cout<<"fail to open"<<s<<endl;system("pause");return 0;}
    fin>>n1;for(int i=1;i<=n1;i++)fin>>orig[i];
    fin>>n2;for(int i=1;i<=n2;i++)fin>>targ[i];
    fin>>spac>>useable;
    for(int i=1;i<=useable;i++)fin>>instr[i];
    fin.close();
    cout<<"The original queue is:";
    for(int i=1;i<=n1;i++)cout<<orig[i]<<' ';cout<<endl;
    cout<<"The targeted queue is:";
    for(int i=1;i<=n2;i++)cout<<targ[i]<<' ';cout<<endl;
    cout<<"The number of empty spaces is "<<spac<<endl;
    cout<<"The available instructions are:";
    for(int i=1;i<=useable;i++)cout<<instr[i]<<' ';cout<<endl;
    return 1;
}