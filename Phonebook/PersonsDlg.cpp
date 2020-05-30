// PersonsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Phonebook.h"
#include "PersonsDlg.h"
#include "afxdialogex.h"
#include "PhoneNumbersDlg.h"
#include "PhoneNumbersReadOnlyDlg.h"
#include "PersonsView.h"
#include "Validator.h"


IMPLEMENT_DYNAMIC(CPersonsDlg, CDialog)
BEGIN_MESSAGE_MAP(CPersonsDlg, CDialog)
	ON_WM_INITMENUPOPUP()
	ON_NOTIFY(LVN_ITEMACTIVATE, IDC_LSC_PERSONS_PHONE_NUMBERS, &CPersonsDlg::OnItemActivatePhoneNumbers)
	ON_COMMAND(IDC_BTN_POPUP_EDIT, &CPersonsDlg::OnBtnPopupEdit)
	ON_COMMAND(IDC_BTN_POPUP_DELETE, &CPersonsDlg::OnBtnPopupDelete)
	ON_COMMAND(IDC_BTN_POPUP_INSERT, &CPersonsDlg::OnBtnPopupInsert)
	ON_UPDATE_COMMAND_UI(IDC_BTN_POPUP_EDIT, &CPersonsDlg::OnUpdateBtnPopup)
	ON_UPDATE_COMMAND_UI(IDC_BTN_POPUP_DELETE, &CPersonsDlg::OnUpdateBtnPopup)
	ON_UPDATE_COMMAND_UI(IDC_BTN_POPUP_INSERT, &CPersonsDlg::OnUpdateBtnPopup)
	ON_NOTIFY(NM_RCLICK, IDC_LSC_PERSONS_PHONE_NUMBERS, &CPersonsDlg::OnNMRClickPhoneNumbers)
END_MESSAGE_MAP()

// Constants
// ----------------

const CString CPersonsDlg::_strPhoneNumbersTypeColumnCaption = _T("Type");
const CString CPersonsDlg::_strPhoneNumbersNumberColumnCaption = _T("Number");

const int CPersonsDlg::_nPhoneNumbersTypeColumnWidth = 90;
const int CPersonsDlg::_nPhoneNumbersNumberColumnWidth = 160;

const int CPersonsDlg::_nSubmenuIndex = 0;


// Constructor / Destructor
// ----------------


CPersonsDlg::CPersonsDlg(CPerson& oPerson, const CCitiesMap& oCitiesMap, const CPhoneTypesMap& oPhoneTypesMap, CWnd* pParent)
	: m_oPerson(oPerson), m_oCitiesMap(oCitiesMap), m_oPhoneTypesMap(oPhoneTypesMap), CDialog(IDD_PERSONS_DIALOG, pParent)
{
	
}

CPersonsDlg::~CPersonsDlg()
{
}

// Methods
// ----------------
void CPersonsDlg::BuildListCtrl()
{
	m_lscPhoneNumbers.ModifyStyle(0, LVS_REPORT);
	m_lscPhoneNumbers.ModifyStyle(0, LVS_SINGLESEL);
	m_lscPhoneNumbers.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	m_lscPhoneNumbers.InsertColumn(PhoneNumbersColumnType, _strPhoneNumbersTypeColumnCaption, LVCFMT_CENTER, _nPhoneNumbersTypeColumnWidth);
	m_lscPhoneNumbers.InsertColumn(PhoneNumbersColumnNumber, _strPhoneNumbersNumberColumnCaption, LVCFMT_CENTER, _nPhoneNumbersNumberColumnWidth);
}

void CPersonsDlg::FillListCtrl()
{
	const CPhoneNumbersArray& oPhoneNumbersArray = m_oPerson.oPhoneNumbersArray;
	for (int i = 0; i < oPhoneNumbersArray.GetCount(); i++)
	{
		const PHONE_NUMBERS* pPhoneNumber = oPhoneNumbersArray.GetAt(i);
		if (pPhoneNumber == NULL)
			continue;

		CString strType = FindPhoneType(pPhoneNumber->lPhoneTypeID);

		if (strType.IsEmpty())
			continue;

		PHONE_NUMBERS_VIEW_DATA recPhoneNumberViewData;
		recPhoneNumberViewData.recPhoneNumber = *pPhoneNumber;
		recPhoneNumberViewData.strType = strType;

		InsertItem(recPhoneNumberViewData);
	}	
}

