#include "stdafx.h"
#include "PhoneTypesView.h"
#include "Phonebook.h"
#include "PhoneTypesDlg.h"
#include "PhoneTypesReadOnlyDlg.h"
#include "PhoneTypesUpdateObject.h"
#include "RecordOperationTypes.h"


IMPLEMENT_DYNCREATE(CPhoneTypesView, CListView)

BEGIN_MESSAGE_MAP(CPhoneTypesView, CListView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_NOTIFY_REFLECT(LVN_ITEMACTIVATE, &CPhoneTypesView::OnItemActivate)
	ON_COMMAND(IDC_BTN_POPUP_EDIT, &CPhoneTypesView::OnBtnPopupEdit)
	ON_COMMAND(IDC_BTN_POPUP_DELETE, &CPhoneTypesView::OnBtnPopupDelete)
	ON_COMMAND(IDC_BTN_POPUP_INSERT, &CPhoneTypesView::OnBtnPopupInsert)
	ON_UPDATE_COMMAND_UI(IDC_BTN_POPUP_EDIT, &CPhoneTypesView::OnUpdateBtnPopup)
	ON_UPDATE_COMMAND_UI(IDC_BTN_POPUP_DELETE, &CPhoneTypesView::OnUpdateBtnPopup)
	ON_UPDATE_COMMAND_UI(IDC_BTN_POPUP_INSERT, &CPhoneTypesView::OnUpdateBtnPopup)
END_MESSAGE_MAP()

// Constants
// ----------------

const CString CPhoneTypesView::_strTypeColumnCaption = _T("Type");
const int CPhoneTypesView::_nTypeColumnWidth = 250;

// Constructor / Destructor
// ----------------

CPhoneTypesView::CPhoneTypesView()
{
}

CPhoneTypesView::~CPhoneTypesView()
{
}

// Methods
// ----------------

void CPhoneTypesView::BuildListCtrl()
{
	CListCtrl& oListCtrl = GetListCtrl();
	oListCtrl.ModifyStyle(0, LVS_REPORT);
	oListCtrl.ModifyStyle(0, LVS_SINGLESEL);
	oListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	oListCtrl.InsertColumn(ColumnType, _strTypeColumnCaption, LVCFMT_CENTER, _nTypeColumnWidth);
}

void CPhoneTypesView::FillListCtrl()
{
	const CPhoneTypesArray& oPhoneTypesArray = GetDocument().GetAllPhoneTypes();

	for (int i = 0; i < oPhoneTypesArray.GetCount(); i++)
	{
		const PHONE_TYPES* pPhoneType = oPhoneTypesArray.GetAt(i);
		if (pPhoneType == NULL)
			continue;

		InsertItem(*pPhoneType);
	}
}

void CPhoneTypesView::EditRecord()
{
	PHONE_TYPES recPhoneType;
	if (!InitFilledDialog(recPhoneType, false))
		return;

	if (!GetDocument().Update(recPhoneType.lID, recPhoneType))
		return;

	AfxMessageBox(_T("Successfully updated phone type."));
}

void CPhoneTypesView::InsertRecord()
{
	PHONE_TYPES recPhoneType;
	if (!InitDialog(recPhoneType, false))
		return;

	if (!GetDocument().Insert(recPhoneType))
		return;

	AfxMessageBox(_T("Successfully inserted phone type."));
}

void CPhoneTypesView::DeleteRecord()
{
	if (AfxMessageBox(_T("Are you sure you want to delete this record?"), MB_YESNO) == IDNO)
		return;

	int nIndex = FindSelectedItem();
	if (nIndex == CB_ERR)
		return;

	long lID = GetListCtrl().GetItemData(nIndex);

	if (!GetDocument().Delete(lID))
		return;

	AfxMessageBox(_T("Phone type has been successfully deleted."));
}

void CPhoneTypesView::ReadRecord()
{
	PHONE_TYPES recPhoneType;
	if (!InitFilledDialog(recPhoneType, true))
		return;
}

const int CPhoneTypesView::FindSelectedItem()
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

const int CPhoneTypesView::FindItemByData(const long lItemData)
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

BOOL CPhoneTypesView::InitDialog(PHONE_TYPES& recPhoneType, bool bReadOnly)
{
	if (bReadOnly)
	{
		CPhoneTypesReadOnlyDlg oPhoneTypesReadOnlyDlg(recPhoneType);
		if (oPhoneTypesReadOnlyDlg.DoModal() != IDOK)
			return FALSE;
	} 
	else
	{
		CPhoneTypesDlg oPhoneTypesDlg(recPhoneType);
		if (oPhoneTypesDlg.DoModal() != IDOK)
			return FALSE;
	}

	return TRUE;
}

BOOL CPhoneTypesView::LoadSelectedRecord(PHONE_TYPES& recPhoneType)
{
	int nIndex = FindSelectedItem();
	if (nIndex == CB_ERR)
		return FALSE;

	long lID = GetListCtrl().GetItemData(nIndex);

	if (!GetDocument().LoadPhoneType(lID, recPhoneType))
		return FALSE;

	return TRUE;
}

BOOL CPhoneTypesView::InitFilledDialog(PHONE_TYPES& recPhoneType, bool bReadOnly)
{
	if (!LoadSelectedRecord(recPhoneType))
		return FALSE;

	if (!InitDialog(recPhoneType, bReadOnly))
		return FALSE;

	return TRUE;
}

void CPhoneTypesView::UpdateItem(int nIndex, const PHONE_TYPES& recPhoneType)
{
	CListCtrl& oListCtrl = GetListCtrl();
	oListCtrl.SetItemText(nIndex, ColumnType, recPhoneType.szType);
	oListCtrl.SetItemData(nIndex, recPhoneType.lID);
}

void CPhoneTypesView::InsertItem(const PHONE_TYPES& recPhoneType)
{
	int nIndex = GetListCtrl().InsertItem(ColumnType, recPhoneType.szType);
	UpdateItem(nIndex, recPhoneType);
}

void CPhoneTypesView::OnBtnPopupEdit()
{
	EditRecord();
}

void CPhoneTypesView::OnBtnPopupDelete()
{
	DeleteRecord();
}

void CPhoneTypesView::OnBtnPopupInsert()
{
	InsertRecord();
}

void CPhoneTypesView::OnUpdateBtnPopup(CCmdUI* pCmdUI)
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

void CPhoneTypesView::OnItemActivate(NMHDR* pNMHDR, LRESULT* pResult)
{
	ReadRecord();
}

// Overrides
// ----------------

CPhoneTypesDocument& CPhoneTypesView::GetDocument() const
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPhoneTypesDocument)));
	return *(CPhoneTypesDocument*)m_pDocument;
}

void CPhoneTypesView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	if (!pHint)
		return;

	CPhoneTypesUpdateObject& oPhoneTypesUpdateObject = *(CPhoneTypesUpdateObject*)pHint;
	const PHONE_TYPES& recPhoneType = oPhoneTypesUpdateObject.GetData();
	const int nIndex = FindItemByData(recPhoneType.lID);
	RecordOperationTypes eRecordOperationTypes = oPhoneTypesUpdateObject.GetOperationType();

	if (nIndex == CB_ERR && eRecordOperationTypes != RecordOperationTypeInsert)
		return;

	switch (eRecordOperationTypes)
	{
	case RecordOperationTypeUpdate:
		UpdateItem(nIndex, recPhoneType);
		break;
	case RecordOperationTypeInsert:
		InsertItem(recPhoneType);
		break;
	case RecordOperationTypeDelete:
		GetListCtrl().DeleteItem(nIndex);
		break;
	default:
		break;
	}
}

void CPhoneTypesView::OnInitialUpdate()
{
	BuildListCtrl();
	FillListCtrl();
}

void CPhoneTypesView::OnContextMenu(CWnd* pWnd, CPoint oPoint)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, oPoint.x, oPoint.y, this, TRUE);
#endif
}

