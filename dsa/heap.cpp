#include <iostream>
using namespace std;

class Heap
{
    int arr[100];
    int size;

public:
    Heap()
    {
        size = 0;
        arr[0] = -1;
    }

    void insert(int data)
    {
        size++;
        int index = size;
        arr[index] = data;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[index] > arr[parent])
                swap(arr[index], arr[parent]);
            else
                return;
            index = parent;
        }
    }

    void print()
    {
        cout << endl;
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteFromHeap()
    {
        if (size == 0)
            return;

        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i <= size)
        {
            int left = 2 * i, right = 2 * i + 1;
            int largest = i;

            if (left <= size && arr[left] > arr[largest]) largest = left;
            
            if (right <= size && arr[right] > arr[largest]) largest = right;

            if (largest != i){
                swap(arr[i], arr[largest]);
                i = largest;
            }else return;
        }
    }
};

int main()
{
    Heap h;
    h.insert(2);
    h.insert(3);
    h.insert(4);
    h.insert(1);
    h.insert(5);
    h.insert(6);

    h.print();

    h.deleteFromHeap();

    h.print();

    h.deleteFromHeap();

    h.print();

    return 0;
}