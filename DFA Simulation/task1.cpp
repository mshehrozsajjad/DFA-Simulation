#include <stdio.h>
#include <iostream>
#include <sstream>
using namespace std;

bool Task1a();
bool Task1b();

int main(void) {
    
    
    string input = "";
    cout << "+------------------------------------+"<< endl;
    cout << "|       DFA SIMULATION PROGRAM       |"<< endl;
    cout << "|                                    |"<< endl;
    cout << "|     By Muhammad Shehroz Sajjad     |"<< endl;
    cout << "|                                    |"<< endl;
    cout << "|          DFA : a(bb)*bc            |"<< endl;
    cout << "+------------------------------------+\n"<< endl;
    cout << "Please select one option:"<< endl;
    cout << "1. Using Goto statement."<< endl;
    cout << "2. Using Switch statement."<< endl;
    getline(cin, input);
    if(input == "1"){
        Task1a();
    }else if(input == "2"){
        Task1b();
    }
    
}

bool Task1a() {
START:
    string input = "";
    cout << "Input string (Containing a,b,c only): ";
    getline(cin, input);
    for (int a = 0; a < input.length(); a++) {
        if (input[a] == 'a' || input[a] == 'b' || input[a] == 'c')
            continue;
        else {
            cout << "String is not accepted by language!" << endl;
            cout << "\n\nPress any key to continue..." << endl;
            getchar();
            return 0;
        }
    }
    int i = 0;
    goto S1;
    
    
S1:
    if (input[i] == 'a')
        goto S2;
    else
        goto TRAP;
S2:
    i++;
    if (input[i] == 'b')
        goto S3;
    else
        goto TRAP;
S3:
    i++;
    if (input[i] == 'b')
        goto S2;
    else if (input[i] == 'c')
        goto S4;
    else
        goto TRAP;
TRAP:
    cout << "String is not accepted by language!" << endl;
    cout << "\n\nPress any key to continue..." << endl;
    getchar();
    return 0;
S4:
    i++;
    if (input[i] != '\0')
        goto TRAP;
    cout << "String is accepted by language!" << endl;
    cout << "\n\nPress any key to continue..." << endl;
    getchar();
    return  0;
}

bool Task1b() {
    string input = "";
    cout << "Input string (Containing a,b,c only): ";
    getline(cin, input);
    for (int a = 0; a < input.length(); a++) {
        if (input[a] == 'a' || input[a] == 'b' || input[a] == 'c')
            continue;
        else {
            cout << "String is not recognized by language!" << endl;
            cout << "\n\nPress any key to continue..." << endl;
            getchar();
            break;
        }
    }
    int i = 0;
    int cn = 1;
    
    while (true) {
        switch (cn) {
            case 0:
                cout << "String is not accepted by language!" << endl;
                cout << "\n\nPress any key to continue..." << endl;
                getchar();                return false;
                break;
            case 1:
                if (input[i] == 'a')
                    cn = 2;
                else
                    cn = 0;
                break;
            case 2:
                if (input[i] == 'b')
                    cn = 3;
                else
                    cn = 0;
                break;
            case 3:
                if (input[i] == 'b')
                    cn = 2;
                else if (input[i] == 'c')
                    cn = 4;
                else
                    cn = 0;
                break;
            case 4:
                if (input[i] != '\0')
                    cn = 0;
                    break;
                cout << "String is accepted by language!" << endl;
                cout << "\n\nPress any key to continue..." << endl;
                getchar();
                return true;
        }
        i++;
    }
}


