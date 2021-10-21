#include <array>
#include <iostream>
#include <ctime>
#include <cstdlib> //qsort, bsearch, NULL
using namespace std;
#define ASIZE 50000000

namespace jj01 {
	void test_array() {
		cout << "\ntest_array().......... \n";

		array<long, ASIZE> c;

		clock_t timeStart = clock();
		for (long i = 0; i < ASIZE; ++i) {
			c[i] = rand();
		}
		cout << "milli-seconds : " << (clock() - timeStart) << endl;	//
		cout << "array.size()= " << c.size() << endl;
		cout << "array.front()= " << c.front() << endl;
		cout << "array.back()= " << c.back() << endl;
		cout << "array.data()= " << c.data() << endl;

		long target = get_a_target_long();

		timeStart = clock();
		::qsort(c.data(), ASIZE, sizeof(long), compareLongs);
		long *pItem = (long *)::bsearch(&target, (c.data()), ASIZE, sizeof(long), compareLongs);
		cout << "qsort()+bsearch(), milli-seconds : " << (clock() - timeStart) << endl;	//
		if (pItem != NULL)
			cout << "found, " << *pItem << endl;
		else
			cout << "not found! " << endl;
	}
}
//---------------------------------------------------
#include <vector>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime>

#include <algorithm> 	//sort()
namespace jj02 {
	void test_vector(long &value) {
		cout << "\ntest_vector().......... \n";

		vector<string> c;
		char buf[10];

		clock_t timeStart = clock();
		for (long i = 0; i < value; ++i) {
			try {
				snprintf(buf, 10, "%d", rand());
				c.push_back(string(buf));
			} catch (exception &p) {
				cout << "i=" << i << " " << p.what() << endl;
				//曾經最高 i=58389486 then std::bad_alloc
				abort();
			}
		}
		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "vector.max_size()= " << c.max_size() << endl;	//1073747823
		cout << "vector.size()= " << c.size() << endl;
		cout << "vector.front()= " << c.front() << endl;
		cout << "vector.back()= " << c.back() << endl;
		cout << "vector.data()= " << c.data() << endl;
		cout << "vector.capacity()= " << c.capacity() << endl << endl;


		string target = get_a_target_string();
		{
			timeStart = clock();
			auto pItem = find(c.begin(), c.end(), target);
			cout << "std::find(), milli-seconds : " << (clock() - timeStart) << endl;

			if (pItem != c.end())
				cout << "found, " << *pItem << endl << endl;
			else
				cout << "not found! " << endl << endl;
		}

		{
			timeStart = clock();
			sort(c.begin(), c.end());
			cout << "sort(), milli-seconds : " << (clock() - timeStart) << endl;

			timeStart = clock();
			string *pItem = (string *)::bsearch(&target, (c.data()),
			                                    c.size(), sizeof(string), compareStrings);
			cout << "bsearch(), milli-seconds : " << (clock() - timeStart) << endl;

			if (pItem != NULL)
				cout << "found, " << *pItem << endl << endl;
			else
				cout << "not found! " << endl << endl;
		}

		c.clear();
		test_moveable(vector<MyString>(), vector<MyStrNoMove>(), value);
	}
}
//---------------------------------------------------
#include <list>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <algorithm> //find()
#include <iostream>
#include <ctime>

