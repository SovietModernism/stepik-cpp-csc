#include <cstddef>

template <typename T>
class Array {
public:
    explicit Array(size_t size, const T& value = T()): size_(size), ptr_((T*) new char[size_*sizeof(T)]) {
        for (size_t i = 0; i != size_; i++)
                new (&ptr_[i]) T(value);
    }
    Array(): size_(0), ptr_(nullptr) {}
    Array(const Array & in) : size_(in.size_), ptr_((T*) new char[size_*sizeof(T)]){
        for (size_t i = 0; i != size_; i++)
            new (&ptr_[i]) T(in[i]);
    }
    ~Array() {
        for (size_t i = 0; i != size_; i++)
            ptr_[i].~T();
        delete [] ((char *)ptr_);
    }
    void swap(Array &other){
        std::swap(size_, other.size_);
        std::swap(ptr_, other.ptr_);
    }
    Array& operator=(const Array &in){
        if (&in != this)
            Array(in).swap(*this);
        return *this;
    }
    size_t size() const {return size_;}
    T& operator[](size_t ind) {return ptr_[ind];}
    const T& operator[](size_t ind) const {return ptr_[ind];}
private:
    size_t size_;
    T* ptr_;
};