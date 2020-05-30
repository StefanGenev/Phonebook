#pragma once
#include "Structures.h"
#include "DatabaseAccessor.h"


/// <summary>
/// Клас за достъпване на колони на таблица CITIES
/// </summary>
class CCitiesAccessor : public CDatabaseAccessor<CITIES>
{

// Constants
// ----------------
private:
	/// <summary>Номер на колона за име на град в дата аксесор</summary>
	static const int _nDataAccessorNameColumnNumber = 3;

	/// <summary>Номер на колона за област на град в дата аксесор</summary>
	static const int _nDataAccessorRegionColumnNumber = 4;

// Constructor / Destructor
// ----------------

// Methods
// ----------------
protected:
/// <summary>Функция създаваща аксесори, които достъпват колони от таблица</summary>
	BEGIN_ACCESSOR_MAP(CCitiesAccessor, _nNumberOfAccessors)
		BEGIN_ACCESSOR(_nIdentityAccessor, true)
			COLUMN_ENTRY(_nIdentityAccessorIDColumnNumber, m_recDatabaseRecord.lID)
		END_ACCESSOR()

		BEGIN_ACCESSOR(_nDataAccessor, true)
		COLUMN_ENTRY(_nDataAccessorUpdateCounterColumnNumber, m_recDatabaseRecord.lUpdateCounter)
		COLUMN_ENTRY(_nDataAccessorNameColumnNumber, m_recDatabaseRecord.szName)
		COLUMN_ENTRY(_nDataAccessorRegionColumnNumber, m_recDatabaseRecord.szRegion)
		END_ACCESSOR()
	END_ACCESSOR_MAP()

// Overrides
// ----------------


// Members
// ----------------

};