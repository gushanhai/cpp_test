#define _CRT_SECURE_NO_WARNINGS 1

using namespace std;

#pragma once

#include<assert.h>
#include<iostream>

namespace bt
{
	template <class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const iterator;
		//vector(const vecotr<T>& v)
		//{
		//	_start = new T[v.capacity()];
		//	memcpy(_start, v._start, v.size() * sizeof(T));
		//	_finish = _start + v.size();
		//	_end_of_storage = _start + capacity();
		//}

		vector(const vector<T>& v)
		{
			reserve(v.capacity());
			for (auto e : v)
			{
				push_back(e);
			}
		}

		~vector()//析构函数
		{
			if (_start)//如果当前当前空间中有数据
			{
				delete[] _start;//释放空间
				_finish = _start = end_of_storage = nullptr;//指针制空
			}
		}

		void reserve(size_t n)//预留空间
		{
			if (n > capacity())//判断当前空间是否足够
			{
				size_t old = size();//获取原来空间大小
				T* tmp = new T[n];//重新开辟n个空间的大小
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T) * old);//将原来空间的内容拷贝到新空间
					delete[] _start;//释放旧空间
				}
				_start = tmp;
				_finish = _start + old;
				_end_of_storage = _start + n;
			}
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}
		
		const iterator begin() const
		{
			return _start;
		}

		const iterator end() const
		{
			return _finish;
		}

		size_t size()
		{
			return _finish - _start;
		}

		size_t capacity()
		{
			return _end_of_storage - _start;
		}

		void push_back(const T& x)
		{
			if (_end_of_storage == _finish)
			{
				size_t newcapacity = capacity() == 0 ? 4 : 2 * capacity();
				reserve(newcapacity);
			}
			*_finish = x;
			++_finish;
		}

		void pop_back(const T& x)
		{
			assert(size()> 0);
			_finish--;
		}

		void insert(iterator pos, const T& x)//在pos位置插入
		{
			assert(_pos >= start && pos <= _finish);//判断插入位置是否合法
			if (_finish == _end_of_storage)//判断当前空间是否够插入
			{
				size_t len = pos - _start;//记录应该插入的下标
				reserve(capacity() == 0 ? 4 : 2 * capacity());//扩容
				pos = len + _start;//将应该插入的下标位置pos进行更新
				//如果不更新pos位置，会导致插入失败
				//插入失败的原因是迭代器失效
				//迭代器失效的原因是因为原来的迭代器记录的位置已经失效了，而我们依然对失效的迭代器
				//记录的位置进行访问或者操作
				//在对空间进行修改后，一定要将迭代器的位置进行更新
			}
			memmove(pos + 1, sizeof(T) * (_finish - _start));
			*pos = x;
		}


		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}
	private:
		iterator* _start;
		iterator* _finish;
		iterator* _end_of_storage;
	};
}