#pragma once
#include "PhoneTypesDlg.h"

/// <summary>
/// ���� �� ������ �� ������ �� ���������� �� ��� �������
/// </summary>
class CPhoneTypesReadOnlyDlg : public CPhoneTypesDlg
{
// Constants
// ----------------

// Constructor / Destructor
// ----------------
public:
	CPhoneTypesReadOnlyDlg(PHONE_TYPES& recPhoneType);
	virtual ~CPhoneTypesReadOnlyDlg();

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