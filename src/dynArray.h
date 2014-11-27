#ifndef DYNARRAY_H_
#define DYNARRAY_H_

#include <vector>
#include <iterator>

template<typename T>
class dynArray {
	using vec = std::vector<T>;
	vec data;

	using iterator = typename vec::iterator;
	using const_iterator = typename vec::const_iterator;
public:
	dynArray();
	dynArray(std::initializer_list<T> initList);
	dynArray(int count, T value);
	dynArray(std::istream_iterator<T> begin, std::istream_iterator<T> end);
	iterator begin() noexcept;
	const_iterator begin() const noexcept;

};

template<typename T>
inline dynArray<T>::dynArray() :
		data { } {
}

template<typename T>
inline dynArray<T>::dynArray(std::initializer_list<T> initList) :
		data { initList } {
}

template<typename T>
inline dynArray<T>::dynArray(int count, T value) :
		data { count, value } {

}

template<typename T>
inline dynArray<T>::dynArray(std::istream_iterator<T> begin, std::istream_iterator<T> end) :
		data { begin, end } {
}

//DAS LETSCHTE WO INETUESCH ISCH IM -1

#endif /* DYNARRAY_H_ */
