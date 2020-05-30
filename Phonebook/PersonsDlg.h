#pragma once
#include "Structures.h"
#include "afxwin.h"
#include "afxcmn.h"
#include "Person.h"
#include "PhoneNumbersViewData.h"
#include "Validator.h"

/// <summary>
/// ���� �� ������ �� �������� � �������� �� ������ � �������� ��������
/// </summary>
class CPersonsDlg : public CDialog
{
	DECLARE_DYNAMIC(CPersonsDlg)

// Constants
// ----------------

private:
	/// <summary>Enum � ������ ������ � ���� �������� �� ��������� ������</summary>
	enum PhoneNumbersColumns
	{
		PhoneNumbersColumnType = 0,
		PhoneNumbersColumnNumber = 1
	};


	/// <summary>��� �� ������ �� ��� �� ��������� ����� �� ���� �������� �� ��������� ������</summary>
	static const CString _strPhoneNumbersTypeColumnCaption;

	/// <summary>��� �� ������ �� ��������� ����� �� ���� �������� �� ��������� ������</summary>
	static const CString _strPhoneNumbersNumberColumnCaption;

	/// <summary>�������� �� ������ �� ��� �� ��������� ����� �� ���� �������� �� ��������� ������</summary>
	static const int _nPhoneNumbersTypeColumnWidth;

	/// <summary>�������� �� ������ �� ��������� ����� �� ���� �������� �� ��������� ������</summary>
	static const int _nPhoneNumbersNumberColumnWidth;

	/// <summary>������ �� �������, ����� �� �� ������ ��� ����� ���� ����� ���� ���������� � ����������� ������</summary>
	static const int _nSubmenuIndex;


// Constructor / Destructor
// ----------------
public:
	CPersonsDlg(CPerson& oPerson, const CCitiesMap& oCitiesMap, const CPhoneTypesMap& oPhoneTypesMap, CWnd* pParent = NULL);
	virtual ~CPersonsDlg();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PERSONS_DIALOG };
#endif

// Methods
// ----------------
protected:
	/// <summary>�����, ����� ������ ������ � ���� ��������</summary>
	void BuildListCtrl();

	/// <summary>�����, ����� ������� ������ � ���� ��������</summary>
	void FillListCtrl();

	/// <summary>����� ������� ����� �� ������� �� ���� ��������� � �������</summary>
	void SetTextLimits();

	/// <summary>�����, ����� ������� �������� ���������� ��� ������� � ���� ���������</summary>
	void FillEditBoxes();

	/// <summary>�����, ����� ������� ����� ���� cmbCity � �������� �������</summary>
	virtual void FillCities();

