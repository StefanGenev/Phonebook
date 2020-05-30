#pragma once
#include "stdafx.h"
#include "Structures.h"
#include "PhoneTypesDocument.h"

/// <summary>
/// ���� �� list view �� ������ ��������
/// </summary>
class CPhoneTypesView : public CListView
{
	DECLARE_DYNCREATE(CPhoneTypesView)

// Constants
// ----------------
	/// <summary>Enum � ������ ������ � Phone Types view</summary>
	enum Columns
	{
		ColumnType = 0
	};

	/// <summary>��� �� ������ �� ��� �� ��������� �����</summary>
	static const CString _strTypeColumnCaption;

private:
	/// <summary>�������� ������ �� ��� �� ��������� �����</summary>
	static const int _nTypeColumnWidth;

// Constructor / Destructor
// ----------------
public:
	CPhoneTypesView();
	virtual ~CPhoneTypesView();

// Methods
// ----------------
private:
	/// <summary>�����, ����� ������ ������ � ���� ��������</summary>
	void BuildListCtrl();

	/// <summary>�����, ����� ������� ������ � ���� ��������</summary>
	void FillListCtrl();

	/// <summary>�����, ����� ������ ������ �� �������� �� ����� � ������� ����������� ����� ��� ���������</summary>
	void EditRecord();

	/// <summary>�����, ����� ������ ������ �� ��������� �� ��� ����� � ������� ���������� ����� ��� ���������</summary>
	void InsertRecord();

	/// <summary>�����, ����� ����� �� ��������� �� ������ ������ �����</summary>
	void DeleteRecord();

	/// <summary>�����, ����� ������� ���������� �� ����� ����� � ������, ����� �� ��������� ��������</summary>
	void ReadRecord();

	/// <summary>�����, ����� ������ ������ �� ������ ���</summary>
	///<returns> ��������� ����� int �������� ������ �� ���������� ��� ��� -1 ��� ���� �����</returns>
	const int FindSelectedItem();

	/// <summary>�����, ����� ������ ������ �� ��� �� �������� data</summary>
	/// <param name="lItemData">Data, �� ����� �� ����� ���</param>
	///<returns> ��������� ����� int �������� ������ �� ��� � �������� data ��� -1 ��� ���� �����</returns>
	const int FindItemByData(const long lItemData);

	/// <summary>�����, ����� ������ ������</summary>
	/// <param name="recPhoneType">�����, � ����� �� ������� ������������ �� ������������� ��� �������</param>
	/// <param name="bReadOnly">������ ��������, ����� �������� ���� ������������ � ������� �� ���� �� �� ���������</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL InitDialog(PHONE_TYPES& recPhoneType, bool bReadOnly);

	/// <summary>�����, ����� ����� ���������� �����</summary>
	/// <param name="recPhoneType">�����, � ����� �� ������� ������������ �� ������������� ��� �������</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL LoadSelectedRecord(PHONE_TYPES& recPhoneType);

	/// <summary>�����, ����� ������ ������ � ��������� ������</summary>
	/// <param name="recPhoneType">�����, � ����� �� ������� ������������ �� ������������� ��� �������</param>
	/// <param name="bReadOnly">������ ��������, ����� �������� ���� ������������ � ������� �� ���� �� �� ���������</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL InitFilledDialog(PHONE_TYPES& recPhoneType, bool bReadOnly);

	/// <summary>�����, ����� ������� ����������� ��� �� ���� ����������</summary>
	/// <param name="nIndex">������ �� ��� �� ���� ����������</param>
	/// <param name="recPhoneType">����� �� ��� �������, �������� ���������� �� ����� �� ������� �����</param>
	void UpdateItem(int nIndex, const PHONE_TYPES& recPhoneType);

	/// <summary>�����, ����� ������ ��� � ���� ����������</summary>
	/// <param name="recPhoneType">����� �� ��� �������, �������� ���������� �� ����� �� ������� ������ ���</param>
	void InsertItem(const PHONE_TYPES& recPhoneType);

	/// <summary>�����, ����� �� ��������� ���� ����������� �� �dit ������ �� �������� ������</summary>
	afx_msg void OnBtnPopupEdit();

	/// <summary>�����, ����� �� ��������� ���� ����������� �� Delete ������ �� �������� ������</summary>
	afx_msg void OnBtnPopupDelete();

	/// <summary>�����, ����� �� ��������� ���� ����������� �� Insert ������ �� �������� ������</summary>
	afx_msg void OnBtnPopupInsert();

	/// <summary>�����, �������� ����������� �� �������� �� ������������ ����, ���������� �� ����� ����� ���������� �� ������</summary>
	afx_msg void OnUpdateBtnPopup(CCmdUI* pCmdUI);

	/// <summary>�����, ����� �� ��������� ���� ������������ �� ��� �� ���� ����������</summary>
	afx_msg void OnItemActivate(NMHDR* pNMHDR, LRESULT* pResult);

// Overrides
// ----------------
private:
	/// <summary>�����, ���������� �� ��� ������ �� �������� view</summary>
	/// <param name="pSender">�������� ����� ��� view, ����� � ��������� ���������. ��� �������� NULL �� ������� ����� view.</param>
	/// <param name="lHint">��������� �������� ���������� �� ���������</param>
	/// <param name="pHint">�������� ����� ����� ���������� ���������� �� ���������</param>
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);

	/// <summary>�����, ���������� �� ��� ����������� �� ���� ��������� �� PhoneTypesView</summary>
	virtual void OnInitialUpdate();

	/// <summary>�����, ���������� �� ��� ��������� �� ����� ����� �� �������</summary>
	/// <param name="nFlags">���������, ����� �������� ���� �� ��������� ���������� ������ </param>
	/// <param name="oPoint">����� �������� ���������� �� �������</param>
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint oPoint);

	/// <summary>�����, ����� ����� �������� ������� � PhoneTypesView</summary>
	///<returns> ��������� ����� �������� ����� ��������� �� PhoneTypesView</returns>
	CPhoneTypesDocument& GetDocument() const;

// Members
// ----------------
private:
	/// <summary>�����, ����� �������� �������� ���������</summary>
	DECLARE_MESSAGE_MAP()
};