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
		//Ĭ�Ϲ��캯��
		string(const char* _str = "");
		string(const string& s);
		//Ĭ����������
		~string();
		//size����
		size_t size();
		//reserve����,Ϊ�ַ���Ԥ���ռ�
		void reserve(size_t n);
		//��ȡ�ַ���
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
		void clear();//���ַ�����Ϊ���ַ���
		friend std::ostream& operator<<(std::ostream& out, const string& s);
		friend std::istream& operator>>(std::istream& in, string& s);
	};
}