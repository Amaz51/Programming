#include<iostream>
using namespace std;
class Faculty {
public:
	void virtual print() {
		cout << "Faculty class" << endl;
	}
};
class Administrator :public virtual Faculty {
public:
	void print() {
		cout << "Administrator class" << endl;
	}
};
class Teacher :public virtual Faculty {
public:
	void print() {
		cout << "Teacher class"<<endl;
	}
};
	
class AdministratorTeacher :public Administrator,public Teacher {
public:
	void print() {
		Teacher::print();
 
	}
};

int main() {
	Faculty* f[3];
	Administrator a;
	Teacher t;
	AdministratorTeacher at;
	f[0] = &a;
	f[1] = &t;
	f[2] = &at;
	for (int i = 0; i < 3; i++) {
		f[i]->print();
	}

}