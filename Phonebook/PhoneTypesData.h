#pragma once
#include "Structures.h"
#include "PhoneTypesTable.h"
#include "DataSourceProvider.h"

/// <summary>
/// ���� �� ������ ������ � �������� ����� CPhoneTypesTable
/// </summary>
class CPhoneTypesData
{

// Constants
// ----------------


// Constructor / Destructor
// ----------------
public:
	CPhoneTypesData();
	virtual ~CPhoneTypesData();

// Methods
// ----------------

public:
	/// <summary>�����, ����� ������� ������ ������ ��������</summary>
	/// <param name="oPhoneTypesArray">�����, � ����� �� �������� ����������� ������ ��������</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL LoadAllPhoneTypes(CPhoneTypesArray& oPhoneTypesArray);

	/// <summary>�����, ����� ����� ��� ������� �� �������� �������������</summary>
	/// <param name="lID">�������� �������������</param>
	/// <param name="recPhoneType">�����, � ����� �� ������� ������������ �� ���������� ��� �������</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL LoadPhoneType(const long lID, PHONE_TYPES& recPhoneType);

	/// <summary>�����, ����� ������� ��� ������� �� �������� �������������</summary>
	/// <param name="lID">�������� �������������</param>
	/// <param name="recPhoneType">�����, ����� ������� ������� �� ������� �� ��� �������</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL Update(const long lID, const PHONE_TYPES& recPhoneType);

	/// <summary>�����, ����� ������� ��� ��� ������� � ������ �����</summary>
	/// <param name="recPhoneType">�����, ����� ������� ���������� �� �������� �� ��� �������</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL Insert(PHONE_TYPES& recPhoneType);

	/// <summary>�����, ����� ������� ��� ������� �� �������� �������������</summary>
	/// <param name="lID">�������� �������������</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL Delete(const long lID);

// Overrides
// ----------------


// Members
// ----------------
};