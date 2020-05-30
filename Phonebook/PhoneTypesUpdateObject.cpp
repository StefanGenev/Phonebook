#pragma once
#include "stdafx.h"
#include "PhoneTypesUpdateObject.h"


// Constructor / Destructor
// ----------------

CPhoneTypesUpdateObject::CPhoneTypesUpdateObject(const PHONE_TYPES& recPhoneType, RecordOperationTypes eRecordOperationTypes)
	: CUpdateObject(recPhoneType, eRecordOperationTypes)
{
}

CPhoneTypesUpdateObject::~CPhoneTypesUpdateObject()
{
}

// Methods
// ----------------


// Overrides
// ----------------