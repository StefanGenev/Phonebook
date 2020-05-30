#pragma once
#include "Structures.h"

/// <summary>
/// Структура за пренос на абонат заедно със стрингова стойност на града, в който живее той
/// </summary>
struct PERSONS_VIEW_DATA
{
	/// <summary>Запис на абонат</summary>
	PERSONS recPerson;

	/// <summary>Град на абонат</summary>
	CString strCity;	
};

typedef CAutoClearPtrArray<PERSONS_VIEW_DATA> CPersonsViewDataArray;