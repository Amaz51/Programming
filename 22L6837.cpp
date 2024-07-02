#include<iostream>
#include<string>
using namespace std;
class MyString
{
private:
	char* str;
	int length;						
	char GetStringFromBuffer;		
	char Concatenate;

public:
	
	MyString operator+(const MyString);
	MyString& operator=(const MyString&);
	bool operator<(MyString);

	MyString()
	{
		str = NULL;
		length = 1;
	}
	char& operator[](int);
	MyString operator()(int, int);
	friend ostream& operator<<(ostream& COUT, const MyString& myString)
	{
		if (myString.str != nullptr) {
			COUT << myString.str;

		}
		return COUT;
	}
	friend istream& operator>> (istream& CIN, MyString& Mystring)
	{

		char temp[1000];
		int i = 0;
		char ch;
		while ((ch = CIN.get()) != '\n')
		{
			temp[i++] = ch;
		}
		temp[i] = '\0';
		Mystring.length = i + 1; // add 1 for the null character
		Mystring.str = new char[Mystring.length];
		for (int j = 0; j < i; j++)
		{
			Mystring.str[j] = temp[j];
		}
		Mystring.str[i] = '\0';
		return CIN;
	}
	bool operator!() {
		return (str == nullptr || length <= 1);
	}
	void myStringCopy(char* dest, const char* src)
	{
		int i = 0;
		while (src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	//~MyString() {
	//    delete[] str; // release the memory allocated for the string
	//    length = 0; // set the length to 0 to indicate that the string is no longer valid
	//}
};
//--------------------------Add your code here----------------------
char& MyString ::operator[](int i)
{
	return str[i];
}
MyString MyString::operator()(int start, int end)
{
	int newLength = end - start + 2;
	char* newStr = new char[newLength];
	for (int i = 0; i < newLength - 1; i++) {
		newStr[i] = str[start + i];
	}
	newStr[newLength - 1] = '\0';

	MyString result;
	result.length = newLength;
	result.str = newStr;

	return result;
}

MyString MyString::operator+(MyString other)
{
	MyString result;
	result.length = length + other.length - 1; // subtracting 1 as the last character is a null character
	result.str = new char[result.length];
	myStringCopy(result.str, str);
	myStringCopy(result.str + length - 1, other.str);
	return result;
}

bool MyString:: operator<(MyString other)
{
	int i = 0;
	while (str[i] != '\0' && other.str[i] != '\0')
	{
		if (str[i] < other.str[i])
			return true;
		else if (str[i] > other.str[i])
			return false;
		i++;
	}
	if (str[i] == '\0' && other.str[i] != '\0')
		return true;
	return false;
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		delete[] str;
		length = other.length;
		str = new char[length];
		myStringCopy(str, other.str);
	}
	return *this;
}


//-------------DO_NOT_CHANGE REGION starts below---------------------
int main()
{
	MyString str1, str2, str3, str4; //Default constructor will make a string of lenght 1 having null character only i.e.empty string
	if (!str1)
	{
		cout << "String 1 is Empty.\n";
		cout << "Str 1 = " << str1 << endl << endl << endl;

	}
	cout << "Enter String 1:\t";
	cin >> str1;
	cout << "Enter String 2:\t";
	cin >> str2;
	cout << "\n\n\nUser Entered:\n";
	cout << "String 1 = " << str1 << endl;
	cout << "String 2 = " << str2 << endl << endl << endl;
	//What is following code testing?
	cout << "Before str1 = str1; str1 = " << str1 << endl;
	str1 = str1;
	cout << "After str1 = str1, str1 = " << str1 << endl << endl << endl;
	cout << "Before str4 = str3 = str1+str2\n";
	cout << "str1 = " << str1 << endl;
	cout << "str2 = " << str2 << endl;
	cout << "str3 = " << str3 << endl;
	cout << "str4 = " << str4 << endl;
	str4 = str3 = str1 + str2;
	cout << "\n\n\nAfter str4 = str3 = str1+str2\n";
	cout << "str1 = " << str1 << endl;
	cout << "str2 = " << str2 << endl;
	cout << "str3 = " << str3 << endl;
	cout << "str4 = " << str4 << endl;
	cout << "\n\n\nEnter String 3:\t";
	cin >> str3;
	cout << "\n\n\nEnter String 4:\t";
	cin >> str4;
	cout << "\n\n\nstr3 = " << str3 << endl;
	cout << "str4 = " << str4 << endl;
	if (str3 < str4)
		cout << "String 3 is Less than String 4.\n";
	else
		cout << "String 3 is NOT Less than String 4.\n";
	MyString str5 = str1 + str2;
	cout << "\n\n\nStr5:\t" << str5 << endl;
	cout << "Str5[7]:\t" << str5[7] << endl; //Function Call: str5.operator[](7).
	str5[7] = '$';
	cout << "\n\nStr5:\t" << str5 << endl;
	cout << "\n\n\nstr5(5, 10):\t" << str5(5, 10) << endl;// Substring of lenght 10	starting from index 5.Function Call str5.operator()(5, 10) Let the returned MyString or	char* leak
}
//-------------End of DO_NOT_CHANGE REGION---------------------