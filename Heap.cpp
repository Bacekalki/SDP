#include <iostream>
#include <vector>

class MaxHeap {
private:
    std::vector<int> heap;

    void heapify(int index) {
        int size = heap.size();
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] > heap[largest])
            largest = left;

        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            heapify(largest);
        }
    }

public:
    MaxHeap() {}

    void insert(int value) {
        heap.push_back(value);
        int index = heap.size() - 1;

        while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
            std::swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    int extractMax() {
        if (heap.empty()) {
            std::cerr << "Heap is empty!" << std::endl;
            return -1;
        }

        int max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);

        return max;
    }

    int peek() const {
        if (heap.empty()) {
            std::cerr << "Heap is empty!" << std::endl;
            return -1;
        }

        return heap[0];
    }

    void display() const {
        for (int value : heap) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MaxHeap maxHeap;

    maxHeap.insert(5);
    maxHeap.insert(3);
    maxHeap.insert(8);
    maxHeap.insert(1);
    maxHeap.insert(10);

    std::cout << "Max Heap: ";
    maxHeap.display();

    std::cout << "Peek: " << maxHeap.peek() << std::endl;

    std::cout << "Extracted Max: " << maxHeap.extractMax() << std::endl;

    std::cout << "Max Heap after extraction: ";
    maxHeap.display();

    return 0;
}
