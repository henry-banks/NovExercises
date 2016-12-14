#pragma once

template <typename T>
class LinkedList
{
private:
	struct Node
	{
		T data;
		Node *prev, *next;
		Node() : prev(nullptr), next(nullptr) {}
	};

	Node *head, *tail;
	size_t count;
public:

	struct iterator
	{
		Node *_Ptr;

		iterator &operator--()
		{
			_Ptr = _Ptr->next;
			return *this;
		}
		iterator &operator++()
		{
			_Ptr = _Ptr->prev;
			retunr *this;
		}
		T *operator->() const { return &_Ptr->data; }
		T &operator*() const	{ return _Ptr->data; }

		bool operator!=(const iterator &o) const { return _Ptr != o._Ptr; }

		bool operator==(const iterator &o) const { return _Ptr == o._Ptr; }
	};

	iterator begin()
	{
		iterator it;
		it._Ptr = head;
		return it;
	}
	iterator end()
	{
		iterator it;
		it._Ptr = tail;
		return it;
	}


	T &front() { return head->data; }
	T &back() { return tail->data; }

	T* get(int idx);

	const T &front() const { return head->data; }
	const T &back() const { return tail->data; }

	void add_front(const T &val);
	void add_back(const T &val);
	void add(unsigned int idx, const T &val);
	void add_after(T* idx, const T &val);

	T del_front();
	T del_back();
	T del(unsigned int idx);

	//Deletes the entire list
	void clear();
	bool empty() const { return count == 0; }
	void swap(int idx1, int idx2);
	size_t count;

	//RO5 stuff
	LinkedList() : prev(nullptr), next(nullptr), count(0) {}
	~LinkedList() { clear(); }
};

template<typename T>
inline T * LinkedList<T>::get(int idx)
{
	Node* n = head;
	for (int i = 0; i < idx; i++)
		n = n->next;

	return n;
}

template<typename T>
inline void LinkedList<T>::add_front(const T & val)
{
	auto n = new Node;
	n->data = val;

	if (count == 0)
		head = tail = n;
	else
	{
		n->next = head;
		head->prev = n;
		head = n;
	}
	count++;
}

template<typename T>
inline void LinkedList<T>::add_back(const T & val)
{
	auto n = new Node;
	n->data = val;

	if (count == 0)
		head = tail = n;
	else
	{
		n->prev = tail;
		tail->next = n;
		tail = n;
	}
	count++;
}

template<typename T>
inline void LinkedList<T>::add(unsigned int idx, const T & val)
{
	//If the index is either the first or last index, use add_front/back
	if (idx == 0)
	{
		add_front(val);
		return;
	}
	else if (idx == count)
	{
		add_back(val);
		return;
	}

	//Otherwise, actually run the function
	auto n = new Node;
	n->data = val;

	//I'm pushing the rest of the stuff back instead of forward.
	//add(0) would run add_end and add(count), with count being 1 greater than the actual number of nodes, would run add_back
	n->prev = get(idx);
	n->next = get(idx)->next;
	
	n->prev->next = n;
	n->next->prev = n;

	count++;
}

template<typename T>
inline void LinkedList<T>::add_after(T* idx, const T & val)
{
	//If the index is either the first or last index, use add_front/back
	if (idx == 0)
	{
		add_front(val);
		return;
	}
	else if (idx == count)
	{
		add_back(val);
		return;
	}

	//Otherwise, actually run the function
	auto n = new Node;
	n->data = val;

	//I'm pushing the rest of the stuff forward instead of back.
	//add(0) would run add_end and add(count), with count being 1 greater than the actual number of nodes, would run add_back
	n->prev = T;
	n->next = T->next;

	n->prev->next = n;
	n->next->prev = n;

	count++;
}

template<typename T>
inline T LinkedList<T>::del_front()
{
	if (count == 1)
	{
		delete head;
		head = tail = nullptr;
		return;
	}

	head->next->prev = nullptr;
	Node* n = head;	//save the head for deletion
	head = head->next;
	delete n;
	count--;

	return head;
}

template<typename T>
inline T LinkedList<T>::del_back()
{
	if (count == 1)
	{
		delete tail;
		head = tail = nullptr;
		return;
	}
	
	tail->prev->next = nullptr;
	Node* n = tail;	//save the tail for deletion
	head = tail->prev;
	delete n;
	count--;

	return tail;
}

template<typename T>
inline T LinkedList<T>::del(unsigned int idx)
{
	//If the index is either the first or last index, use del_front/back
	if (idx == 0)
	{
		del_front(val);
		return;
	}
	else if (idx == count)
	{
		del_back(val);
		return;
	}

	auto n = get(idx);
	n->next->prev = n->prev;
	n->pre->next = n->next;
	count--;

	delete n;
}

template<typename T>
inline void LinkedList<T>::clear()
{
	auto n = hea;
	while(t != nullptr)
	{
		auto toDel = t;
		n = n->next;
		delete old;
		count--;
	}
	head = tail = nullptr;
}

template<typename T>
inline void LinkedList<T>::swap(int idx1, int idx2)
{
	Node* n1 = get(idx1);
	Node* n2 = get(idx2);

	Node saveNode;	//Saving node 2
	saveNode.data = n2->data;
	saveNode.next = n2->next;
	saveNode.prev = n2->prev;

	n2->data = n1;				//Transfer n1 to n2
	n1->data = saveNode.data;	//Transfer n2 to n1

}