void CPersonsDlg::EditRecord()
{
	PHONE_NUMBERS_VIEW_DATA recPhoneNumberViewData;
	if (!InitFilledDialog(recPhoneNumberViewData, false))
		return;

	int nItemIndex = FindSelectedItem();
	if (nItemIndex == CB_ERR)
		return;

	UpdateItem(nItemIndex, recPhoneNumberViewData);

	int nPhoneNumberIndex = FindPhoneNumberIndex(m_lscPhoneNumbers.GetItemData(nItemIndex));
	if (nPhoneNumberIndex == CB_ERR)
		return;

	m_oPerson.oPhoneNumbersArray.Delete(nPhoneNumberIndex);
	m_oPerson.oPhoneNumbersArray.Insert(recPhoneNumberViewData.recPhoneNumber);
}

void CPersonsDlg::InsertRecord()
{
	PHONE_NUMBERS_VIEW_DATA recPhoneNumberViewData;
	recPhoneNumberViewData.recPhoneNumber.lPersonID = m_oPerson.recPerson.lID;

	if (!InitDialog(recPhoneNumberViewData, false))
		return;

	InsertItem(recPhoneNumberViewData);
	m_oPerson.oPhoneNumbersArray.Insert(recPhoneNumberViewData.recPhoneNumber);
}

void CPersonsDlg::DeleteRecord()
{
	if (AfxMessageBox(_T("Are you sure you want to delete this record?"), MB_YESNO) == IDNO)
		return;

	int nItemIndex = FindSelectedItem();
	if (nItemIndex == CB_ERR)
		return;

	int nPhoneNumberIndex = FindPhoneNumberIndex(m_lscPhoneNumbers.GetItemData(nItemIndex));
	if (nPhoneNumberIndex == CB_ERR)
		return;

	m_lscPhoneNumbers.DeleteItem(nItemIndex);
	m_oPerson.oPhoneNumbersArray.Delete(nPhoneNumberIndex);
}

void CPersonsDlg::ReadRecord()
{
	PHONE_NUMBERS_VIEW_DATA recPhoneNumberViewData;
	if (!InitFilledDialog(recPhoneNumberViewData, true))
		return;
}

void CPersonsDlg::UpdateItem(int nIndex, const PHONE_NUMBERS_VIEW_DATA& recPhoneNumberViewData)
{
	m_lscPhoneNumbers.SetItemText(nIndex, PhoneNumbersColumnNumber, recPhoneNumberViewData.recPhoneNumber.szPhoneNumber);
	m_lscPhoneNumbers.SetItemText(nIndex, PhoneNumbersColumnType, recPhoneNumberViewData.strType);
	m_lscPhoneNumbers.SetItemData(nIndex, recPhoneNumberViewData.recPhoneNumber.lID);
}

void CPersonsDlg::InsertItem(const PHONE_NUMBERS_VIEW_DATA& recPhoneNumberViewData)
{
	const PHONE_NUMBERS& recPhoneNumber = recPhoneNumberViewData.recPhoneNumber;
	int nIndex = m_lscPhoneNumbers.InsertItem(PhoneNumbersColumnNumber, recPhoneNumber.szPhoneNumber);
	UpdateItem(nIndex, recPhoneNumberViewData);
}

