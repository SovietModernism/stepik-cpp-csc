#include <cstddef>

struct Expression;
struct Number;
struct BinaryOperation;
struct FunctionCall;
struct Variable;

struct Counter 
{
public:
  void addref() { count_++; }
  size_t release() { return --count_; }

private:
  size_t count_; // reference counter
};

struct SharedPtr
{
  explicit SharedPtr(Expression *ptr = 0) {
    ptr_ = ptr;
    reference_ = 0;
    if (ptr_ != 0) {
      reference_ = new Counter();
      reference_->addref();
    }
  }

  ~SharedPtr() {
    if (ptr_ != 0) {
      if (reference_->release() == 0) {
	delete ptr_;
	delete reference_;
      }
    }
  }

  SharedPtr(const SharedPtr & sp)
    : ptr_(sp.ptr_), reference_(sp.reference_) {
    if (ptr_ != 0) {
      reference_->addref();
    }
  }

  SharedPtr& operator=(const SharedPtr & sp) {
    if (this != &sp) {
      if (ptr_ != 0) {
	if (reference_->release() == 0) {
	  delete ptr_;
	  delete reference_;
	}
      }
      if (sp.ptr_ != 0) {
	// копируем данные и счетчик, а потом инкремент счетчика
	ptr_ = sp.ptr_;
	reference_ = sp.reference_;
	reference_->addref();
      }
    }
    return *this;
  }

  Expression* get() const { return ptr_; }

  void reset(Expression *ptr = 0) {

    if (ptr_) {
      if (reference_->release() == 0) {
	delete ptr_;
	delete reference_;
      }
    }

    ptr_ = ptr;
    reference_ = 0;
    if (ptr_ != 0) {
      reference_ = new Counter();
      reference_->addref();
    }
  }

  Expression& operator*() const { return *ptr_; }

  Expression* operator->() const { return ptr_; }


private:
  Expression *ptr_;
  Counter *reference_;
};