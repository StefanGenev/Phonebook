#pragma once
#include "stdafx.h"
#include "CitiesUpdateObject.h"

// Constructor / Destructor
// ----------------

CCitiesUpdateObject::CCitiesUpdateObject(const CITIES& recCity, RecordOperationTypes eRecordOperationTypes) 
	: CUpdateObject(recCity, eRecordOperationTypes)
{
}

CCitiesUpdateObject::~CCitiesUpdateObject()
{
}

// Methods
// ----------------


// Overrides
// ----------------