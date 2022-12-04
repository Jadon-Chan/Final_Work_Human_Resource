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

bool check(int i)
{
    if (!binary_search(instr, instr+sizeof(instr), users[i]))
        return 0;
    string op;
    char operand[100];
    stringstream s(usres[i]);
    s >> op;
    switch (op)
    {
        case "inbox":
        if (s.tellp()!=streampos(0))
            return 0;
        case "outbox":
        if (s.tellp()!=streampos(0))
            return 0;
        //how to judge now nownum
        case "add":
        case "sub":
        //how to judge field x
        if (s.tellp()==streampos(0))
            return 0;
        s >> operand;
        for (int i = 0; i < strlen(operand); i++)
        {
            if (operand[i] < '0'|| operand[i] > '9')
                return 0;
        }
        case "copyto":
        if (s.tellp()==streampos(0))
            return 0;
        s >> operand;
        for (int i = 0; i < strlen(operand); i++)
        {
            if (operand[i] < '0'|| operand[i] > '9')
                return 0;
        }
        case "copyfrom":
        if (s.tellp()==streampos(0))
            return 0;
        s >> operand;
        for (int i = 0; i < strlen(operand); i++)
        {
            if (operand[i] < '0'|| operand[i] > '9')
                return 0;
        }
        case "jump":
        case "jumpifzero":
        if (s.tellp()==streampos(0))
            return 0;
        s >> operand;
        for (int i = 0; i < strlen(operand); i++)
        {
            if (operand[i] < '0'|| operand[i] > '9')
                return 0;
        }
        if (users[operand]=="")
            return 0;
    }
}