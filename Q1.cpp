//#include<iostream>
//using namespace std;
//
//void selectionsortt(int a[], int b) {
//
//	for (int i = 0; i < b; i++) {
//		
//		for (int j = i + 1; j < b; j++) {
//			if (a[j] < a[i]) {
//				int temp = a[i];
//				a[i] = a[j];
//				a[j] = temp;
//			}
//
//		}
//	}
//	cout << "The array is : ";
//	for (int k = 0; k < b; k++)
//	{
//		cout << a[k] << " ";
//	}
//	
//}
//
//int main() {
//	int n, arr[100];
//	cout << "Enter the size of array : ";
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//	selectionsortt(arr, n);
//
//}