BOOL CPersonsDlg::InitDialog(PHONE_NUMBERS_VIEW_DATA& recPhoneNumberViewData, bool bReadOnly)
{
	if (bReadOnly)
	{
		CPhoneNumbersReadOnlyDlg oPhoneNumbersReadOnlyDlg(recPhoneNumberViewData, m_oPhoneTypesMap);
		if (oPhoneNumbersReadOnlyDlg.DoModal() != IDOK)
			return FALSE;
	}
	else
	{
		CPhoneNumbersDlg oPhoneNumbersDlg(recPhoneNumberViewData, m_oPhoneTypesMap);
		if (oPhoneNumbersDlg.DoModal() != IDOK)
			return FALSE;
	}

	return TRUE;
}

BOOL CPersonsDlg::LoadItem(int nIndex, PHONE_NUMBERS_VIEW_DATA& recPhoneNumberViewData)
{
	if (nIndex == CB_ERR)
		return FALSE;

	CString strType = m_lscPhoneNumbers.GetItemText(nIndex, PhoneNumbersColumnType);
	long lID = m_lscPhoneNumbers.GetItemData(nIndex);

	int nPhoneNumberIndex = FindPhoneNumberIndex(lID);
	if (nPhoneNumberIndex == CB_ERR)
		return FALSE;

	const PHONE_NUMBERS* pPhoneNumber = m_oPerson.oPhoneNumbersArray.GetAt(nPhoneNumberIndex);
	if (pPhoneNumber == NULL)
		return FALSE;

	recPhoneNumberViewData.recPhoneNumber = *pPhoneNumber;
	recPhoneNumberViewData.strType = strType;
	
	return TRUE;
}

BOOL CPersonsDlg::LoadSelectedItem(PHONE_NUMBERS_VIEW_DATA& recPhoneNumberViewData)
{	
	int nIndex = FindSelectedItem();
	if (nIndex == CB_ERR)
		return FALSE;

	if (!LoadItem(nIndex, recPhoneNumberViewData))
		return FALSE;

	return TRUE;
}

BOOL CPersonsDlg::InitFilledDialog(PHONE_NUMBERS_VIEW_DATA& recPhoneNumberViewData, bool bReadOnly)
{
	if (!LoadSelectedItem(recPhoneNumberViewData))
		return FALSE;

	if (!InitDialog(recPhoneNumberViewData, bReadOnly))
		return FALSE;

	return TRUE;
}

const int CPersonsDlg::FindSelectedItem()
{
	POSITION oPosition = m_lscPhoneNumbers.GetFirstSelectedItemPosition();
	int nSelected = -1;

	if (oPosition == NULL)
		return nSelected;

	while (oPosition)
	{
		nSelected = m_lscPhoneNumbers.GetNextSelectedItem(oPosition);
	}

	return nSelected;
}

const CString CPersonsDlg::FindPhoneType(const long lID)
{
	CString strType;
	PHONE_TYPES* pPhoneType = NULL;

	if (m_oPhoneTypesMap.Lookup(lID, pPhoneType))
		strType = pPhoneType->szType;

	return strType;
}

const int CPersonsDlg::FindPhoneNumberIndex(const long lID)
{
	int nIndex = -1;
	for (int i = 0; i < m_oPerson.oPhoneNumbersArray.GetCount(); i++)
	{
		const PHONE_NUMBERS* pPhoneNumber = m_oPerson.oPhoneNumbersArray.GetAt(i);

		if (pPhoneNumber == NULL)
			continue;

		if (pPhoneNumber->lID != lID)
			continue;

		nIndex = i;
		break;
	}
	return nIndex;
}

void CPersonsDlg::OnBtnPopupEdit()
{
	EditRecord();
}

void CPersonsDlg::OnBtnPopupDelete()
{
	DeleteRecord();
}

void CPersonsDlg::OnBtnPopupInsert()
{
	InsertRecord();
}

void CPersonsDlg::OnUpdateBtnPopup(CCmdUI* pCmdUI)
{
	int nIndex = FindSelectedItem();
	int nButtonID = pCmdUI->m_nID;

	if (nButtonID == IDC_BTN_POPUP_DELETE && nIndex != CB_ERR)
		return;

	if (nButtonID == IDC_BTN_POPUP_EDIT && nIndex != CB_ERR)
		return;

	if (nButtonID == IDC_BTN_POPUP_INSERT && nIndex == CB_ERR)
		return;

	pCmdUI->Enable(FALSE);
}

