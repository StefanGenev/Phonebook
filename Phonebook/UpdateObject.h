#pragma once
#include "stdafx.h"
#include "Structures.h"
#include "RecordOperationTypes.h"


/// <summary>
/// Клас за пренасяне на информация за ъпдейт на лист контрола
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
	/// <summary>Метод, който връща референция към запис</summary>
	///<returns> Функцията връща референция към CPersonsVisual обект</returns>
	const TYPE& GetData();

	/// <summary>Метод, който връща тип операция за извършване върху запис</summary>
	///<returns> Функцията връща enum стойност от RecordOperationTypes</returns>
	const RecordOperationTypes GetOperationType();

// Overrides
// ----------------

// Members
// ----------------
protected:
	/// <summary>Референция към запис</summary>
	const TYPE& m_recData;

	/// <summary>Тип операция за извършване върху запис</summary>
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
