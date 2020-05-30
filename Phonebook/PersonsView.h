#pragma once
#include "PersonsDocument.h"
#include "Person.h"

/// <summary>
/// ���� �� list view �� �������
/// </summary>
class CPersonsView : public CListView
{
	DECLARE_DYNCREATE(CPersonsView)

// Constants
// ----------------
private:
	/// <summary>Enum � ������ ������ � CPersonsView</summary>
	enum Columns
	{
		ColumnFirstName = 0,
		ColumnMiddleName = 1,
		ColumnLastName = 2,
		ColumnUCN = 3,
		ColumnCity = 4,
		ColumnAddress = 5
	};

	/// <summary>��� �� ������ �� ����� ��� �� ������</summary>
	static const CString _strFirstNameColumnCaption;

	/// <summary>��� �� ������ �� ������� �� ������</summary>
	static const CString _strMiddleNameColumnCaption;

	/// <summary>��� �� ������ �� ������� �� ������</summary>
	static const CString _strLastNameColumnCaption;

	/// <summary>��� �� ������ �� ��� �� ������</summary>
	static const CString _strUCNColumnCaption;

	/// <summary>��� �� ������ �� ���� �� ������</summary>
	static const CString _strCityColumnCaption;

	/// <summary>��� �� ������ �� ����� �� ������</summary>
	static const CString _strAddressColumnCaption;

	/// <summary>�������� �� ������ �� ����� ��� �� ������</summary>
	static const int _nFirstNameColumnWidth;

	/// <summary>�������� �� ������ �� ������� �� ������</summary>
	static const int _nMiddleNameColumnWidth;

	/// <summary>�������� �� ������ �� ������� �� ������</summary>
	static const int _nLastNameColumnWidth;

	/// <summary>�������� �� ������ �� ��� �� ������</summary>
	static const int _nUCNColumnWidth;

	/// <summary>�������� �� ������ �� ���� �� ������</summary>
	static const int _nCityColumnWidth;

	/// <summary>�������� �� ������ �� ����� �� ������</summary>
	static const int _nAddressColumnWidth;

// Constructor / Destructor
// ----------------	
public:
	CPersonsView();
	virtual ~CPersonsView();

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
	/// <param name="oPerson">�����, � ����� �� ������� ������������ �� ������ � �������� ��������� ������</param>
	/// <param name="bReadOnly">������ ��������, ����� �������� ���� ������������ � ������� �� ���� �� �� ���������</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL InitDialog(CPerson& oPerson, bool bReadOnly);

	/// <summary>�����, ����� ����� ���������� �����</summary>
	/// <param name="oPerson">�����, � ����� �� ������� ������������ �� ������ � �������� ��������� ������</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL LoadSelectedRecord(CPerson& oPerson);

	/// <summary>�����, ����� ������ ������ � ��������� ������</summary>
	/// <param name="oPerson">�����, � ����� �� ������� ������������ �� ������ � �������� ��������� ������</param>
	/// <param name="bReadOnly">������ ��������, ����� �������� ���� ������������ � ������� �� ���� �� �� ���������</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL InitFilledDialog(CPerson& oPerson, bool bReadOnly);

	/// <summary>�����, ����� ������� ����������� ��� �� ���� ����������</summary>
	/// <param name="nIndex">������ �� ��� �� ���� ����������</param>
	/// <param name="recPersonViewData">����� �� ������, �������� ���������� �� ����� �� ������� �����</param>
	void UpdateItem(int nIndex, const PERSONS_VIEW_DATA& recPersonViewData);

	/// <summary>�����, ����� ������ ��� � ���� ����������</summary>
	/// <param name="recPersonViewData">����� �� ������, �������� ���������� �� ����� �� ������� ������ ���</param>
	void InsertItem(const PERSONS_VIEW_DATA& recPersonViewData);

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
	CPersonsDocument& GetDocument() const;

// Members
// ----------------
private:
	/// <summary>�����, ����� �������� �������� ���������</summary>
	DECLARE_MESSAGE_MAP()


};


