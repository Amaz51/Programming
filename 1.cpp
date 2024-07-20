//#include<iostream>
//using namespace std;
//int main() {
//	
//	cout << "Enter the size of array : ";
//	int n;
//	char key;
//	cin >> n;
//	char* arr = new char[n];
//	cout << "Enter the array elements : ";
//	cin.ignore();
//	cin.getline(arr, n);
//	cout << "Enter the encryption key : ";
//	cin >> key;
//	
//	int len = 0;
//	for (int i = 0; arr[i] != '\0'; i++) {
//		len++;
//	}cout << endl << "New size of array is : " << len <<endl;
//	for (int i = 0; arr[i] != '\0'; i++) {
//		int shiftarr = arr[i] + (int)key;
//		if ((arr[i] >= 'a' && arr[i] <= 'z')||(arr[i]==' ')) {
//			for (int j = 0; shiftarr > 'z'; j++) {
//				shiftarr -= 26;
//			}
//		}
//		else {
//			for (int j = 0; shiftarr > 'Z'; j++) {
//				shiftarr -= 25;
//			}
//		}
//		*(arr + i) = (char)shiftarr;
//	}cout << "The encrypted array is : ";
//	for (int i = 0; i<len; i++) {
//		cout << *(arr + i);
//	}
//	delete[] arr;
//}