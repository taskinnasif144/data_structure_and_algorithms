#include <bits/stdc++.h>
using namespace std;

void insertHeap(vector<int> &heap, int val)
{
    heap.push_back(val);
    int currIdx = heap.size() - 1;
    int parIdx = (currIdx - 1) / 2;

    while (currIdx > 0)
    {
        if (heap[parIdx] > heap[currIdx])
            break;
        swap(heap[parIdx], heap[currIdx]);
        currIdx = parIdx;
        parIdx = (currIdx - 1) / 2;
    }
}

void deleteHeap(vector<int> &heap)
{
    heap[0] = heap.back();
    heap.pop_back();
    int currIdx = 0;
    while (true)
    {
        int leftIdx = (currIdx * 2) + 1;
        int rightIdx = (currIdx * 2) + 2;
        int leftVal = INT_MIN, rightVal = INT_MIN;
        if (leftIdx < heap.size())
            leftVal = heap[leftIdx];
        if (rightIdx < heap.size())
            rightVal = heap[rightIdx];
        if (leftVal > rightVal && leftVal > heap[currIdx])
        {
            swap(heap[leftIdx], heap[currIdx]);
            currIdx = leftIdx;
        }
        else if (rightVal > leftVal && rightVal > heap[currIdx])
        {
            swap(heap[rightIdx], heap[currIdx]);
            currIdx = rightIdx;
        }
        else
            break;
    }
}

void printHeap(vector<int> heap)
{
    for (int x : heap)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> heap;
    int val;
    while (cin >> val)
    {
        insertHeap(heap, val);
    }

    printHeap(heap);
    deleteHeap(heap);
    printHeap(heap);
    deleteHeap(heap);
    printHeap(heap);
    deleteHeap(heap);
    printHeap(heap);
    deleteHeap(heap);
    printHeap(heap);
    deleteHeap(heap);
    printHeap(heap);
    deleteHeap(heap);
    printHeap(heap);

    return 0;
}