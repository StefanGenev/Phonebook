#include "stdafx.h"
#include "PhoneTypesData.h"

// Constructor / Destructor
// ----------------

CPhoneTypesData::CPhoneTypesData()
{
}

CPhoneTypesData::~CPhoneTypesData()
{
}


// Methods
// ----------------

BOOL CPhoneTypesData::LoadAllPhoneTypes(CPhoneTypesArray& oPhoneTypesArray)
{
	CPhoneTypesTable oPhoneTypesTable;
	if (!oPhoneTypesTable.SelectAll(oPhoneTypesArray))
		return FALSE;
	
	return TRUE;
}

BOOL CPhoneTypesData::LoadPhoneType(const long lID, PHONE_TYPES& recPhoneType)
{
	CPhoneTypesTable oPhoneTypesTable;
	if (!oPhoneTypesTable.SelectWhereID(lID, recPhoneType))
		return FALSE;

	return TRUE;	
}

BOOL CPhoneTypesData::Update(const long lID, const PHONE_TYPES& recPhoneType)
{
	CPhoneTypesTable oPhoneTypesTable;

	if (!oPhoneTypesTable.UpdateWhereID(lID, recPhoneType))
		return FALSE;

	return TRUE;
}

BOOL CPhoneTypesData::Insert(PHONE_TYPES& recPhoneType)
{
	CPhoneTypesTable oPhoneTypesTable;
	if (!oPhoneTypesTable.Insert(recPhoneType))
		return FALSE;
	
	return TRUE;
}

BOOL CPhoneTypesData::Delete(const long lID)
{
	CPhoneTypesTable oPhoneTypesTable;

	if (!oPhoneTypesTable.DeleteWhereID(lID))
		return FALSE;

	return TRUE;
}

// Overrides
// ----------------