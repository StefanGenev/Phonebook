
#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Phonebook.h"
#endif

#include "PersonsDocument.h"
#include "PersonsData.h"
#include "Structures.h"
#include "PersonsUpdateObject.h"
#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CPersonsDocument, CDocument)

BEGIN_MESSAGE_MAP(CPersonsDocument, CDocument)

END_MESSAGE_MAP()



// Constructor / Destructor
// ----------------
CPersonsDocument::CPersonsDocument()
{
}

CPersonsDocument::~CPersonsDocument()
{
}

// Methods
// ----------------
const CPersonsViewDataArray& CPersonsDocument::GetAllPersons()
{
	return m_oPersonsViewDataArray;
}

const CCitiesMap& CPersonsDocument::GetAllCities()
{
	if (m_oCitiesMap.IsEmpty())
	{
		if (!m_oPersonsData.LoadAllCities(m_oCitiesMap))
			AfxMessageBox(_T("Could not load cities."));
	}	
			
	return m_oCitiesMap;
}

const CPhoneTypesMap& CPersonsDocument::GetAllPhoneTypes()
{
	if (m_oPhoneTypesMap.IsEmpty())
	{
		if (!m_oPersonsData.LoadAllPhoneTypes(m_oPhoneTypesMap))
			AfxMessageBox(_T("Could not load cities."));
	}
		
	return m_oPhoneTypesMap;
}

BOOL CPersonsDocument::LoadPerson(const long lID, CPerson& oPerson)
{
	return m_oPersonsData.LoadPerson(lID, oPerson);
}

BOOL CPersonsDocument::Insert(CPerson& oPerson)
{
	if (!m_oPersonsData.Insert(oPerson))
		return FALSE;

	PERSONS_VIEW_DATA recPersonViewData;
	recPersonViewData.recPerson = oPerson.recPerson;
	if (!FindCity(recPersonViewData.recPerson.lCityID, recPersonViewData.strCity))
		return FALSE;

	m_oPersonsViewDataArray.Insert(recPersonViewData);

	CPersonsUpdateObject oPersonsUpdateObject(recPersonViewData, RecordOperationTypeInsert);
	UpdateAllViews(NULL, 0, (CObject*)&oPersonsUpdateObject);
	return TRUE;
}

BOOL CPersonsDocument::Update(const long lID, const CPerson& oPerson)
{
	if (!m_oPersonsData.Update(lID, oPerson))
		return FALSE;

	int nIndex = FindRecord(lID);
	if (nIndex == CB_ERR)
		return FALSE;

	PERSONS_VIEW_DATA recPersonViewData;
	recPersonViewData.recPerson = oPerson.recPerson;

	if (!FindCity(recPersonViewData.recPerson.lCityID, recPersonViewData.strCity))
		return FALSE;

	m_oPersonsViewDataArray.Delete(nIndex);
	m_oPersonsViewDataArray.Insert(recPersonViewData);

	CPersonsUpdateObject oPersonsUpdateObject(recPersonViewData, RecordOperationTypeUpdate);
	UpdateAllViews(NULL, 0, (CObject*)&oPersonsUpdateObject);
	return TRUE;
}

BOOL CPersonsDocument::Delete(const long lID)
{
	if (!m_oPersonsData.Delete(lID))
		return FALSE;

	int nIndex = FindRecord(lID);
	if (nIndex == CB_ERR)
		return FALSE;

	m_oPersonsViewDataArray.Delete(nIndex);
	PERSONS_VIEW_DATA recPersonViewData;
	recPersonViewData.recPerson.lID = lID;

	CPersonsUpdateObject oPersonsUpdateObject(recPersonViewData, RecordOperationTypeDelete);
	UpdateAllViews(NULL, 0, (CObject*)&oPersonsUpdateObject);
	return TRUE;
}

int CPersonsDocument::FindRecord(const long lID)
{
	int nIndex = -1;
	for (int i = 0; i < m_oPersonsViewDataArray.GetCount(); i++)
	{
		const PERSONS_VIEW_DATA* pPersonViewData = m_oPersonsViewDataArray.GetAt(i);

		if (pPersonViewData == NULL)
			continue;

		if (pPersonViewData->recPerson.lID != lID)
			continue;

		nIndex = i;
		break;
	}
	return nIndex;
}

BOOL CPersonsDocument::FindCity(const long lID, CString& strCity)
{
	CITIES* pCity = NULL;
	if (!m_oCitiesMap.Lookup(lID, pCity))
		return FALSE;

	strCity = pCity->szName;

	return TRUE;
}

// Overrides
// ----------------
BOOL CPersonsDocument::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	if (!m_oPersonsData.LoadAllPersons(m_oPersonsViewDataArray))
		return FALSE;

	return TRUE;
}