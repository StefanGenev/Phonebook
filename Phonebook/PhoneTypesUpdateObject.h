#pragma once
#include "stdafx.h"
#include "Structures.h"
#include "PhoneTypesDocument.h"
#include "RecordOperationTypes.h"
#include "UpdateObject.h"

/// <summary>
/// Клас за пренасяне на информация за ъпдейт на лист контрола
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