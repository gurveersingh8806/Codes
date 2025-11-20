#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin;
    ofstream fout;

    char ch;

    // 1. READ ORIGINAL FILE → ENCRYPT → WRITE TO encrypted.txt
    fin.open("original.txt");
    fout.open("encrypted.txt");

    if (!fin || !fout) {
        cout << "Error opening file." << endl;
        return 1;
    }

    while (fin.get(ch)) {      // read character-by-character
        ch = ch + 1;           // encrypt by shifting ASCII +1
        fout.put(ch);          // write encrypted character
    }

    fin.close();
    fout.close();

    // 2. READ encrypted.txt → DECRYPT → WRITE TO decrypted.txt
    fin.open("encrypted.txt");
    fout.open("decrypted.txt");

    if (!fin || !fout) {
        cout << "Error opening file." << endl;
        return 1;
    }

    while (fin.get(ch)) {
        ch = ch - 1;           // decrypt by shifting ASCII -1
        fout.put(ch);          // write original character
    }

    fin.close();
    fout.close();

    cout << "Encryption and decryption completed successfully!" << endl;

    return 0;
}
