#pragma once
#pragma once
#include "Structures.h"
#include "DatabaseAccessor.h"


/// <summary>
/// ���� �� ���������� �� ������ �� ������� PHONE_TYPES
/// </summary>
class CPhoneTypesAccessor : public CDatabaseAccessor<PHONE_TYPES>
{

// Constants
// ----------------
private:
	/// <summary>����� �� ������ �� ��� ������� � ���� �������</summary>
	static const int _nDataAccessorTypeColumnNumber = 3;

// Constructor / Destructor
// ----------------

// Methods
// ----------------
protected:
	/// <summary>������� ��������� ��������, ����� ��������� ������ �� �������</summary>
	BEGIN_ACCESSOR_MAP(CPhoneTypesAccessor, _nNumberOfAccessors)
		BEGIN_ACCESSOR(_nIdentityAccessor, true)
		COLUMN_ENTRY(_nIdentityAccessorIDColumnNumber, m_recDatabaseRecord.lID)
		END_ACCESSOR()

		BEGIN_ACCESSOR(_nDataAccessor, true)
		COLUMN_ENTRY(_nDataAccessorUpdateCounterColumnNumber, m_recDatabaseRecord.lUpdateCounter)
		COLUMN_ENTRY(_nDataAccessorTypeColumnNumber, m_recDatabaseRecord.szType)
		END_ACCESSOR()
	END_ACCESSOR_MAP()

// Overrides
// ----------------

// Members
// ----------------

};