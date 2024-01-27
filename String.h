#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

using namespace std;

#include<iostream>
#include<assert.h>

namespace bt
{
	class string
	{
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		static const size_t npos = -1;
	public:
		//string(const char* str)
		//	:npos(-1)
		//	,_str((char*)"")
		//{
		//	_size = strlen(str);
		//	_capacity = _size;
		//	_str = new char[_capacity + 1];
		//	strcpy(_str, str);
		//}
		string(const char* str = "");//默认构造函数

		//string(const string& s)
		// 传统写法的拷贝构造函数
		//	_size = s._size;
		//	_capacity = s._capacity;
		//	_str = new char[s._capacity + 1];
		//	strcpy(_str, s._str);
		//}

		//现代写法的拷贝构造函数
		string(const string& s);

		~string();//析构函数
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()//迭代器
		{
			return _str;
		}

		iterator end()//迭代器
		{
			return begin() + _size;
		}

		const_iterator begin() const//迭代器
		{
			return _str;
		}

		const_iterator end() const//迭代器
		{
			return _str + _size;
		}

		const char* c_str() const;//对字符串进行解引用
	
		char& operator[](size_t pos);//[]操作符的重载

		const char& operator[](size_t pos) const;//[]操作符的重载

		size_t size() const;//size_t（）方法

		void reserve(size_t n);//预留字符串存储空间
		
		void append(const char* str);//在字符串后追加一个字符串

		void push_back(char ch);//在字符串后追加一个字符

		string& operator+=(char ch);//+=操作符的重载

		string& operator+=(const char* str);//+=操作符的重载
		
		void insert(size_t pos, const char ch);//insert()（在pos位置插入一个字符)

		void insert(size_t pos, const char* str);//insert()(在pos位置插入一个字符串)

		//void insert(size_t pos, const char ch)//在pos位置插入一个字符
		//{
		//	assert(pos <= _size);
		//	if (_size == _capacity)
		//	{
		//		size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
		//		reserve(newcapacity);
		//	}
		//	//int end = _size;
		//	//while (end >= (int)pos)
		//	//{
		//	//	_str[end + 1] = _str[end];
		//	//	--end;
		//	//}
		//	size_t end = _size + 1;
		//	while (end > pos)
		//	//使用>防止end为0时再次转换从unsigned int类型的-1隐式类型转化为int
		//	//防止出现死循环
		//	{
		//		_str[end] = _str[end - 1];
		//		//因为是让end>pos
		//		//所以让end位置处的位置=end-1处的位置，将每个元素向后挪动一个下标
		//		--end;
		//	}
		//	_str[pos] = ch;
		//	_size++;
		//}

		//void insert(size_t pos, const char* str)//在pos位置插入一个字符串
		//{
		//	assert(pos <= _size);
		//	size_t len = strlen(str);
		//	if (_size + len > _capacity)
		//	{
		//		reserve(_size + len);
		//	}
		//	int end = _size;
		//	while (end >= (int)pos)
		//	{
		//		_str[end + len] = _str[end];
		//		--end;
		//	}
		//	strncpy(_str + pos, str, len);
		//	_size += len;
		//}

		void earse(size_t pos, size_t len = npos);

		void erase(size_t pos, size_t len = npos);//erase()(从pos位置开始删除len长度的字串)

		void swap(string& s);//交换两个string对象

		size_t find(char ch, size_t pos = 0);//从pos位置查找字符并且返回下标

		size_t find(const char* str, size_t pos = 0);//从pos位置查找字串，并且返回下标

		size_t rfind(const char ch, size_t pos = 0);//从尾开始的pos位置开始查找字符，并且返回下标

		size_t rfind(const char* str, size_t pos = 0);//从尾开始的pos位置开始查找字串，并且返回下标

		string substr(size_t pos = 0, size_t len = npos);//获取子串

 	//	string& operator=(const string& s)//=操作符的重载
		//{
		//	if (this != &s)
		//	{
		//		char* tmp = new char[s._capacity + 1];
		//		strcpy(tmp, s._str);
		//		delete[] _str;
		//		_str = tmp;
		//		_size = s._size;
		//		_capacity = s._capacity;	
		//	}
		//	return *this;
		//}

		string& operator=(string s);

		friend std::ostream& operator<<(std::ostream& out, const string& s);
		friend std::istream& operator>>(std::istream& in, string& s);

		void clear();//将字符串边为空字符串
	};
}