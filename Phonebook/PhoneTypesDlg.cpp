// PhoneTypesDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Phonebook.h"
#include "PhoneTypesDlg.h"
#include "afxdialogex.h"
#include "PhoneTypesView.h"
#include "Validator.h"


IMPLEMENT_DYNAMIC(CPhoneTypesDlg, CDialog)
BEGIN_MESSAGE_MAP(CPhoneTypesDlg, CDialog)
END_MESSAGE_MAP()

// Constructor / Destructor
// ----------------

CPhoneTypesDlg::CPhoneTypesDlg(PHONE_TYPES& recPhoneType, CWnd* pParent) : m_recPhoneType(recPhoneType), CDialog(IDD_PHONE_TYPES_DIALOG, pParent)
{

}

CPhoneTypesDlg::~CPhoneTypesDlg()
{
}

void CPhoneTypesDlg::SetTextLimits()
{
	m_edbType.SetLimitText(PHONE_TYPES_TYPE_LENGTH);
}

void CPhoneTypesDlg::FillEditBoxes()
{
	m_edbType.SetWindowText(m_recPhoneType.szType);
}

CString CPhoneTypesDlg::ValidateEditBox(const CEdit& edbCtrl, const CString& strFieldName, const CValidator::EdbTypes eEdbTypes)
{
	CString strValue;
	edbCtrl.GetWindowText(strValue);
	strValue.Trim();

	CString strMessage;
	bool bIsValid = true;

	if (!CValidator::ValidateField(strValue, strFieldName.Left(strFieldName.GetLength() - 1), eEdbTypes, bIsValid, strMessage))
		return strMessage;

	if (!bIsValid)
		GotoDlgCtrl(GetDlgItem(edbCtrl.GetDlgCtrlID()));

	return strMessage;
}

BOOL CPhoneTypesDlg::ValidateData()
{	
	CString strTypeLabel;
	GetDlgItem(IDC_STT_PHONE_TYPES_TYPE)->GetWindowText(strTypeLabel);

	CString strMessage;
	strMessage.Append(ValidateEditBox(m_edbType, strTypeLabel, CValidator::EdbTypeNames));

	if (!strMessage.IsEmpty())
	{
		AfxMessageBox(strMessage);
		return FALSE;
	}

	return TRUE;
}

void CPhoneTypesDlg::TransferDataToRecord()
{
	CString strType;
	m_edbType.GetWindowText(strType);

	_tcscpy_s(m_recPhoneType.szType, strType.Trim());
}

// Methods
// ----------------

// Overrides
// ----------------

void CPhoneTypesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDB_PHONE_TYPES_TYPE, m_edbType);
}

BOOL CPhoneTypesDlg::OnInitDialog()
{
	if (!CDialog::OnInitDialog())
		return FALSE;

	SetTextLimits();
	FillEditBoxes();
	
	return TRUE;  
}

void CPhoneTypesDlg::OnOK()
{	
	CString strFirstData;

	if (!ValidateData())
		return;

	TransferDataToRecord();

	CDialog::OnOK();
}
