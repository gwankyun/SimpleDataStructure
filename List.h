#pragma once
#include <cassert>

template<typename T>
class Node
{
public:
	T* data;
	Node<T>* next;
	Node()
	{
		data = nullptr;
		next = nullptr;
	}

	Node(T d)
	{
		data = new T(d);
		next = nullptr;
	}

	~Node()
	{
		if (data != nullptr)
		{
			delete data;
		}
	}

private:

};


template<typename T>
class List
{
public:
	List() : _begin(new Node<T>()), _end(new Node<T>()), _size(0)
	{
		//_begin = new Node<T>;
		//_end = new Node<T>;
		_begin->next = _end;
		assert(_end != nullptr);
	}
	~List()
	{

	}

	void push_back(T value)
	{
		//if (_end == nullptr)
		//{
		//	std::cout << "_end is nullptr" << std::endl;
		//}
		if (_size == 0)
		{
			_begin->data = new T(value);
			_size++;
		}
		else
		{
			assert(_end != nullptr);
			_end->data = new T(value);
			_end->next = new Node<T>();
			_end = _end->next;
			_size++;
		}
	}

	Node<T>* begin()
	{
		return _begin;
	}

	Node<T>* end()
	{
		return _end;
	}

private:
	Node<T>* _begin;
	Node<T>* _end;
	int _size;
};
