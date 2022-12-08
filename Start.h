#pragma once

#include "variable.h"
using namespace std;

int start(int cnt)
{
    A=1000;
    if(cnt==0)
        cout << "Hi, there!\nWelcome to the human resource game!\n\n";
    ifstream pass(task[0]);
    string test;
    coun = 0;
    while(!pass.eof())
    {
        pass >> test;
        if (test == "yes")
            coun++;
    }
    cout << "Your current status:\n";
    for (int i = 0; i < 4; i++)
    {
        cout << "\tLevel " << i+1 << ": ";
        i < coun ?  cout << "Finished\n"
                  :  cout << "Unfinished\n";
    }
    cout << "Which level you'd like to try?    press 0 for exit\n";
    int level;
    cin >> level;
    while (level > coun+1 || level < 0)
    {
        cout << "Unlocked level! Please re-enter:\n";
        cin >> level;
    }
    return level;
}