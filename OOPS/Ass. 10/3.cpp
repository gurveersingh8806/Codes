#include <iostream>
using namespace std;

class Sports {
protected:
    int score;   // sports score

public:
    void inputSports() {
        cout << "Enter sports score: ";
        cin >> score;
    }

    void displaySports() const {
        cout << "Sports Score: " << score << endl;
    }
};

class Exam {
protected:
    int marks;   // exam marks

public:
    void inputExam() {
        cout << "Enter exam marks: ";
        cin >> marks;
    }

    void displayExam() const {
        cout << "Exam Marks: " << marks << endl;
    }
};

class Result : public Sports, public Exam {
private:
    int total;

public:
    void calculate() {
        total = score + marks;
    }

    void displayResult() const {
        displaySports();
        displayExam();
        cout << "Total Performance Score: " << total << endl;
    }
};

int main() {
    Result r;
    r.inputSports();
    r.inputExam();
    r.calculate();
    r.displayResult();

    return 0;
}
