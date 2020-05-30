#pragma once
#include "stdafx.h"
#include "PersonsUpdateObject.h"

// Constructor / Destructor
// ----------------

CPersonsUpdateObject::CPersonsUpdateObject(const PERSONS_VIEW_DATA& recPersonViewData, RecordOperationTypes eRecordOperationTypes) 
	: CUpdateObject(recPersonViewData, eRecordOperationTypes)
{
}

CPersonsUpdateObject::~CPersonsUpdateObject()
{
}

// Methods
// ----------------


// Overrides
// ----------------


