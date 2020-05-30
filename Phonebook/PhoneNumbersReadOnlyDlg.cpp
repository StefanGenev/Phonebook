#include "stdafx.h"
#include "PhoneNumbersReadOnlyDlg.h"

// Constructor / Destructor
// ----------------
CPhoneNumbersReadOnlyDlg::CPhoneNumbersReadOnlyDlg(PHONE_NUMBERS_VIEW_DATA& recPhoneNumberViewData, const CPhoneTypesMap& oPhoneTypesMap)
	: CPhoneNumbersDlg(recPhoneNumberViewData, oPhoneTypesMap)
{
}

CPhoneNumbersReadOnlyDlg::~CPhoneNumbersReadOnlyDlg()
{
}

// Methods
// ----------------

// Overrides
// ----------------
BOOL CPhoneNumbersReadOnlyDlg::OnInitDialog()
{
	if (!CPhoneNumbersDlg::OnInitDialog())
		return FALSE;

	m_edbNumber.EnableWindow(FALSE);
	m_cmbType.EnableWindow(FALSE);

	return TRUE;
}

void CPhoneNumbersReadOnlyDlg::OnOK()
{
	CDialog::OnOK();
}

void CPhoneNumbersReadOnlyDlg::FillPhoneTypes()
{
	PHONE_TYPES* pPhoneType = NULL;
	if (!m_oPhoneTypesMap.Lookup(recPhoneNumberViewData.recPhoneNumber.lPhoneTypeID, pPhoneType))
		return;

	if (pPhoneType == NULL)
		return;

	int nIndex = m_cmbType.AddString(pPhoneType->szType);
	m_cmbType.SetCurSel(nIndex);
}
