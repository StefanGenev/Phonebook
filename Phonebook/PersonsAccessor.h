#pragma once
#pragma once
#include "Structures.h"
#include "DatabaseAccessor.h"


/// <summary>
/// Клас за достъпване на колони на таблица PERSONS
/// </summary>
class CPersonsAccessor : public CDatabaseAccessor<PERSONS>
{

// Constants
// ----------------
private:
	/// <summary>Номер на колона за първо име на абонат в дата аксесор</summary>
	static const int _nDataAccessorFirstNameColumnNumber = 3;

	/// <summary>Номер на колона за презиме на абонат в дата аксесор</summary>
	static const int _nDataAccessorMiddleNameColumnNumber = 4;

	/// <summary>Номер на колона за фамилия на абонат в дата аксесор</summary>
	static const int _nDataAccessorLastNameColumnNumber = 5;

	/// <summary>Номер на колона за ЕГН абонат в дата аксесор</summary>
	static const int _nDataAccessorUCNColumnNumber = 6;

	/// <summary>Номер на колона за идентификатор на град на абонат в дата аксесор</summary>
	static const int _nDataAccessorCityIDColumnNumber = 7;

	/// <summary>Номер на колона за адрес на абонат в дата аксесор</summary>
	static const int _nDataAccessorAddressColumnNumber = 8;

// Constructor / Destructor
// ----------------

// Methods
// ----------------
protected:
	/// <summary>Функция създаваща аксесори, които достъпват колони от таблица</summary>
	BEGIN_ACCESSOR_MAP(CPersonsAccessor, _nNumberOfAccessors)
		BEGIN_ACCESSOR(_nIdentityAccessor, true)
		COLUMN_ENTRY(_nIdentityAccessorIDColumnNumber, m_recDatabaseRecord.lID)
		END_ACCESSOR()

		BEGIN_ACCESSOR(_nDataAccessor, true)
		COLUMN_ENTRY(_nDataAccessorUpdateCounterColumnNumber, m_recDatabaseRecord.lUpdateCounter)
		COLUMN_ENTRY(_nDataAccessorFirstNameColumnNumber, m_recDatabaseRecord.szFirstName)
		COLUMN_ENTRY(_nDataAccessorMiddleNameColumnNumber, m_recDatabaseRecord.szMiddleName)
		COLUMN_ENTRY(_nDataAccessorLastNameColumnNumber, m_recDatabaseRecord.szLastName)
		COLUMN_ENTRY(_nDataAccessorUCNColumnNumber, m_recDatabaseRecord.szUCN)
		COLUMN_ENTRY(_nDataAccessorCityIDColumnNumber, m_recDatabaseRecord.lCityID)
		COLUMN_ENTRY(_nDataAccessorAddressColumnNumber, m_recDatabaseRecord.szAddress)
		END_ACCESSOR()
	END_ACCESSOR_MAP()

// Overrides
// ----------------

// Members
// ----------------

};