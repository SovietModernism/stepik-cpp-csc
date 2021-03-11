#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
	String(const char *str = "");
	String(size_t n, char c);
	~String();


	void append(String &other)
	{
	    size+=other.size;
	    char * m=new char[size+1];
	    strcpy(m,str);
	    strcat(m,other.str);
	    
	    delete [] str;
	    str=m;
    }

	size_t size;
	char *str;
};