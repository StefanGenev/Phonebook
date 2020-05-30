#pragma once

#include "stdafx.h"
#include "Structures.h"
#include "CitiesAccessor.h"
#include "DatabaseTable.h"

/// <summary>
/// Клас за таблица с градове CCitiesTable
/// </summary>
class CCitiesTable : public CDatabaseTable<CCitiesAccessor, CITIES>
{

// Constants
// ----------------


// Constructor / Destructor
// ----------------

public:
	CCitiesTable();
	CCitiesTable(CDatabaseSession& oSession);
	virtual ~CCitiesTable();
	
// Methods
// ----------------

// Overrides
// ----------------
private:
	/// <summary>Функция връщаша име на таблица от база данни</summary>
	///<returns> Функцията връща string с име на таблица</returns>
	virtual CString GetTableName();

	/// <summary>Функция връщаща референция към идентификатор на запис от таблица</summary>
	/// <param name="recCity">Запис от таблица</param>
	///<returns> Функцията връща константна референция към long</returns>
	virtual const long& GetIdentificator(const CITIES& recCity);

	/// <summary>Функция връщаща референция към брояч на промени на таблица</summary>
	/// <param name="recCity">Запис от таблица</param>
	///<returns> Функцията връща референция към long</returns>
	virtual long& GetUpdateCounter(CITIES& recCity);


// Members
// ----------------

};