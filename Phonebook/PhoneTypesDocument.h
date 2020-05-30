#pragma once
#include "Structures.h"
#include "PhoneTypesData.h"

/// <summary>
/// ���� �� �������� �� ������ ��������
/// </summary>
class CPhoneTypesDocument : public CDocument
{
	DECLARE_DYNCREATE(CPhoneTypesDocument)

// Constants
// ----------------

// Constructor / Destructor
// ----------------
public:
	CPhoneTypesDocument();
	virtual ~CPhoneTypesDocument();


// Methods
// ----------------
public:
	/// <summary>�����, ����� ����� ����� � ������ ������ ��������</summary>
	///<returns> ��������� ����� ������������� �� �����, �������� ��������� ��� ������ ������ ��������</returns>
	const CPhoneTypesArray& GetAllPhoneTypes();

	/// <summary>�����, ����� ������� ��� ������� �� ����� ������������� </summary>
	/// <param name="lID">�������� �������������</param>
	/// <param name="recPhoneType">�����, � ����� �� ������� ������������ �� ���������� ��� �������</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL LoadPhoneType(const long lID, PHONE_TYPES& recPhoneType);

	/// <summary>�����, ����� ������� ����� �� ��� ��� ������� </summary>
	/// <param name="recPhoneType">����� �������� ��������� �� ��� �������</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL Insert(PHONE_TYPES& recPhoneType);

	/// <summary>�����, ����� ������� ��� ������� </summary>
	/// <param name="lID">�������� �������������</param>
	/// <param name="recPhoneType">����� �������� ��������� �� ��� �������</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL Update(const long lID, const PHONE_TYPES& recPhoneType);

	/// <summary>�����, ����� ������� ��� ������� </summary>
	/// <param name="lID">�������� �������������</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL Delete(const long lID);

private:
	/// <summary>�����, ����� ������ ������ �� ����� � ������ �� �������������</summary>
	/// <param name="lID">�������� �������������</param>
	///<returns> ��������� ����� ������ �� �������� ����� ����� � ������� ������������� ��� -1 ��� ���� �����</returns>
	int FindRecord(const long lID);

// Overrides
// ----------------

private:
	/// <summary>����� �� ��������� �� ��� ��������</summary>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	virtual BOOL OnNewDocument();

// Members
// ----------------
private:
	/// <summary>�����, ����� �������� �������� ���������</summary>
	DECLARE_MESSAGE_MAP()

	/// <summary>����� �������� ������ �� ������ ��������</summary>
	CPhoneTypesArray m_oPhoneTypesArray;

	/// <summary>����� �������� � �������� ���������� �� ������ ����� �������� ������ ������</summary>
	CPhoneTypesData m_oPhoneTypesData;
};