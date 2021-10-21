#include <iostream>

class MyString {
	public:
		MyString(): _data(NULL), _len(0) {}
		MyString(const char *p): _len(strlen(p)) {
			_init_data(p);
		}

		MyString(const MyString &str)  {
			_init_data(str._data);
		}

		MyString(MyString &&str) noexcept: _data(str._data), _len(str._len) {
			str._len = 0;
			str._data = NULL;
		}

		MyString &operator=(const MyString &str) {
			if (this != &str) {
				if (_data)
					delete _data;
				_len = str._len;
				_init_data(str._data);
			}
			return *this;
		}
		virtual ~MyString() {
			if (_data)
				delete _data;
		}

	private:
		char *_data;
		size_t _len;
		void _init_data(const char *s) {
			_data = new char[_len + 1];
			memcpy(_data, s, _len);
			_data[_len] = '\0';
		}

};

int main() {
	MyString a("Hello");
	MyString b(a);
	return 0;
}