#pragma once

/// <summary>
/// Клас за създаване на масив от указатели, който се зачиства сам
/// </summary>

template<class TYPE>
class CAutoClearPtrArray : public CTypedPtrArray<CPtrArray, TYPE*>
{

// Constants
// ----------------

// Constructor / Destructor
// ----------------
public:
	CAutoClearPtrArray() {};

	/// <summary>Деструктор, който зачиства масива</summary>
	virtual ~CAutoClearPtrArray()
	{
		DeleteAll();
	};

// Methods
// ----------------
public:
	/// <summary>Метод, който изтрива указател от масива по индекс и освобождава паметта заета от него</summary>
	/// <param name="nIndex">Индекс на елемента в масива</param>
	void Delete(int nIndex)
	{
		if (nIndex < 0)
			return;

		delete this->GetAt(nIndex);
		RemoveAt(nIndex);
	}

	/// <summary>Метод, който добавя в масива нов указател сочещ към подаден запис</summary>
	/// <param name="recType">Запис, към който ще сочи указателят, който се добавя в масива</param>
	void Insert(const TYPE& recType)
	{
		TYPE* pType = new TYPE();
		*pType = recType;
		this->Add(pType);
	}

	/// <summary>Метод, който зачиства масива и освобождава паметта заета от него</summary>
	void DeleteAll()
	{
		for (int i = 0; i < this->GetCount(); i++)
		{
			void* pData = this->GetAt(i);

			if (pData == NULL)
				continue;

			delete pData;
		}
		RemoveAll();
	}

// Overrides
// ----------------

// Members
// ---------------

};