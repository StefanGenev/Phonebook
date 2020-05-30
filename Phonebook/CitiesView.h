
// CitiesView.h : interface of the CCitiesView class
//

#pragma once
#include "CitiesDocument.h"

/// <summary>
/// ���� �� list view �� �������
/// </summary>
class CCitiesView : public CListView
{
	DECLARE_DYNCREATE(CCitiesView)

// Constants
// ----------------
private:
	/// <summary>Enum � ������ ������ � Cities view</summary>
	enum Columns
	{
		ColumnName = 0,
		ColumnRegion = 1
	};

	/// <summary>��� �� ������ �� ��� �� ����</summary>
	static const CString _strNameColumnCaption;

	/// <summary>��� �� ������ �� ������ �� ����</summary>
	static const CString _strRegionColumnCaption;

	/// <summary>�������� �� �� ������ �� ��� �� ����</summary>
	static const int _nNameColumnWidth;

	/// <summary>�������� �� ������ �� ������ �� ����</summary>
	static const int _nRegionColumnWidth;

// Constructor / Destructor
// ----------------	
public:
	CCitiesView();
	virtual ~CCitiesView();

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
	/// <param name="recCity">�����, � ����� �� ������� ������������ �� ����</param>
	/// <param name="bReadOnly">������ ��������, ����� �������� ���� ������������ � ������� �� ���� �� �� ���������</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL InitDialog(CITIES& recCity, bool bReadOnly);

	/// <summary>�����, ����� ����� ���������� �����</summary>
	/// <param name="recCity">�����, � ����� �� ������� ������������ �� ������������� ����</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL LoadSelectedRecord(CITIES& recCity);

	/// <summary>�����, ����� ������ ������ � ��������� ������</summary>
	/// <param name="recCity">�����, � ����� �� ������� ������������ �� ������������� ����</param>
	/// <param name="bReadOnly">������ ��������, ����� �������� ���� ������������ � ������� �� ���� �� �� ���������</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL InitFilledDialog(CITIES& recCity, bool bReadOnly);

	/// <summary>�����, ����� ������� ����������� ��� �� ���� ����������</summary>
	/// <param name="nIndex">������ �� ��� �� ���� ����������</param>
	/// <param name="recCity">����� �� ����, �������� ���������� �� ����� �� ������� �����</param>
	void UpdateItem(int nIndex, const CITIES& recCity);

	/// <summary>�����, ����� ������ ��� � ���� ����������</summary>
	/// <param name="recCity">����� �� ����, �������� ���������� �� ����� �� ������� ������ ���</param>
	void InsertItem(const CITIES& recCity);

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

	/// <summary>�����, ���������� �� ��� ����������� �� ���� ��������� �� CitiesView</summary>
	virtual void OnInitialUpdate();

	/// <summary>�����, ���������� �� ��� ��������� �� ����� ����� �� �������</summary>
	/// <param name="nFlags">���������, ����� �������� ���� �� ��������� ���������� ������ </param>
	/// <param name="oPoint">����� �������� ���������� �� �������</param>
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint oPoint);

	/// <summary>�����, ����� ����� �������� ������� � CitiesView</summary>
	///<returns> ��������� ����� �������� ����� ��������� �� CitiesView</returns>
	CCitiesDocument& GetDocument() const;

// Members
// ----------------
private:
	/// <summary>�����, ����� �������� �������� ���������</summary>
	DECLARE_MESSAGE_MAP()


};


