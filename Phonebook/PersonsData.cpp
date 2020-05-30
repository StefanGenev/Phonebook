
#include "stdafx.h"
#include "PersonsData.h"
#include "PersonsTable.h"
#include "PhoneNumbersTable.h"
#include "CitiesTable.h"
#include "PhoneTypesTable.h"
#include "DatabaseSession.h"

// Constructor / Destructor
// ----------------

CPersonsData::CPersonsData()
{
}

CPersonsData::~CPersonsData()
{
}

// Methods
// ----------------
BOOL CPersonsData::LoadAllPersons(CPersonsViewDataArray& oPersonsViewDataArray)
{
	CPersonsTable oPersonsTable;
	CPersonsArray oPersonsArray;

	if (!oPersonsTable.SelectAll(oPersonsArray))
		return FALSE;

	if (!GetPersonsWithCities(oPersonsArray, oPersonsViewDataArray))
		return FALSE;

	return TRUE;
}

BOOL CPersonsData::LoadAllCities(CCitiesMap& oCitiesMap)
{
	CCitiesTable oCitiesTable;
	CCitiesArray oCitiesArray;

	if (!oCitiesTable.SelectAll(oCitiesArray))
		return FALSE;

	for (int i = 0; i < oCitiesArray.GetCount(); i++)
	{
		CITIES* pCity = oCitiesArray.GetAt(i);
		if (pCity == NULL)
			continue;

		CITIES* pCityNew = new CITIES(*pCity);

		oCitiesMap.SetAt(pCity->lID, pCityNew);
	}

	return TRUE;
}

BOOL CPersonsData::LoadAllPhoneTypes(CPhoneTypesMap& oPhoneTypesMap)
{
	CPhoneTypesTable oPhoneTypesTable;
	CPhoneTypesArray oPhoneTypesArray;

	if (!oPhoneTypesTable.SelectAll(oPhoneTypesArray))
		return FALSE;

	for (int i = 0; i < oPhoneTypesArray.GetCount(); i++)
	{
		PHONE_TYPES* pPhoneType = oPhoneTypesArray.GetAt(i);
		if (pPhoneType == NULL)
			continue;

		PHONE_TYPES* pPhoneTypeNew = new PHONE_TYPES(*pPhoneType);
		oPhoneTypesMap.SetAt(pPhoneType->lID, pPhoneTypeNew);
	}

	return TRUE;
}

BOOL CPersonsData::LoadPerson(const long lID, CPerson& oPerson)
{
	CPersonsTable oPersonsTable;
	CPhoneNumbersTable oPhoneNumbersTable;

	if (!oPersonsTable.SelectWhereID(lID, oPerson.recPerson))
		return FALSE;

	CString strColumn = _T("PERSON_ID");
	if (!oPhoneNumbersTable.SelectWhere(lID, strColumn, oPerson.oPhoneNumbersArray))
		return FALSE;

	return TRUE;
}

BOOL CPersonsData::Update(const long lID, const CPerson& oPerson)
{
	CDatabaseSession oDatabaseSession;
	CPersonsTable oPersonsTable(oDatabaseSession);
	CPhoneNumbersTable oPhoneNumbersTable(oDatabaseSession);

	if (!oDatabaseSession.OpenTransaction())
		return FALSE;
		
	if (!oPersonsTable.UpdateWhereID(lID, oPerson.recPerson))
		return FALSE;

	CPhoneNumbersArray oPhoneNumbersArrayOld;
	CString strColumn = _T("PERSON_ID");

	if (!oPhoneNumbersTable.SelectWhere(lID, strColumn, oPhoneNumbersArrayOld, CPhoneNumbersTable::LockHintUpdLock))
		return FALSE;

	if (!oPhoneNumbersTable.Synchronise(oPerson.oPhoneNumbersArray, oPhoneNumbersArrayOld))
		return FALSE;

	if (!oDatabaseSession.CommitTransaction())
		return FALSE;

	return TRUE;
}

