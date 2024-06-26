//#include <iostream>
//
//class IntervalHeap {
//private:
//    int hsize;       // Number of elements in heap
//    int maxsize;     // Size of the array
//    int** h;         // Array to store the lower and higher ends of closed intervals
//
//public:
//    // Constructor
//    IntervalHeap(int s = 100) {
//        maxsize = s;
//        hsize = 0;
//        h = new int* [2];
//        h[0] = new int[maxsize];  // Store the lower end of the closed interval
//        h[1] = new int[maxsize];  // Store the higher end of the closed interval
//    }
//
//    // Destructor
//    ~IntervalHeap() {
//        delete[] h[0];
//        delete[] h[1];
//        delete[] h;
//    }
//
//    // Function to insert an element into the interval heap
//    void Insert(int d) {
//        // Ensure there is space in the interval heap
//        if (hsize < maxsize) {
//            // If the number of elements is even, create a new node
//            if (hsize % 2 == 0) {
//                // New node with both ends equal to the data element
//                h[0][hsize] = d;
//                h[1][hsize] = d;
//
//                // Restore the heap properties by adjusting the elements if needed
//                int parent = (hsize - 1) / 2;
//                int current = hsize;
//
//                // Swap elements to maintain min heap property for left ends
//                while (current > 0 && h[0][parent] > h[0][current]) {
//                    std::swap(h[0][parent], h[0][current]);
//                    current = parent;
//                    parent = (current - 1) / 2;
//                }
//
//                // Swap elements to maintain max heap property for right ends
//                while (current > 0 && h[1][parent] < h[1][current]) {
//                    std::swap(h[1][parent], h[1][current]);
//                    current = parent;
//                    parent = (current - 1) / 2;
//                }
//
//                ++hsize;
//            }
//            else {
//                // The last node is not full, update its higher end
//                h[1][hsize - 1] = d;
//                ++hsize;
//            }
//        }
//        else {
//            std::cout << "Interval heap is full. Cannot insert element." << std::endl;
//        }
//    }
//
//    // Function to update an element in the interval heap
//    void Update(int index, int newElement) {
//        // Ensure the index is valid
//        if (index >= 0 && index < hsize) {
//            // Update the element at the specified index
//            h[0][index] = newElement;
//            h[1][index] = newElement;
//
//            // Maintain heap properties by adjusting the elements if needed
//            int current = index;
//
//            // Swap elements to maintain min heap property for left ends
//            while (current > 0 && h[0][(current - 1) / 2] > h[0][current]) {
//                std::swap(h[0][(current - 1) / 2], h[0][current]);
//                current = (current - 1) / 2;
//            }
//
//            // Swap elements to maintain max heap property for right ends
//            while (current > 0 && h[1][(current - 1) / 2] < h[1][current]) {
//                std::swap(h[1][(current - 1) / 2], h[1][current]);
//                current = (current - 1) / 2;
//            }
//        }
//        else {
//            std::cout << "Invalid index for update." << std::endl;
//        }
//    }
//
//    // Function to delete an element from the interval heap
//    void Delete(int index) {
//        // Ensure the index is valid
//        if (index >= 0 && index < hsize) {
//            // Swap the element at the specified index with the last element
//            std::swap(h[0][index], h[0][hsize - 1]);
//            std::swap(h[1][index], h[1][hsize - 1]);
//
//            // Adjust the heap size
//            --hsize;
//
//            // Maintain heap properties by adjusting the elements if needed
//            int current = index;
//
//            // Swap elements to maintain min heap property for left ends
//            while (current < hsize) {
//                int leftChild = 2 * current + 1;
//                int rightChild = 2 * current + 2;
//                int minIndex = current;
//
//                if (leftChild < hsize && h[0][leftChild] < h[0][minIndex]) {
//                    minIndex = leftChild;
//                }
//
//                if (rightChild < hsize && h[0][rightChild] < h[0][minIndex]) {
//                    minIndex = rightChild;
//                }
//
//                if (minIndex != current) {
//                    std::swap(h[0][current], h[0][minIndex]);
//                    current = minIndex;
//                }
//                else {
//                    break;
//                }
//            }
//
//            // Swap elements to maintain max heap property for right ends
//            current = index;
//
//            while (current < hsize) {
//                int leftChild = 2 * current + 1;
//                int rightChild = 2 * current + 2;
//                int maxIndex = current;
//
//                if (leftChild < hsize && h[1][leftChild] > h[1][maxIndex]) {
//                    maxIndex = leftChild;
//                }
//
//                if (rightChild < hsize && h[1][rightChild] > h[1][maxIndex]) {
//                    maxIndex = rightChild;
//                }
//
//                if (maxIndex != current) {
//                    std::swap(h[1][current], h[1][maxIndex]);
//                    current = maxIndex;
//                }
//                else {
//                    break;
//                }
//            }
//        }
//        else {
//            std::cout << "Invalid index for deletion." << std::endl;
//        }
//    }
//
//    // Function to display the current state of the interval heap
//    void Display() {
//        std::cout << "Interval Heap:" << std::endl;
//        for (int i = 0; i < hsize; ++i) {
//            std::cout << "(" << h[0][i] << "," << h[1][i] << ") ";
//        }
//        std::cout << std::endl;
//    }
//};
//
//int main() {
//    // Example usage
//    IntervalHeap intervalHeap;
//
//    // Insert elements into the interval heap
//    intervalHeap.Insert(2);
//    intervalHeap.Insert(3);
//    intervalHeap.Insert(4);
//    intervalHeap.Insert(5);
//
//    // Display the interval heap
//    intervalHeap.Display();
//
//    // Update an element
//    intervalHeap.Update(2, 10);
//    intervalHeap.Display();
//
//    // Delete an element
//    intervalHeap.Delete(1);
//    intervalHeap.Display();
//
//    return 0;
//}
