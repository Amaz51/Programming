//#include<iostream>
//using namespace std;
//
//void insertionsortt(int a[], int b) {
//
//	for (int i = 0; i < b; i++) {
//		int curren = a[i];
//		int j = i - 1;
//		while (a[j] > curren && j >= 0) {
//			a[j + 1] = a[j];
//			j--;
//		}
//		a[j + 1] = curren;
//	}
//	cout << "The array is : ";
//		for (int k = 0; k < b; k++)
//		{
//			cout << a[k] <<" ";
//		}
//	}
//
//int main() {
//	int n,arr[100];
//	cout << "Enter the size of array : ";
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//	insertionsortt(arr,n);
//
//}