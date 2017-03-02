#pragma once

template<typename T>
class Node
{
public:
	T data;
	Node<T>* next;
	Node()
	{
	}

	Node(T d)
	{
		data = d;
		next = nullptr;
	}

	~Node()
	{
		next = nullptr;
	}

private:

};


template<typename T>
class List
{
public:
	List()
	{
		_end = _begin.next;
	}
	~List()
	{

	}

	void push_back(T value)
	{
		Node<T> node = Node<T>(value);
		_end = node;
		_end = node.next;
	}

	Node<T> begin()
	{
		return _begin;
	}

	Node<T> end()
	{
		return _end;
	}

private:
	Node<T> _begin = Node<T>();
	Node<T> _end = nullptr;
};
