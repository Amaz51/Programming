//#include<iostream>
//using namespace std;
//int main() {
//	//Write a program in C to count the total number of alphabets, digits, and
//	//special characters in a string.
//	int alphabet =0, digit=0, spc=0;
//	char a[100];
//	cout << "Enter : ";
//	cin.getline(a, 100);
//	for (int i = 0; a[i] != '\0'; i++) {
//		if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z')) {
//			alphabet++;
//		}
//		else if (a[i] >= '0' && a[i] <= '9') {
//			digit++;
//		}
//		else {
//			for (int j = 0; a[j] != '\0'; j++) {
//				a[j] = a[j + 1];
//			}
//			
//		}
//		cout << a[i];
//	}
//	cout << endl<<"Total Alphabets are : " << alphabet << endl << "Total digits are : " << digit << endl << "Total special characters are : " << spc << endl;
//}