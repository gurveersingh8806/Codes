#include <iostream>
using namespace std;

int sum(int a, int b) {
    return a + b;
}

void sumByRef(int a, int b, int &result) {
    result = a + b;
}

int reverseNumber(int num) {
    int k = 0;
    while (num > 0) {
        int digit = num % 10;
        k = k * 10 + digit;
        num /= 10;
    }
    return k;
}

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int x, y;
    cout << "Enter two numbers: " <<endl;
    cin >> x >> y;

    int result1 = sum(x, y);
    cout << "Sum: "  << result1 << endl;

    int result2;
    sumByRef(x, y, result2);
    cout << "Sum using call by reference: " << result2 << endl;

    int num;
    cout << "Enter a number to reverse: ";
    cin >> num;
    int k = reverseNumber(num);
    cout << "Reversed number: " << k << endl;

    cout << "Enter a number to check for prime: ";
    cin >> num;
    if (isPrime(num)) {
        cout << num << " is a prime number." << endl;
    } else {
        cout << num << " is not a prime number." << endl;
    }

    return 0;
}