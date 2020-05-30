#pragma once

#include "stdafx.h"
#include "Structures.h"
#include "CitiesAccessor.h"
#include "DatabaseTable.h"

/// <summary>
/// ���� �� ������� � ������� CCitiesTable
/// </summary>
class CCitiesTable : public CDatabaseTable<CCitiesAccessor, CITIES>
{

// Constants
// ----------------


// Constructor / Destructor
// ----------------

public:
	CCitiesTable();
	CCitiesTable(CDatabaseSession& oSession);
	virtual ~CCitiesTable();
	
// Methods
// ----------------

// Overrides
// ----------------
private:
	/// <summary>������� ������� ��� �� ������� �� ���� �����</summary>
	///<returns> ��������� ����� string � ��� �� �������</returns>
	virtual CString GetTableName();

	/// <summary>������� ������� ���������� ��� ������������� �� ����� �� �������</summary>
	/// <param name="recCity">����� �� �������</param>
	///<returns> ��������� ����� ���������� ���������� ��� long</returns>
	virtual const long& GetIdentificator(const CITIES& recCity);

	/// <summary>������� ������� ���������� ��� ����� �� ������� �� �������</summary>
	/// <param name="recCity">����� �� �������</param>
	///<returns> ��������� ����� ���������� ��� long</returns>
	virtual long& GetUpdateCounter(CITIES& recCity);


// Members
// ----------------

};