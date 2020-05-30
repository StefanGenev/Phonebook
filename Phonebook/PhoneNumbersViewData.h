#pragma once
#include "Structures.h"

/// <summary>
/// Структура за визуализация на телефонен номер с неговият тип
/// </summary>
struct PHONE_NUMBERS_VIEW_DATA
{
	/// <summary>Запис на телефонен номер</summary>
	PHONE_NUMBERS recPhoneNumber;

	/// <summary>Тип телефон</summary>
	CString strType;
};

typedef CAutoClearPtrArray<PHONE_NUMBERS_VIEW_DATA> CPhoneNumbersViewDataArray;

