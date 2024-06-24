#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int power(int base, int exp) {

	if (exp == 0) {
		return 1;
	}
	int result = base;
	for (int i = 1; i < exp; i++) {
		result *= base;
	}

	return result;
}
class Bigint {
	int v[5];
public:
	Bigint() {
		for (int i = 0; i < 5; i++) {
			v[i] = 0;
		}
	}
	Bigint(int x0) {
		v[0] = x0;
		for (int i = 1; i < 5; i++) {
			v[i] = 0;
		}
	}
	Bigint(int x0, int x1) {
		v[0] = x0;
		v[1] = x1;
		for (int i = 2; i < 5; i++) {
			v[i] = 0;
		}
	}
	Bigint(int x0, int x1, int x2) {
		v[0] = x0;
		v[1] = x1;
		v[2] = x2;
		for (int i = 3; i < 5; i++) {
			v[i] = 0;
		}
	}
	Bigint(int x0, int x1, int x2, int x3) {
		v[0] = x0;
		v[1] = x1;
		v[2] = x2;
		v[3] = x3;
		v[4] = 0;

	}
	Bigint(int x0, int x1, int x2, int x3, int x4) {
		v[0] = x0;
		v[1] = x1;
		v[2] = x2;
		v[3] = x3;
		v[4] = x4;

	}


	friend ostream& operator<<(ostream& str, const Bigint& num) {
		int ind = 4;
		for (; ind > 0 && num.v[ind] == 0;)ind--;
		str << num.v[ind];
		for (int i = ind - 1; i >= 0; i--) {
			str << setfill('0') << setw(9) << num.v[i];
		}return str;
	}

	friend istream& operator>>(istream& strm, Bigint& num) {
		string input;

		strm >> input;
		int len = 0;
		for (int i = 0; input[i] != '\0'; i++) {
			len++;
		}

		int i = 0;
		while (i < len&& input[i] == '0')i++;  //indexes with zero value.

		if (i == len) {
			num = Bigint();
			return strm;
		}
		else {
			int j = len - 1;

			for (int k = 0; k <= 4 && j > i - 1; k++) {
				int digits = 0, l = 0;

				while (l < 9 && j >= i)
				{
					int inte = (input[j] - '0');
					digits += (inte * power(10, l));
					j--;
					l++;
				}
				num.v[k] = digits;
			}
		}

		return strm;
	}



	bool operator<(const Bigint& other) const {
		for (int i = 0; i < 5; i++) {
			if (v[i] < other.v[i]) {
				return true;
			}
			else if (other.v[i] < v[i]) {
				return false;
			}
		}return false;
	}
	bool operator>(const Bigint& other) const {
		for (int i = 0; i < 5; i++) {
			if (v[i] > other.v[i]) {
				return 1;
			}
			else if (v[i] < other.v[i]) {
				return false;

			}
		}				return false;

	}
	bool operator<=(const Bigint& other) const {
		for (int i = 0; i < 5; i++) {
			if (v[i] <= other.v[i]) {
				return true;
			}
			else if (other.v[i] <= v[i]) {
				return false;

			}
		}				return false;

	}
	bool operator>=(const Bigint& other) const {
		for (int i = 0; i < 5; i++) {
			if (v[i] >= other.v[i]) {
				return true;
			}
			else if (other.v[i] >= v[i]) {
				return 0;
			}
		}				return false;

	}
	bool operator==(const Bigint& other) const {
		for (int i = 0; i < 5; i++) {
			if (v[i] == other.v[i]) {
				return true;
			}
			else {
				return 0;
			}
		}return 0;
	}
	bool operator!=(const Bigint& other) const {
		for (int i = 0; i < 5; i++) {
			if (v[i] != other.v[i]) {
				return true;
			}
			else {
				return 0;
			}
		}return 0;
	}
	Bigint operator-(const Bigint& other) const {
		Bigint output;
		int borrow = 0, diff = 0;
		for (int i = 0; i < 5; i++) {
			diff = v[i] - other.v[i] - borrow;
			if (diff < 0) {
				diff += power(10, 9);
				borrow = 1;
			}
			else {
				borrow = 0;
			}
			output.v[i] = diff;
		}return output;
	}
	Bigint operator+(const Bigint& other) const {
		Bigint output;
		int carry = 0, sum = 0;
		for (int i = 0; i < 5; i++) {
			sum = v[i] + other.v[i] + carry;
			output.v[i] = sum % (power(10, 9));
			carry = sum / (power(10, 9));
		}return output;
	}
};


int main()
{
	Bigint x;
	Bigint y;

	if (x == y) cout << x << " is equal to " << y << "." << endl;
	if (x != y) cout << x << " is not equal to " << y << "." << endl;
	if (x > y) cout << x << " is larger than " << y << "." << endl;
	if (x >= y) cout << x << " is larger than or equal to " << y << "." << endl;
	if (x < y) cout << x << " is smaller than " << y << "." << endl;
	if (x <= y) cout << x << " is smaller than or equal to " << y << "." << endl;

	Bigint x1(123456789);
	Bigint y1(111111111);

	if (x1 == y1) cout << x1 << " is equal to " << y1 << "." << endl;
	if (x1 != y1) cout << x1 << " is not equal to " << y1 << "." << endl;
	if (x1 > y1) cout << x1 << " is larger than " << y1 << "." << endl;
	if (x1 >= y1) cout << x1 << " is larger than or equal to " << y1 << "." << endl;
	if (x1 < y1) cout << x1 << " is smaller than " << y1 << "." << endl;
	if (x1 <= y1) cout << x1 << " is smaller than or equal to " << y1 << "." << endl;

	Bigint x2(123456789, 111, 111, 111, 111);
	Bigint y2(111111111, 111, 111, 111, 111);

	if (x2 == y2) cout << x2 << " is equal to " << y2 << "." << endl;
	if (x2 != y2) cout << x2 << " is not equal to " << y2 << "." << endl;
	if (x2 > y2) cout << x2 << " is larger than " << y2 << "." << endl;
	if (x2 >= y2) cout << x2 << " is larger than or equal to " << y2 << "." << endl;
	if (x2 < y2) cout << x2 << " is smaller than " << y2 << "." << endl;
	if (x2 <= y2) cout << x2 << " is smaller than or equal to " << y2 << "." << endl;

	Bigint x3(123456789, 12, 12);
	Bigint y3(111111111, 13, 12);

	if (x3 == y3) cout << x3 << " is equal to " << y3 << "." << endl;
	if (x3 != y3) cout << x3 << " is not equal to " << y3 << "." << endl;
	if (x3 > y3) cout << x3 << " is larger than " << y3 << "." << endl;
	if (x3 >= y3) cout << x3 << " is larger than or equal to " << y3 << "." << endl;
	if (x3 < y3) cout << x3 << " is smaller than " << y3 << "." << endl;
	if (x3 <= y3) cout << x3 << " is smaller than or equal to " << y3 << "." << endl;

	Bigint x4(999999999, 999999999, 999999999, 20);

	cout << x4 << "+1 = " << x4 + 1 << endl;

	Bigint y4(000000000, 000000000, 000000000, 000000000, 0000000001);

	cout << y4 << "-1 = " << y4 - 1 << endl;

	cout << x1 + x2 + x3 + x4 - y3 + 1 << endl;

	for (int i = 0; i < 3; i++) {
		Bigint x5, y5;
		cin >> x5 >> y5;
		cout << "x = " << x5 << endl;
		cout << "y = " << y5 << endl;

		cout << "x+y=" << x5 + y5 << endl;
		cout << "x-y=" << x5 - y5 << endl;
	}
}