#pragma once

template<typename T>
class tvector {
	T *m_data;
	size_t m_size;
	void resize(size_t newSize);
public:
	tvector();
	~tvector();

	tvector(const tvector &o);
	tvector(tvector &&o);

	size_t append(T val);
	size_t remove*size_t idx);

	size_t length() { return m_size; };

	tvector &operator=(const tvector &o);
	tvector &operator=(tvector &&o);


};