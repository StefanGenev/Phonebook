#pragma once
#pragma once

#include "stdafx.h"
#include "Structures.h"
#include "PersonsAccessor.h"
#include "DatabaseTable.h"

/// <summary>
/// ���� �� ������� � ������� PERSONS
/// </summary>
class CPersonsTable : public CDatabaseTable<CPersonsAccessor, PERSONS>
{

// Constants
// ----------------


// Constructor / Destructor
// ----------------

public:
	CPersonsTable();
	CPersonsTable(CDatabaseSession& oSession);
	virtual ~CPersonsTable();


// Methods
// ----------------

// Overrides
// ----------------
private:
	/// <summary>������� ������� ��� �� ������� �� ���� �����</summary>
	///<returns> ��������� ����� string � ��� �� �������</returns>
	virtual CString GetTableName();

	/// <summary>������� ������� ���������� ��� ������������� �� ����� �� �������</summary>
	/// <param name="recPerson">����� �� �������</param>
	///<returns> ��������� ����� ���������� ���������� ��� long</returns>
	virtual const long& GetIdentificator(const PERSONS& recPerson);

	/// <summary>������� ������� ���������� ��� ����� �� ������� �� �������</summary>
	/// <param name="recPerson">����� �� �������</param>
	///<returns> ��������� ����� ���������� ��� long</returns>
	virtual long& GetUpdateCounter(PERSONS& recPerson);

// Members
// ----------------


};