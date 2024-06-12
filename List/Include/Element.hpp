#pragma once
#include "Exception.hpp"

template <class T>
class Element {
protected:
	Element<T>* next;
	Element<T>* prev;
	T info;
public:
	Element<T>(T info);

	Element<T>(const Element<T>& elem);

	Element<T>(const Element<T>& prev, const Element<T>& next, const T info);

	Element<T>(Element<T>* prev, std::nullptr_t, const T info);

	T get_info() const;

	~Element<T>();

	template <class T>
	friend class LinkedList;
	template <class T>

	friend std::ostream& operator<<(std::ostream& s, LinkedList<T>& el);
};

template<class T>
Element<T>::Element<T>(T info) : info(info), next(nullptr), prev(nullptr) {}

template <class T>
Element<T>::Element<T>(const Element<T>& elem) :
	next(elem.next), prev(elem.prev), info(elem.info) {}

template <class T>
Element<T>::Element<T>(const Element<T>& prev, const Element<T>& next, const T info)
	: prev(prev), next(next), info(info) {}

template <class T>
Element<T>::Element<T>(Element<T>* prev, std::nullptr_t, const T info) :
	prev(prev), next(nullptr), info(info) {}

template <class T>
T Element<T>::get_info() const {
	return info;
}

template <class T>
Element<T>::~Element<T>() {}

template<class T>
std::ostream& operator<<(std::ostream& s, Element<T>& el)
{
	s << el.info;
	return s;
}