#pragma once
#include "stdafx.h"
#include "PhoneNumbersAccessor.h"
#include "DatabaseTable.h"

/// <summary>
/// ���� �� ������� � ��������� ������ PHONE_NUMBERS
/// </summary>
class CPhoneNumbersTable : public CDatabaseTable<CPhoneNumbersAccessor, PHONE_NUMBERS>
{

// Constants
// ----------------

// Constructor / Destructor
// ----------------
public:
	CPhoneNumbersTable();
	CPhoneNumbersTable(CDatabaseSession& oSession);
	virtual ~CPhoneNumbersTable();

// Methods
// ----------------

// Overrides
// ----------------
private:
	/// <summary>������� ������� ��� �� ������� �� ���� �����</summary>
	///<returns> ��������� ����� string � ��� �� �������</returns>
	virtual CString GetTableName();

	/// <summary>������� ������� ���������� ��� ������������� �� ����� �� �������</summary>
	/// <param name="recPhoneNumber">����� �� �������</param>
	///<returns> ��������� ����� ���������� ���������� ��� long</returns>
	virtual const long& GetIdentificator(const PHONE_NUMBERS& recPhoneNumber);

	/// <summary>������� ������� ���������� ��� ����� �� ������� �� �������</summary>
	/// <param name="recPhoneNumber">����� �� �������</param>
	///<returns> ��������� ����� ���������� ��� long</returns>
	virtual long& GetUpdateCounter(PHONE_NUMBERS& recPhoneNumber);

// Members
// ----------------

};