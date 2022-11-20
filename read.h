#include "variable.h"
#include <iostream>
#include <string>

bool test(char *str)
{
    if (strlen(str) > 2)
        return 0;
    for (int i = 0; i < strlen(str); i++)
        if (!isdigit(str[i]))
            return 0;
    return 1;
}
void getdeci(int *a)
{
    char line[11];
    cin.getline(line, 11);
    while (!test(line))
    {
        cout << "Jesus! I've told you to enter the appropriate value!\n";
        char ch;
        cin.getline(line, 11);
    }
    sscanf(line, "%d", a);
}

void read(void)
{
    string way;
    ofstream keyboard("Instructions");
    ifstream file("Instructions");
    cout << "Choose the way you want to input?\n"
         << "keyboard or file?\n";
    cin >> way;
    getchar();
    while (way != "file" && way != "keyboard")
    {
        cout << "No such way for input.Please re-enter:\n";
        cin >> way;
    }
    if (way == "keyboard")
    {
        cout << "Great. How mang pieces of instructions you'd like to enter?" << endl
             << "(You won't enter a non-integer to embarass me, right?)" << endl
             << "(And you can make 99 pieces at most)" << endl;
        getdeci(&lines);
        string line;
        for (int i = 0; i < lines; i++)
        {
            cin.getline(line);
            keyboard << line;
        }
    }
    
}
