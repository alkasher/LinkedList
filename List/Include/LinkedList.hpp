#include "Element.hpp"

template<class T>
class LinkedList {
protected:
	Element<T>* head;
	Element<T>* tail;
public:
	LinkedList<T>();
	LinkedList<T>(const T* arr, int len);

	LinkedList<T>(const LinkedList<T>& another_list);

	void print() const;

	Element<T>* operator[](int index) const;

	void push_back(T info);

	void push_back(const T* arr, const int len);

	void insert(const int index, const T info);

	void remove(const int index);

	Element<T>* get_head() const;
	Element<T>* get_tail() const;
	int size() const;

	virtual ~LinkedList();
};

template<class T>
LinkedList<T>::LinkedList<T>() : head(nullptr), tail(nullptr) {}

template <class T>
LinkedList<T>::LinkedList<T>(const T* arr, int len) {
	if (len <= 0) throw InvalidLengthException("LinkedList constructor: InvalidLength");
	if (arr == nullptr) throw NullptrException("LinkedList constructor: Nullptr");
	Element<T>* current;
	if (!(current = new Element<T>(arr[0])))
		throw NotEnoughSpaceException("LinkedList constructor: NotEnoughSpace");
	head = current;
	for (int i = 1; i < len; ++i) {
		if (!(current->next = new Element<T>(current, nullptr, arr[i])))
			throw NotEnoughSpaceException("LinkedList constructor: NotEnoughSpace");
		current = current->next;
	}
	tail = current;
}

template <class T>
LinkedList<T>::LinkedList<T>(const LinkedList<T>& another_list) {
	if (another_list.head == nullptr || another_list.tail == nullptr)
		throw NullptrException("LinkedList CopyConstructor: Nullptr");
	Element<T>* current;
	Element<T>* current_another = another_list.head;
	if (!(current = new Element<T>(current_another)))
		throw NotEnoughSpaceException("LinkedList constructor: NotEnoughSpace");
	head = current;
	while (current_another != another_list.tail) {
		current_another = current_another->next;
		if (!(current->next = new Element<T>(current, nullptr, current_another)))
			throw NotEnoughSpaceException("LinkedList constructor: NotEnoughSpace");
		current = current->next;

	}
	tail = current;
}

template <class T>
void LinkedList<T>::print() const {
	std::cout << "\n\n";
	if (head == nullptr) return;//used for testing destructor
	for (Element<T>* current = head; current != tail; current = current->next) {
		std::cout << current->get_info() << ' ';
	}
	std::cout << tail->get_info();
}

template <class T>
Element<T>* LinkedList<T>::operator[](int index) const {
	Element<T>* current = head;
	for (int i = 0; i < index; ++i, current = current->next) {
		if (current == tail)
			throw InvalidLengthException("operator[]: InvalidLength");
	}
	return current;
}


template <class T>
void LinkedList<T>::push_back(T info) {

	Element<T>* elem;
	if (!(elem = new Element<T>(info)))
		throw NotEnoughSpaceException("LinkedList push: NotEnoughSpace");
	if (head == nullptr) { tail = elem; head = elem; }
	if (tail != nullptr) {
		tail->next = elem;
		elem->prev = tail;
		tail = elem;
	}
}


template <class T>
void LinkedList<T>::push_back(const T* arr, const int len) {
	if (arr == nullptr) throw NullptrException("push_back: Nullptr");
	if (len <= 0) throw InvalidLengthException("push_back: InvalidLength");

	Element<T>* current;
	if (!(current = new Element<T>(arr[0])))
		throw NotEnoughSpaceException("push_back: NotEnoughSpace");
	if (head == nullptr) {
		head = current;
	}
	else {
		tail->next = current;
	}
	for (int i = 1; i < len; ++i) {
		if (!(current->next = new Element<T>(current, nullptr, arr[i])))
			throw NotEnoughSpaceException("LinkedList constructor: NotEnoughSpace");
		current = current->next;
	}
	tail = current;
}


template <class T>
Element<T>* LinkedList<T>::get_head() const {
	return head;
}

template <class T>
Element<T>* LinkedList<T>::get_tail() const {
	return tail;
}

template <class T>
int LinkedList<T>::size() const {
	int size = 0;
	if (head == nullptr) return 0;
	for (Element<T>* current = head; current != tail; current = current->next, ++size) {
	}
	return ++size;
}


template <class T>
LinkedList<T>::~LinkedList() {
	if (head != nullptr) {
		Element<T>* current = head;
		while (current != tail) {
			current = current->next;
			delete current->prev;
		}
		delete current;
		head = nullptr;
		tail = nullptr;
	}
	std::cout << "\ndestructor\n";
	this->print();
	std::cout << "\ndestructor worked correctly, if nothing was above\n\n\n";
}

template <class T>
void LinkedList<T>::insert(const int index, const T info) {
	if (index < 0)
		throw InvalidLengthException("LinkedList insert: InvalidIndex");
	Element<T>* elem;
	if (!(elem = new Element<T>(info)))
		throw NotEnoughSpaceException("LinkedList insert: NotEnoughSpace");

	if (head == nullptr) {
		if (index > 0)
			throw InvalidLengthException("LinkedList insert: InvalidIndex");
		head = tail = elem;
		return;
	}

	Element<T>* current = head;

	if (head == tail) {
		if (index == 0) {
			head = elem;
			elem->next = current;
			current->prev = elem;
			tail = current;
			return;
		}
		else if (index == 1) {
			current->next = elem;
			elem->prev = current;
			tail = elem;
			return;
		}
		else
			throw InvalidLengthException("LinkedList insert: InvalidIndex");
	}

	for (int i = 0; i < index; ++i, current = current->next) {
		if (current == tail) {

			if (i == index - 1) { // instead of this cases I could've checked list length -> what is more efficient?
				// then use something like if (index == length - 1)
				current->next = elem;
				elem->prev = current;
				tail = elem;
				return;
			}
			else if (index - i == 2) {
				elem->next = current;
				elem->prev = current->prev;
				current->prev->next = elem;
				current->prev = elem;
				tail = current;
				return;
			}
			else {
				throw InvalidLengthException("LinkedList insert: InvalidIndex");
			}
		}
	}
	if (index == 0) {
		current->prev = elem;
		elem->next = current;
		head = elem;
		return;
	}
	elem->next = current;
	elem->prev = current->prev;
	current->prev->next = elem;
	current->prev = elem;
	return;
}

template <class T>
void LinkedList<T>::remove(const int index) {
	if (index < 0 || head == nullptr)
		throw InvalidLengthException("LinkedList remove: InvalidIndex");
	if (head == tail) {
		if (index > 0)
			throw InvalidLengthException("LinkedList remove: InvalidIndex");
		delete head;
		head = tail = nullptr;
		return;
	}
	Element<T>* current = head;
	for (int i = 1; i <= index; ++i, current = current->next) {
		if (current == tail && index > i) {
			throw InvalidLengthException("LinkedList remove: InvalidIndex");
		}
	}
	if (current == head) {
		head = current->next;
		delete current;
		head->prev = nullptr;
		return;
	}
	if (current == tail)
	{
		tail = current->prev;
		delete current;
		tail->next = nullptr;
		return;
	}

	current->next->prev = current->prev;
	current->prev->next = current->next;
	delete current;
}