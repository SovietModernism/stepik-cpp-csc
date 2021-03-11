#include <cstddef>

template<class U, class T>
void copy_n(T * ta, U * ua, int n) {
	for(int i = 0; i < n; i++) {
		ta[i] = (T)(ua[i]);
	}
}