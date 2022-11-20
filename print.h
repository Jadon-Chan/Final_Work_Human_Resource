#pragma once

#include <iostream>
using namespace std;

int di[]={0,2,2,0};int dj[]={0,0,4,4};
void makemap(char mapp[101][101],int n1,int n2,int orig[101],int targ[101],int spac){
    int N=n1*3,NN=n2*3,M=max(spac,1)*5+30;
    for(int i=1;i<=max(14,max(N,NN));i++)
        for(int j=1;j<=M;j++)
            mapp[i][j]=' ';
    mapp[2][1]='I';mapp[2][2]='N';mapp[2][M-3]='O';mapp[2][M-2]='U';mapp[2][M-1]='T';
    for(int k=0;k<4;k++){
        for(int i=1;i<=N;i+=3)
            mapp[i+di[k]][6+dj[k]]='+';
        for(int i=1;i<=NN;i+=3)
            mapp[i+di[k]][M-9+dj[k]]='+';
        mapp[1+di[k]][16+dj[k]]='+';
        for(int j=16;j<=5*spac+11;j+=5)
            mapp[11+di[k]][j+dj[k]]='+';
    }
    for(int de=0;de<3;de++){
        for(int i=1;i<=N;i+=3)
            mapp[i][7+de]=mapp[i+2][7+de]='-';
        for(int i=1;i<=NN;i+=3)
            mapp[i][M-8+de]=mapp[i+2][M-8+de]='-';
        mapp[1][17+de]=mapp[3][17+de]='-';
        for(int j=17;j<=5*spac+12;j+=5)
            mapp[11][j+de]=mapp[13][j+de]='-';
    }
    for(int de=0;de<5;de+=4){
        for(int i=2;i<=N;i+=3)
            mapp[i][6+de]='|';
        for(int i=2;i<=NN;i+=3)
            mapp[i][M-9+de]='|';
        mapp[2][16+de]='|';
        for(int j=16;j<=5*spac+11;j+=5)
            mapp[12][j+de]='|';
    }
    mapp[4][16]=mapp[4][20]='@';
    for(int i=16;i<=20;i++)mapp[5][i]='-';
    mapp[6][16]=mapp[6][20]='|';
    mapp[7][17]=mapp[7][19]='@';
    mapp[8][18]='+';
    mapp[9][16]='/';mapp[9][20]='\\';
    mapp[10][17]=mapp[10][19]='|';
    for(int i=2;i<=3*n1-1;i+=3){
        int jkl=orig[(i+1)/3];
        if(jkl<0){mapp[i][7]='-';jkl=-jkl;}
        if(jkl>=10)mapp[i][8]=char((jkl/10)+'0'),mapp[i][9]=char((jkl%10)+'0');
        else mapp[i][8]=char(jkl+'0');
    }
    for(int i=2;i<=3*n2-1;i+=3){
        int jkl=targ[(i+1)/3];
        if(jkl<0){mapp[i][M-8]='-';jkl=-jkl;}
        if(jkl>=10)mapp[i][M-7]=char((jkl/10)+'0'),mapp[i][M-6]=char((jkl%10)+'0');
        else mapp[i][M-7]=char(jkl+'0');
    }
    mapp[2][18]='X';
    for(int j=18;j<=5*spac+13;j+=5)
        mapp[12][j]='X',mapp[14][j]=char((j-13)/5-1+'0');
    return ;
}

void print(int n,int spac,char mapp[101][101],int instrnum,string instr[101]){
    int N=max(14,n*3),M=max(spac,1)*5+30;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++)putchar(mapp[i][j]);
        if(i==1)cout<<"| ===== CODE ===="<<endl;
        else{
            if(i<=instrnum+1)
                cout<<"|   "<<i-2<<' '<<instr[i-2]<<endl;
            else cout<<'|'<<endl;
        }
    }
    return ;
}//小箭头