#include <cstddef>

template <typename T>
class Array
{
	public:

    	explicit Array(size_t size = 0, const T& value = T()) {
		_array = new T[size];
		_size = size;
		for(size_t i = 0; i < size; i++) {
			_array[i] = value;
		}
	}

    Array(const Array & a) : _array(new T[a._size]), _size(a._size) {
		for(size_t i = 0; i < _size; i++)
			_array[i] = a._array[i];
	}

    ~Array() {
		delete [] _array;
	}

    Array& operator=(const Array & a) { 
		if(this != &a) {
			delete [] _array;
			_size = a._size;
			_array = new T[_size];
			for(size_t i = 0; i < _size; i++)
				_array[i] = a._array[i];
		}
		return *this;
	}
  

    size_t size() const {
		return _size;
	}

    T& operator[](size_t i) {
		return _array[i];
	}

    const T& operator[](size_t i) const {
		return _array[i];
	}

	private:
	T * _array;
	size_t _size;
};