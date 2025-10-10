#include <iostream>
#include <string>
using namespace std;

class String {
    string str;

public:
    // Constructor
    String() {}
    String(string s) : str(s) {}

    // (a) Toggle function
    void toggle() {
        for (int i = 0; i < str.length(); i++) {
            if (isupper(str[i]))
                str[i] = tolower(str[i]);
            else if (islower(str[i]))
                str[i] = toupper(str[i]);
        }
    }

    // (b) Overload + operator to join two strings
    String operator+(const String &s) {
        return String(str + s.str);
    }

    // Function to display the string
    void show() const {
        cout << str;
    }
};

int main() {
    String s1("HeLLo"), s2("WoRLd");
    cout << "Original Strings:\n";
    cout << "s1 = "; s1.show(); cout << endl;
    cout << "s2 = "; s2.show(); cout << endl;

    s1.toggle();
    s2.toggle();

    cout << "\nAfter toggle():\n";
    cout << "s1 = "; s1.show(); cout << endl;
    cout << "s2 = "; s2.show(); cout << endl;

    String s3 = s1 + s2;
    cout << "\nAfter concatenation (s1 + s2): ";
    s3.show();
    cout << endl;

    return 0;
}
