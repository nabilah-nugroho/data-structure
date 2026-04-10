#include <iostream>
#include <string>
using namespace std;

class NilaiMatkul{
    public:
        string nim;
        string nama;
        float nilai;
};

class Queue{
    private:
        int first;
        int last;
        NilaiMatkul data[10];
    public:
        Queue(){
            first = -1;
            last = -1;
        }

    bool isEmpty(){
        return first == -1;
    }

    bool isFull(){
        return last == 9;
    }

    void add(string nim, string nama, float nilai){
        if(isEmpty()){
            first = last = 0;
        } else if(!isFull()) {
            last++;
        } else {
            cout << "Queue penuh" << endl;
            return;
        }
        data[last].nim = nim;
        data[last].nama = nama;
        data[last].nilai = nilai;
    }

    void del(){
        if (isEmpty()){
            cout << "Queue Kosong" << endl;
            return;
        }
        if(last==0){
            first = last = -1;
        } else {
            for(int i = first + 1; i <= last; i++){
                data[i-1] = data[i];
            }
            last--;
        }
    }

    void printQueue(){
        if(isEmpty){
            cout << "========ISI QUEUE=========" << endl;
            for(int i = last; i >= first; i--){
                cout << "=============================" << endl;
                cout << "elemen ke- : " << i << endl;
                cout << "nim    : " << data[i].nim << endl;
                cout << "nama   : " << data[i].nama << endl;
                cout << "nilai  : " << data[i].nilai << endl;
                cout << "==============================" << endl;
            }
        } else {
            cout << "Queue Kosong" << endl;
        }
    }
};

int main() {
    Queue q;
    q.printQueue();

    cout << "========operasi add========" << endl;
    q.add("123456781", "Nana", 64.75);
    q.add("123456782", "Banu", 75.11);
    q.add("123456783", "Dea", 84.43);
    cout << "===========================" << endl;

    q.printQueue();

    cout << "========operasi del========" << endl;
    q.del();
    q.printQueue();

    return 0;
}