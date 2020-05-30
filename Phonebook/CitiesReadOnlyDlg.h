#pragma once
#include "CitiesDlg.h"

/// <summary>
/// ���� �� ������ �� ������ �� ���������� �� ����
/// </summary>
class CCitiesReadOnlyDlg : public CCitiesDlg
{
// Constants
// ----------------

// Constructor / Destructor
// ----------------
public:
	CCitiesReadOnlyDlg(CITIES& recCity);
	virtual ~CCitiesReadOnlyDlg();

// Methods
// ----------------

// Overrides
// ----------------
private:
	/// <summary>�����, ����� �� ��������� ��� ������������� �� ������</summary>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	virtual BOOL OnInitDialog();

	/// <summary>�����, ����� �� ��������� ��� ����������� �� ������ OK</summary>
	virtual void OnOK();

// Members
// ----------------
};