#pragma once

class Stack
{
private:
	class Element
	{
	public:
		Element(int value, Element* pNext)
			:
			value(value),
			pNext(pNext)
		{}
		Element(const Element& source)
			:
			value(source.value)
		{
			if (source.pNext != nullptr)
			{
				pNext = new Element(*source.pNext);
			}
		}
		~Element()
		{
			delete pNext;
			pNext = nullptr;
		}
		Element& operator!=(const Element& rhs) = delete;
		int GetValue() const
		{
			return value;
		}
		Element* Disconnect()
		{
			auto temp = pNext;
			pNext = nullptr;
			return temp;
		}
		int CountElements() const 
		{
			if (pNext != nullptr)
			{
				return pNext->CountElements() + 1;
			}
			else
			{
				return 1;
			}
		}
	private:
		Element* pNext = nullptr;
		int value;
	};
public:
	Stack() = default;
	Stack(const Stack& s)
	{
		*this = s;
	}
	Stack& operator=(const Stack& s)
	{
		if (&s != this)
		{
			if (!Empty())
			{
				delete pTop;
				pTop = nullptr;
			}
			if(!s.Empty())
			{
				pTop = new Element(*s.pTop);
			}
		}
		return *this;
	}
	~Stack()
	{
		delete pTop;
		pTop = nullptr;
	}
	void Push(int value)
	{
		pTop = new Element(value, pTop);
	}
	int Pop()
	{
		if (!Empty())
		{
			auto pOldTop = pTop;
			pTop = pTop->Disconnect();
			int temp = pOldTop->GetValue();
			delete pOldTop;
			return temp;
		}
		else
		{
			return -1;
		}
	}
	int Size() const
	{
		if (!Empty())
		{
			return pTop->CountElements();
		}
		else
		{
			return 0;
		}
	}
	bool Empty() const
	{
		return pTop == nullptr;
	}
private:
	Element* pTop = nullptr;
};