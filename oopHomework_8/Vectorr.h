#pragma once
template<typename T, size_t CAPACITY = 5>
class Vector {
private:
	T* _array = nullptr;
	size_t _size = 0;
	size_t _capacity = CAPACITY;
public:
	Vector() {
		_array = new T[CAPACITY];
	}


	T* getData() const { return _array; }
	size_t size() const { return _size; }
	size_t capacity() const { return _capacity; }
	T& operator[](size_t index) {
		return _array[index];
	}
	Vector& push_back(const T value) {
		if (_size < _capacity)
		{
			_array[_size++] = value;
			return *this;
		}


		_capacity *= 2;
		T* temp = new T[_capacity];

		for (size_t i = 0; i < _size; i++)
			temp[i] = _array[i];

		temp[_size++] = value;

		delete[] _array;
		_array = temp;
		return *this;
	}
	Vector& push_front(const T value) {

		if (_size < _capacity)
		{
			T* temp = new T[_capacity]{};

			temp[0] = value;
			for (size_t i = 1, j = 0; i <= _size; i++)
				temp[i] = _array[j++];
			_size++;
			delete[] _array;
			_array = temp;

			return *this;
		}


		_capacity *= 2;
		T* temp = new T[_capacity];

		temp[0] = value;
		for (size_t i = 0; i < _size; i++)
			temp[i] = _array[i];
		_size++;

		delete[] _array;
		_array = temp;
		return *this;
	}
	Vector& pop_back() {
		T* temp = new T[_capacity]{};
		for (size_t i = 0; i < _size; i++)
			temp[i] = _array[i];
		_size--;
		delete[] _array;
		_array = temp;

		return *this;
	}
	Vector& pop_front() {
		T* temp = new T[_capacity]{};
		for (size_t i = 1, j = 0; i <= _size; i++)
			temp[j++] = _array[i];
		_size--;
		delete[] _array;
		_array = temp;

		return *this;
	}
	void delete_by_index(const size_t index);
	void insert_by_index(const size_t index, const T element);
	size_t find(const T element);
	size_t rfind(const T element);
	void sort(bool reverse = false);
};

template<typename T, size_t CAPACITY>
void Vector<T, CAPACITY>::sort(bool reverse)
{
	for (size_t i = 0; i < _size; i++)
	{
		for (size_t j = 0; j < _size - i - 1; j++)
		{
			if (reverse)
			{
				if (_array[j] < _array[j + 1])
				{
					T temp = _array[j];
					_array[j] = _array[j + 1];
					_array[j + 1] = temp;
				}
			}
			else
			{
				if (_array[j] > _array[j + 1])
				{
					T temp = _array[j];
					_array[j] = _array[j + 1];
					_array[j + 1] = temp;
				}
			}
		}
	}
}

template<typename T, size_t CAPACITY>
size_t Vector<T, CAPACITY>::find(const T element) {
	for (size_t i = 0; i < _size; i++)
	{
		if (_array[i] == element)
			return i;
	}
	return -1;
}


template<typename T, size_t CAPACITY>
size_t Vector<T, CAPACITY>::rfind(const T element) {
	for (size_t i = _size; i >= 0; i--)
	{
		if (_array[i] == element)
			return i;
	}
	return -1;
}

template<typename T, size_t CAPACITY>
void Vector<T, CAPACITY>::delete_by_index(const size_t index) {
	T* temp = new T[_capacity]{};
	for (size_t i = 0; i < index; i++)
		temp[i] = _array[i];
	for (size_t i = index + 1, j = index; i <= _size; i++)
	{
		temp[j++] = _array[i];
	}
	_size--;
	delete[] _array;
	_array = temp;
}

template<typename T, size_t CAPACITY>
void Vector<T, CAPACITY>::insert_by_index(const size_t index, const T element) {
	T* temp = new T[_capacity]{};
	for (size_t i = 0; i < index; i++)
		temp[i] = _array[i];
	temp[index] = element;
	for (size_t i = index + 1, j = index; i <= _size; i++)
	{
		temp[i] = _array[j++];
	}
	_size++;
	delete[] _array;
	_array = temp;
}

