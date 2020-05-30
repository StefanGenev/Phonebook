#pragma once
#include "PhoneNumbersDlg.h"
#include "PhoneNumbersViewData.h"

/// <summary>
/// ���� �� ������ �� ������ �� ���������� �� ��������� �����
/// </summary>
class CPhoneNumbersReadOnlyDlg : public CPhoneNumbersDlg
{
// Constants
// ----------------

// Constructor / Destructor
// ----------------
public:
	CPhoneNumbersReadOnlyDlg(PHONE_NUMBERS_VIEW_DATA& recPhoneNumberViewData, const CPhoneTypesMap& oPhoneTypesMap);
	virtual ~CPhoneNumbersReadOnlyDlg();

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

	/// <summary>�����, ������� ����� ���� � ������ ��������</summary>
	virtual void FillPhoneTypes();

// Members
// ----------------

};