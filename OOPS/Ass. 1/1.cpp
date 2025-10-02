#include<iostream>
#include<stdlib.h>
using namespace std;

void insertElement(int arr[], int n, int pos, int val){

    int i = 0;
    arr[n] = 0;

    while(n-i > pos){
        arr[n-i] = arr[n-i-1];
        i++;
    }
    arr[pos] = val;
    return;

}

void deleteElement(int arr[],int n,int pos){

    int i = pos;

    while(i< n){
        arr[i] = arr[i+1];
        i++;
    }

    return;
}

void searchElement(int arr[], int n, int val) {
    int s = 0, e = n - 1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == val) {
            cout << "Element found at index - " << mid << endl;
            return;
        } else if (arr[mid] < val) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    cout << "Element not found." << endl;
}


void updateElement(int arr[], int n, int pos, int val) {
    if (pos >= 0 && pos < n) {
        arr[pos] = val;
    } else {
        cout << "Invalid position." << endl;
    }
}

void sort(int arr[], int n){

    for(int i =0; i<n; i++){
        for(int j = i+1; j<n;j++){
            int temp =0;
            if(arr[i]>arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    return;


}


int main(){

    int arr[1000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    cin >> arr[i];

    int c =0;
    while(1){

        cout << "what do you want to do?"<< endl;
        cout<< "(i)Insert an element at a specific position" << endl;
        cout <<"(ii) Delete an element at a specific position." << endl;
        cout << "(iii) Search for an element." << endl;
        cout << "(iv) Update the value of an element." << endl;
        cout << "(v) Sort the array in ascending order."<< endl;
        cout << "(vi) Display the array elements." << endl;
        cout << "(vii) exit" << endl;

        cin >> c;
        switch(c){
            case 1:{
                int pos;
                int val;
                cout << "Enter the position where you want to insert the element: ";
                cin >> pos;
                cout << "Enter the element you want to insert: ";
                cin >> val;
                insertElement(arr, n, pos, val);
                n++;
                break;
            }
            case 2:{
                int pos;
                cout << "Enter the position where you want to delete the element: ";
                cin >> pos;
                deleteElement(arr, n, pos);
                n--;
                break;
                }
            case 3:{
                int val;
                cout << "Enter the element you want to search: ";
                cin >> val;
                searchElement(arr, n, val);
                break;
                }
            case 4:{
                int pos;
                int val;
                cout << "Enter the position of the element you want to update: ";
                cin >> pos;
                cout << "Enter the new value of the element: ";
                cin >> val;
                updateElement(arr, n, pos, val);
                break;
        }
        case 5:{
            sort(arr, n);
            break;
            }
        case 6:{
            for (int i =0; i<n; i++)
                cout << arr[i] << " ";
            cout << endl;
            break;
        }
        case 7 : {
            cout << "End of code." << endl;
            exit(0);
        }
    }
}
}