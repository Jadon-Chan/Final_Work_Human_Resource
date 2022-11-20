#include <string>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <cctype>
using namespace std;

int search(string sets[], int n, string a)
{
    for (int i = 0; i < n; i++)
    {
        if (sets[i] == a)
            return i;
    }
    return -1;
}
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
string sets[] = {"inbox", "outbox", "add", "sub", "copyto", "copyfrom", "jump", "jumpifzero"};
string neat[] = {"inbox", "outbox"};
void read(void)
{
    string way;
    int lines;
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
        cout << "Okay then. Tell the robot what to do now:\n";
        for (int i = 0; i < lines; i++)
        {
            string a;
            int num;
            cin >> a;
            getchar();
            while (search(sets, 8, a) == -1)
            {
                cout << "Robo can't understand what you are saying.Please re-enter.\n";
                cin >> a;
            }
            if (search(neat, 2, a) == -1)
            {
                cout << "Well, then what about the operating number of this?" << endl
                     << "No larger than 99" << endl;
                getdeci(&num);
                char snum[3];
                sprintf(snum, " %d", num);
                a += snum;
            }
            keyboard << a << endl;
            if (i != lines-1)
                cout << "Great. Next line." << endl;
        }
    }
}