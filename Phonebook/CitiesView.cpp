
// CitiesView.cpp : implementation of the CCitiesView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Phonebook.h"
#endif

#include "CitiesDocument.h"
#include "CitiesView.h"
#include "CitiesDlg.h"
#include "CitiesReadOnlyDlg.h"
#include "CitiesUpdateObject.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif




IMPLEMENT_DYNCREATE(CCitiesView, CListView)

BEGIN_MESSAGE_MAP(CCitiesView, CListView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_NOTIFY_REFLECT(LVN_ITEMACTIVATE, &CCitiesView::OnItemActivate)
	ON_COMMAND(IDC_BTN_POPUP_EDIT, &CCitiesView::OnBtnPopupEdit)
	ON_COMMAND(IDC_BTN_POPUP_DELETE, &CCitiesView::OnBtnPopupDelete)
	ON_COMMAND(IDC_BTN_POPUP_INSERT, &CCitiesView::OnBtnPopupInsert)
	ON_UPDATE_COMMAND_UI(IDC_BTN_POPUP_EDIT, &CCitiesView::OnUpdateBtnPopup)
	ON_UPDATE_COMMAND_UI(IDC_BTN_POPUP_DELETE, &CCitiesView::OnUpdateBtnPopup)
	ON_UPDATE_COMMAND_UI(IDC_BTN_POPUP_INSERT, &CCitiesView::OnUpdateBtnPopup)
END_MESSAGE_MAP()

// Constants
// ----------------

const CString CCitiesView::_strNameColumnCaption = _T("Name");
const CString CCitiesView::_strRegionColumnCaption = _T("Region");
const int CCitiesView::_nNameColumnWidth = 150;
const int CCitiesView::_nRegionColumnWidth = 150;

// Constructor / Destructor
// ----------------
CCitiesView::CCitiesView()
{

}

CCitiesView::~CCitiesView()
{

}

// Methods
// ----------------
void CCitiesView::BuildListCtrl()
{
	CListCtrl& oListCtrl = GetListCtrl();
	oListCtrl.ModifyStyle(0, LVS_REPORT);
	oListCtrl.ModifyStyle(0, LVS_SINGLESEL);
	oListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	oListCtrl.InsertColumn(ColumnName, _strNameColumnCaption, LVCFMT_CENTER, _nNameColumnWidth);
	oListCtrl.InsertColumn(ColumnRegion, _strRegionColumnCaption, LVCFMT_CENTER, _nRegionColumnWidth);
}

void CCitiesView::FillListCtrl()
{
	const CCitiesArray& oCitiesArray = GetDocument().GetAllCities();

	for (int i = 0; i < oCitiesArray.GetCount(); i++)
	{
		const CITIES* pCity = oCitiesArray.GetAt(i);
		if (pCity == NULL)
			continue;

		InsertItem(*pCity);
	}
}

void CCitiesView::EditRecord()
{
	CITIES recCity;
	if (!InitFilledDialog(recCity, false))
		return;

	if (!GetDocument().Update(recCity.lID, recCity))
		return;

	AfxMessageBox(_T("Successfully updated city."));
}

void CCitiesView::InsertRecord()
{
	CITIES recCity;
	if (!InitDialog(recCity, false))
		return;

	if (!GetDocument().Insert(recCity))
		return;

	AfxMessageBox(_T("Successfully inserted city."));
}

void CCitiesView::DeleteRecord()
{
	if (AfxMessageBox(_T("Are you sure you want to delete this record?"), MB_YESNO) == IDNO)
		return;

	int nIndex = FindSelectedItem();
	if (nIndex == CB_ERR)
		return;

	long lID = GetListCtrl().GetItemData(nIndex);

	if (!GetDocument().Delete(lID))
		return;

	AfxMessageBox(_T("City has been successfully deleted."));
}

void CCitiesView::ReadRecord()
{
	CITIES recCity;
	if (!InitFilledDialog(recCity, true))
		return;
}

const int CCitiesView::FindSelectedItem()
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

const int CCitiesView::FindItemByData(const long lItemData)
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

BOOL CCitiesView::InitDialog(CITIES& recCity, bool bReadOnly)
{	
	if (bReadOnly)
	{
		CCitiesReadOnlyDlg oCitiesReadOnlyDlg(recCity);
		if (oCitiesReadOnlyDlg.DoModal() != IDOK)
			return FALSE;
	}
	else
	{
		CCitiesDlg oCitiesDlg(recCity);
		if (oCitiesDlg.DoModal() != IDOK)
			return FALSE;
	}	
		
	return TRUE;
}

BOOL CCitiesView::LoadSelectedRecord(CITIES& recCity)
{
	int nIndex = FindSelectedItem();
	if (nIndex == CB_ERR)
		return FALSE;

	long lID = GetListCtrl().GetItemData(nIndex);

	if (!GetDocument().LoadCity(lID, recCity))
		return FALSE;

	return TRUE;
}

BOOL CCitiesView::InitFilledDialog(CITIES& recCity, bool bReadOnly)
{
	if (!LoadSelectedRecord(recCity))
		return FALSE;

	if (!InitDialog(recCity, bReadOnly))
		return FALSE;

	return TRUE;
}

void CCitiesView::UpdateItem(int nIndex, const CITIES& recCity)
{
	CListCtrl& oListCtrl = GetListCtrl();
	oListCtrl.SetItemText(nIndex, ColumnName, recCity.szName);
	oListCtrl.SetItemText(nIndex, ColumnRegion, recCity.szRegion);
	oListCtrl.SetItemData(nIndex, recCity.lID);
}

void CCitiesView::InsertItem(const CITIES& recCity)
{
	int nIndex = GetListCtrl().InsertItem(ColumnName, recCity.szName);
	UpdateItem(nIndex, recCity);
}

void CCitiesView::OnBtnPopupEdit()
{
	EditRecord();
}

void CCitiesView::OnBtnPopupDelete()
{
	DeleteRecord();
}

void CCitiesView::OnBtnPopupInsert()
{
	InsertRecord();
}

void CCitiesView::OnUpdateBtnPopup(CCmdUI* pCmdUI)
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

void CCitiesView::OnItemActivate(NMHDR* pNMHDR, LRESULT* pResult)
{
	ReadRecord();
}

// Overrides
// ----------------

CCitiesDocument& CCitiesView::GetDocument() const 
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCitiesDocument)));
	return *(CCitiesDocument*)m_pDocument;
}

void CCitiesView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	if (!pHint)
		return;

	CCitiesUpdateObject& oCitiesUpdateObject = *(CCitiesUpdateObject*) pHint;
	const CITIES& recCity = oCitiesUpdateObject.GetData();
	const int nIndex = FindItemByData(recCity.lID);
	RecordOperationTypes eRecordOperationTypes = oCitiesUpdateObject.GetOperationType();

	if (nIndex == CB_ERR && eRecordOperationTypes != RecordOperationTypeInsert)
		return;

	switch (eRecordOperationTypes)
	{
	case RecordOperationTypeUpdate:
		UpdateItem(nIndex, recCity);
		break;
	case RecordOperationTypeInsert:
		InsertItem(recCity);
		break;
	case RecordOperationTypeDelete:
		GetListCtrl().DeleteItem(nIndex);
		break;
	default:
		break;
	}
}

void CCitiesView::OnInitialUpdate()
{	
	BuildListCtrl();	
	FillListCtrl();	
}

void CCitiesView::OnContextMenu(CWnd* pWnd , CPoint oPoint)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, oPoint.x, oPoint.y, this, TRUE);
#endif
}





