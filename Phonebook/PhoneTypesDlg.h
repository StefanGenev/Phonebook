#pragma once
#include "afxwin.h"
#include "Structures.h"
#include "Validator.h"

/// <summary>
/// ���� �� ������ �� �������� � �������� �� ��� �������
/// </summary>
class CPhoneTypesDlg : public CDialog
{
	DECLARE_DYNAMIC(CPhoneTypesDlg)

// Constants
// ----------------


// Constructor / Destructor
// ----------------

public:
	CPhoneTypesDlg(PHONE_TYPES& recPhoneType, CWnd* pParent = NULL);
	virtual ~CPhoneTypesDlg();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PHONE_TYPES_DIALOG };
#endif

// Methods
// ----------------
protected:
	/// <summary>����� ������� ����� �� ������� �� ���� ��������� � �������</summary>
	void SetTextLimits();

	/// <summary>�����, ����� ������� �������� ���������� ��� ������� � ���� ���������</summary>
	void FillEditBoxes();

	/// <summary>�����, ����� �������� ���� ��������</summary>
	/// <param name="edbCtrl">���� ��������</param>
	/// <param name="strFieldName">��� �� ������, ����� ���� ����������</param>
	/// <param name="eEdbTypes">��� �� �����, ����� ������� ���� ����������</param>
	///<returns> ��������� ����� ������ � ���������� �� ������� ��������� � ������ ������ ��� ������� ������� �����</returns>
	CString ValidateEditBox(const CEdit& edbCtrl, const CString& strFieldName, const CValidator::EdbTypes eEdbTypes);

	/// <summary>�����, ����� �������� ������ ����� �� �������</summary>
	BOOL ValidateData();

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
private:
	/// <summary>�����, ����� �������� �������� ���������</summary>
	DECLARE_MESSAGE_MAP()

	/// <summary>���������� �� �dit box �� ��� �������</summary>
	CEdit m_edbType;

	/// <summary>����� �� ��� �������</summary>
	PHONE_TYPES& m_recPhoneType;
};
