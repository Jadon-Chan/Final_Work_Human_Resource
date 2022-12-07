#include <sstream>
#include <algorithm>
#include <fstream>
#include <string>
#include <iostream>
#include "variable.h"

void keyboard(void)
{
    cout << "How many lines you'd like to input?" << endl;
    cin >> lines;
    for (int i = 0; i < lines; i++)
    {
        cin >> users[i];
    }
}

void file(void)
{
    cout << "Note that your file should consist of n+1 lines," << endl
         << "the first line is an integer n, meaning you have n pieces of instructions." << endl
         << "the rest n lines are the instructions, only one piece of instruction for one line" << endl;
    cout << "Enter the path of your instruction file:" << endl;
    string path;
    cin >> path;
    ifstream source.open(path);
    source >> lines;
    for (int i = 0; i < n; i++)
    {
        source >> users[i];
    }
}

void read(void)
{
    cout << "In which way you'd like to input instructions?" << endl;
    cout << "a) via keyboard    b) via file" << endl;
    char manner;
    while (1)
    {
        cin >> manner;
        switch (manner)
        {
        case 'a':
            keyboard();
            break;
        case 'b':
            file();
            break;
        default:
            cout << "No such an option, please choose between a and b!" << endl;
            continue;
        }
        break;
    }
}
bool isint(char *oprand)
{
    for (int i = 0; i < strlen(operand); i++)
    {
        if (operand[i] < '0' || operand[i] > '9')
            return 0;
    }
    return 1;
}
bool check(int i)
{
    if (!binary_search(instr, instr + sizeof(instr), users[i]))
        return 0;
    char op[15];
    char operand[100];
    stringstream s(users[i]);
    s >> op >> operand;
    string temp = convertToString(op);
    int situ;
    string sets[] = {"inbox", "outbox", "add", "sub", "copyto", "copyfrom", "jump", "jumpifzero"};
    for (int i = 0; i < 8; i++)
    {
        if (temp == sets[i])
        {
            situ = i;
            break;
        }
    }
    switch (situ)
    {
    case 0:
        if (s.tellp() == 0)
            return 0;
    case 1:
        if (s.tellp() == 0)
            return 0;
        // how to judge now nownum
        if (nownum == A)
            return 0;
    case 2:
    case 3:
        // how to judge field x
        if (s.tellp() != 0)
            return 0;
        if (!isint(operand))
            return 0;
        string temp = convertToString(operand);
        if (stoi(temp) > spac || empt[stoi(temp)] == A)
            return 0;
    case 4:
        if (s.tellp() != 0)
            return 0;
        if (!isint(operand))
            return 0;
        string temp = convertToString(operand);
        if (stoi(temp) > spac)
            return 0;
        if (nownum == A)
            return 0;
    case 5:
        if (s.tellp() != 0)
            return 0;
        if (!isint(operand))
            return 0;
        string temp = convertToString(operand);
        if (stoi(temp) > spac || empt[stoi(temp)] == A)
            return 0;
    case 6:
    case 7:
        if (s.tellp() != 0)
            return 0;
        string temp = convertTostring(operand);
        if (users[stoi(temp)] == "")
            return 0;
        if (situ == 7 && nownum == A)
            return 0;
    }
    return 1;
}