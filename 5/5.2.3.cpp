struct Rational {
    Rational(int numerator = 0, int denominator = 1);

    void add(Rational rational);
    void sub(Rational rational);
    void mul(Rational rational);
    void div(Rational rational);

    void neg();
    void inv();
    double to_double() const;

	Rational & operator+=(Rational const & other) { 
		add(other);
		return *this;
	}

	Rational & operator-=(Rational const & other) { 
		sub(other);
		return *this;
	}

	Rational & operator*=(Rational const & other) { 
		mul(other);
		return *this;
	}

	Rational & operator/=(Rational const & other) { 
		div(other);
		return *this;
	}

	Rational & operator+=(int i) { 
		numerator_ += (i * denominator_);
		return *this;
	}

	Rational & operator-=(int i) { 
		numerator_ -= (i * denominator_);
		return *this;
	}

	Rational & operator*=(int i) { 
		numerator_ *= i;
		return *this;
	}

	Rational & operator/=(int i) { 
		denominator_ *= i;
		return *this;
	}

	private:
	int numerator_;
	int denominator_;
};

Rational operator+(Rational left, Rational const & right) { 
	return left += right;                          
}                                                  

Rational operator-(Rational left, Rational const & right) { 
	return left -= right;                          
}                                                  

Rational operator*(Rational left, Rational const & right) { 
	return left *= right;                          
}                                                  

Rational operator/(Rational left, Rational const & right) { 
	return left /= right;
}


Rational operator+(Rational left, int i) { 
	return left += i;                          
}                                                  

Rational operator-(Rational left, int i) { 
	return left -= i;                          
}                                                  

Rational operator*(Rational left, int i) { 
	return left *= i;                          
}                                                  

Rational operator/(Rational left, int i) { 
	return left /= i;                          
}                                                  

Rational operator-(Rational left) { 
	left.neg();
	return left;
}

Rational operator+(Rational left) { 
	return left;
}