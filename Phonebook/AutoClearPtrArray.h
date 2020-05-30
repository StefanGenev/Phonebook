#pragma once

/// <summary>
/// ���� �� ��������� �� ����� �� ���������, ����� �� �������� ���
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

	/// <summary>����������, ����� �������� ������</summary>
	virtual ~CAutoClearPtrArray()
	{
		DeleteAll();
	};

// Methods
// ----------------
public:
	/// <summary>�����, ����� ������� �������� �� ������ �� ������ � ����������� ������� ����� �� ����</summary>
	/// <param name="nIndex">������ �� �������� � ������</param>
	void Delete(int nIndex)
	{
		if (nIndex < 0)
			return;

		delete this->GetAt(nIndex);
		RemoveAt(nIndex);
	}

	/// <summary>�����, ����� ������ � ������ ��� �������� ����� ��� ������� �����</summary>
	/// <param name="recType">�����, ��� ����� �� ���� ����������, ����� �� ������ � ������</param>
	void Insert(const TYPE& recType)
	{
		TYPE* pType = new TYPE();
		*pType = recType;
		this->Add(pType);
	}

	/// <summary>�����, ����� �������� ������ � ����������� ������� ����� �� ����</summary>
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