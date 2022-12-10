#include "getmission.h"
#include "print.h"
#include "work.h"
#include "Start.h"
#include "read.h"
#include "variable.h"
using namespace std;

int n1,n2,lines,spac,useable;
int orig[101],subs[101],empt[101];
int targ[101];
string instr[101],users[101];
char mapp[101][101];
int nownum,len1,len2;
string instruction;int num;
int A,p;
int coun;
bool omo;
string task[]={
    "Pass_Situation.txt",
    "mission1.txt",
    "mission2.txt",
    "mission3.txt"};

int main(void)
{
    int cnt=0;
    while(1){
        p=start(cnt);
        if(p==0)break;
        if (!getmission(p))break;
        makemap();
        print(0);
        read();
        if(work()){
            p=max(p,coun);
            sus(p);
        }
        system("pause");
        cnt++;
    }
    return 0;
}