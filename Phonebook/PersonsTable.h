#pragma once
#pragma once

#include "stdafx.h"
#include "Structures.h"
#include "PersonsAccessor.h"
#include "DatabaseTable.h"

/// <summary>
/// Клас за таблица с абонати PERSONS
/// </summary>
class CPersonsTable : public CDatabaseTable<CPersonsAccessor, PERSONS>
{

// Constants
// ----------------


// Constructor / Destructor
// ----------------

public:
	CPersonsTable();
	CPersonsTable(CDatabaseSession& oSession);
	virtual ~CPersonsTable();


// Methods
// ----------------

// Overrides
// ----------------
private:
	/// <summary>Функция връщаша име на таблица от база данни</summary>
	///<returns> Функцията връща string с име на таблица</returns>
	virtual CString GetTableName();

	/// <summary>Функция връщаща референция към идентификатор на запис от таблица</summary>
	/// <param name="recPerson">Запис от таблица</param>
	///<returns> Функцията връща константна референция към long</returns>
	virtual const long& GetIdentificator(const PERSONS& recPerson);

	/// <summary>Функция връщаща референция към брояч на промени на таблица</summary>
	/// <param name="recPerson">Запис от таблица</param>
	///<returns> Функцията връща референция към long</returns>
	virtual long& GetUpdateCounter(PERSONS& recPerson);

// Members
// ----------------


};