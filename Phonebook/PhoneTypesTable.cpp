#include "stdafx.h"
#include "PhoneTypesTable.h"

// Constructor / Destructor
// ----------------

CPhoneTypesTable::CPhoneTypesTable()
{
}

CPhoneTypesTable::CPhoneTypesTable(CDatabaseSession& oSession) 
	: CDatabaseTable(oSession)
{
}

CPhoneTypesTable::~CPhoneTypesTable()
{
}


// Methods
// ----------------

// Overrides
// ----------------
CString CPhoneTypesTable::GetTableName()
{
	return _T("PHONE_TYPES");
}

const long& CPhoneTypesTable::GetIdentificator(const PHONE_TYPES& recPhoneType)
{
	return recPhoneType.lID;
}

long& CPhoneTypesTable::GetUpdateCounter(PHONE_TYPES& recPhoneType)
{
	return recPhoneType.lUpdateCounter;
}
