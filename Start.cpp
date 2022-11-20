#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int start(void)
{
    cout << "Hi, there!\nWelcome to the human resource game!\n\n";
    ifstream pass("Pass_Situation");
    string test;
    int count = 0;
    while(!pass.eof())
    {
        pass >> test;
        if (test == "yes")
            count++;
    }
    cout << "Your current status:\n";
    for (int i = 0; i < 4; i++)
    {
        cout << "\tLevel " << i+1 << ": ";
        i < count ?  cout << "Finished\n"
                  :  cout << "Unfinished\n";
    }
    cout << "Which level you'd like to try?\n";
    int level;
    cin >> level;
    while (level > count+1)
    {
        cout << "Unlocked level! Please re-enter:\n";
        cin >> level;
    }
    return level;
}