void CPersonsDlg::OnItemActivatePhoneNumbers(NMHDR* pNMHDR, LRESULT* pResult)
{
	ReadRecord();
}

void CPersonsDlg::SetTextLimits()
{
	m_edbFirstName.SetLimitText(PERSONS_FIRST_NAME_LENGTH);
	m_edbMiddleName.SetLimitText(PERSONS_MIDDLE_NAME_LENGTH);
	m_edbLastName.SetLimitText(PERSONS_LAST_NAME_LENGTH);
	m_edbUCN.SetLimitText(PERSONS_UCN_LENGTH);
	m_edbAddress.SetLimitText(PERSONS_ADDRESS_LENGTH);
}

void CPersonsDlg::FillEditBoxes()
{
	m_edbFirstName.SetWindowText(m_oPerson.recPerson.szFirstName);
	m_edbMiddleName.SetWindowText(m_oPerson.recPerson.szMiddleName);
	m_edbLastName.SetWindowText(m_oPerson.recPerson.szLastName);
	m_edbUCN.SetWindowText(m_oPerson.recPerson.szUCN);
	m_edbAddress.SetWindowText(m_oPerson.recPerson.szAddress);
}

void CPersonsDlg::FillCities()
{
	for (POSITION oPosition = m_oCitiesMap.GetStartPosition(); oPosition != NULL;)
	{
		long lID = 0;
		CITIES* pCity = NULL;
		m_oCitiesMap.GetNextAssoc(oPosition, lID, pCity);

		if (lID <= CB_OKAY)
			continue;

		if (pCity == NULL)
			continue;

		int nIndex = m_cmbCity.AddString(pCity->szName);
		m_cmbCity.SetItemData(nIndex, lID);

		if (lID != m_oPerson.recPerson.lCityID)
			continue;

		m_cmbCity.SetCurSel(nIndex);
	}
}

CString CPersonsDlg::ValidateEditBox(const CEdit& edbCtrl, const CString& strFieldName, const CValidator::EdbTypes eEdbTypes)
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

CString CPersonsDlg::ValidateComboBox(const CComboBox& cmbCtrl, const CString& strFieldName)
{
	CString strMessage;

	if (cmbCtrl.GetCurSel() == CB_ERR) 
	{
		GotoDlgCtrl(GetDlgItem(cmbCtrl.GetDlgCtrlID()));
		strMessage.AppendFormat(_T("\nNo value for '%s' is chosen."), strFieldName.Left(strFieldName.GetLength()-1));
	}
		
	return strMessage;
}

BOOL CPersonsDlg::ValidateData()
{
	CString strFirstNameLabel, strMiddleNameLabel, strLastNameLabel, strUCNLabel, strAddressLabel, stCityLabel;

	GetDlgItem(IDC_STT_PERSONS_FIRST_NAME)->GetWindowText(strFirstNameLabel);
	GetDlgItem(IDC_STT_PERSONS_MIDDLE_NAME)->GetWindowText(strMiddleNameLabel);
	GetDlgItem(IDC_STT_PERSONS_LAST_NAME)->GetWindowText(strLastNameLabel);
	GetDlgItem(IDC_STT_PERSONS_UCN)->GetWindowText(strUCNLabel);
	GetDlgItem(IDC_STT_PERSONS_ADDRESS)->GetWindowText(strAddressLabel);
	GetDlgItem(IDC_STT_PERSONS_CITY)->GetWindowText(stCityLabel);

	CString strMessage;
	strMessage.Append(ValidateEditBox(m_edbFirstName, strFirstNameLabel, CValidator::EdbTypeNames));
	strMessage.Append(ValidateEditBox(m_edbMiddleName, strMiddleNameLabel, CValidator::EdbTypeNames));
	strMessage.Append(ValidateEditBox(m_edbLastName, strLastNameLabel, CValidator::EdbTypeNames));
	strMessage.Append(ValidateEditBox(m_edbUCN, strUCNLabel, CValidator::EdbTypeUCN));
	strMessage.Append(ValidateComboBox(m_cmbCity, stCityLabel));
	strMessage.Append(ValidateEditBox(m_edbAddress, strAddressLabel, CValidator::EdbTypeAddress));

	if (!strMessage.IsEmpty())
	{
		AfxMessageBox(strMessage);
		return FALSE;
	}

	return TRUE;
}

