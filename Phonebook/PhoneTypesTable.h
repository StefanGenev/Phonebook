#pragma once
#include "stdafx.h"
#include "Structures.h"
#include "PhoneTypesAccessor.h"
#include "DatabaseTable.h"

/// <summary>
/// ���� �� ������� � ������ �������� PHONE_TYPES
/// </summary>
class CPhoneTypesTable : public CDatabaseTable<CPhoneTypesAccessor, PHONE_TYPES>
{

// Constants
// ----------------

// Constructor / Destructor
// ----------------
public:
	CPhoneTypesTable();
	CPhoneTypesTable(CDatabaseSession& oSession);
	virtual ~CPhoneTypesTable();

// Methods
// ----------------

// Overrides
// ----------------
private:
	/// <summary>������� ������� ��� �� ������� �� ���� �����</summary>
	///<returns> ��������� ����� string � ��� �� �������</returns>
	virtual CString GetTableName();

	/// <summary>������� ������� ���������� ��� ������������� �� ����� �� �������</summary>
	/// <param name="recPhoneType">����� �� �������</param>
	///<returns> ��������� ����� ���������� ���������� ��� long</returns>
	virtual const long& GetIdentificator(const PHONE_TYPES& recPhoneType);

	/// <summary>������� ������� ���������� ��� ����� �� ������� �� �������</summary>
	/// <param name="recPhoneType">����� �� �������</param>
	///<returns> ��������� ����� ���������� ��� long</returns>
	virtual long& GetUpdateCounter(PHONE_TYPES& recPhoneType);

// Members
// ----------------

};