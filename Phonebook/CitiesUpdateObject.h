#pragma once
#include "stdafx.h"
#include "Structures.h"
#include "CitiesDocument.h"
#include "RecordOperationTypes.h"
#include "UpdateObject.h"

/// <summary>
/// ���� �� ��������� �� ���������� �� ������ �� ���� ��������
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