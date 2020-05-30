#pragma once
#include "stdafx.h"
#include "Structures.h"
#include "RecordOperationTypes.h"


/// <summary>
/// ���� �� ��������� �� ���������� �� ������ �� ���� ��������
/// </summary>
template <class TYPE>
class CUpdateObject : public CObject
{

// Constants
// ----------------

// Constructor / Destructor
// ----------------
public:
	CUpdateObject(const TYPE& recType, RecordOperationTypes eRecordOperationTypes);
	virtual ~CUpdateObject();

// Methods
// ----------------
public:
	/// <summary>�����, ����� ����� ���������� ��� �����</summary>
	///<returns> ��������� ����� ���������� ��� CPersonsVisual �����</returns>
	const TYPE& GetData();

	/// <summary>�����, ����� ����� ��� �������� �� ���������� ����� �����</summary>
	///<returns> ��������� ����� enum �������� �� RecordOperationTypes</returns>
	const RecordOperationTypes GetOperationType();

// Overrides
// ----------------

// Members
// ----------------
protected:
	/// <summary>���������� ��� �����</summary>
	const TYPE& m_recData;

	/// <summary>��� �������� �� ���������� ����� �����</summary>
	RecordOperationTypes m_eRecordOperationTypes;
};

template<class TYPE>
inline CUpdateObject<TYPE>::CUpdateObject(const TYPE& oType, RecordOperationTypes eRecordOperationTypes) : m_recData(oType)
{
	m_eRecordOperationTypes = eRecordOperationTypes;
}

template<class TYPE>
inline CUpdateObject<TYPE>::~CUpdateObject()
{
}

template<class TYPE>
inline const TYPE& CUpdateObject<TYPE>::GetData()
{
	return m_recData;
}

template<class TYPE>
inline const RecordOperationTypes CUpdateObject<TYPE>::GetOperationType()
{
	return m_eRecordOperationTypes;
}
