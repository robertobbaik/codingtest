#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class MaxHeap
{
public:
    void enqueue(int value)
    {
        heap.push_back(value);
        bubbleUp(heap.size() - 1);
    }

    int dequeue()
    {
        int value = heap.front();
        heap.pop_front();
        bubbleUp(heap.size() - 1);
        return value;
    }

    void print()
    {
        for (int n : heap)
        {
            cout << n << " ";
        }
        cout << endl;
    }

private:
    deque<int> heap;

    void bubbleUp(int index)
    {
        while (index)
        {
            int parentIndex = (index - 1) / 2;

            if (heap[index] > heap[parentIndex])
            {
                swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }
};

int main(void)
{
    MaxHeap *maxHeap = new MaxHeap();

    maxHeap->enqueue(8);
    maxHeap->enqueue(4);
    maxHeap->enqueue(2);
    maxHeap->enqueue(1);
    maxHeap->enqueue(9);

    maxHeap->print();

    maxHeap->dequeue();
    maxHeap->print();

    maxHeap->dequeue();
    maxHeap->print();

    maxHeap->dequeue();
    maxHeap->print();

    maxHeap->dequeue();
    maxHeap->print();

    return 0;
}