private:
	/// <summary>�����, ����� ������ ������ �� �������� �� ����� � ������� ����������� ����� ��� ���� ����������</summary>
	void EditRecord();

	/// <summary>�����, ����� ������ ������ �� ��������� �� ��� ����� � ������� ���������� ����� ��� ���� ����������</summary>
	void InsertRecord();

	/// <summary>�����, ����� ������� ������ ����� �� ���� ����������</summary>
	void DeleteRecord();

	/// <summary>�����, ����� ������� ���������� �� ����� ����� � ������, ����� �� ��������� ��������</summary>
	void ReadRecord();

	/// <summary>�����, ����� ������ ������</summary>
	/// <param name="recPhoneNumberViewData">�����, � ����� �� ������� ������������ ��������� �����</param>
	/// <param name="bReadOnly">������ ��������, ����� �������� ���� ������������ � ������� �� ���� �� �� ���������</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL InitDialog(PHONE_NUMBERS_VIEW_DATA& recPhoneNumberViewData, bool bReadOnly);

	/// <summary>�����, ����� ����� �����</summary>
	/// <param name="nIndex">������ �� ���� �� ���� ����������, ����� ������ �� �� ������� � ������</param>
	/// <param name="recPhoneNumberViewData">�����, � ����� �� ������� ������������ �� ��������� �����</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL LoadItem(int nIndex, PHONE_NUMBERS_VIEW_DATA& recPhoneNumberViewData);

	/// <summary>�����, ����� ����� ���������� �����</summary>
	/// <param name="recPhoneNumberViewData">�����, � ����� �� ������� ������������ �� ��������� �����</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL LoadSelectedItem(PHONE_NUMBERS_VIEW_DATA& recPhoneNumberViewData);

	/// <summary>�����, ����� ������ ������ � ��������� ������</summary>
	/// <param name="recPhoneNumberViewData">�����, � ����� �� ������� ������������ �� ��������� �����</param>
	/// <param name="bReadOnly">������ ��������, ����� �������� ���� ������������ � ������� �� ���� �� �� ���������</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL InitFilledDialog(PHONE_NUMBERS_VIEW_DATA& recPhoneNumberViewData, bool bReadOnly);

	/// <summary>�����, ����� ������ ������ �� ������ ���</summary>
	///<returns> ��������� ����� int �������� ������ �� ���������� ��� ��� -1 ��� ���� �����</returns>
	const int FindSelectedItem();

	/// <summary>�����, ����� ������ ��� ������� �� �������������</summary>
	/// <param name="lID">�������� �������������</param>
	///<returns> ��������� ����� ������ � ���� ������� ��� ������ ������ ��� ���� �����</returns>
	const CString FindPhoneType(const long lID);

	/// <summary>�����, ����� ������ ������ �� ����� � ������ �� �������������</summary>
	/// <param name="lID">�������� �������������</param>
	///<returns> ��������� ����� ������ �� �������� ����� ����� � ������� ������������� ��� -1 ��� ���� �����</returns>
	const int FindPhoneNumberIndex(const long lID);

	/// <summary>�����, ����� ������� ����������� ��� �� ���� ����������</summary>
	/// <param name="nIndex">������ �� ��� �� ���� ����������</param>
	/// <param name="recPhoneNumberViewData">����� �� �e������� �����, �������� ����������, �� ����� �� ������� �����</param>
	void UpdateItem(int nIndex, const PHONE_NUMBERS_VIEW_DATA& recPhoneNumberViewData);

	/// <summary>�����, ����� ������ ��� � ���� ����������</summary>
	/// <param name="recPhoneNumberViewData">����� �� �e������� �����, �������� ����������, �� ����� �� ������� ������ ���</param>
	void InsertItem(const PHONE_NUMBERS_VIEW_DATA& recPhoneNumberViewData);

	/// <summary>�����, ����� �� ��������� ���� ����������� �� �dit ������ �� �������� ������</summary>
	afx_msg void OnBtnPopupEdit();

	/// <summary>�����, ����� �� ��������� ���� ����������� �� Delete ������ �� �������� ������</summary>
	afx_msg void OnBtnPopupDelete();

	/// <summary>�����, ����� �� ��������� ���� ����������� �� Insert ������ �� �������� ������</summary>
	afx_msg void OnBtnPopupInsert();

	/// <summary>�����, �������� ����������� �� �������� �� ������������ ����, ���������� �� ����� ����� ���������� �� ������</summary>
	afx_msg virtual void OnUpdateBtnPopup(CCmdUI* pCmdUI);

	/// <summary>�����, ����� �� ��������� ��� ��������� �� ��������� �����</summary>
	afx_msg void OnItemActivatePhoneNumbers(NMHDR* pNMHDR, LRESULT* pResult);

	/// <summary>�����, ����� ������� ���������� ���� ��� ����� ���� ����� ���������� � ����������� ������</summary>
	afx_msg void OnNMRClickPhoneNumbers(NMHDR* pNMHDR, LRESULT* pResult);

	/// <summary>�����, ����� �������� ���� ��������</summary>
	/// <param name="edbCtrl">���� ��������</param>
	/// <param name="strValue">��������� ��������, ����� ���� ��������� �� ���������</param>
	/// <param name="strFieldName">��� �� ������, ����� ���� ����������</param>
	/// <param name="eEdbTypes">��� �� �����, ����� ������� ���� ����������</param>
	///<returns> ��������� ����� ������ � ���������� �� ������� ��������� � ������ ������ ��� ������� ������� �����</returns>
	CString ValidateEditBox(const CEdit& edbCtrl, const CString& strFieldName, const CValidator::EdbTypes eEdbTypes);

	/// <summary>�����, ����� �������� ����� ����</summary>
	/// <param name="cmbCtrl">����� ����</param>
	/// <param name="strFieldName">��� �� ������, ����� ���� ����������</param>
	///<returns> ��������� ����� ������ � ���������� �� ������� ��������� � ������ ������ ��� ������� ������� �����</returns>
	CString ValidateComboBox(const CComboBox& cmbCtrl, const CString& strFieldName);
	
	/// <summary>�����, ����� �������� ������� �� ����������</summary>
	///<returns> ��������� ����� �������� TRUE ��� ������� ����� � FALSE ��� ������� �� ���� ���� ��������� �����</returns>
	BOOL ValidateData();

	/// <summary>�����, ����� ����������� ������� �� ���������� � ������</summary>
	void TransferDataToRecord();


// Overrides
// ----------------
protected:
	/// <summary>�����, ����� ����� ������� �� �������</summary>
	/// <param name="pDx">�������� ����� CDataExchange �����</param>
	virtual void DoDataExchange(CDataExchange* pDX);

	/// <summary>�����, ����� �� ��������� ��� ������������� �� ������</summary>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	virtual BOOL OnInitDialog();

	/// <summary>�����, ����� �� ��������� ��� ����������� �� ������ OK</summary>
	virtual void OnOK();

	/// <summary>�����, ����� �� ��������� ��� ������������� �� popup ����</summary>
	/// <param name="pPopupMenu">�������� ����� ��� ���� ����� �� popup ������</param>
	/// <param name="nIndex">������ �� popup ������ � �������� ����</param>
	/// <param name="bSysMenu">���������� ��� �������� TRUE ��� popup ������ � ��������� ���� � FALSE ��� �� �</param>
	virtual void OnInitMenuPopup(CMenu* pPopupMenu, UINT nIndex, BOOL bSysMenu);

// Members
// ----------------
protected:
	/// <summary>���������� �� �dit box �� ����� ��� �� ������</summary>
	CEdit m_edbFirstName;

	/// <summary>���������� �� �dit box �� ������� �� ������</summary>
	CEdit m_edbMiddleName;

	/// <summary>���������� �� �dit box �� ������� �� ������</summary>
	CEdit m_edbLastName;

	/// <summary>���������� �� �dit box �� ��� �� ������</summary>
	CEdit m_edbUCN;

	/// <summary>���������� �� combo box �� ���� �� ������</summary>
	CComboBox m_cmbCity;

	/// <summary>���������� �� �dit box �� ����� �� ������</summary>
	CEdit m_edbAddress;

	/// <summary>���������� �� list �������� �� ��������� ������ �� ������ � ������� ������</summary>
	CListCtrl m_lscPhoneNumbers;

	/// <summary>�����, � ����� �� ������� ������������ �� ������ � �������� ��������� ������</summary>
	CPerson& m_oPerson;

	/// <summary>��� � ��������� ������ ������ �� ������ �������</summary>
	const CCitiesMap& m_oCitiesMap;

	/// <summary>��� � ��������� ������ ������ �� ������ ������ ��������</summary>
	const CPhoneTypesMap& m_oPhoneTypesMap;

	private:
		/// <summary>�����, ����� �������� �������� ���������</summary>
		DECLARE_MESSAGE_MAP()
};