void CPersonsDlg::TransferDataToRecord()
{
	CString strFirstName, strMiddleName, strLastName, strUCN, strAddress;
	m_edbFirstName.GetWindowText(strFirstName);
	m_edbMiddleName.GetWindowText(strMiddleName);
	m_edbLastName.GetWindowText(strLastName);
	m_edbUCN.GetWindowText(strUCN);
	m_edbAddress.GetWindowText(strAddress);

	PERSONS& recPerson = m_oPerson.recPerson;
	_tcscpy_s(recPerson.szFirstName, strFirstName.Trim());
	_tcscpy_s(recPerson.szMiddleName, strMiddleName.Trim());
	_tcscpy_s(recPerson.szLastName, strLastName.Trim());
	_tcscpy_s(recPerson.szUCN, strUCN.Trim());
	recPerson.lCityID = m_cmbCity.GetItemData(m_cmbCity.GetCurSel());
	_tcscpy_s(recPerson.szAddress, strAddress.Trim());
}

// Overrides
// ----------------
void CPersonsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDB_PERSONS_FIRST_NAME, m_edbFirstName);
	DDX_Control(pDX, IDC_EDB_PERSONS_MIDDLE_NAME, m_edbMiddleName);
	DDX_Control(pDX, IDC_EDB_PERSONS_LAST_NAME, m_edbLastName);
	DDX_Control(pDX, IDC_EDB_PERSONS_UCN, m_edbUCN);
	DDX_Control(pDX, IDC_CMB_PERSONS_CITY, m_cmbCity);
	DDX_Control(pDX, IDC_EDB_PERSONS_ADDRESS, m_edbAddress);
	DDX_Control(pDX, IDC_LSC_PERSONS_PHONE_NUMBERS, m_lscPhoneNumbers);
}

BOOL CPersonsDlg::OnInitDialog()
{
	if (!CDialog::OnInitDialog())
		return FALSE;

	BuildListCtrl();
	FillListCtrl();

	SetTextLimits();
	FillEditBoxes();
	FillCities();

	return TRUE;  
}

void CPersonsDlg::OnOK()
{
	if (!ValidateData())
		return;

	TransferDataToRecord();

	CDialog::OnOK();
}

void CPersonsDlg::OnInitMenuPopup(CMenu* pPopupMenu, UINT nIndex, BOOL bSysMenu)
{
	if (pPopupMenu && !bSysMenu)
	{
		CCmdUI oCmdUI;
		oCmdUI.m_pMenu = pPopupMenu;
		oCmdUI.m_nIndexMax = pPopupMenu->GetMenuItemCount();
		for (UINT i = 0; i < oCmdUI.m_nIndexMax; i++)
		{
			oCmdUI.m_nIndex = i;
			oCmdUI.m_nID = pPopupMenu->GetMenuItemID(i);
			oCmdUI.DoUpdate(this, FALSE);
		}
	}
}

void CPersonsDlg::OnNMRClickPhoneNumbers(NMHDR* pNMHDR, LRESULT* pResult)
{
	CMenu oContextMenu;
	if (!oContextMenu.LoadMenu(IDR_POPUP_EDIT))
		return;

	CMenu* pSubMenu = oContextMenu.GetSubMenu(_nSubmenuIndex);
	if (!pSubMenu)
		return;

	CPoint oPoint;
	if (!GetCursorPos(&oPoint))
		return;

	pSubMenu->TrackPopupMenu(TPM_LEFTALIGN, oPoint.x, oPoint.y, this);
}
