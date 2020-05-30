#pragma once
#include "stdafx.h"
#include "Structures.h"
#include "PhoneTypesDocument.h"
#include "RecordOperationTypes.h"
#include "UpdateObject.h"

/// <summary>
/// ���� �� ��������� �� ���������� �� ������ �� ���� ��������
/// </summary>
class CPhoneTypesUpdateObject : public CUpdateObject<PHONE_TYPES>
{

// Constants
// ----------------

// Constructor / Destructor
// ----------------
public:
	CPhoneTypesUpdateObject(const PHONE_TYPES& recPhoneType, RecordOperationTypes eRecordOperationTypes);
	virtual ~CPhoneTypesUpdateObject();

// Methods
// ----------------


// Overrides
// ----------------

// Members
// ----------------

};