#include <cstddef>

template<typename T, size_t N>
size_t array_size(T (&arr)[N]) {
  return N;
}