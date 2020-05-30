
#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Phonebook.h"
#endif

#include "PersonsDocument.h"
#include "PersonsView.h"
#include "PersonsDlg.h"
#include "PersonsUpdateObject.h"
#include "PersonsReadOnlyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



IMPLEMENT_DYNCREATE(CPersonsView, CListView)

BEGIN_MESSAGE_MAP(CPersonsView, CListView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_NOTIFY_REFLECT(LVN_ITEMACTIVATE, &CPersonsView::OnItemActivate)
	ON_COMMAND(IDC_BTN_POPUP_EDIT, &CPersonsView::OnBtnPopupEdit)
	ON_COMMAND(IDC_BTN_POPUP_DELETE, &CPersonsView::OnBtnPopupDelete)
	ON_COMMAND(IDC_BTN_POPUP_INSERT, &CPersonsView::OnBtnPopupInsert)
	ON_UPDATE_COMMAND_UI(IDC_BTN_POPUP_EDIT, &CPersonsView::OnUpdateBtnPopup)
	ON_UPDATE_COMMAND_UI(IDC_BTN_POPUP_DELETE, &CPersonsView::OnUpdateBtnPopup)
	ON_UPDATE_COMMAND_UI(IDC_BTN_POPUP_INSERT, &CPersonsView::OnUpdateBtnPopup)
END_MESSAGE_MAP()

// Constants
// ----------------

const CString CPersonsView::_strFirstNameColumnCaption = _T("First Name");
const CString CPersonsView::_strMiddleNameColumnCaption = _T("Middle Name");
const CString CPersonsView::_strLastNameColumnCaption = _T("Last Name");
const CString CPersonsView::_strUCNColumnCaption = _T("UCN");
const CString CPersonsView::_strCityColumnCaption = _T("City");
const CString CPersonsView::_strAddressColumnCaption = _T("Address");

const int CPersonsView::_nFirstNameColumnWidth = 120;
const int CPersonsView::_nMiddleNameColumnWidth = 120;
const int CPersonsView::_nLastNameColumnWidth = 120;
const int CPersonsView::_nUCNColumnWidth = 100;
const int CPersonsView::_nCityColumnWidth = 150;
const int CPersonsView::_nAddressColumnWidth = 150;

// Constructor / Destructor
// ----------------
CPersonsView::CPersonsView()
{

}

CPersonsView::~CPersonsView()
{

}

// Methods
// ----------------
void CPersonsView::BuildListCtrl()
{
	CListCtrl& oListCtrl = GetListCtrl();
	oListCtrl.ModifyStyle(0, LVS_REPORT);
	oListCtrl.ModifyStyle(0, LVS_SINGLESEL);
	oListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	oListCtrl.InsertColumn(ColumnFirstName, _strFirstNameColumnCaption, LVCFMT_CENTER, _nFirstNameColumnWidth);
	oListCtrl.InsertColumn(ColumnMiddleName, _strMiddleNameColumnCaption, LVCFMT_CENTER, _nMiddleNameColumnWidth);
	oListCtrl.InsertColumn(ColumnLastName, _strLastNameColumnCaption, LVCFMT_CENTER, _nLastNameColumnWidth);
	oListCtrl.InsertColumn(ColumnUCN, _strUCNColumnCaption, LVCFMT_CENTER, _nUCNColumnWidth);
	oListCtrl.InsertColumn(ColumnCity, _strCityColumnCaption, LVCFMT_CENTER, _nCityColumnWidth);
	oListCtrl.InsertColumn(ColumnAddress, _strAddressColumnCaption, LVCFMT_CENTER, _nAddressColumnWidth);
}

void CPersonsView::FillListCtrl()
{
	const CPersonsViewDataArray& oPersonsViewDataArray = GetDocument().GetAllPersons();

	for (int i = 0; i < oPersonsViewDataArray.GetCount(); i++)
	{
		const PERSONS_VIEW_DATA* pPersonViewData = oPersonsViewDataArray.GetAt(i);
		if (pPersonViewData == NULL)
			continue;

		InsertItem(*pPersonViewData);
	}
}

void CPersonsView::EditRecord()
{
	CPerson oPerson;
	if (!InitFilledDialog(oPerson, false))
		return;

	if (!GetDocument().Update(oPerson.recPerson.lID, oPerson))
		return;

	AfxMessageBox(_T("Successfully updated person."));
}

void CPersonsView::InsertRecord()
{
	CPerson oPerson;
	if (!InitDialog(oPerson, false))
		return;

	if (!GetDocument().Insert(oPerson))
		return;

	AfxMessageBox(_T("Successfully inserted person."));
}

void CPersonsView::DeleteRecord()
{
	if (AfxMessageBox(_T("Are you sure you want to delete this record?"), MB_YESNO) == IDNO)
		return;

	long lID = GetListCtrl().GetItemData(FindSelectedItem());

	if (!GetDocument().Delete(lID))
		return;

	AfxMessageBox(_T("Person has been successfully deleted."));
}

void CPersonsView::ReadRecord()
{
	CPerson oPerson;
	if (!InitFilledDialog(oPerson, true))
		return;
}

const int CPersonsView::FindSelectedItem()
{
	CListCtrl& oListCtrl = GetListCtrl();
	POSITION oPosition = oListCtrl.GetFirstSelectedItemPosition();
	int nSelected = -1;

	if (oPosition == NULL)
		return nSelected;

	while (oPosition)
	{
		nSelected = oListCtrl.GetNextSelectedItem(oPosition);
	}

	return nSelected;
}

const int CPersonsView::FindItemByData(const long lItemData)
{
	CListCtrl& oListCtrl = GetListCtrl();
	int nIndex = -1;

	for (int i = 0; i < oListCtrl.GetItemCount(); i++)
	{
		if (oListCtrl.GetItemData(i) != lItemData)
			continue;

		nIndex = i;
		break;
	}

	return nIndex;
}

BOOL CPersonsView::InitDialog(CPerson& oPerson, bool bReadOnly)
{
	CPersonsDocument& oPersonsDocument = GetDocument();
	const CCitiesMap& oCitiesMap = oPersonsDocument.GetAllCities();
	const CPhoneTypesMap& oPhoneTypesMap = oPersonsDocument.GetAllPhoneTypes();

	if (bReadOnly)
	{
		CPersonsReadOnlyDlg oPersonsReadOnlyDlg(oPerson, oCitiesMap, oPhoneTypesMap);
		if (oPersonsReadOnlyDlg.DoModal() != IDOK)
			return FALSE;
	}
	else
	{
		CPersonsDlg oPersonsDlg(oPerson, oCitiesMap, oPhoneTypesMap);
		if (oPersonsDlg.DoModal() != IDOK)
			return FALSE;
	}

	return TRUE;
}

BOOL CPersonsView::LoadSelectedRecord(CPerson& oPerson)
{
	long lID = GetListCtrl().GetItemData(FindSelectedItem());

	if (!GetDocument().LoadPerson(lID, oPerson))
		return FALSE;

	return TRUE;
}

BOOL CPersonsView::InitFilledDialog(CPerson& oPerson, bool bReadOnly)
{
	if (!LoadSelectedRecord(oPerson))
		return FALSE;

	if (!InitDialog(oPerson, bReadOnly))
		return FALSE;

	return TRUE;
}

void CPersonsView::UpdateItem(int nIndex, const PERSONS_VIEW_DATA& recPersonViewData)
{
	const PERSONS& recPerson = recPersonViewData.recPerson;
	CListCtrl& oListCtrl = GetListCtrl();

	oListCtrl.SetItemText(nIndex, ColumnFirstName, recPerson.szFirstName);
	oListCtrl.SetItemText(nIndex, ColumnMiddleName, recPerson.szMiddleName);
	oListCtrl.SetItemText(nIndex, ColumnLastName, recPerson.szLastName);
	oListCtrl.SetItemText(nIndex, ColumnUCN, recPerson.szUCN);
	oListCtrl.SetItemText(nIndex, ColumnCity, recPersonViewData.strCity);
	oListCtrl.SetItemText(nIndex, ColumnAddress, recPerson.szAddress);
	oListCtrl.SetItemData(nIndex, recPerson.lID);
}

void CPersonsView::InsertItem(const PERSONS_VIEW_DATA& recPersonVisual)
{
	int nIndex = GetListCtrl().InsertItem(ColumnFirstName, recPersonVisual.recPerson.szFirstName);
	UpdateItem(nIndex, recPersonVisual);
}

void CPersonsView::OnBtnPopupEdit()
{
	EditRecord();
}

void CPersonsView::OnBtnPopupDelete()
{
	DeleteRecord();
}

void CPersonsView::OnBtnPopupInsert()
{
	InsertRecord();
}

void CPersonsView::OnUpdateBtnPopup(CCmdUI* pCmdUI)
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

void CPersonsView::OnItemActivate(NMHDR* pNMHDR, LRESULT* pResult)
{
	if (FindSelectedItem() == CB_ERR)
		return;

	ReadRecord();
}

// Overrides
// ----------------

CPersonsDocument& CPersonsView::GetDocument() const
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPersonsDocument)));
	return *(CPersonsDocument*)m_pDocument;
}

void CPersonsView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	if (!pHint)
		return;

	CPersonsUpdateObject& oPersonsUpdateObject = *(CPersonsUpdateObject*)pHint;

	const PERSONS_VIEW_DATA& recPersonViewData = oPersonsUpdateObject.GetData();
	RecordOperationTypes eRecordOperationTypes = oPersonsUpdateObject.GetOperationType();
	const int nIndex = FindItemByData(recPersonViewData.recPerson.lID);

	if (nIndex == CB_ERR && eRecordOperationTypes != RecordOperationTypeInsert)
		return;

	switch (eRecordOperationTypes)
	{
	case RecordOperationTypeUpdate:
		UpdateItem(nIndex, recPersonViewData);
		break;
	case RecordOperationTypeInsert:
		InsertItem(recPersonViewData);
		break;
	case RecordOperationTypeDelete:
		GetListCtrl().DeleteItem(nIndex);
		break;
	default:
		break;
	}
}

void CPersonsView::OnInitialUpdate()
{
	BuildListCtrl();
	FillListCtrl();
}

void CPersonsView::OnContextMenu(CWnd* pWnd, CPoint oPoint)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, oPoint.x, oPoint.y, this, TRUE);
#endif
	
}





