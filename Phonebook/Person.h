#pragma once
#include "stdafx.h"
#include "Structures.h"



/// <summary>
/// ���� �� ��������� �� ���������� �� ������ � �������� ��������� ������
/// </summary>
class CPerson
{

// Constants
// ----------------

// Constructor / Destructor
// ----------------
public:
	CPerson();
	virtual ~CPerson();

// Methods
// ----------------

// Overrides
// ----------------

// Members
// ----------------
public:
	/// <summary>����� �� ������</summary>
	PERSONS recPerson;

	/// <summary>����� � ��������� ������ �� ������</summary>
	CPhoneNumbersArray oPhoneNumbersArray;

};