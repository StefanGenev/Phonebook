
#include "stdafx.h"
#include "CitiesData.h"
#include "CitiesTable.h"

// Constructor / Destructor
// ----------------

CCitiesData::CCitiesData()
{
	
}

CCitiesData::~CCitiesData()
{

}

// Methods
// ----------------

BOOL CCitiesData::LoadAllCities(CCitiesArray& oCitiesArray)
{	
	CCitiesTable oCitiesTable;

	if (!oCitiesTable.SelectAll(oCitiesArray))
		return FALSE;

	return TRUE;
}

BOOL CCitiesData::LoadCity(const long lID, CITIES& recCity)
{
	CCitiesTable oCitiesTable;

	if (!oCitiesTable.SelectWhereID(lID, recCity))
		return FALSE;

	return TRUE;
}

BOOL CCitiesData::Update(const long lID, const CITIES& recCity)
{	
	CCitiesTable oCitiesTable;

	if (!oCitiesTable.UpdateWhereID(lID, recCity))
		return FALSE;

	return TRUE;
}

BOOL CCitiesData::Insert(CITIES& recCity)
{
	CCitiesTable oCitiesTable;

	if (!oCitiesTable.Insert(recCity))
		return FALSE;

	return TRUE;
}

BOOL CCitiesData::Delete(const long lID)
{
	CCitiesTable oCitiesTable;

	if (!oCitiesTable.DeleteWhereID(lID))
		return FALSE;

	return TRUE;
}


// Overrides
// ----------------

