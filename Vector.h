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

		~vector()//��������
		{
			if (_start)//�����ǰ��ǰ�ռ���������
			{
				delete[] _start;//�ͷſռ�
				_finish = _start = end_of_storage = nullptr;//ָ���ƿ�
			}
		}

		void reserve(size_t n)//Ԥ���ռ�
		{
			if (n > capacity())//�жϵ�ǰ�ռ��Ƿ��㹻
			{
				size_t old = size();//��ȡԭ���ռ��С
				T* tmp = new T[n];//���¿���n���ռ�Ĵ�С
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T) * old);//��ԭ���ռ�����ݿ������¿ռ�
					delete[] _start;//�ͷžɿռ�
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

		void insert(iterator pos, const T& x)//��posλ�ò���
		{
			assert(_pos >= start && pos <= _finish);//�жϲ���λ���Ƿ�Ϸ�
			if (_finish == _end_of_storage)//�жϵ�ǰ�ռ��Ƿ񹻲���
			{
				size_t len = pos - _start;//��¼Ӧ�ò�����±�
				reserve(capacity() == 0 ? 4 : 2 * capacity());//����
				pos = len + _start;//��Ӧ�ò�����±�λ��pos���и���
				//���������posλ�ã��ᵼ�²���ʧ��
				//����ʧ�ܵ�ԭ���ǵ�����ʧЧ
				//������ʧЧ��ԭ������Ϊԭ���ĵ�������¼��λ���Ѿ�ʧЧ�ˣ���������Ȼ��ʧЧ�ĵ�����
				//��¼��λ�ý��з��ʻ��߲���
				//�ڶԿռ�����޸ĺ�һ��Ҫ����������λ�ý��и���
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