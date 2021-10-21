#include <iostream>
template<typename... Values>class tup;

template<>class tup<> {};
template<typename Head, typename...Tail>

class tup<Head, Tail...> {
		typedef tup<Tail...>composited;
	protected:
		composited m_tail;
		Head m_head;
	public:

		tup() {}
		tup(Head v, Tail... vtail): m_tail(vtail...), m_head(v) {}
		Head head() {
			return m_head;
		}
		composited &tail() {
			return m_tail;
		}
};

int main() {
	tup<int, float, std::string>it1(41, 6.3, "nico");
	std::cout << sizeof(it1) << std::endl;
	std::cout << it1.head() << std::endl;
	std::cout << it1.tail().head() << std::endl;
	return 0;
}