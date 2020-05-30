#pragma once
#include "stdafx.h"
#include "PhoneNumbersAccessor.h"
#include "DatabaseTable.h"

/// <summary>
/// Клас за таблица с телефонни номера PHONE_NUMBERS
/// </summary>
class CPhoneNumbersTable : public CDatabaseTable<CPhoneNumbersAccessor, PHONE_NUMBERS>
{

// Constants
// ----------------

// Constructor / Destructor
// ----------------
public:
	CPhoneNumbersTable();
	CPhoneNumbersTable(CDatabaseSession& oSession);
	virtual ~CPhoneNumbersTable();

// Methods
// ----------------

// Overrides
// ----------------
private:
	/// <summary>Функция връщаша име на таблица от база данни</summary>
	///<returns> Функцията връща string с име на таблица</returns>
	virtual CString GetTableName();

	/// <summary>Функция връщаща референция към идентификатор на запис от таблица</summary>
	/// <param name="recPhoneNumber">Запис от таблица</param>
	///<returns> Функцията връща константна референция към long</returns>
	virtual const long& GetIdentificator(const PHONE_NUMBERS& recPhoneNumber);

	/// <summary>Функция връщаща референция към брояч на промени на таблица</summary>
	/// <param name="recPhoneNumber">Запис от таблица</param>
	///<returns> Функцията връща референция към long</returns>
	virtual long& GetUpdateCounter(PHONE_NUMBERS& recPhoneNumber);

// Members
// ----------------

};