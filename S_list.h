#pragma once
#include<assert.h>
#include<iostream>
namespace bt
{
	template<class T>
	struct listNode
	{
		listNode<T>* _prev;
		listNode<T>* _next;
		T _data;

		listNode(const T& x= T())
			:_prev(nullptr)
			,_next(nullptr)
			,_data(x)
		{}
	};
	template<class T, class Ref, class Ptr>
	struct __list_iterator
	{
		typedef listNode<T> Node;
		typedef __list_iterator<T, Ref, Ptr> self;
		Node* _node;

		__list_iterator(Node* x)
			:_node(x)
		{}

		// ++it
		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		// it++
		self operator++(int)
		{
			//__list_iterator<T> tmp(*this);
			self tmp(*this);

			_node = _node->_next;

			return tmp;
		}

		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		self operator--(int)
		{
			self tmp(*this);

			_node = _node->_prev;

			return tmp;
		}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		bool operator!=(const self& x) const
		{
			return _node != x._node;
		}

		bool operator==(const self& x) const
		{
			return _node == x._node;
		}
	};

	template<class T, class Ptr>
	struct Reverse_iterator
	{
		typedef listNode<T> node;
		typedef Reverse_iterator<T, Ptr> self;
		node* _node;
		Reverse_iterator(node* x)
			:_node(x)
		{}

		T& operator*()
		{
			return _node->_data;
		}

		self& operator++()
		{
			_node = _node->_prev;
			return *this;
		}

		self operator++(int)
		{
			self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		self& operator--()
		{
			_node = _node->_next;
			return *this;
		}

		self operator--(int)
		{
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}
		bool operator!=(const self& x) const
		{
			return _node != x._node;
		}

		bool operator==(const self& x) const
		{
			return _node == x._node;
		}
	};

	/*template<class iterator, class Ref, class Ptr>
	struct Reverse_iterator
	{
		typedef Reverse_iterator<iterator, Ref, Ptr> self;
		iterator _it;
		Reverse_iterator(iterator& x)
			:_it(x)
		{}

		Ref operator*()
		{
			iterator tmp = _it;
			return *tmp;
		}


		self& operator++()
		{
			--_it;
			return *this;
		}

		self operator++(int)
		{
			self tmp(*this);
			--_it;
			return tmp;
		}

		self& operator--()
		{
			++_it;
			return *this;
		}

		self operator--(int)
		{
			self tmp(*this);
			++_it;
			return tmp;
		}

		Ptr operator->()
		{
			return &(operator*());	
		}

		bool operator==(const self& x)
		{
			return (_it == x._it);
		}
		bool operator!=(const self& x)
		{
			return (_it != x._it);
		}
	};*/

	//template<class T>
	//struct __const_iterator_list
	//{
	//	typedef listNode<T> node;
	//	typedef __const_iterator_list<T> self;
	//	node* _node;
	//	__const_iterator_list(node* x)
	//		:node(x)
	//	{}
	//	const T& operator*()
	//	{
	//		return _node->_data;
	//	}
	//	
	//	self& operator++()
	//	{
	//		_node = _node->_next;
	//		return *this;
	//	}

	//	self& operator++(int)
	//	{
	//		self tmp(*this);
	//		_node = _node->_next;
	//		return tmp;
	//	}

	//	self& operator--()
	//	{
	//		_node = _node->_prev;
	//		return *this;
	//	}

	//	self& operator--(int)
	//	{
	//		self tmp(*this);
	//		_node = _node->_prev;
	//		return tmp;
	//	}

	//	bool operator!=(const self& x)
	//	{
	//		return x._node != _node;
	//	}

	//	bool operator==(const self& x)
	//	{
	//		return x._node == _node;
	//	}
	//};
	template<class T>
	class list
	{
		typedef listNode<T> Node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;
		//typedef Reverse_iterator<T,T&> r_iterator;
		typedef Reverse_iterator<T, T&> r_iterator;

		void empty_init()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		list()
		{
			empty_init();
		}
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		~list()
		{
			clear();

			delete _head;
			_head = nullptr;
		}

		//list(const list<T>& lt)
		list(list<T>& lt)
		{
			empty_init();

			for (const auto& e : lt)
			{
				push_back(e);
			}
		}

		// lt1 = lt2;
		// list<T>& operator=(const list<T>& lt)
		/*list<T>& operator=(list<T>& lt)
		{
			if (this != &lt)
			{
				clear();
				for (const auto& e : lt)
				{
					push_back(e);
				}
			}
			return *this;
		}*/

		void swap(list<T>& tmp)
		{
			std::swap(_head, tmp._head);
		}

		//list& operator=(list lt)
		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}

		void push_back(const T& x)
		{
			/*Node* newnode = new Node(x);
			Node* tail = _head->_prev;

			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;*/

			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		iterator begin()
		{
			return _head->_next;
		}

		iterator end()
		{
			return _head;
		}

		const_iterator begin() const
		{
			return _head->_next;
		}

		const_iterator end() const
		{
			return _head;
		}

		r_iterator rbegin()
		{
			return (r_iterator)_head->_prev;
		}

		r_iterator rend()
		{
			return (r_iterator)_head;
		}

		// vector insert会导致迭代器失效
		// list不会导致迭代器失效，因为list是新增结点，并不会进行扩容
		iterator insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);

			// prev newnode cur
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;

			//return iterator(newnode);
			return newnode;
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());

			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;
			prev->_next = next;
			next->_prev = prev;

			delete cur;

			return next;
		}

	private:
		Node* _head;
	};
}