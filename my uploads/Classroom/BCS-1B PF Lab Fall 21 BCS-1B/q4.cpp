#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    
    int n;
    char message[100];
    cout << "1. Encrypt data\n";
    cout << "2. Decrypt data\n";
    cout << "Enter Your Option: ";
    cin >> n;
    while (n > 2 && n < 1)
    {
        cout << "Enter Your Option again: ";
        cin >> n;
    }
    if (n == 1)
    {
        cout << "input in input.txt\n";
        ifstream input_in("input.txt");
        input_in.getline(message, 99);
        cout << message << endl;
        ofstream encrypt_out("encrypt.txt");
        for (int i = 0; message[i] != '\0'; i++)
        {
            message[i]++;
            encrypt_out << message[i];
        }
        cout << "Output in encrypt.txt\n";
        cout << message << endl;
    }
    else
    {
        cout << "input in encrypt.txt\n";
        ifstream encrypt_in("encrypt.txt");
        encrypt_in.getline(message, 99);
        cout << message << endl;
        ofstream input_out("input.txt");
        for (int i = 0; message[i] != '\0'; i++)
        {
            message[i]--;
            input_out << message[i];
        }
        cout << "Output in input.txt\n";
        cout << message << endl;
    }

    return 0;
}