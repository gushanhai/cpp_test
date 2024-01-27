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
		string(const char* str = "");//Ĭ�Ϲ��캯��

		//string(const string& s)
		// ��ͳд���Ŀ������캯��
		//	_size = s._size;
		//	_capacity = s._capacity;
		//	_str = new char[s._capacity + 1];
		//	strcpy(_str, s._str);
		//}

		//�ִ�д���Ŀ������캯��
		string(const string& s);

		~string();//��������
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()//������
		{
			return _str;
		}

		iterator end()//������
		{
			return begin() + _size;
		}

		const_iterator begin() const//������
		{
			return _str;
		}

		const_iterator end() const//������
		{
			return _str + _size;
		}

		const char* c_str() const;//���ַ������н�����
	
		char& operator[](size_t pos);//[]������������

		const char& operator[](size_t pos) const;//[]������������

		size_t size() const;//size_t��������

		void reserve(size_t n);//Ԥ���ַ����洢�ռ�
		
		void append(const char* str);//���ַ�����׷��һ���ַ���

		void push_back(char ch);//���ַ�����׷��һ���ַ�

		string& operator+=(char ch);//+=������������

		string& operator+=(const char* str);//+=������������
		
		void insert(size_t pos, const char ch);//insert()����posλ�ò���һ���ַ�)

		void insert(size_t pos, const char* str);//insert()(��posλ�ò���һ���ַ���)

		//void insert(size_t pos, const char ch)//��posλ�ò���һ���ַ�
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
		//	//ʹ��>��ֹendΪ0ʱ�ٴ�ת����unsigned int���͵�-1��ʽ����ת��Ϊint
		//	//��ֹ������ѭ��
		//	{
		//		_str[end] = _str[end - 1];
		//		//��Ϊ����end>pos
		//		//������endλ�ô���λ��=end-1����λ�ã���ÿ��Ԫ�����Ų��һ���±�
		//		--end;
		//	}
		//	_str[pos] = ch;
		//	_size++;
		//}

		//void insert(size_t pos, const char* str)//��posλ�ò���һ���ַ���
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

		void erase(size_t pos, size_t len = npos);//erase()(��posλ�ÿ�ʼɾ��len���ȵ��ִ�)

		void swap(string& s);//��������string����

		size_t find(char ch, size_t pos = 0);//��posλ�ò����ַ����ҷ����±�

		size_t find(const char* str, size_t pos = 0);//��posλ�ò����ִ������ҷ����±�

		size_t rfind(const char ch, size_t pos = 0);//��β��ʼ��posλ�ÿ�ʼ�����ַ������ҷ����±�

		size_t rfind(const char* str, size_t pos = 0);//��β��ʼ��posλ�ÿ�ʼ�����ִ������ҷ����±�

		string substr(size_t pos = 0, size_t len = npos);//��ȡ�Ӵ�

 	//	string& operator=(const string& s)//=������������
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

		void clear();//���ַ�����Ϊ���ַ���
	};
}