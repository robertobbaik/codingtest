#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

class Heap
{
public:
    void make_heap()
    {
        int index = heap.size() - 1;

        while(index > 0)
        {
            int parent_index = (index  + 1) / 2;

            if(heap[index] > heap[parent_index])
            {
                swap(heap[index], heap[parent_index]);
                index = parent_index;
            }
            else
            {
                break;
            }
        }
    }

    void sort_heap()
    {

    }

private:
    vector<int> heap;
};

int main(void)
{
    vector<int> v = {1, 9, 7, 2, 5, 4, 3, 8, 6};
    
    make_heap(v.begin(), v.end());

    for (int n : v)
    {
        cout << n << " ";
    }
    cout << endl;

    sort_heap(v.begin(), v.end());

    for (int n : v)
    {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}