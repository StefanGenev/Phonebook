#pragma once
#include "stdafx.h"
#include "Structures.h"
#include "CitiesDocument.h"
#include "RecordOperationTypes.h"
#include "UpdateObject.h"

/// <summary>
/// Клас за пренасяне на информация за ъпдейт на лист контрола
/// </summary>
class CCitiesUpdateObject : public CUpdateObject<CITIES>
{

// Constants
// ----------------

// Constructor / Destructor
// ----------------
public:
	CCitiesUpdateObject(const CITIES& recCity, RecordOperationTypes eRecordOperationTypes);
	virtual ~CCitiesUpdateObject();

// Methods
// ----------------

// Overrides
// ----------------

// Members
// ----------------
};