#pragma once
#include<string.h>
#include<assert.h>
#include<iostream>

namespace bt
{
	class string
	{
	private:
		int _size;
		int _capacity;
		char* _str;
		const static int _npos = -1;
	public:
		//默认构造函数
		string(const char* _str = "");
		string(const string& s);
		//默认析构函数
		~string();
		//size方法
		size_t size();
		//reserve方法,为字符串预留空间
		void reserve(size_t n);
		//读取字符串
		char* c_str();
		typedef char* iterator;
		typedef const char* const iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return begin() + _size;
		}

		const iterator begin()const
		{
			return _str;
		}
		const iterator end()const
		{
			return _str + _size;
		}

		const char* operator[](size_t pos)const;
		void append(const char* str);
		void push_back(const char s);
		void append(const char* str)const;
		void push_back(const char s)const;

		string& operator+=(const char* str);
		string& operator+=(const char s);

		void insert(const size_t pos, const char s);
		void insert(const size_t pos, const char* str);

		void earse(const size_t pos = 0, size_t len = _npos);
		void swap(string& s);

		size_t find(const char s, size_t pos);
		size_t find(const char* s, size_t pos = 0);
		size_t rfind(const char s, size_t pos = 0);
		size_t rfind(const char* s, size_t pos = 0);

		char* substr(size_t pos = 0, size_t len = _npos);
		string& operator=(string str);
		void clear();//将字符串变为空字符串
		friend std::ostream& operator<<(std::ostream& out, const string& s);
		friend std::istream& operator>>(std::istream& in, string& s);
	};
}