//#include <iostream>
//
//class IntervalHeap {
//private:
//    int hsize;         // number of elements in heap
//    int maxsize;       // size of the array
//    int** h;           // 2D array to store the lower and higher ends of closed intervals
//    bool insertOnLeft; // Flag to track whether the next insert should be on the left or right
//
//public:
//    // Constructor
//   // Constructor
//    IntervalHeap(int s = 100) {
//        maxsize = s;
//        hsize = 0;
//        h = new int* [2];
//        h[0] = new int[maxsize];  // store the lower end of closed interval (min heap)
//        h[1] = new int[maxsize];  // store the higher end of closed interval (max heap)
//        insertOnLeft = true;       // Initialize to insert on the left side first
//
//        // Initialize arrays with a known value for better debugging
//        for (int i = 0; i < maxsize; ++i) {
//            h[0][i] = -1;
//            h[1][i] = -1;
//        }
//    }
//
//
//    // Destructor to free allocated memory
//    ~IntervalHeap() {
//        delete[] h[0];
//        delete[] h[1];
//        delete[] h;
//    }
//
//    void Insert(int d) {
//
//        if (hsize < maxsize) {
//            // Insert the element into the appropriate heap (left or right)
//            if (hsize % 2 == 0) {
//                h[0][hsize] = d;          // Left side (min heap)
//                h[1][hsize / 2] = h[0][hsize];  // Form a closed interval with the previous element
//            }
//            else {
//                h[1][hsize] = d;          // Right side (max heap)
//            }
//
//            // Call a function to maintain interval heap properties
//            MaintainIntervalHeapProperties(hsize);
//
//            // Increment the size of the heap
//            hsize++;
//        }
//        else {
//            std::cout << "Error: Interval heap is full." << std::endl;
//        }
//    }
//
//    // Function to update an existing closed interval in the interval heap
//    void Update(int index, int newLeft, int newRight) {
//        if (index >= 0 && index < hsize) {
//            // Update the interval
//            h[0][index] = newLeft;
//            h[1][index] = newRight;
//
//            // Call a function to maintain interval heap properties
//            MaintainIntervalHeapProperties(index);
//        }
//        else {
//            std::cout << "Error: Invalid index for update." << std::endl;
//        }
//    }
//
//    // Function to delete a closed interval from the interval heap
//    void Delete(int index) {
//        if (index >= 0 && index < hsize) {
//            // Replace the interval to be deleted with the last interval
//            h[0][index] = h[0][hsize - 1];
//            h[1][index] = h[1][hsize - 1];
//
//            // Decrement the size of the heap
//            hsize--;
//
//            // Call a function to maintain interval heap properties
//            MaintainIntervalHeapProperties(index);
//        }
//        else {
//            std::cout << "Error: Invalid index for deletion." << std::endl;
//        }
//    }
//
//    // Function to print the contents of the interval heap
//    void Display() {
//        std::cout << "Interval Heap: ";
//        for (int i = 0; i < hsize; ++i) {
//            std::cout << "(" << h[0][i] << "," << h[1][i] << ") ";
//        }
//        std::cout << std::endl;
//    }
//
//private:
//    // Function to maintain interval heap properties after insertion, update, or deletion
//    void MaintainIntervalHeapProperties(int currentIndex) {
//        while (currentIndex > 0) {
//            int parentIndex = (currentIndex - 1) / 2;
//
//            // Check whether the current node violates the interval heap properties
//            if (currentIndex % 2 == 0) {
//                // Even index, right element (max heap property)
//                if (h[1][currentIndex] > h[1][parentIndex]) {
//                    std::swap(h[0][currentIndex], h[0][parentIndex]);
//                    std::swap(h[1][currentIndex], h[1][parentIndex]);
//                    currentIndex = parentIndex;
//                }
//                else {
//                    break;
//                }
//            }
//            else {
//                // Odd index, left element (min heap property)
//                if (h[0][currentIndex] < h[0][parentIndex]) {
//                    std::swap(h[0][currentIndex], h[0][parentIndex]);
//                    std::swap(h[1][currentIndex], h[1][parentIndex]);
//                    currentIndex = parentIndex;
//                }
//                else {
//                    break;
//                }
//            }
//        }
//    }
//};
//
//int main() {
//    // Example usage of IntervalHeap
//    IntervalHeap intervalHeap(100);
//
//    // Insert intervals alternately
//    intervalHeap.Insert(2);
//    intervalHeap.Insert(30);
//    intervalHeap.Insert(3);
//    intervalHeap.Insert(17);
//
//    // Display the interval heap
//    intervalHeap.Display();
//
//    // Update interval at index 2
//    intervalHeap.Update(2, 5, 12);
//    intervalHeap.Display();
//
//    // Delete interval at index 1
//    intervalHeap.Delete(1);
//    intervalHeap.Display();
//
//    return 0;
//}
