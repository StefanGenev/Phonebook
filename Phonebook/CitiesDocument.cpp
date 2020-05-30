
// CitiesDocument.cpp : implementation of the CCitiesDocument class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Phonebook.h"
#endif

#include "CitiesDocument.h"
#include "CitiesData.h"
#include "Structures.h"
#include "CitiesUpdateObject.h"
#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CCitiesDocument, CDocument)

BEGIN_MESSAGE_MAP(CCitiesDocument, CDocument)
	
END_MESSAGE_MAP()



// Constructor / Destructor
// ----------------
CCitiesDocument::CCitiesDocument()
{
}

CCitiesDocument::~CCitiesDocument()
{
}

// Methods
// ----------------
const CCitiesArray& CCitiesDocument::GetAllCities()
{
	return m_oCitiesArray;
}

BOOL CCitiesDocument::LoadCity(const long lID, CITIES& recCity)
{
	 return m_oCitiesData.LoadCity(lID, recCity);
}

BOOL CCitiesDocument::Insert(CITIES& recCity)
{
	if (!m_oCitiesData.Insert(recCity))
		return FALSE;

	m_oCitiesArray.Insert(recCity);

	const CCitiesUpdateObject oCitiesUpdateObject(recCity, RecordOperationTypeInsert);
	UpdateAllViews(NULL, 0, (CObject*)&oCitiesUpdateObject);
	return TRUE;
}

BOOL CCitiesDocument::Update(const long lID, const CITIES& recCity)
{	
	if (!m_oCitiesData.Update(lID, recCity))
		return FALSE;

	int nIndex = FindRecord(lID);
	if (nIndex == CB_ERR)
		return FALSE;

	m_oCitiesArray.Delete(nIndex);
	m_oCitiesArray.Insert(recCity);

	const CCitiesUpdateObject oCitiesUpdateObject(recCity, RecordOperationTypeUpdate);
	UpdateAllViews(NULL, 0, (CObject*)&oCitiesUpdateObject);
	return TRUE;
}

BOOL CCitiesDocument::Delete(const long lID)
{
	if (!m_oCitiesData.Delete(lID))
		return FALSE;

	int nIndex = FindRecord(lID);
	if (nIndex == CB_ERR)
		return FALSE;

	m_oCitiesArray.Delete(nIndex);

	CITIES recCity;
	recCity.lID = lID;

	const CCitiesUpdateObject oCitiesUpdateObject(recCity, RecordOperationTypeDelete);
	UpdateAllViews(NULL, 0, (CObject*)&oCitiesUpdateObject);
	return TRUE;
}

int CCitiesDocument::FindRecord(const long lID)
{
	int nIndex = -1;
	for (int i = 0; i < m_oCitiesArray.GetCount(); i++)
	{
		CITIES* pCity = m_oCitiesArray.GetAt(i);

		if (pCity == NULL)
			continue;

		if (pCity->lID != lID)
			continue;

		nIndex = i;
		break;
	}
	return nIndex;
}

// Overrides
// ----------------
BOOL CCitiesDocument::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	if (!m_oCitiesData.LoadAllCities(m_oCitiesArray))
		return FALSE;
	
	return TRUE;
}