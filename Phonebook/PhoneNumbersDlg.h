#pragma once
#include "afxwin.h"
#include "Structures.h"
#include "PhoneNumbersViewData.h"
#include "Validator.h"

/// <summary>
/// ���� �� ������ �� �������� � �������� �� ��������� �����
/// </summary>
class CPhoneNumbersDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPhoneNumbersDlg)

// Constants
// ----------------


// Constructor / Destructor
// ----------------
public:
	CPhoneNumbersDlg(PHONE_NUMBERS_VIEW_DATA& recPhoneNumberViewData, const CPhoneTypesMap& oPhoneTypesMap, CWnd* pParent = NULL);
	virtual ~CPhoneNumbersDlg();


#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PHONE_NUMBERS_DIALOG };
#endif
// Methods
// ----------------
protected:
	/// <summary>����� ������� ����� �� ������� �� ���� ��������� � �������</summary>
	void SetTextLimits();

	/// <summary>�����, ����� ������� �������� ���������� ��� ������� � ���� ���������</summary>
	void FillEditBoxes();
	
	/// <summary>�����, ����� ������� ����� ���� m_cmbType � �������� ������ ��������</summary>
	virtual void FillPhoneTypes();

private:
	/// <summary>�����, ����� �������� ������� �� ����������</summary>
	///<returns> ��������� ����� �������� TRUE ��� ������� ����� � FALSE ��� ������� �� ���� ���� ��������� �����</returns>
	BOOL ValidateData();

	/// <summary>�����, ����� �������� ���� ��������</summary>
	/// <param name="edbCtrl">���� ��������</param>
	/// <param name="strFieldName">��� �� ������, ����� ���� ����������</param>
	/// <param name="eEdbTypes">��� �� �����, ����� ������� ���� ����������</param>
	///<returns> ��������� ����� ������ � ���������� �� ������� ��������� � ������ ������ ��� ������� ������� �����</returns>
	CString ValidateEditBox(const CEdit& edbCtrl, const CString& strFieldName, const CValidator::EdbTypes eEdbTypes);

	/// <summary>�����, ����� �������� ����� ����</summary>
	/// <param name="cmbCtrl">����� ����</param>
	/// <param name="strFieldName">��� �� ������, ����� ���� ����������</param>
	///<returns> ��������� ����� ������ � ���������� �� ������� ��������� � ������ ������ ��� ������� ������� �����</returns>
	CString ValidateComboBox(const CComboBox& cmbCtrl, const CString& strFieldName);

	/// <summary>�����, ����� ����������� ������� �� ���������� � ������</summary>
	void TransferDataToRecord();

// Overrides
// ----------------
protected:
	/// <summary>�����, ����� ����� ������� �� �������</summary>
	/// <param name="pDx">�������� ����� CDataExchange �����</param>
	virtual void DoDataExchange(CDataExchange* pDX);

	/// <summary>�����, ����� �� ��������� ��� ������������� �� ������</summary>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	virtual BOOL OnInitDialog();

	/// <summary>�����, ����� �� ��������� ��� ����������� �� ������ OK</summary>
	virtual void OnOK();

// Members
// ----------------
protected:
	/// <summary>����� �� ��������� �����</summary>
	PHONE_NUMBERS_VIEW_DATA& recPhoneNumberViewData;

private:
	/// <summary>�����, ����� �������� �������� ���������</summary>
	DECLARE_MESSAGE_MAP()

	/// <summary>���������� �� combo box �� ��� �� ��������� �����</summary>
	CComboBox m_cmbType;

	/// <summary>���������� �� �dit box �� ��������� �����</summary>
	CEdit m_edbNumber;

	/// <summary>��� � ��������� ������ ������ �� ������ ������ ��������</summary>
	const CPhoneTypesMap& m_oPhoneTypesMap;


};
