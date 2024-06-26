#include <iostream>
using namespace std;
class IntervalHeap {
private:
    int hsize;
    int maxsize;
    int** h;

public:
    // Constructor
    IntervalHeap(int s = 100) {
        maxsize = s;
        hsize = 0;
        h = new int* [2];
        h[0] = new int[maxsize];  //min
        h[1] = new int[maxsize];  //max
    }

    // Destructor
    ~IntervalHeap() {
        delete[] h[0];
        delete[] h[1];
        delete[] h;
    }

    void Update(int index, int newLeft, int newRight) {
        if (index >= 0 && index < hsize) {

            h[0][index] = newLeft;
            h[1][index] = newRight;

            heapprop(index);
        }
        else {
            cout << "Index is invalid for update." << endl;
        }
    }

    void Delete(int index) {
        if (index >= 0 && index < hsize) {

            h[0][index] = h[0][hsize - 1];
            h[1][index] = h[1][hsize - 1];


            hsize--;
            heapprop(index);
        }
        else {
            cout << "Invalid Index for deletion." << endl;
        }
    }

    void Insert(int left, int right) {
        if (hsize >= maxsize) {
            cout << "Interval heap is full." << endl;
        }
        if (hsize < maxsize) {
            h[0][hsize] = left;
            h[1][hsize] = right;
            heapprop(hsize);
            hsize++;
        }

    }

    void Display() {
        cout << "Interval Heap: ";
        for (int i = 0; i < hsize; ++i) {
            cout << "(" << h[0][i] << "," << h[1][i] << ") ";
        }
        cout << endl;
    }

private:

    void heapprop(int currind) {

        while (currind > 0) {
            int parentind = (currind - 1) / 2;
            if (currind % 2 == 0) {

                if (h[1][currind] > h[1][parentind]) {
                    swap(h[0][currind], h[0][parentind]);
                    swap(h[1][currind], h[1][parentind]);
                    currind = parentind;
                }
                else {
                    break;
                }
            }
            else {
                if (h[0][currind] < h[0][parentind]) {
                    swap(h[0][currind], h[0][parentind]);
                    swap(h[1][currind], h[1][parentind]);
                    currind = parentind;
                }
                else {
                    break;
                }
            }
        }
    }
};

int main() {
    IntervalHeap Iheap(100);
    Iheap.Insert(2, 30);
    Iheap.Insert(3, 17);
    Iheap.Insert(4, 15);
    Iheap.Insert(4, 12);

    Iheap.Display();

    Iheap.Update(2, 5, 12);

    Iheap.Display();

    Iheap.Insert(3, 52);
    Iheap.Display();
    Iheap.Insert(50, 1);
    Iheap.Delete(1);
    Iheap.Display();

}
