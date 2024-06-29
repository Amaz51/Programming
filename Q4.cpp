//#include<iostream>
//using namespace std;
//void sorttt(int a[],int b) {
//	for (int i = 0; i < b; i++) {
//		for (int j = i + 1; j < b; j++) {
//			if (a[j] < a[i]) {
//				int temp = a[i];
//				a[i] = a[j];
//				a[j] = temp;
//			}
//		}
//	}cout << endl;
//	cout << "The sorted array is : ";
//	for (int h = 0; h < b; h++) {
//		cout << a[h] << " ";
//	}
//	cout << endl;
//}
//
//void insertt(int b[],int &c) {
//	cout << "Enter the number to insert in sorted array : ";
//	int num;
//	cin >> num;
//	b[c] = num;
//	cout << endl;
//	c++;
//}
//void deletee(int c[],int &d) {
//	int post;
//	cout << "Enter the index to delete in sorted array : ";
//	cin >> post;
//	for (int i = post; i < d; i++) {
//
//		c[i] = c[i + 1];
//
//	}
//	cout << endl;
//	d--;
//}
//int main()
//{
//	int arr[100], ser, n;
//	cout << "Enter the size of array : ";
//	cin >> n;
//	cout << "Enter the array elements : ";
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//	sorttt(arr, n);
//	cout << "Enter the number to search : ";
//	cin >> ser;
//	for (int i = 0; i < n; i++) {
//		if (arr[i] == ser) {
//			cout << "The number is at : " << i << endl;
//		}
//	}
//		
//	cout << endl;
//	insertt(arr, n);
//	deletee(arr, n);
//	sorttt(arr, n);
//	
//}