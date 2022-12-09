#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

class MinHeap {
    public:
        vector<int> heap;

    MinHeap(vector<int> vector) {heap = buildHeap(vector);}

    vector<int> buildHeap(vector<int> &vector){
        // Start from first parent idx (don't need to start with leaf)
        int firstParentIdx = (vector.size()-2)/2;

        for(int curIdx = firstParentIdx; curIdx >=0; curIdx--){
            siftDown(curIdx, vector.size()-1, vector);
        }

        return vector;
    }

    void siftDown(int currentIdx, int endIdx, vector<int>& heap){
        int childOneIdx = currentIdx*2+1;

        while(childOneIdx <= endIdx){
            int childTwoIdx = currentIdx*2+2 <= endIdx ? currentIdx*2+2 : -1;
            int idxToSwap;
            if(childTwoIdx != -1 && heap[childTwoIdx] < heap[childOneIdx]){
                idxToSwap = childTwoIdx;
            }else{
                idxToSwap = childOneIdx;
            }

            if(heap[idxToSwap] < heap[currentIdx]){
                swap(heap[idxToSwap], heap[currentIdx]);
                currentIdx = idxToSwap;
                childOneIdx = currentIdx*2+1;
            }
        }
    }

    void siftUp(int currentIdx, vector<int> &heap){
        int parentIdx = (currentIdx-1)/2;

        while(parentIdx>=0 && heap[parentIdx] > heap[currentIdx]){
            swap(heap[parentIdx], heap[currentIdx]);
            currentIdx = parentIdx;
            parentIdx = (currentIdx-1)/2;
        }
    }

    int peek(){
        return heap[0];
    }

    int remove(){
        swap(heap[0], heap[heap.size()-1]);

        int valueToRemove = heap.back();
        heap.pop_back();

        siftDown(0, heap.size()-1, heap);
        return valueToRemove;
    }

    void insert(int value){
        heap.push_back(value);

        siftUp(heap.size()-1, heap);
    }
};

int fibonacci(int n){
    if(n==0 || n==1){
        return 1;
    }else{
        return fibonacci(n-1)+fibonacci(n-2);
    }
}

int main(){

    auto start = chrono::high_resolution_clock::now();

    for(int i=0; i<50; i++){
        auto stop = chrono::high_resolution_clock::now();
        std::cout<<fibonacci(i)<<endl;
            auto duration = chrono::duration_cast<std::chrono::microseconds> (stop-start);

    cout<<"Execution Time for fibonacci ("<<i<<") : "<<duration.count()<<endl;
    }

    





    return 0;
}