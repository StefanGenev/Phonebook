#pragma once
#include "stdafx.h"
#include "Structures.h"
#include "PersonsViewData.h"
#include "RecordOperationTypes.h"
#include "UpdateObject.h"


/// <summary>
/// ���� �� ��������� �� ���������� �� ������ �� ���� ��������
/// </summary>
class CPersonsUpdateObject : public CUpdateObject<PERSONS_VIEW_DATA>
{

// Constants
// ----------------

// Constructor / Destructor
// ----------------
public:
	CPersonsUpdateObject(const PERSONS_VIEW_DATA& recPersonViewData, RecordOperationTypes eRecordOperationTypes);
	virtual ~CPersonsUpdateObject();

// Methods
// ----------------


// Overrides
// ----------------

// Members
// ----------------

};