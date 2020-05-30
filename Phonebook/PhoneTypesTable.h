#pragma once
#include "stdafx.h"
#include "Structures.h"
#include "PhoneTypesAccessor.h"
#include "DatabaseTable.h"

/// <summary>
/// Клас за таблица с типове телефони PHONE_TYPES
/// </summary>
class CPhoneTypesTable : public CDatabaseTable<CPhoneTypesAccessor, PHONE_TYPES>
{

// Constants
// ----------------

// Constructor / Destructor
// ----------------
public:
	CPhoneTypesTable();
	CPhoneTypesTable(CDatabaseSession& oSession);
	virtual ~CPhoneTypesTable();

// Methods
// ----------------

// Overrides
// ----------------
private:
	/// <summary>Функция връщаша име на таблица от база данни</summary>
	///<returns> Функцията връща string с име на таблица</returns>
	virtual CString GetTableName();

	/// <summary>Функция връщаща референция към идентификатор на запис от таблица</summary>
	/// <param name="recPhoneType">Запис от таблица</param>
	///<returns> Функцията връща константна референция към long</returns>
	virtual const long& GetIdentificator(const PHONE_TYPES& recPhoneType);

	/// <summary>Функция връщаща референция към брояч на промени на таблица</summary>
	/// <param name="recPhoneType">Запис от таблица</param>
	///<returns> Функцията връща референция към long</returns>
	virtual long& GetUpdateCounter(PHONE_TYPES& recPhoneType);

// Members
// ----------------

};