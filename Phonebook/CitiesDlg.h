#pragma once
#include "afxwin.h"
#include "Structures.h"
#include "Validator.h"

/// <summary>
/// ���� �� ������ �� �������� � �������� �� ����
/// </summary>
class CCitiesDlg : public CDialog
{
	DECLARE_DYNAMIC(CCitiesDlg)

// Constants
// ----------------

// Constructor / Destructor
// ----------------

public:
	CCitiesDlg(CITIES& recCity, CWnd* pParent = NULL);
	virtual ~CCitiesDlg();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CITIES_DIALOG };
#endif

// Methods
// ----------------
private:
	/// <summary>����� ������ ����� �� ������� �� ���� ��������� � �������</summary>
	void SetTextLimits();

	/// <summary>�����, ����� ������� �������� ���������� ��� ������� � ���� ���������</summary>
	void FillEditBoxes();

	/// <summary>�����, ����� �������� ���� ��������</summary>
	/// <param name="edbCtrl">���� ��������</param>
	/// <param name="strFieldName">��� �� ������, ����� ���� ����������</param>
	/// <param name="eEdbTypes">��� �� �����, ����� ������� ���� ����������</param>
	///<returns> ��������� ����� ������ � ���������� �� ������� ��������� � ������ ������ ��� ������� ������� �����</returns>
	CString ValidateEditBox(const CEdit& edbCtrl, const CString& strFieldName, const CValidator::EdbTypes eEdbTypes);

	/// <summary>�����, ����� �������� ������ ����� �� �������</summary>
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

// Members
// ----------------
private:
	/// <summary>�����, ����� �������� �������� ���������</summary>
	DECLARE_MESSAGE_MAP()

protected:
	/// <summary>���������� �� �dit box �� ��� �� ����</summary>
	CEdit m_edbName;

	/// <summary>���������� �� �dit box �� ������ �� ����</summary>
	CEdit m_edbRegion;

	/// <summary>����� �� ����</summary>
	CITIES& m_recCity;

};
