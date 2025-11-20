#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin;
    ofstream fout;

    char ch;

    fin.open("original.txt");
    fout.open("encrypted.txt");

    if (!fin || !fout) {
        cout << "Error opening file." << endl;
        return 1;
    }

    while (fin.get(ch)) {      
        ch = ch + 1;           
        fout.put(ch);         
    }

    fin.close();
    fout.close();

    fin.open("encrypted.txt");
    fout.open("decrypted.txt");

    if (!fin || !fout) {
        cout << "Error opening file." << endl;
        return 1;
    }

    while (fin.get(ch)) {
        ch = ch - 1;           
        fout.put(ch);          
    }

    fin.close();
    fout.close();

    cout << "Encryption and decryption completed successfully!" << endl;

    return 0;
}
