#include "stdafx.h"
#include "CitiesReadOnlyDlg.h"

// Constructor / Destructor
// ----------------
CCitiesReadOnlyDlg::CCitiesReadOnlyDlg(CITIES& recCity) : CCitiesDlg(recCity)
{
}

CCitiesReadOnlyDlg::~CCitiesReadOnlyDlg()
{
}

// Methods
// ----------------

// Overrides
// ----------------
BOOL CCitiesReadOnlyDlg::OnInitDialog()
{
	if (!CCitiesDlg::OnInitDialog())
		return FALSE;

	m_edbName.EnableWindow(FALSE);
	m_edbRegion.EnableWindow(FALSE);

	return TRUE;
}

void CCitiesReadOnlyDlg::OnOK()
{
	CDialog::OnOK();
}