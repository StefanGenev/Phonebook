#include "stdafx.h"
#include "PhoneTypesDocument.h"
#include "PhoneTypesUpdateObject.h"

IMPLEMENT_DYNCREATE(CPhoneTypesDocument, CDocument)

BEGIN_MESSAGE_MAP(CPhoneTypesDocument, CDocument)

END_MESSAGE_MAP()

// Constructor / Destructor
// ----------------

CPhoneTypesDocument::CPhoneTypesDocument()
{
}

CPhoneTypesDocument::~CPhoneTypesDocument()
{
}

// Methods
// ----------------

const CPhoneTypesArray& CPhoneTypesDocument::GetAllPhoneTypes()
{
	return m_oPhoneTypesArray;
}

BOOL CPhoneTypesDocument::LoadPhoneType(const long lID, PHONE_TYPES& recPhoneType)
{
	return m_oPhoneTypesData.LoadPhoneType(lID, recPhoneType);
}

BOOL CPhoneTypesDocument::Insert(PHONE_TYPES& recPhoneType)
{
	if (!m_oPhoneTypesData.Insert(recPhoneType))
		return FALSE;

	m_oPhoneTypesArray.Insert(recPhoneType);

	const CPhoneTypesUpdateObject oPhoneTypesUpdateObject(recPhoneType, RecordOperationTypeInsert);
	UpdateAllViews(NULL, 0, (CObject*)&oPhoneTypesUpdateObject);
	return TRUE;
}

BOOL CPhoneTypesDocument::Update(const long lID, const PHONE_TYPES& recPhoneType)
{
	if (!m_oPhoneTypesData.Update(lID, recPhoneType))
		return FALSE;

	int nIndex = FindRecord(lID);
	if (nIndex == CB_ERR)
		return FALSE;

	m_oPhoneTypesArray.Delete(nIndex);
	m_oPhoneTypesArray.Insert(recPhoneType);
	
	const CPhoneTypesUpdateObject oPhoneTypesUpdateObject(recPhoneType, RecordOperationTypeUpdate);
	UpdateAllViews(NULL, 0, (CObject*)&oPhoneTypesUpdateObject);
	return TRUE;
}

BOOL CPhoneTypesDocument::Delete(const long lID)
{
	if (!m_oPhoneTypesData.Delete(lID))
		return FALSE;

	int nIndex = FindRecord(lID);
	if (nIndex == CB_ERR)
		return FALSE;
	
	m_oPhoneTypesArray.Delete(nIndex);

	PHONE_TYPES recPhoneType;
	recPhoneType.lID = lID;

	const CPhoneTypesUpdateObject oPhoneTypesUpdateObject(recPhoneType, RecordOperationTypeDelete);
	UpdateAllViews(NULL, 0, (CObject*)&oPhoneTypesUpdateObject);
	return TRUE;
}

int CPhoneTypesDocument::FindRecord(const long lID)
{
	int nIndex = -1;
	for (int i = 0; i < m_oPhoneTypesArray.GetCount(); i++)
	{
		PHONE_TYPES* pPhoneType = m_oPhoneTypesArray.GetAt(i);

		if (pPhoneType == NULL)
			continue;

		if (pPhoneType->lID != lID)
			continue;

		nIndex = i;
		break;
	}
	return nIndex;
}


// Overrides
// ----------------

BOOL CPhoneTypesDocument::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	if (!m_oPhoneTypesData.LoadAllPhoneTypes(m_oPhoneTypesArray))
		return FALSE;

	return TRUE;
}
