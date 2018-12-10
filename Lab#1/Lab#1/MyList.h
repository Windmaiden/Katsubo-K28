#pragma once

template <class T>
class MyList
{
private:
	struct Item
	{
		T Data;
		struct Item* next;
	};
	int size;
	struct Item* Head;
public:
	MyList()
	{
		Head = NULL;
		size = 0;
	}
	int getSize() { return size; }
	T GetElementByIndex(int n);
	void AddNew(const T data);
	void Delete(int n);	
	int FindByValue(T data);
};

template <class T>
T MyList<T>::GetElementByIndex(int n)
{
	if (n < size)
	{
		struct Item *Current = Head;

		for (int i = 0; i < n; i++)
		{
			Current = Current->next;
		}
		return Current->Data;
	}
	//return NULL;
}

template <class T>
void MyList<T>::AddNew(const T data)
{
	if (Head != NULL)
	{
		struct Item* Current = Head;

		while (Current->next != NULL)
			Current = Current->next;

		Current->next = new struct Item;
		Current = Current->next;
		Current->next = NULL;
		Current->Data = data;
	}
	else
	{
		Head = new struct Item;
		Head->Data = data;
		Head->next = NULL;
	}
	size++;
}

template <class T>
void MyList<T>::Delete(int n)
{
	if (n < size)
	{
		struct Item *Current = Head;
		struct Item *Parent = Head;
		size--;
		
		if (n == 0)
		{
			Current = Head->next;
			delete Head;
			Head = Current;
			return;
		}
		

		for (int i = 0; i < n ; i++)
		{
			Parent = Current;
			Current = Current->next;
		}
		Parent->next = Current->next;
		delete Current;
	}
}

template <class T>
int MyList<T>::FindByValue(T data)
{
	struct Item *Current = Head;
	int Index = 0;
	while (Current != NULL && Current->Data != data)
	{
		Current = Current->next;
		Index++;
	}

	if (Current != NULL)
		return Index;
	return -1;
}