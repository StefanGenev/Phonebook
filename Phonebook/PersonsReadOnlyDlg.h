#pragma once
#include "PersonsDlg.h"

/// <summary>
/// ���� �� ������ �� ������ �� ���������� �� ����
/// </summary>
class CPersonsReadOnlyDlg : public CPersonsDlg
{
// Constants
// ----------------

// Constructor / Destructor
// ----------------
public:
	CPersonsReadOnlyDlg(CPerson& oPerson, const CCitiesMap& oCitiesMap, const CPhoneTypesMap& oPhoneTypesMap);
	virtual ~CPersonsReadOnlyDlg();

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

	/// <summary>�����, �������� ����������� �� �������� �� ������������ ����, ���������� �� ����� ����� ���������� �� ������</summary>
	afx_msg virtual void OnUpdateBtnPopup(CCmdUI* pCmdUI);

	/// <summary>�����, ����� ������� ����� ���� cmbCity � �������� �������</summary>
	virtual void FillCities();

// Members
// ----------------
};