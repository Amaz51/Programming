#include<iostream>
using namespace std;
int main(){
	char st[100];
	cout << "Enter the string: ";
	cin.getline(st, 100);
	int count = 0;
	for (int i = 0; st[i] != '\0'; i++) {
		if (st[i] == ' ') {
			count++;
		}
	}cout << "The number of words are : "<<count+1;
}