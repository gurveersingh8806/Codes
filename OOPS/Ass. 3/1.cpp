#include <iostream>
using namespace std;

int main() {
    int ballot[5] = {0}; 

    int n;
    cout << "Enter the number of votes: ";
    cin >> n;

    int spoilt = 0;

    cout << "Enter the votes (candidate numbers 1-5):" << endl;
    for (int i = 0; i < n; i++) {
        int vote;
        cin >> vote;

        if (vote >= 1 && vote <= 5) {
            ballot[vote - 1]++; 
        } 
        else {
            spoilt++;
        }
    }

    cout << "\nResults:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Candidate " << i + 1 << " got " << ballot[i] << " votes." << endl;
    }

    cout << "Total number of spoilt votes: " << spoilt << endl;

    return 0;
}
