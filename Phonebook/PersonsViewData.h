#pragma once
#include "Structures.h"

/// <summary>
/// ��������� �� ������ �� ������ ������ ��� ��������� �������� �� �����, � ����� ����� ���
/// </summary>
struct PERSONS_VIEW_DATA
{
	/// <summary>����� �� ������</summary>
	PERSONS recPerson;

	/// <summary>���� �� ������</summary>
	CString strCity;	
};

typedef CAutoClearPtrArray<PERSONS_VIEW_DATA> CPersonsViewDataArray;