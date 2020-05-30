#pragma once
#include "stdafx.h"

/// <summary>
/// ���� �� ��������� �� ����� �� edit box
/// </summary>
class CValidator
{

// Constants
// ----------------
public:
	/// <summary>Enum � ������ ���� ������� ������ �������, ����� ��������</summary>
	enum EdbTypes
	{
		EdbTypeNames = 0,
		EdbTypeUCN = 1,
		EdbTypeAddress = 2,
		EdbTypePhoneNumber = 3
	};
	
private:
	/// <summary>������� ������� �� �����</summary>
	static const CString _strNamesValidSymbols;

	/// <summary>������� ������� �� ���</summary>
	static const CString _strUCNValidSymbols;

	/// <summary>������� ������� �� ������</summary>
	static const CString _strAddressValidSymbols;

	/// <summary>������� ������� �� ��������� �����</summary>
	static const CString _strPhoneNumberValidSymbols;

	/// <summary>������� �� ���</summary>
	static const int _nUCNLength;

	/// <summary>��������� ������� �� ��������� �����</summary>
	static const int _nPhoneNumberMinimumLength;

// Constructor / Destructor
// ----------------
public:
	CValidator();
	virtual ~CValidator();


// Methods
// ----------------

public:
	/// <summary>�����, ����� �������� ����</summary>
	/// <param name="strValue">��������� ��������, ����� ���� ��������� �� ���������</param>
	/// <param name="strFieldName">��� �� ������, ����� ���� ����������</param>
	/// <param name="eEdbTypes">��� �� �����, ����� ������� ���� ����������</param>
	/// <param name="bIsValid">������ ��������, ����� ������� ���� ������� �� �������</param>
	/// <param name="strMessage">��������� �� ���������� �� ��������� �����</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	static BOOL ValidateField(const CString& strValue, const CString& strFieldName, const EdbTypes& eEdbTypes, bool& bIsValid, CString& strMessage);

private:
	/// <summary>�����, ����� �������� �����</summary>
	/// <param name="strValue">��������� ��������, ����� ���� ��������� �� ���������</param>
	/// <param name="strFieldName">��� �� ������, ����� ���� ����������</param>
	///<returns> ��������� ����� ������ � ���������� �� ������� ��������� � ������ ������ ��� ������� ������� �����</returns>
	static CString ValidateName(const CString& strValue, const CString& strFieldName);

	/// <summary>�����, ����� ��������  ���</summary>
	/// <param name="strValue">��������� ��������, ����� ���� ��������� �� ���������</param>
	/// <param name="strFieldName">��� �� ������, ����� ���� ����������</param>
	///<returns> ��������� ����� ������ � ���������� �� ������� ��������� � ������ ������ ��� ������� ������� �����</returns>
	static CString ValidateUCN(const CString& strValue, const CString& strFieldName);

	/// <summary>�����, ����� �������� ������</summary>
	/// <param name="strValue">��������� ��������, ����� ���� ��������� �� ���������</param>
	/// <param name="strFieldName">��� �� ������, ����� ���� ����������</param>
	///<returns> ��������� ����� ������ � ���������� �� ������� ��������� � ������ ������ ��� ������� ������� �����</returns>
	static CString ValidateAddress(const CString& strValue, const CString& strFieldName);

	/// <summary>�����, ����� �������� ��������� ������</summary>
	/// <param name="strValue">��������� ��������, ����� ���� ��������� �� ���������</param>
	/// <param name="strFieldName">��� �� ������, ����� ���� ����������</param>
	///<returns> ��������� ����� ������ � ���������� �� ������� ��������� � ������ ������ ��� ������� ������� �����</returns>
	static CString ValidatePhoneNumber(const CString& strValue, const CString& strFieldName);

// Overrides
// ----------------

// Members
// ----------------

};