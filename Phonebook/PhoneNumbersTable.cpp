#include "stdafx.h"
#include "PhoneNumbersTable.h"

// Constants
// ----------------




// Constructor / Destructor
// ----------------
CPhoneNumbersTable::CPhoneNumbersTable()
{
}

CPhoneNumbersTable::CPhoneNumbersTable(CDatabaseSession& oSession) 
	: CDatabaseTable(oSession)
{
}

CPhoneNumbersTable::~CPhoneNumbersTable()
{
}


// Methods
// ----------------



// Overrides
// ----------------
CString CPhoneNumbersTable::GetTableName()
{
	return _T("PHONE_NUMBERS");
}

const long& CPhoneNumbersTable::GetIdentificator(const PHONE_NUMBERS& recPhoneNumber)
{
	return recPhoneNumber.lID;
}

long& CPhoneNumbersTable::GetUpdateCounter(PHONE_NUMBERS& recPhoneNumber)
{
	return recPhoneNumber.lUpdateCounter;
}


