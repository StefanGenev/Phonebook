#include "stdafx.h"
#include "Phonebook.h"
#include "PhoneNumbersDlg.h"
#include "PersonsDlg.h"
#include "afxdialogex.h"
#include "Validator.h"



IMPLEMENT_DYNAMIC(CPhoneNumbersDlg, CDialogEx)
BEGIN_MESSAGE_MAP(CPhoneNumbersDlg, CDialogEx)
END_MESSAGE_MAP()

// Constants
// ----------------


// Constructor / Destructor
// ----------------

CPhoneNumbersDlg::CPhoneNumbersDlg(PHONE_NUMBERS_VIEW_DATA& recPhoneNumberViewData, const CPhoneTypesMap& oPhoneTypesMap, CWnd* pParent)
	:recPhoneNumberViewData(recPhoneNumberViewData), m_oPhoneTypesMap(oPhoneTypesMap), CDialogEx(IDD_PHONE_NUMBERS_DIALOG, pParent)
{
	
}

CPhoneNumbersDlg::~CPhoneNumbersDlg()
{
}

// Methods
// ----------------
void CPhoneNumbersDlg::SetTextLimits()
{
	m_edbNumber.SetLimitText(PHONE_NUMBERS_PHONE_NUMBER_LENGTH);
}

void CPhoneNumbersDlg::FillEditBoxes()
{
	m_edbNumber.SetWindowText(recPhoneNumberViewData.recPhoneNumber.szPhoneNumber);
}

void CPhoneNumbersDlg::FillPhoneTypes()
{
	for (POSITION oPosition = m_oPhoneTypesMap.GetStartPosition(); oPosition != NULL;)
	{
		long lID = 0;
		PHONE_TYPES* pPhoneType = NULL;
		m_oPhoneTypesMap.GetNextAssoc(oPosition, lID, pPhoneType);

		if (lID <= CB_OKAY)
			continue;

		if (pPhoneType == NULL)
			continue;

		int nIndex = m_cmbType.AddString(pPhoneType->szType);
		m_cmbType.SetItemData(nIndex, lID);

		if (lID != recPhoneNumberViewData.recPhoneNumber.lPhoneTypeID)
			continue;

		m_cmbType.SetCurSel(nIndex);
	}
}

BOOL CPhoneNumbersDlg::ValidateData()
{
	CString strTypeLabel, strNumberLabel;
	GetDlgItem(IDC_STT_PHONE_NUMBERS_TYPE)->GetWindowText(strTypeLabel);
	GetDlgItem(IDC_STT_PHONE_NUMBERS_NUMBER)->GetWindowText(strNumberLabel);

	CString strMessage;
	strMessage.Append(ValidateComboBox(m_cmbType, strTypeLabel));
	strMessage.Append(ValidateEditBox(m_edbNumber, strNumberLabel, CValidator::EdbTypePhoneNumber));

	if (!strMessage.IsEmpty())
	{
		AfxMessageBox(strMessage);
		return FALSE;
	}

	return TRUE;
}

CString CPhoneNumbersDlg::ValidateEditBox(const CEdit& edbCtrl, const CString& strFieldName, const CValidator::EdbTypes eEdbTypes)
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

CString CPhoneNumbersDlg::ValidateComboBox(const CComboBox& cmbCtrl, const CString& strFieldName)
{
	CString strMessage;

	if (cmbCtrl.GetCurSel() == CB_ERR)
	{
		GotoDlgCtrl(GetDlgItem(cmbCtrl.GetDlgCtrlID()));
		strMessage.AppendFormat(_T("\nNo value for '%s' is chosen."), strFieldName.Left(strFieldName.GetLength() - 1));
	}

	return strMessage;
}

void CPhoneNumbersDlg::TransferDataToRecord()
{
	CString strPhoneNumber;
	m_edbNumber.GetWindowText(strPhoneNumber);

	_tcscpy_s(recPhoneNumberViewData.recPhoneNumber.szPhoneNumber, strPhoneNumber.Trim());
	recPhoneNumberViewData.recPhoneNumber.lPhoneTypeID = m_cmbType.GetItemData(m_cmbType.GetCurSel());
	m_cmbType.GetWindowText(recPhoneNumberViewData.strType);
}

// Overrides
// ----------------
void CPhoneNumbersDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CMB_PHONE_NUMBERS_TYPE, m_cmbType);
	DDX_Control(pDX, IDC_EDB_PHONE_NUMBERS_NUMBER, m_edbNumber);
}

BOOL CPhoneNumbersDlg::OnInitDialog()
{
	if (!CDialog::OnInitDialog())
		return FALSE;
	
	SetTextLimits();
	FillPhoneTypes();
	FillEditBoxes();

	return TRUE;
}

void CPhoneNumbersDlg::OnOK()
{
	CString strPhoneNumber;
	if (!ValidateData())
		return;

	TransferDataToRecord();

	CDialogEx::OnOK();
}
