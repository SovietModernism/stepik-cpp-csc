struct ICloneable
{
	virtual ICloneable* clone() const = 0;
	virtual ~ICloneable() { }
};

template <typename T>
struct ValueHolder : ICloneable {
    
	ValueHolder(T const  & a) : data_(a) {}
    
	ValueHolder* clone() const {
		return new ValueHolder(data_);
	}
    
	T data_;
};