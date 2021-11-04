#pragma once
#include <iostream>

using namespace std;

template <class T> struct Node
{
	T value;
	Node* next;
	Node* prev;
};

template <class T> class Ring
{
	template <class T> friend class Iterator;
	Node<T>* first;
	Node<T>* last;
public:
	class Iterator;
	Ring();
	Ring(Ring<T>& ring) {
		first = ring.first;
		last = ring.last;
	}
	~Ring();
	bool isEmpty();
	void push_back(T);
	void push_front(T);
	void show();
	int getSize();
	void sortFIO();
	void sortGr();
	void DellEl(string fio);
	void del(Node<T>*);
	void insert(T&, int);
	Node<T>* search(string);
	Node<T>* getBegin() { return first; }
	Node<T>* getEnd() { return last; }
	Node<T>* searchGr(string);
};


template <class T> class Iterator {
	Node<T>* cur;
	Ring<T>* ptr;
public:
	Iterator() {
		cur = NULL;
		ptr = NULL;
	}
	Iterator(Ring<T>& list) {
		ptr = &list;
		cur = list.first;
	}
	Iterator(const Iterator& it) {
		cur = it.cur;
		ptr = it.ptr;
	}

	Iterator<T>& End(){
		cur = ptr->last;
		return *this;
	}

	Iterator<T>& Begin() {
		cur = ptr->first;
		return *this;
	}

	Iterator<T>& operator++() {
		cur = cur->next;
		return *this;
	}
	Iterator<T>& operator--() {
		cur = cur->prev;
		return *this;
	}

	bool operator!=(const Iterator<T>& it) {
		return cur != it.cur;
	}
	bool operator==(const Iterator<T>& it) {
		return cur == it.cur;
	}

	Iterator<T>& operator=(const Iterator<T>& it) {
		cur = it.cur;
		ptr = it.ptr;
		return *this;
	}

	Iterator<T>& operator=(const T& it) {
		cur->value = it;
		return *this;
	}

	/*bool operator!=(const Node<T>* it) {
		return cur != it;
	}
	bool operator==(const Node<T>& it) {
		return cur == it;
	}*/

	bool operator>(const Iterator<T>& it) {
		return cur->value.getFIO() > it.cur->value.getFIO();
	}
	bool operator<(const Iterator<T>& it) {
		return cur->value.getFIO() < it.cur->value.getFIO();
	}

	T& operator*() {
		return cur->value;
	}
};

template <class T> void Ring<T>::sortGr() {
	T tempdata;
	Node<T>* temp1 = first;
	int n = getSize();

	for (int x = 0; x < n - 1; x++)
	{
		Node<T>* temp2 = temp1->prev;

		for (int i = x; i < n - 1; i++)
		{
			if (temp1->value.getGroup() == temp2->value.getGroup()) {
				if (temp1->value.getFIO() < temp2->value.getFIO())
				{
					tempdata = temp2->value;
					temp2->value = temp1->value;
					temp1->value = tempdata;
				}
			}else if (temp1->value.getGroup() < temp2->value.getGroup())
			{
				tempdata = temp2->value;
				temp2->value = temp1->value;
				temp1->value = tempdata;
			}

			temp2 = temp2->prev;
		}
		temp1 = temp1->prev;
	}
}

template <class T> inline Ring<T>::Ring()
{
	first = NULL;
	last = NULL;
}

template <class T> inline Ring<T>::~Ring()
{
	while (first != last){
		Node<T>* temp = first;
		first = first->prev;
		delete temp;
	}
	delete last;
}

template <class T> bool Ring<T>::isEmpty() {
	return first == NULL;
}

template <class T> void Ring<T>::push_back(T value) {
	Node<T>* newlink = new Node<T>;
	newlink->value = value;
	
	if (first) {
		newlink->prev = first;
		first->next = newlink;
	} else last = newlink;

	newlink->next = last;
	last->prev = newlink;
	first = newlink;
}

template<class T> void Ring<T>::insert(T& dat, int index)
{
	if (index == getSize()) push_back(dat);
	else if (index == 1) push_front(dat);
	else {
		Node<T>* tmp = first;
		for (int i = 0; i < index - 1; i++) {
			tmp = tmp->next;
		}
		Node<T>* newNode = new Node<T>;
		newNode->value = dat;
		newNode->next = tmp->next;
		tmp->next->prev = newNode;
		newNode->prev = tmp;
		tmp->next = newNode;
	}
}

template <class T> void Ring<T>::push_front(T value) {
	Node<T>* newlink = new Node<T>;
	newlink->value = value;

	if (last) {
		newlink->next = last;
		last->prev = newlink;
	}
	else first = newlink;

	newlink->prev = first;
	first->next = newlink;
	last = newlink;
}

//template <class T> void Ring<T>::pop_back() {
//	cout << last;
//	del(last);
//}
//
//template <class T> void Ring<T>::pop_front() {
//	del(first);
//}

template <class T> void Ring<T>::show() {
	if (first) {
		Node<T>* temp = last;
		do {
			cout << temp->value << endl;
			temp = temp->next;
		} while (temp != last);
	}
}

template <class T> int Ring<T>::getSize(){
	if (first)
	{
		Node<T>* temp = first;
		int i = 0;

		do
		{
			temp = temp->prev;
			i++;
		} while (temp != first);

		return i;
	}
	else {
		return 0;
	}
}

template <class T> void Ring<T>::sortFIO() {
	T tempdata;
	Node<T>* temp1 = first;
	int n = getSize();

	for (int x = 0; x < n - 1; x++)
	{
		Node<T>* temp2 = temp1->prev;

		for (int i = x; i < n - 1; i++)
		{
			if (temp1->value.getFIO() < temp2->value.getFIO())
			{
				tempdata = temp2->value;
				temp2->value = temp1->value;
				temp1->value = tempdata;
			}

			temp2 = temp2->prev;
		}
		temp1 = temp1->prev;
	}
}

template <class T> void Ring<T>::DellEl(string fio) {
	Node<T>* temp = search(fio);
	del(temp);
}

/*while (first->prev != last)
	{
		Node<T>* temp = first->prev;
		first = first->prev;
		delete temp;
	}
	last = NULL;
	first = NULL;*/



template <class T> void Ring<T>::del(Node<T>* temp) {
	//if (first)                  
	//{
		if (temp->next == temp)    
		{
			first = NULL;
			last = NULL;
		}
		else
		{
			if (temp == last)     
				last = last->next;

			if (temp == first)     
				first = first->prev;

			(temp->next)->prev = temp->prev;
			(temp->prev)->next = temp->next;

			delete temp;
		}
	//}
}

template <class T> Node<T>* Ring<T>::search(string fio) {
	Node<T>* temp = first;

	if (first) {
		do
		{
			if (temp->value.getFIO() == fio) {
				//cout << temp->value;
				return temp;
			}

			temp = temp->prev;

		} while (temp != first);
	} 
	return NULL;
}

template <class T> Node<T>* Ring<T>::searchGr(string gr) {
	Node<T>* temp = first;

	if (first) {
		do
		{
			if (temp->value.getGroup() == gr) {
				//cout << temp->value;
				return temp;
			}

			temp = temp->prev;

		} while (temp != first);
	}
	return NULL;
}