template <typename X, typename Y>
struct SameType
{
    static const bool value = false;
};

template <typename T>
struct SameType<T, T>
{
    static const bool value = true;
};