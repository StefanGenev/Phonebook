#pragma once
#include "stdafx.h"
#include "Structures.h"



/// <summary>
/// Клас за пренасяне на информация за абонат и неговите телефонни номера
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
	/// <summary>Запис на абонат</summary>
	PERSONS recPerson;

	/// <summary>Масив с телефонни номера на абонат</summary>
	CPhoneNumbersArray oPhoneNumbersArray;

};