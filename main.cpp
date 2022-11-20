#include <iostream>
#include <string>
#include "getmission.h"
#include "print.h"
#include "read.h"
#include "Start.h"
using namespace std;

int n1,n2,spac,useable;
int orig[101],targ[101];
int mapp[101][101] = {0};
string instr[101];
int lines;

int main(void)
{
    if (!getmission(start()))
        return 0;
    read();
}