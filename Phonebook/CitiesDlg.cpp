// CitiesDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Phonebook.h"
#include "CitiesDlg.h"
#include "afxdialogex.h"
#include "Resource.h"
#include "Structures.h"
#include "CitiesView.h"
#include "Validator.h"



IMPLEMENT_DYNAMIC(CCitiesDlg, CDialog)
BEGIN_MESSAGE_MAP(CCitiesDlg, CDialog)
END_MESSAGE_MAP()

// Constructor / Destructor
// ----------------

CCitiesDlg::CCitiesDlg(CITIES& recCity, CWnd* pParent) : m_recCity(recCity), CDialog(IDD_CITIES_DIALOG, pParent) 
{

}

CCitiesDlg::~CCitiesDlg()
{
}
// Methods
// ----------------

void CCitiesDlg::SetTextLimits()
{
	m_edbName.SetLimitText(CITIES_NAME_LENGTH);
	m_edbRegion.SetLimitText(CITIES_REGION_LENGTH);
}

void CCitiesDlg::FillEditBoxes()
{
	m_edbName.SetWindowText(m_recCity.szName);
	m_edbRegion.SetWindowText(m_recCity.szRegion);
}

CString CCitiesDlg::ValidateEditBox(const CEdit& edbCtrl, const CString& strFieldName, const CValidator::EdbTypes eEdbTypes)
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

BOOL CCitiesDlg::ValidateData()
{
	CString strNameLabel, strRegionLabel;

	GetDlgItem(IDC_STT_CITIES_NAME)->GetWindowText(strNameLabel);
	GetDlgItem(IDC_STT_CITIES_REGION)->GetWindowText(strRegionLabel);

	CString strMessage;
	strMessage.Append(ValidateEditBox(m_edbName, strNameLabel, CValidator::EdbTypeNames));
	strMessage.Append(ValidateEditBox(m_edbRegion, strRegionLabel, CValidator::EdbTypeNames));

	if (!strMessage.IsEmpty())
	{
		AfxMessageBox(strMessage);
		return FALSE;
	}
	
	return TRUE;
}

void CCitiesDlg::TransferDataToRecord()
{
	CString strName, strRegion;

	m_edbName.GetWindowText(strName);
	m_edbRegion.GetWindowText(strRegion);

	_tcscpy_s(m_recCity.szName, strName.Trim());
	_tcscpy_s(m_recCity.szRegion, strRegion.Trim());
}

// Overrides
// ----------------
void CCitiesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDB_CITIES_NAME, m_edbName);
	DDX_Control(pDX, IDC_EDB_CITIES_REGION, m_edbRegion);
}

BOOL CCitiesDlg::OnInitDialog()
{
	if (!CDialog::OnInitDialog())
		return FALSE;
	
	SetTextLimits();
	FillEditBoxes();

	return TRUE;  
}

void CCitiesDlg::OnOK()
{		
	if (!ValidateData())
		return;
	
	TransferDataToRecord();

	CDialog::OnOK();
}




