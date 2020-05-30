#include "stdafx.h"
#include "PhoneTypesReadOnlyDlg.h"

// Constructor / Destructor
// ----------------
CPhoneTypesReadOnlyDlg::CPhoneTypesReadOnlyDlg(PHONE_TYPES& recPhoneType) : CPhoneTypesDlg(recPhoneType)
{
}

CPhoneTypesReadOnlyDlg::~CPhoneTypesReadOnlyDlg()
{
}

// Methods
// ----------------

// Overrides
// ----------------
BOOL CPhoneTypesReadOnlyDlg::OnInitDialog()
{
	if (!CPhoneTypesDlg::OnInitDialog())
		return FALSE;

	m_edbType.EnableWindow(FALSE);

	return TRUE;
}

void CPhoneTypesReadOnlyDlg::OnOK()
{
	CDialog::OnOK();
}