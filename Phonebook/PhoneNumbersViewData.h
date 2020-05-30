#pragma once
#include "Structures.h"

/// <summary>
/// ��������� �� ������������ �� ��������� ����� � �������� ���
/// </summary>
struct PHONE_NUMBERS_VIEW_DATA
{
	/// <summary>����� �� ��������� �����</summary>
	PHONE_NUMBERS recPhoneNumber;

	/// <summary>��� �������</summary>
	CString strType;
};

typedef CAutoClearPtrArray<PHONE_NUMBERS_VIEW_DATA> CPhoneNumbersViewDataArray;

