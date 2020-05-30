#pragma once

#include "Structures.h"
#include "DatabaseAccessor.h"

/// <summary>
/// ���� �� ���������� �� ������ �� ������� PHONE_NUMBERS
/// </summary>
class CPhoneNumbersAccessor : public CDatabaseAccessor<PHONE_NUMBERS>
{

// Constants
// ----------------
private:
	/// <summary>����� �� ������ �� ������������� �� ������ � ���� �������</summary>
	static const int _nDataAccessorPersonIDColumnNumber = 3;

	/// <summary>����� �� ������ �� ������������� �� ��� ������� � ���� �������</summary>
	static const int _nDataAccessorPhoneTypeIDColumnNumber = 4;

	/// <summary>����� �� ������ �� ��������� ����� � ���� �������</summary>
	static const int _nDataAccessorPhoneNumberColumnNumber = 5;

// Constructor / Destructor
// ----------------

// Methods
// ----------------
protected:
	/// <summary>������� ��������� ��������, ����� ��������� ������ �� �������</summary>
	BEGIN_ACCESSOR_MAP(CPhoneNumbersAccessor, _nNumberOfAccessors)
		BEGIN_ACCESSOR(_nIdentityAccessor, true)
		COLUMN_ENTRY(_nIdentityAccessorIDColumnNumber, m_recDatabaseRecord.lID)
		END_ACCESSOR()

		BEGIN_ACCESSOR(_nDataAccessor, true)
		COLUMN_ENTRY(_nDataAccessorUpdateCounterColumnNumber, m_recDatabaseRecord.lUpdateCounter)
		COLUMN_ENTRY(_nDataAccessorPersonIDColumnNumber, m_recDatabaseRecord.lPersonID)
		COLUMN_ENTRY(_nDataAccessorPhoneTypeIDColumnNumber, m_recDatabaseRecord.lPhoneTypeID)
		COLUMN_ENTRY(_nDataAccessorPhoneNumberColumnNumber, m_recDatabaseRecord.szPhoneNumber)
		END_ACCESSOR()
	END_ACCESSOR_MAP()

// Overrides
// ----------------

// Members
// ----------------

};