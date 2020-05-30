#include "stdafx.h"
#include "PersonsTable.h"


// Constants
// ----------------


// Constructor / Destructor
// ----------------
CPersonsTable::CPersonsTable()
{
}

CPersonsTable::CPersonsTable(CDatabaseSession& oSession)
	: CDatabaseTable(oSession)
{
}

CPersonsTable::~CPersonsTable()
{
}

// Methods
// ----------------


// Overrides
// ----------------
CString CPersonsTable::GetTableName()
{
	return _T("PERSONS");
}

const long& CPersonsTable::GetIdentificator(const PERSONS& recPerson)
{
	return recPerson.lID;
}

long& CPersonsTable::GetUpdateCounter(PERSONS& recPerson)
{
	return recPerson.lUpdateCounter;
}


