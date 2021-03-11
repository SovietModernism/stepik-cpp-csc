#include <iostream>
using namespace std;

struct ICloneable
{
    virtual ICloneable* clone() const = 0;
    virtual ~ICloneable() { }
};

template <typename T>
struct ValueHolder : ICloneable {

    ValueHolder(T value) : data_(value) {};

    ValueHolder * clone() const {
        return new ValueHolder(*this);
    }

    ~ValueHolder() {}

    T data_;
};

class Any
{

public:
    Any() : data_(0){}


    template < class T >
    Any(T data) : data_(new ValueHolder<T>(data)){}

    ~Any(){
        delete data_;
    }

    Any (Any const & obj) : data_(obj.data_->clone()) {}

    template <typename T>
    Any& operator=(const T & obj){
            delete data_;
            data_ = new ValueHolder<T>(obj);
        return *this;
    }

    Any& operator=(const Any & obj){
        if (this != &obj){
            delete data_;
            data_ = obj.data_->clone();
        }
        return *this;
    }

    template <typename T>
    T* cast() {
        if (data_) {
            ValueHolder<T> *res = dynamic_cast<ValueHolder<T> *>(data_);
            if (res) {
                return &(res->data_);
            }
        }
        return 0;
    }

    ICloneable * data_;
};