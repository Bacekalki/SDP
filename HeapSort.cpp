#include <iostream>
#include <vector>

// Function to heapify a subtree rooted at index i in a vector v
void heapify(std::vector<int>& v, int size, int rootIndex) {
    int largest = rootIndex;
    int left = 2 * rootIndex + 1;
    int right = 2 * rootIndex + 2;

    if (left < size && v[left] > v[largest])
        largest = left;

    if (right < size && v[right] > v[largest])
        largest = right;

    if (largest != rootIndex) {
        std::swap(v[rootIndex], v[largest]);

        // Recursively heapify the affected sub-tree
        heapify(v, size, largest);
    }
}

void heapSort(std::vector<int>& v) {
    int n = v.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(v, n, i);

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        std::swap(v[0], v[i]);

        // Call max heapify on the reduced heap
        heapify(v, i, 0);
    }
}

void printVector(const std::vector<int>& v) {
    for (int num : v) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> numbers = {33, 55, 9, 15, 66, 1, 99, 88, 12, 11, 22, 3, 37, 6, 44, 8, 77};
    std::cout << "Original array: ";
    printVector(numbers);

    heapSort(numbers);

    std::cout << "Sorted array: ";
    printVector(numbers);

    return 0;
}
