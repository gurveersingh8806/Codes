#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int data){
        size++;
        int idx = size;
        arr[idx] = data;

        while(idx > 1){

            if(arr[idx] > arr[idx/2]){
                swap(arr[idx],arr[idx/2]);
                idx/= 2;
            }
            else return;
        }
    }

    void print(){
        for (int i=1; i<= size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteroot(){
    if(size == 0){
        cout << "Heap is empty\n";
        return;
    }

    arr[1] = arr[size];
    size--;

    int idx = 1;

    while(idx <= size){
        int left = 2 * idx;
        int right = 2 * idx + 1;
        int largest = idx;

        if(left <= size && arr[left] > arr[largest])
            largest = left;

        if(right <= size && arr[right] > arr[largest])
            largest = right;

        if(largest != idx){
            swap(arr[idx], arr[largest]);
            idx = largest;
        }
        else
            return;
    }



    }
};

void heapify(int arr[],int n,int i){

    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[left] > arr[largest] ){
        largest = left;
    }
    if(right <= n && arr[right] > arr[largest] ){
        largest = right;
    }
    
    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
    else return;
}

void heapsort(int arr[],int n){

    int size = n;
    while(size>1){

        swap(arr[1],arr[size]);
        size--;

        heapify(arr,size,1);

    }
}

int main(){ 

    heap h;
    h.insert(10);
    h.insert(100);
    h.insert(14);
    h.insert(28);
    h.insert(55);
    h.insert(54);
    h.insert(51);
    h.insert(34);
    h.insert(77);
    h.insert(1001);
 //   h.print();
   // h.deleteroot();
   // h.print();

    int arr[8] ={-1,14,45,3,66,445,22,30};
    int n = 7;

    for(int i= n/2;i>0;i--){
        heapify(arr,n,i);
    }
    for(int i=1;i<=n;i++)
    cout << arr[i] << " ";
    cout << endl;

    heapsort(arr,n);

    for(int i=1;i<=n;i++)
    cout << arr[i] << " ";
    cout << endl;




}

