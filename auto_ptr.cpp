#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Student {
	public:
		Student(string name, int age) {
			m_name = new string(name);
			m_age = age;
		}
		~Student() {
			if (m_name != NULL)
				delete m_name;
		}
		void print() {
			cout << *m_name << ":" << m_age << endl;
		}

	private:
		string *m_name;
		int m_age;
};

int main() {
	auto_ptr<Student>pStu1(new Student("lichen", 23));
	pStu1->print();
	auto_ptr<Student>pStu2(pStu1);

	pStu1->print();
	return 0;
}