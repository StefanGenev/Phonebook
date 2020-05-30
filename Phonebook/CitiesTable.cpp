#include "stdafx.h"
#include "CitiesTable.h"


// Constants
// ----------------


// Constructor / Destructor
// ----------------
CCitiesTable::CCitiesTable()
{
}

CCitiesTable::CCitiesTable(CDatabaseSession& oDatabaseSession) 
	: CDatabaseTable(oDatabaseSession)
{
}

CCitiesTable::~CCitiesTable()
{
}


// Methods
// ----------------

// Overrides
// ----------------

CString CCitiesTable::GetTableName()
{
	return _T("CITIES");
}

const long& CCitiesTable::GetIdentificator(const CITIES& recCity)
{
	return recCity.lID;
}

long& CCitiesTable::GetUpdateCounter(CITIES& recCity)
{
	return recCity.lUpdateCounter;
}

