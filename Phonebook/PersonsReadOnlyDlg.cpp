#include "stdafx.h"
#include "PersonsReadOnlyDlg.h"

// Constructor / Destructor
// ----------------
CPersonsReadOnlyDlg::CPersonsReadOnlyDlg(CPerson& oPerson, const CCitiesMap& oCitiesMap, const CPhoneTypesMap& oPhoneTypesMap) 
	: CPersonsDlg(oPerson, oCitiesMap, oPhoneTypesMap)
{
}

CPersonsReadOnlyDlg::~CPersonsReadOnlyDlg()
{
}

// Methods
// ----------------


// Overrides
// ----------------
BOOL CPersonsReadOnlyDlg::OnInitDialog()
{
	if (!CPersonsDlg::OnInitDialog())
		return FALSE;

	m_edbFirstName.EnableWindow(FALSE);
	m_edbMiddleName.EnableWindow(FALSE);
	m_edbLastName.EnableWindow(FALSE);
	m_cmbCity.EnableWindow(FALSE);
	m_edbUCN.EnableWindow(FALSE);
	m_edbAddress.EnableWindow(FALSE);
	
	return TRUE;
}

void CPersonsReadOnlyDlg::OnOK()
{
	CDialog::OnOK();
}

void CPersonsReadOnlyDlg::OnUpdateBtnPopup(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(FALSE);
}

void CPersonsReadOnlyDlg::FillCities()
{
	CITIES* pCity = NULL;
	if (!m_oCitiesMap.Lookup(m_oPerson.recPerson.lCityID, pCity))
		return;

	if (pCity == NULL)
		return;

	int nIndex = m_cmbCity.AddString(pCity->szName);
	m_cmbCity.SetCurSel(nIndex);
}