BOOL CPersonsData::Insert(CPerson& oPerson)
{
	CDatabaseSession oDatabaseSession;
	CPersonsTable oPersonsTable(oDatabaseSession);

	if (!oDatabaseSession.OpenTransaction())
		return FALSE;

	if (!oPersonsTable.Insert(oPerson.recPerson)) 
		return FALSE;
	
	if (!InsertPhoneNumbers(oPerson.recPerson.lID, oPerson.oPhoneNumbersArray, oDatabaseSession))
		return FALSE;

	if (!oDatabaseSession.CommitTransaction())
		return FALSE;

	return TRUE;
}

BOOL CPersonsData::Delete(const long lID)
{
	CDatabaseSession oDatabaseSession;
	CPersonsTable oPersonsTable(oDatabaseSession);
	CPhoneNumbersArray oPhoneNumbersArrayFound;

	if (!oDatabaseSession.OpenTransaction())
		return FALSE;

	if (!DeletePhoneNumbers(lID, oDatabaseSession))
		return FALSE;

	if (!oPersonsTable.DeleteWhereID(lID))
		return FALSE;

	if (!oDatabaseSession.CommitTransaction())
		return FALSE;

	return TRUE;
}

BOOL CPersonsData::LoadCity(const long lID, CITIES& recCity)
{
	CCitiesTable oCitiesTable;
	if (!oCitiesTable.SelectWhereID(lID, recCity))
		return FALSE;

	return TRUE;
}

BOOL CPersonsData::GetPersonsWithCities(const CPersonsArray& oPersonsArray, CPersonsViewDataArray& oPersonsViewDataArray)
{
	CCitiesMap oCitiesMap;

	for (int i = 0; i < oPersonsArray.GetCount(); i++)
	{
		const PERSONS* pPerson = oPersonsArray.GetAt(i);
		if (pPerson == NULL)
			continue;

		PERSONS_VIEW_DATA recPersonViewData;
		recPersonViewData.recPerson = *pPerson;

		CITIES* pCity = NULL;
		if (!oCitiesMap.Lookup(pPerson->lCityID, pCity))
		{
			pCity = new CITIES();
			if (!LoadCity(pPerson->lCityID, *pCity))
				return FALSE;
			
			oCitiesMap.SetAt(pPerson->lCityID, pCity);
		}

		recPersonViewData.strCity = pCity->szName;
		oPersonsViewDataArray.Insert(recPersonViewData);
	}

	return TRUE;
}

BOOL CPersonsData::InsertPhoneNumbers(const long lID, CPhoneNumbersArray& oPhoneNumbersArray, CDatabaseSession& oDatabaseSession)
{
	CPhoneNumbersTable oPhoneNumbersTable(oDatabaseSession);
	for (int i = 0; i < oPhoneNumbersArray.GetCount(); i++)
	{
		PHONE_NUMBERS* pPhoneNumber = oPhoneNumbersArray.GetAt(i);
		if (pPhoneNumber == NULL)
			return FALSE;

		pPhoneNumber->lPersonID = lID;

		if (!oPhoneNumbersTable.Insert(*pPhoneNumber))
			return FALSE;
	}

	return TRUE;
}

BOOL CPersonsData::DeletePhoneNumbers(const long lPersonID, CDatabaseSession& oDatabaseSession)
{
	CPhoneNumbersTable oPhoneNumbersTable(oDatabaseSession);
	CPhoneNumbersArray oPhoneNumbersArray;

	CString strColumn = _T("PERSON_ID");
	if (!oPhoneNumbersTable.SelectWhere(lPersonID, strColumn, oPhoneNumbersArray, CPhoneNumbersTable::LockHintUpdLock))
		return FALSE;
	
	for (int i = 0; i < oPhoneNumbersArray.GetCount(); i++)
	{
		const PHONE_NUMBERS& recPhoneNumber = *oPhoneNumbersArray.GetAt(i);
		if (!oPhoneNumbersTable.DeleteWhereID(recPhoneNumber.lID))
			return FALSE;
	}

	return TRUE;
}


// Overrides
// ----------------

