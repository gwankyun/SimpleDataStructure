#pragma once

template<typename T>
class Vector
{
public:
	Vector(int size) : _room(size), _size(0)
	{
		_data = new T[_room];
	}

	~Vector()
	{
		delete[] _data;
	}

	T get(int index)
	{
		return _data[index];
	}

	T set(int index, T value)
	{
		_data[index] = value;
	}

	void push_back(T value)
	{
		if (_size == _room)
		{
			extend();
		}
		_data[_size] = value;
		_size++;
	}

	int size()
	{
		return _size;
	}

private:
	T* _data = nullptr;
	int _size = 0;
	int _room = 0;

	void extend()
	{
		T* newData = new T[_size * 2];
		_room *= 2;
		std::copy(_data, _data + _size, newData);
		delete[] _data;
		_data = newData;
	}
};
