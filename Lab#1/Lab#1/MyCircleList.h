#pragma once

template <class T>
class MyCircleList
{
private:
	struct Item
	{
		T item;
		struct Item* next;
	};
	int size;
	struct Item* Head;
public:
	MyCircleList()
	{
		Head = NULL;
		size = 0;
	}
	T GetElementByIndex(int n)
	{
		if (Head == NULL)
			return NULL;

		struct Item *Current = Head;

		for (int i = 0; i < n; i++)
		{
			Current = Current->next;
		}
		return Current->item;
	}
	void AddNew(T data)
	{
		if (Head != NULL)
		{
			struct Item* Current = Head;

			while (Current->next != Head)
				Current = Current->next;

			Current->next = new struct Item;
			Current = Current->next;
			Current->item = data;
			Current->next = Head;
		}
		else
		{
			Head = new struct Item;
			Head->item = data;
			Head->next = Head;
		}
		size++;
	}
	void Delete(int n)
	{
		if (n < size)
		{
			struct Item *Current = Head;
			if (n == 0)
			{
				Current = Head->next;
				delete Head;
				Head = Current;
			}
			else
			{
				for (int i = 0; i < n - 1; i++)
					Current = Current->next;
				struct Item *buff = Current->next;
				Current->next = buff->next;
				delete buff;
			}
			size--;
		}
	}
	int getSize() { return size; }

	int FindByValue(T data)
	{
		struct Item *Current = Head;

		if (Head->item == data)
			return 0;

		int c = 0;
		do
		{
			Current = Current->next;
			c++;
		} while (Current != Head && Current->item != data);

		if (Current->item == data)
			return c;
		return -1;
	}
};