namespace jj03 {
	void test_list(long &value) {
		cout << "\ntest_list().......... \n";

		list<string> c;
		char buf[10];

		clock_t timeStart = clock();
		for (long i = 0; i < value; ++i) {
			try {
				snprintf(buf, 10, "%d", rand());
				c.push_back(string(buf));
			} catch (exception &p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "list.size()= " << c.size() << endl;
		cout << "list.max_size()= " << c.max_size() << endl;    //357913941
		cout << "list.front()= " << c.front() << endl;
		cout << "list.back()= " << c.back() << endl;

		string target = get_a_target_string();
		timeStart = clock();
		auto pItem = find(c.begin(), c.end(), target);
		cout << "std::find(), milli-seconds : " << (clock() - timeStart) << endl;

		if (pItem != c.end())
			cout << "found, " << *pItem << endl;
		else
			cout << "not found! " << endl;

		timeStart = clock();
		c.sort();
		cout << "c.sort(), milli-seconds : " << (clock() - timeStart) << endl;

		c.clear();
		test_moveable(list<MyString>(), list<MyStrNoMove>(), value);
	}
}
//---------------------------------------------------
#include <forward_list>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime>

namespace jj04 {
	void test_forward_list(long &value) {
		cout << "\ntest_forward_list().......... \n";

		forward_list<string> c;
		char buf[10];

		clock_t timeStart = clock();
		for (long i = 0; i < value; ++i) {
			try {
				snprintf(buf, 10, "%d", rand());
				c.push_front(string(buf));
			} catch (exception &p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "forward_list.max_size()= " << c.max_size() << endl;  //536870911
		cout << "forward_list.front()= " << c.front() << endl;


		string target = get_a_target_string();
		timeStart = clock();
		auto pItem = find(c.begin(), c.end(), target);
		cout << "std::find(), milli-seconds : " << (clock() - timeStart) << endl;

		if (pItem != c.end())
			cout << "found, " << *pItem << endl;
		else
			cout << "not found! " << endl;

		timeStart = clock();
		c.sort();
		cout << "c.sort(), milli-seconds : " << (clock() - timeStart) << endl;

		c.clear();
	}
}
//---------------------------------------------------
#include <deque>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime>

namespace jj05 {
	void test_deque(long &value) {
		cout << "\ntest_deque().......... \n";

		deque<string> c;
		char buf[10];

		clock_t timeStart = clock();
		for (long i = 0; i < value; ++i) {
			try {
				snprintf(buf, 10, "%d", rand());
				c.push_back(string(buf));
			} catch (exception &p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "deque.size()= " << c.size() << endl;
		cout << "deque.front()= " << c.front() << endl;
		cout << "deque.back()= " << c.back() << endl;
		cout << "deque.max_size()= " << c.max_size() << endl;	//1073741821

		string target = get_a_target_string();
		timeStart = clock();
		auto pItem = find(c.begin(), c.end(), target);
		cout << "std::find(), milli-seconds : " << (clock() - timeStart) << endl;

		if (pItem != c.end())
			cout << "found, " << *pItem << endl;
		else
			cout << "not found! " << endl;

		timeStart = clock();
		sort(c.begin(), c.end());
		cout << "sort(), milli-seconds : " << (clock() - timeStart) << endl;

		c.clear();
		test_moveable(deque<MyString>(), deque<MyStrNoMove>(), value);
	}
}
//---------------------------------------------------
#include <set>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime>

namespace jj06 {
	void test_multiset(long &value) {
		cout << "\ntest_multiset().......... \n";

		multiset<string> c;
		char buf[10];
		clock_t timeStart = clock();
		for (long i = 0; i < value; ++i) {
			try {
				snprintf(buf, 10, "%d", rand());
				c.insert(string(buf));
			} catch (exception &p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "multiset.size()= " << c.size() << endl;
		cout << "multiset.max_size()= " << c.max_size() << endl;	//214748364

		string target = get_a_target_string();
		{
			timeStart = clock();
			auto pItem = find(c.begin(), c.end(), target);	//比 c.find(...) 慢很多
			cout << "std::find(), milli-seconds : " << (clock() - timeStart) << endl;
			if (pItem != c.end())
				cout << "found, " << *pItem << endl;
			else
				cout << "not found! " << endl;
		}

		{
			timeStart = clock();
			auto pItem = c.find(target);		//比 std::find(...) 快很多
			cout << "c.find(), milli-seconds : " << (clock() - timeStart) << endl;
			if (pItem != c.end())
				cout << "found, " << *pItem << endl;
			else
				cout << "not found! " << endl;
		}

		c.clear();
		test_moveable(multiset<MyString>(), multiset<MyStrNoMove>(), value);
	}
}
//---------------------------------------------------
#include <map>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime>

namespace jj07 {
	void test_multimap(long &value) {
		cout << "\ntest_multimap().......... \n";

		multimap<long, string> c;
		char buf[10];

		clock_t timeStart = clock();
		for (long i = 0; i < value; ++i) {
			try {
				snprintf(buf, 10, "%d", rand());
				//multimap 不可使用 [] 做 insertion
				c.insert(pair<long, string>(i, buf));
			} catch (exception &p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "multimap.size()= " << c.size() << endl;
		cout << "multimap.max_size()= " << c.max_size() << endl;	//178956970

		long target = get_a_target_long();
		timeStart = clock();
		auto pItem = c.find(target);
		cout << "c.find(), milli-seconds : " << (clock() - timeStart) << endl;
		if (pItem != c.end())
			cout << "found, value=" << (*pItem).second << endl;
		else
			cout << "not found! " << endl;

		c.clear();
	}
}
//---------------------------------------------------
#include <unordered_set>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime>

namespace jj08 {
	void test_unordered_multiset(long &value) {
		cout << "\ntest_unordered_multiset().......... \n";

		unordered_multiset<string> c;
		char buf[10];

		clock_t timeStart = clock();
		for (long i = 0; i < value; ++i) {
			try {
				snprintf(buf, 10, "%d", rand());
				c.insert(string(buf));
			} catch (exception &p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "unordered_multiset.size()= " << c.size() << endl;
		cout << "unordered_multiset.max_size()= " << c.max_size() << endl;	//357913941
		cout << "unordered_multiset.bucket_count()= " << c.bucket_count() << endl;
		cout << "unordered_multiset.load_factor()= " << c.load_factor() << endl;
		cout << "unordered_multiset.max_load_factor()= " << c.max_load_factor() << endl;
		cout << "unordered_multiset.max_bucket_count()= " << c.max_bucket_count() << endl;
		for (unsigned i = 0; i < 20; ++i) {
			cout << "bucket #" << i << " has " << c.bucket_size(i) << " elements.\n";
		}

		string target = get_a_target_string();
		{
			timeStart = clock();
			auto pItem = find(c.begin(), c.end(), target);	//比 c.find(...) 慢很多
			cout << "std::find(), milli-seconds : " << (clock() - timeStart) << endl;
			if (pItem != c.end())
				cout << "found, " << *pItem << endl;
			else
				cout << "not found! " << endl;
		}

		{
			timeStart = clock();
			auto pItem = c.find(target);		//比 std::find(...) 快很多
			cout << "c.find(), milli-seconds : " << (clock() - timeStart) << endl;
			if (pItem != c.end())
				cout << "found, " << *pItem << endl;
			else
				cout << "not found! " << endl;
		}

		c.clear();
		test_moveable(unordered_multiset<MyString>(), unordered_multiset<MyStrNoMove>(), value);
	}
}
//---------------------------------------------------
#include <unordered_map>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime>

namespace jj09 {
	void test_unordered_multimap(long &value) {
		cout << "\ntest_unordered_multimap().......... \n";

		unordered_multimap<long, string> c;
		char buf[10];

		clock_t timeStart = clock();
		for (long i = 0; i < value; ++i) {
			try {
				snprintf(buf, 10, "%d", rand());
				//multimap 不可使用 [] 進行 insertion
				c.insert(pair<long, string>(i, buf));
			} catch (exception &p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "unordered_multimap.size()= " << c.size() << endl;
		cout << "unordered_multimap.max_size()= " << c.max_size() << endl;	//357913941

		long target = get_a_target_long();
		timeStart = clock();
		auto pItem = c.find(target);
		cout << "c.find(), milli-seconds : " << (clock() - timeStart) << endl;
		if (pItem != c.end())
			cout << "found, value=" << (*pItem).second << endl;
		else
			cout << "not found! " << endl;
	}
}
//---------------------------------------------------
#include <ext\slist>
//注意, 上一行並沒有引發警告訊息如 #include <ext\hash_set> 所引發者：
//...\4.9.2\include\c++\backward\backward_warning.h
//[Warning] ...

#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime>
namespace jj10 {
	void test_slist(long &value) {
		cout << "\ntest_slist().......... \n";

		__gnu_cxx::slist<string> c;
		char buf[10];

		clock_t timeStart = clock();
		for (long i = 0; i < value; ++i) {
			try {
				snprintf(buf, 10, "%d", rand());
				c.push_front(string(buf));
			} catch (exception &p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds : " << (clock() - timeStart) << endl;
	}
}
//---------------------------------------------------
/*
以下測試 hash_multiset, hash_multimap 過程中遇到阻礙：
headers <hash_set> 和 <hash_map> 各有兩個，
分別在 ...\4.9.2\include\c++\backward 和 ...\4.9.2\include\c++\ext，
不知要用哪一組!
用 <ext\...> 那一組會有問題
   ...\4.9.2\include\c++\backward\hashtable.h
   [Error] no match for call to '(const hasher {aka const __gnu_cxx::hash<std::basic_string<char> >}) (const key_type&)'
用 <backward\...> 那一組有相同的問題.
so, 放棄測試 (no insertion or push_back or ...).
*/

#include <ext\hash_set>
//...\4.9.2\include\c++\backward\backward_warning.h
//[Warning] #warning This file includes at least one deprecated or antiquated header
//which may be removed without further notice at a future date.
//Please use a non-deprecated interface with equivalent functionality instead.
//For a listing of replacement headers and interfaces, consult the file backward_warning.h.
//To disable this warning use -Wno-deprecated. [-Wcpp]

#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime>
namespace jj11 {
	void test_hash_multiset(long &value) {
		cout << "\ntest_hash_multiset().......... \n";

		__gnu_cxx::hash_multiset<string> c;
		char buf[10];

		clock_t timeStart = clock();
		for (long i = 0; i < value; ++i) {
			try {
				snprintf(buf, 10, "%d", rand());
				//! c.insert(string(buf));
			} catch (exception &p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds : " << (clock() - timeStart) << endl;
	}
}
//---------------------------------------------------
#include <ext\hash_map>
//...\4.9.2\include\c++\backward\backward_warning.h
//[Warning] #warning This file ... (如上個函數所言)
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime>

namespace jj12 {
	void test_hash_multimap(long &value) {
		cout << "\ntest_hash_multimap().......... \n";

		__gnu_cxx::hash_multimap<long, string> c;
		char buf[10];

		clock_t timeStart = clock();
		for (long i = 0; i < value; ++i) {
			try {
				snprintf(buf, 10, "%d", rand());
				//c.insert(...
			} catch (exception &p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds : " << (clock() - timeStart) << endl;

		timeStart = clock();
		//! auto ite = c.find(...
		cout << "milli-seconds : " << (clock() - timeStart) << endl;
	}
}
//---------------------------------------------------
#include <set>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime>

namespace jj13 {
	void test_set(long &value) {
		cout << "\ntest_set().......... \n";

		set<string> c;
		char buf[10];

		clock_t timeStart = clock();
		for (long i = 0; i < value; ++i) {
			try {
				snprintf(buf, 10, "%d", rand());
				c.insert(string(buf));
			} catch (exception &p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "set.size()= " << c.size() << endl;
		cout << "set.max_size()= " << c.max_size() << endl;	   //214748364

		string target = get_a_target_string();
		{
			timeStart = clock();
			auto pItem = find(c.begin(), c.end(), target);	//比 c.find(...) 慢很多
			cout << "std::find(), milli-seconds : " << (clock() - timeStart) << endl;
			if (pItem != c.end())
				cout << "found, " << *pItem << endl;
			else
				cout << "not found! " << endl;
		}

		{
			timeStart = clock();
			auto pItem = c.find(target);		//比 std::find(...) 快很多
			cout << "c.find(), milli-seconds : " << (clock() - timeStart) << endl;
			if (pItem != c.end())
				cout << "found, " << *pItem << endl;
			else
				cout << "not found! " << endl;
		}
	}
}
//---------------------------------------------------
#include <map>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime>

namespace jj14 {
	void test_map(long &value) {
		cout << "\ntest_map().......... \n";

		map<long, string> c;
		char buf[10];

		clock_t timeStart = clock();
		for (long i = 0; i < value; ++i) {
			try {
				snprintf(buf, 10, "%d", rand());
				c[i] = string(buf);
			} catch (exception &p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "map.size()= " << c.size() << endl;
		cout << "map.max_size()= " << c.max_size() << endl;		//178956970

		long target = get_a_target_long();
		timeStart = clock();
		auto pItem = c.find(target);
		cout << "c.find(), milli-seconds : " << (clock() - timeStart) << endl;
		if (pItem != c.end())
			cout << "found, value=" << (*pItem).second << endl;
		else
			cout << "not found! " << endl;

		c.clear();
	}
}
//---------------------------------------------------
#include <unordered_set>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime>

namespace jj15 {
	void test_unordered_set(long &value) {
		cout << "\ntest_unordered_set().......... \n";

		unordered_set<string> c;
		char buf[10];

		clock_t timeStart = clock();
		for (long i = 0; i < value; ++i) {
			try {
				snprintf(buf, 10, "%d", rand());
				c.insert(string(buf));
			} catch (exception &p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "unordered_set.size()= " << c.size() << endl;
		cout << "unordered_set.max_size()= " << c.max_size() << endl;  //357913941
		cout << "unordered_set.bucket_count()= " << c.bucket_count() << endl;
		cout << "unordered_set.load_factor()= " << c.load_factor() << endl;
		cout << "unordered_set.max_load_factor()= " << c.max_load_factor() << endl;
		cout << "unordered_set.max_bucket_count()= " << c.max_bucket_count() << endl;
		for (unsigned i = 0; i < 20; ++i) {
			cout << "bucket #" << i << " has " << c.bucket_size(i) << " elements.\n";
		}

		string target = get_a_target_string();
		{
			timeStart = clock();
			auto pItem = find(c.begin(), c.end(), target);	//比 c.find(...) 慢很多
			cout << "std::find(), milli-seconds : " << (clock() - timeStart) << endl;
			if (pItem != c.end())
				cout << "found, " << *pItem << endl;
			else
				cout << "not found! " << endl;
		}

		{
			timeStart = clock();
			auto pItem = c.find(target);		//比 std::find(...) 快很多
			cout << "c.find(), milli-seconds : " << (clock() - timeStart) << endl;
			if (pItem != c.end())
				cout << "found, " << *pItem << endl;
			else
				cout << "not found! " << endl;
		}
	}
}
//---------------------------------------------------
#include <unordered_map>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime>

namespace jj16 {
	void test_unordered_map(long &value) {
		cout << "\ntest_unordered_map().......... \n";

		unordered_map<long, string> c;
		char buf[10];

		clock_t timeStart = clock();
		for (long i = 0; i < value; ++i) {
			try {
				snprintf(buf, 10, "%d", rand());
				c[i] = string(buf);
			} catch (exception &p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "unordered_map.size()= " << c.size() << endl;	//357913941
		cout << "unordered_map.max_size()= " << c.max_size() << endl;

		long target = get_a_target_long();
		timeStart = clock();
//! auto pItem = find(c.begin(), c.end(), target);	//map 不適用 std::find()
		auto pItem = c.find(target);

		cout << "c.find(), milli-seconds : " << (clock() - timeStart) << endl;
		if (pItem != c.end())
			cout << "found, value=" << (*pItem).second << endl;
		else
			cout << "not found! " << endl;
	}
}
//---------------------------------------------------
#include <stack>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime>

namespace jj17 {
	void test_stack(long &value) {
		cout << "\ntest_stack().......... \n";

		stack<string> c;
		char buf[10];

		clock_t timeStart = clock();
		for (long i = 0; i < value; ++i) {
			try {
				snprintf(buf, 10, "%d", rand());
				c.push(string(buf));
			} catch (exception &p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "stack.size()= " << c.size() << endl;
		cout << "stack.top()= " << c.top() << endl;
		c.pop();
		cout << "stack.size()= " << c.size() << endl;
		cout << "stack.top()= " << c.top() << endl;


		{
			stack<string, list<string>> c;		//以 list 為底層
			for (long i = 0; i < 10; ++i) {
				snprintf(buf, 10, "%d", rand());
				c.push(string(buf));
			}
			cout << "stack.size()= " << c.size() << endl;
			cout << "stack.top()= " << c.top() << endl;
			c.pop();
			cout << "stack.size()= " << c.size() << endl;
			cout << "stack.top()= " << c.top() << endl;
		}

		{
			stack<string, vector<string>> c;	//以 vector 為底層
			for (long i = 0; i < 10; ++i) {
				snprintf(buf, 10, "%d", rand());
				c.push(string(buf));
			}
			cout << "stack.size()= " << c.size() << endl;
			cout << "stack.top()= " << c.top() << endl;
			c.pop();
			cout << "stack.size()= " << c.size() << endl;
			cout << "stack.top()= " << c.top() << endl;
		}

		{
			stack<string, set<string>> c;	//以 set 為底層
			/*!
			    for(long i=0; i< 10; ++i) {
			    		snprintf(buf, 10, "%d", rand());
			        	c.push(string(buf));
				}
				cout << "stack.size()= " << c.size() << endl;
				cout << "stack.top()= " << c.top() << endl;
				c.pop();
				cout << "stack.size()= " << c.size() << endl;
				cout << "stack.top()= " << c.top() << endl;

			//[Error] 'class std::set<std::basic_string<char> >' has no member named 'push_back'
			//[Error] 'class std::set<std::basic_string<char> >' has no member named 'back'
			//[Error] 'class std::set<std::basic_string<char> >' has no member named 'pop_back'
			*/
		}

//!stack<string, map(string>> c5;	////以 map 為底層, [Error] template argument 2 is invalid
//!stack<string>::iterator ite1;  	//[Error] 'iterator' is not a member of 'std::stack<std::basic_string<char> >'

	}
}
//---------------------------------------------------
#include <queue>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime>

namespace jj18 {
	void test_queue(long &value) {
		cout << "\ntest_queue().......... \n";

		queue<string> c;
		char buf[10];

		clock_t timeStart = clock();
		for (long i = 0; i < value; ++i) {
			try {
				snprintf(buf, 10, "%d", rand());
				c.push(string(buf));
			} catch (exception &p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "queue.size()= " << c.size() << endl;
		cout << "queue.front()= " << c.front() << endl;
		cout << "queue.back()= " << c.back() << endl;
		c.pop();
		cout << "queue.size()= " << c.size() << endl;
		cout << "queue.front()= " << c.front() << endl;
		cout << "queue.back()= " << c.back() << endl;


		{
			queue<string, list<string>> c;		//以 list 為底層
			for (long i = 0; i < 10; ++i) {
				snprintf(buf, 10, "%d", rand());
				c.push(string(buf));
			}
			cout << "queue.size()= " << c.size() << endl;
			cout << "queue.front()= " << c.front() << endl;
			cout << "queue.back()= " << c.back() << endl;
			c.pop();
			cout << "queue.size()= " << c.size() << endl;
			cout << "queue.front()= " << c.front() << endl;
			cout << "queue.back()= " << c.back() << endl;
		}

		{
			queue<string, vector<string>> c;	//以 vector 為底層
			for (long i = 0; i < 10; ++i) {
				snprintf(buf, 10, "%d", rand());
				c.push(string(buf));
			}
			cout << "queue.size()= " << c.size() << endl;
			cout << "queue.front()= " << c.front() << endl;
			cout << "queue.back()= " << c.back() << endl;
			//!c.pop();  //[Error] 'class std::vector<std::basic_string<char> >' has no member named 'pop_front'
			cout << "queue.size()= " << c.size() << endl;
			cout << "queue.front()= " << c.front() << endl;
			cout << "queue.back()= " << c.back() << endl;
		}

		{
			queue<string, set<string>> c;		//以 set 為底層
			/*!
			    for(long i=0; i< 10; ++i) {
			    		snprintf(buf, 10, "%d", rand());
			        	c.push(string(buf));
				}
				cout << "queue.size()= " << c.size() << endl;
				cout << "queue.front()= " << c.front() << endl;
				cout << "queue.back()= " << c.back() << endl;
				c.pop();
				cout << "queue.size()= " << c.size() << endl;
				cout << "queue.front()= " << c.front() << endl;
				cout << "queue.back()= " << c.back() << endl;
			//[Error] 'class std::set<std::basic_string<char> >' has no member named 'push_back'
			//[Error] 'class std::set<std::basic_string<char> >' has no member named 'front'
			//[Error] 'class std::set<std::basic_string<char> >' has no member named 'pop_front'
			*/
		}

//! queue<string, map<string>> c5;	//以 map 為底層, [Error] template argument 2 is invalid
//! queue<string>::iterator ite1;  	//[Error] 'iterator' is not a member of 'std::queue<std::basic_string<char> >'
	}
}
//---------------------------------------------------
#include <list>
#include <stdexcept>
#include <string>
#include <cstdlib> 		//abort()
#include <cstdio>  		//snprintf()
#include <algorithm> 	//find()
#include <iostream>
#include <ctime>

#include <cstddef>
#include <memory>	//內含 std::allocator  
//欲使用 std::allocator 以外的 allocator, 得自行 #include <ext\...>
#ifdef __GNUC__
#include <ext\array_allocator.h>
#include <ext\mt_allocator.h>
#include <ext\debug_allocator.h>
#include <ext\pool_allocator.h>
#include <ext\bitmap_allocator.h>
#include <ext\malloc_allocator.h>
#include <ext\new_allocator.h>
#endif

namespace jj20 {
//pass A object to function template impl()，
//而 A 本身是個 class template, 帶有 type parameter T,
//那麼有無可能在 impl() 中抓出 T, 創建一個 list<T, A<T>> object?
//以下先暫時迴避上述疑問.

	void test_list_with_special_allocator() {
#ifdef __GNUC__
		cout << "\ntest_list_with_special_allocator().......... \n";

		//不能在 switch case 中宣告，只好下面這樣. 				//1000000次
		list<string, allocator<string>> c1;						//3140
		list<string, __gnu_cxx::malloc_allocator<string>> c2;  	//3110
		list<string, __gnu_cxx::new_allocator<string>> c3; 		//3156
		list<string, __gnu_cxx::__pool_alloc<string>> c4;  		//4922
		list<string, __gnu_cxx::__mt_alloc<string>> c5; 		//3297
		list<string, __gnu_cxx::bitmap_allocator<string>> c6;  	//4781

		int choice;
		long value;

		cout << "select: "
		     << " (1) std::allocator "
		     << " (2) malloc_allocator "
		     << " (3) new_allocator "
		     << " (4) __pool_alloc "
		     << " (5) __mt_alloc "
		     << " (6) bitmap_allocator ";

		cin >> choice;
		if ( choice != 0 ) {
			cout << "how many elements: ";
			cin >> value;
		}

		char buf[10];
		clock_t timeStart = clock();
		for (long i = 0; i < value; ++i) {
			try {
				snprintf(buf, 10, "%d", i);
				switch (choice) {
					case 1 :
						c1.push_back(string(buf));
						break;
					case 2 :
						c2.push_back(string(buf));
						break;
					case 3 :
						c3.push_back(string(buf));
						break;
					case 4 :
						c4.push_back(string(buf));
						break;
					case 5 :
						c5.push_back(string(buf));
						break;
					case 6 :
						c6.push_back(string(buf));
						break;
					default:
						break;
				}
			} catch (exception &p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "a lot of push_back(), milli-seconds : " << (clock() - timeStart) << endl;


		//test all allocators' allocate() & deallocate();
		int *p;
		allocator<int> alloc1;
		p = alloc1.allocate(1);
		alloc1.deallocate(p, 1);

		__gnu_cxx::malloc_allocator<int> alloc2;
		p = alloc2.allocate(1);
		alloc2.deallocate(p, 1);

		__gnu_cxx::new_allocator<int> alloc3;
		p = alloc3.allocate(1);
		alloc3.deallocate(p, 1);

		__gnu_cxx::__pool_alloc<int> alloc4;
		p = alloc4.allocate(2);
		alloc4.deallocate(p, 2); 	//我刻意令參數為 2, 但這有何意義!! 一次要 2 個 ints?

		__gnu_cxx::__mt_alloc<int> alloc5;
		p = alloc5.allocate(1);
		alloc5.deallocate(p, 1);

		__gnu_cxx::bitmap_allocator<int> alloc6;
		p = alloc6.allocate(3);
		alloc6.deallocate(p, 3);  	//我刻意令參數為 3, 但這有何意義!! 一次要 3 個 ints?
#endif
	}
}
//---------------------------------------------------
#include <list>
#include <string>
#include <iostream>

#include <memory>		//內含 std::allocator  
//#include <bits\stl_tree.h>  //內含 _RB_tree (不需此行, 因為它被含入於 <set> and <map>)

//欲使用 std::allocator 以外的 allocator, 得自行 #include <ext\...>
#include <ext\array_allocator.h>
#include <ext\mt_allocator.h>
#include <ext\debug_allocator.h>
#include <ext\pool_allocator.h>
#include <ext\bitmap_allocator.h>
#include <ext\malloc_allocator.h>
#include <ext\new_allocator.h>

namespace jj25 {
	void test_components_sizeof() {
		cout << "\ntest_components_size().......... \n";

		//containers
		cout << "sizeof(array<int,100>)= " << sizeof(array<int, 100>) << endl;		//400
		cout << "sizeof(vector<int>)= " << sizeof(vector<int>) << endl;				//12
		cout << "sizeof(list<int>)= " << sizeof(list<int>) << endl;					//8
		cout << "sizeof(forward_list<int>)= " << sizeof(forward_list<int>) << endl;	//4
		cout << "sizeof(deque<int>)= " << sizeof(deque<int>) << endl;				//40
		cout << "sizeof(stack<int>)= " << sizeof(stack<int>) << endl;				//40
		cout << "sizeof(queue<int>)= " << sizeof(queue<int>) << endl;				//40
		cout << "sizeof(set<int>)= " << sizeof(set<int>) << endl;					//24
		cout << "sizeof(map<int,int>)= " << sizeof(map<int, int>) << endl;			//24
		cout << "sizeof(multiset<int>)= " << sizeof(multiset<int>) << endl;			//24
		cout << "sizeof(multimap<int,int>)= " << sizeof(multimap<int, int>) << endl;	//24
		cout << "sizeof(unordered_set<int>)= " << sizeof(unordered_set<int>) << endl;					//28
		cout << "sizeof(unordered_map<int,int>)= " << sizeof(unordered_map<int, int>) << endl;			//28
		cout << "sizeof(unordered_multiset<int>)= " << sizeof(unordered_multiset<int>) << endl;			//28
		cout << "sizeof(unordered_multimap<int,int>)= " << sizeof(unordered_multimap<int, int>) << endl;	//28
		cout << "sizeof(_Rb_tree<...>)= " << sizeof(_Rb_tree<int, int, _Identity<int>, less<int>>) << endl; //24

		//iterators
		cout << "sizeof(array<int,100>::iterator)= " << sizeof(array<int, 100>::iterator) << endl;		//4
		cout << "sizeof(vector<int>::iterator)= " << sizeof(vector<int>::iterator) << endl;				//4
		cout << "sizeof(list<int>::iterator)= " << sizeof(list<int>::iterator) << endl;					//4
		cout << "sizeof(forward_list<int>::iterator)= " << sizeof(forward_list<int>::iterator) << endl; //4
		cout << "sizeof(deque<int>::iterator)= " << sizeof(deque<int>::iterator) << endl;				//16
		//! cout << "sizeof(stack<int>::iterator)= " << sizeof(stack<int>::iterator) << endl;	//[Error] 'iterator' is not a member of 'std::stack<int>'
		//! cout << "sizeof(queue<int>::iterator)= " << sizeof(queue<int>::iterator) << endl;	//[Error] 'iterator' is not a member of 'std::queue<int>
		cout << "sizeof(set<int>::iterator)= " << sizeof(set<int>::iterator) << endl;					//4
		cout << "sizeof(map<int,int>::iterator)= " << sizeof(map<int, int>::iterator) << endl;			//4
		cout << "sizeof(multiset<int>::iterator)= " << sizeof(multiset<int>::iterator) << endl;			//4
		cout << "sizeof(multimap<int,int>::iterator)= " << sizeof(multimap<int, int>::iterator) << endl;	//4
		cout << "sizeof(unordered_set<int>::iterator)= " << sizeof(unordered_set<int>::iterator) << endl;	//4
		cout << "sizeof(unordered_map<int,int>::iterator)= " << sizeof(unordered_map<int, int>::iterator) << endl;	//4
		cout << "sizeof(unordered_multiset<int>::iterator)= " << sizeof(unordered_multiset<int>::iterator) << endl;	//4
		cout << "sizeof(unordered_multimap<int,int>::iterator)= " << sizeof(unordered_multimap<int, int>::iterator) <<
		     endl;	//4
		cout << "sizeof(_Rb_tree<...>::iterator)= " << sizeof(_Rb_tree<int, int, _Identity<int>, less<int>>::iterator) <<
		     endl; //4

		//allocators
		cout << "sizeof(      std::allocator<string>)=" << sizeof(std::allocator<string>) << endl;						//1 (理論值 0)
		cout << "sizeof(__gnu_cxx::malloc_allocator<string>)= " << sizeof(__gnu_cxx::malloc_allocator<string>) <<
		     endl; //1 (理論值 0)
		cout << "sizeof(__gnu_cxx::new_allocator<string>)= " <<  sizeof(__gnu_cxx::new_allocator<string>) <<
		     endl; 	    //1 (理論值 0)
		cout << "sizeof(__gnu_cxx::__pool_alloc<string>)= " << sizeof(__gnu_cxx::__pool_alloc<string>) <<
		     endl;         //1 (理論值 0)
		cout << "sizeof(__gnu_cxx::bitmap_allocator<string>)= " << sizeof(__gnu_cxx::bitmap_allocator<string>) <<
		     endl; //1 (理論值 0)
		cout << "sizeof(__gnu_cxx::__mt_alloc<string>)= " << sizeof(__gnu_cxx::__mt_alloc<string>) << endl;  			//1 (理論值 0)
		cout << "sizeof(__gnu_cxx::array_allocator<int>)= " << sizeof(__gnu_cxx::array_allocator<int>) << endl;  		//8
		//==> 因為它有一個 ptr 指向 array 和一個 size_t 表示消耗到 array 哪兒
		cout << "sizeof(__gnu_cxx::debug_allocator<std::allocator<double>>)= " << sizeof(
		         __gnu_cxx::debug_allocator<std::allocator<double>>) << endl; //8
	}
}
//---------------------------------------------------
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

namespace jj30 {
	void test_all_components() {
		cout << "\ntest_all_components().......... \n";

		int ia[7] = { 27, 210, 12, 47, 109, 83, 40 };
		vector<int, allocator<int>> vi(ia, ia + 7);

		cout << count_if(vi.begin(), vi.end(),
		                 not1(bind2nd(less<int>(), 40)));	//5
		cout << endl;
	}
}
//---------------------------------------------------
#include <set>
#include <functional>
#include <iostream>

namespace jj31 {
	void test_Rb_tree() {
		//G2.9 vs. G2.9 :
		//rb_tree => _Rb_tree,
		//identity<> => _Identity<>
		//insert_unique() => _M_insert_unique()
		//insert_equal() => _M_insert_equal()

		cout << "\ntest_Rb_tree().......... \n";

		_Rb_tree<int, int, _Identity<int>, less<int>> itree;
		cout << itree.empty() << endl;  //1
		cout << itree.size() << endl;   //0

		itree._M_insert_unique(3);
		itree._M_insert_unique(8);
		itree._M_insert_unique(5);
		itree._M_insert_unique(9);
		itree._M_insert_unique(13);
		itree._M_insert_unique(5);  //no effect, since using insert_unique().
		cout << itree.empty() << endl;  //0
		cout << itree.size() << endl;   //5
		cout << itree.count(5) << endl; //1

		itree._M_insert_equal(5);
		itree._M_insert_equal(5);
		cout << itree.size() << endl;   //7, since using insert_equal().
		cout << itree.count(5) << endl; //3
	}
}
//---------------------------------------------------
#include <unordered_set>
#include <functional>
#include <iostream>
#include <string>

namespace jj32 {
	/*
	//下面的 hash<string>, G2.9需要，G4.9不需要，因為 G4.9 basic_string.h 已提供
	template<> struct hash<string>
	{
	  size_t operator()(string s) const {
	      return __stl_hash_string(s.c_str());
	  }
	};
	*/

	void test_Hashtable() {
		cout << "\ntest_Hashtable().......... \n";

// hashtable 的模板參數個數 6=>10 (增加 hash policy 吧大概)
// 所以 G2.9的應用修改起來很麻煩。不改了, 以後再說.
	}
}

//---------------------------------------------------
#include <iostream>     // std::cout
#include <iterator>     // std::iterator_traits
#include <typeinfo>     // typeid
namespace jj33 {
	void _display_category(random_access_iterator_tag) {
		cout << "random_access_iterator" << endl;
	}
	void _display_category(bidirectional_iterator_tag) {
		cout << "bidirectional_iterator" << endl;
	}
	void _display_category(forward_iterator_tag) {
		cout << "forward_iterator" << endl;
	}
	void _display_category(output_iterator_tag) {
		cout << "output_iterator" << endl;
	}
	void _display_category(input_iterator_tag) {
		cout << "input_iterator" << endl;
	}

	template<typename I>
	void display_category(I itr) {
		typename iterator_traits<I>::iterator_category cagy;
		_display_category(cagy);

		cout << "typeid(itr).name()= " << typeid(itr).name() << endl << endl;
		//The output depends on library implementation.
		//The particular representation pointed by the
		//returned valueis implementation-defined,
		//and may or may not be different for different types.
	}

	void test_iterator_category() {
		cout << "\ntest_iterator_category().......... \n";

		display_category(array<int, 10>::iterator());
		display_category(vector<int>::iterator());
		display_category(list<int>::iterator());
		display_category(forward_list<int>::iterator());
		display_category(deque<int>::iterator());

		display_category(set<int>::iterator());
		display_category(map<int, int>::iterator());
		display_category(multiset<int>::iterator());
		display_category(multimap<int, int>::iterator());
		display_category(unordered_set<int>::iterator());
		display_category(unordered_map<int, int>::iterator());
		display_category(unordered_multiset<int>::iterator());
		display_category(unordered_multimap<int, int>::iterator());

		display_category(istream_iterator<int>());
		display_category(ostream_iterator<int>(cout, ""));
	}
}

//---------------------------------------------------
#include <iostream>     // std::cout
#include <functional>   // std::minus
#include <numeric>      // std::accumulate
namespace jj34 {
	int myfunc (int x, int y) {
		return x + 2 * y;
	}

	struct myclass {
		int operator()(int x, int y) {
			return x + 3 * y;
		}
	} myobj;

	void test_accumulate() {
		cout << "\ntest_accumulate().......... \n";
		int init = 100;
		int nums[] = {10, 20, 30};

		cout << "using default accumulate: ";
		cout << accumulate(nums, nums + 3, init); //160
		cout << '\n';

		cout << "using functional's minus: ";
		cout << accumulate(nums, nums + 3, init, minus<int>()); //40
		cout << '\n';

		cout << "using custom function: ";
		cout << accumulate(nums, nums + 3, init, myfunc);	//220
		cout << '\n';

		cout << "using custom object: ";
		cout << accumulate(nums, nums + 3, init, myobj);	//280
		cout << '\n';
	}
}

//---------------------------------------------------
#include <iostream>     // std::cout
#include <algorithm>    // std::for_each
#include <vector>       // std::vector
namespace jj35 {
	void myfunc (int i) {
		cout << ' ' << i;
	}

	struct myclass {
		void operator() (int i) {
			cout << ' ' << i;
		}
	} myobj;

	void test_for_each() {
		cout << "\ntest_for_each().......... \n";

		vector<int> myvec;
		myvec.push_back(10);
		myvec.push_back(20);
		myvec.push_back(30);

		for_each (myvec.begin(), myvec.end(), myfunc);
		cout << endl;		//output: 10 20 30

		for_each (myvec.begin(), myvec.end(), myobj);
		cout << endl;		//output: 10 20 30

		//since C++11, range-based for- statement
		for (auto &elem : myvec)
			elem += 5;

		for (auto elem : myvec)
			cout << ' ' << elem ; 	//output: 15 25 35
	}
}

//---------------------------------------------------
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
namespace jj36 {
	bool myfunc (int i, int j) {
		return (i < j);
	}

	struct myclass {
		bool operator() (int i, int j) {
			return (i < j);
		}
	} myobj;

	bool test_sort() {
		cout << "\ntest_sort().......... \n";

		int myints[] = {32, 71, 12, 45, 26, 80, 53, 33};
		vector<int> myvec(myints, myints + 8);        // 32 71 12 45 26 80 53 33

		// using default comparison (operator <):
		sort(myvec.begin(), myvec.begin() + 4);       //(12 32 45 71)26 80 53 33

		// using function as comp
		sort(myvec.begin() + 4, myvec.end(), myfunc); 	// 12 32 45 71(26 33 53 80)

		// using object as comp
		sort(myvec.begin(), myvec.end(), myobj);      //(12 26 32 33 45 53 71 80)

		// print out content:
		cout << "\nmyvec contains:";
		for (auto elem : myvec)		//C++11 range-based for statement
			cout << ' ' << elem ; 	//output: 12 26 32 33 45 53 71 80

		// using reverse iterators and default comparison (operator <):
		sort(myvec.rbegin(), myvec.rend());

		// print out content:
		cout << "\nmyvec contains:";
		for (auto elem : myvec)		//C++11 range-based for statement
			cout << ' ' << elem ; 	//output: 80 71 53 45 33 32 26 12

		// using explicitly default comparison (operator <):
		sort(myvec.begin(), myvec.end(), less<int>());

		// print out content:
		cout << "\nmyvec contains:";
		for (auto elem : myvec)		//C++11 range-based for statement
			cout << ' ' << elem ; 	//output: 12 26 32 33 45 53 71 80

		// using another comparision criteria (operator >):
		sort(myvec.begin(), myvec.end(), greater<int>());

		// print out content:
		cout << "\nmyvec contains:";
		for (auto elem : myvec)		//C++11 range-based for statement
			cout << ' ' << elem ; 	//output: 80 71 53 45 33 32 26 12
	}
}

//---------------------------------------------------
#include <cstdlib> //rand() and RAND_MAX
namespace jjxx {
	void test_containers() {
		int choice;
		long value;

		srand(time(NULL));

		cout << "\n\ntest_containers()......... \n";
		cout << "select: \n";
		cout << "       (1)array (2)vector (3)list (4)forward_list (5)deque (6)multiset \n";
		cout << "       (7)multimap (8)unordered_multiset (9)unordered_multimap (10)slist \n";
		cout << "       (11)hash_multiset (12)hash_multimap (13)set (14)map (15)unordered_set \n";
		cout << "       (16)unordered_map (17)stack (18)queue \n";
		cout << " (2),(3),(5),(6),(8) will test also moveable elements. \n";
		cin >> choice;
		if ( choice != 1 ) { 	//1 ==> array, use ASIZE
			cout << "how many elements: ";
			cin >> value;
		}

		switch (choice) {
			case 1 :
				jj01::test_array();
				break;
			case 2 :
				jj02::test_vector(value);
				//jj02::test_vector_with_move(value);
				break;
			case 3 :
				jj03::test_list(value);
				break;
			case 4 :
				jj04::test_forward_list(value);
				break;
			case 5 :
				jj05::test_deque(value);
				break;
			case 6 :
				jj06::test_multiset(value);
				break;
			case 7 :
				jj07::test_multimap(value);
				break;
			case 8 :
				jj08::test_unordered_multiset(value);
				break;
			case 9 :
				jj09::test_unordered_multimap(value);
				break;
			case 10:
				jj10::test_slist(value);
				break;
			case 11:
				jj11::test_hash_multiset(value);
				break;
			case 12:
				jj12::test_hash_multimap(value);
				break;
			case 13 :
				jj13::test_set(value);
				break;
			case 14 :
				jj14::test_map(value);
				break;
			case 15 :
				jj15::test_unordered_set(value);
				break;
			case 16 :
				jj16::test_unordered_map(value);
				break;
			case 17 :
				jj17::test_stack(value);
				break;
			case 18 :
				jj18::test_queue(value);
				break;
			default:
				break;
		}
	}
}
//---------------------------------------------------
#include <cstdlib> //rand() and RAND_MAX
int main(int argc, char **argv) {
	jj00::test_misc();

	jjxx::test_containers();

	jj20::test_list_with_special_allocator();
	jj25::test_components_sizeof();
	jj30::test_all_components();
	jj31::test_Rb_tree();
	jj32::test_Hashtable();

	jj33::test_iterator_category();
	jj34::test_accumulate();
	jj35::test_for_each();
	jj36::test_sort();

	return 0;
}