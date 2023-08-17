#pragma once
#include<iostream>


template<typename T>
class Vector {
public:
	typedef T value_type;
	typedef T* iterator;

private:
	T* m_data;
	size_t	 m_size;
	size_t  m_memSize;

public:
	//构造函数
	Vector() : m_data(NULL), m_size(0), m_memSize(0) {}
	Vector(size_t size) : m_data(new T[size]{}), m_size(size), m_memSize(sizeof(T)* size) {}
	Vector(size_t count, T data) {
		m_data = new T[count]{};
		while (count-- > 0) {
			m_data[count] = data;
		}
	}
	//析构函数
	~Vector()
	{
		delete[] m_data;
		m_data = NULL;
		m_size = 0;
		m_memSize = 0;
	}
	//拷贝构造函数
	Vector(const Vector& source)
	{
		//memcpy(m_data, source.m_data, source.m_size);
		m_size = source.m_size;
		m_memSize = source.memSize;
		m_data = new value_type[m_memSize];
		for (int i = 0; i < m_size; ++i) {
			m_data[i] = source.m_data[i];
		}
	}
	//=运算符重载
	Vector& operator=(const Vector& vec) {
		if (this == &vec) {
			return *this;
		}
		value_type* temp = new value_type[vec.m_memSize];
		for (int i = 0; i < vec.m_size; ++i) {
			temp[i] = vec.m_data[i];
		}
		delete[]m_data;
		m_data = temp;
		m_size = vec.m_size;
		m_memSize = vec.m_memSize;
		return *this;
	}
	//[]运算符重载
	value_type& operator[](size_t index) {
		return m_data[index];
	}
	//==运算符重载
	bool operator==(const Vector& vec)const {
		if (m_size != vec.m_size)
		{
			return false;
		}
		for (int i = 0; i < m_size; ++i) {
			if (m_data[i] != vec.m_data[i])
			{
				return false;
			}
		}
		return true;
	}
	//向Vector实例化对象添加元素
	void push_back(value_type val) {
		if (m_memSize == 0) {
			m_memSize = 1;
			m_data = new value_type;
		}
		else if ((m_size + 1) * sizeof(T) > m_memSize) {
			m_memSize *= 2;
			value_type* temp = new value_type[m_memSize];
			for (int i = 0; i < m_size; ++i) {
				temp[i] = m_data[i];
			}
			delete[] m_data;
			m_data = temp;
		}
		m_data[m_size] = val;
		++m_size;
	}
	//删除Vector实例化对象最后一个元素  
	void pop_back() {
		if (m_size != 0)
		{
			m_data[--m_size] = 0;
		}
	}
	//向Vector实例化对象的it位置插入一个元素 
	void insert(iterator it, value_type val) {
		int index = it - m_data;
		if (0 == m_memSize) {
			m_memSize = 1;
			m_data = new value_type[1];
			m_data[0] = val;
		}
		else if (m_size + 1 > m_memSize) {
			m_memSize *= 2;
			value_type* temp = new value_type[m_memSize];
			for (int i = 0; i < index; ++i) {
				temp[i] = m_data[i];
			}
			temp[index] = val;
			for (int i = index; i < m_size; ++i) {
				temp[i + 1] = m_data[i];
			}
			delete[] m_data;
			m_data = temp;
		}
		else {
			for (int i = m_size - 1; i >= index; --i) {
				m_data[i + 1] = m_data[i];
			}
			m_data[index] = val;
		}
		++m_size;

	}

	//删除Vector实例化对象it位置的元素
	void erase(iterator it) {
		size_t index = it - m_data;
		for (int i = index; i< (m_size - 1); ++i) {
			m_data[i] = m_data[i + 1];
		}
		--m_size;
	}

	// 取出Vector对象中的第一个元素 
	value_type front()const {
		return m_data[0];
	}

	// 取出Vector对象中的最后一个元素 
	value_type back()const {
		return m_data[m_size - 1];
	}
	//获取Vector实例化对象的元素首地址
	iterator begin() {
		return m_data;
	}

	//获取Vector实例化对象的最后一个元素的下一个地址
	iterator end() {
		return m_data + m_size;
	}

	//获取Vector实例化对象的元素个数
	size_t size()const {
		return m_size;
	}

	//获取Vector的容积
	size_t capacity()const {
		return m_memSize;
	}

	//判断Vector实例化对象是否为空 
	bool empty() {
		return m_data == m_data + m_size;
	}
};


void Vector_cal_test();
void Vector_io_test();
void Vector_inf_test();