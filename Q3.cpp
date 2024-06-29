#include<iostream>
using namespace std;
int main() {
	int j, n, arr[100], key;
	cout << "Enter the size of array : ";
	cin >> n;
	cout << "Enter the array elements : ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 2; i < n; i++) {
		j = i - 2;
		key = arr[i];
		if ((i + 1) % 2 == 1) {
			while (key >= arr[j] && j >= 0) {
				arr[j + 2] = arr[j];
				j = j - 2;

			}arr[j + 2] = key;
		}
		else {
			while (key <= arr[j] && j >= 0) {
				arr[j + 2] = arr[j];
				j = j - 2;

			}arr[j + 2] = key;
		}
	}
	cout << "The sorted array is : ";
	for (int k = 0; k < n; k++) {
		cout << arr[k] << " ";
	}
	cout << endl;
	
}