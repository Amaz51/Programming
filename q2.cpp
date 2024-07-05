#include<iostream>

using namespace std;

int MajorityElement(int A[], int n, int low, int high) {

	if (low == high) { return A[low]; }
	int mid = (low + high) / 2;
	int lmajor = MajorityElement(A, n, low, mid);
	int rmajor = MajorityElement(A, n, mid+1, high);
	if (lmajor == rmajor) {
		return lmajor;
	}
	int lcount = 0, rcount = 0;
	for (int i = low; i < high; i++) {
		if (A[i] == lmajor) { lcount++; }
		else if (A[i] == rmajor) { rcount++; }
	}
		if (rcount > mid) {
			return rmajor;
		}
		else if (lcount > mid) {
			return lmajor;
		}
		else {
			return -1;
		}

	

}
int Noofrotations(int A[], int lt, int rt) {
	if (lt == rt) { return 0; }
	while (lt < rt) {
		int mid = (lt + rt) / 2;
		if (A[mid] > A[lt]) {
			return Noofrotations(A, lt, mid);
			lt++;
		}
		else {
			return Noofrotations(A, mid+1,rt);
		}
	}
}
int main() {

}

