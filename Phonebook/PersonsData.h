#pragma once
#include "Structures.h"
#include "PersonsTable.h"
#include "PhoneNumbersTable.h"
#include "CitiesTable.h"
#include "DataSourceProvider.h"
#include "PersonsViewData.h"
#include "Person.h"

/// <summary>
/// ���� �� ������ ������ � ������� � ������� �����
/// </summary>
class CPersonsData
{

// Constants
// ----------------

// Constructor / Destructor
// ----------------
public:
	CPersonsData();
	virtual ~CPersonsData();

// Methods
// ----------------
public:
	/// <summary>�����, ����� ������� ������ �������</summary>
	/// <param name="oPersonsViewDataArray">�����, � ����� �� �������� ����������� �������</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL LoadAllPersons(CPersonsViewDataArray& oPersonsViewDataArray);

	/// <summary>�����, ����� ������� ������ �������</summary>
	/// <param name="oCitiesMap">���, � ����� �� �������� ����������� �������</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL LoadAllCities(CCitiesMap& oCitiesMap);

	/// <summary>�����, ����� ������� ������ ������ ��������</summary>
	/// <param name="oPhoneTypesMap">���, � ����� �� �������� ����������� ������ ��������</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL LoadAllPhoneTypes(CPhoneTypesMap& oPhoneTypesMap);

	/// <summary>�����, ����� ����� ������ � �������� ��������� ������ �� �������� �������������</summary>
	/// <param name="lID">�������� �������������</param>
	/// <param name="oPerson">�����, � ����� �� ������� ������������ �� ���������� ������ � �������� ��������� ������</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL LoadPerson(const long lID, CPerson& oPerson);

	/// <summary>�����, ����� ������� ������ � �������� ��������� ������ �� �������� �������������</summary>
	/// <param name="lID">�������� �������������</param>
	/// <param name="oPerson">�����, ����� ������� ���������� �� ������� �� ������ � �������� ��������� ������</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL Update(const long lID, const CPerson& oPerson);

	/// <summary>�����, ����� ������� ��� ������ � �������� ��������� ������ � ������ �����</summary>
	/// <param name="oPerson">�����, ����� ������� ���������� �� �������� �� ������ � �������� ��������� ������</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL Insert(CPerson& oPerson);

	/// <summary>�����, ����� ������� ������ � �������� ��������� ������ �� �������� �������������</summary>
	/// <param name="lID">�������� �������������</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL Delete(const long lID);

private:
	/// <summary>�����, ����� ������� ���� �� ������������� �� ������ �����</summary>
	/// <param name="lID">�������� �������������</param>
	/// <param name="recCity">�����, � ����� �� ������� ���������� �� ����</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL LoadCity(const long lID, CITIES& recCity);

	/// <summary>�����, ����� ����� ����� � ������� � ���������, � ����� ������</summary>
	/// <param name="oPersonsArray">����� � ������ �������</param>
	/// <param name="oPersonsViewDataArray">����� �� ��������� �� ������� � ���������, � ����� ������</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL GetPersonsWithCities(const CPersonsArray& oPersonsArray, CPersonsViewDataArray& oPersonsViewDataArray);

	/// <summary>�����, ����� ������� ���� ������ �� ��������� ������ � ������ �����</summary>
	/// <param name="lPersonID">�������� ������������� �� ������</param>
	/// <param name="oPhoneNumbersArray">����� �������� ������ �� ��������� ������</param>
	/// <param name="oDatabaseSession">�����</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL InsertPhoneNumbers(const long lID, CPhoneNumbersArray& oPhoneNumbersArray, CDatabaseSession& oDatabaseSession);

	/// <summary>�����, ����� ������� ������ ��������� ������ �� ������</summary>
	/// <param name="lPersonID">�������� ������������� �� ������</param>
	/// <param name="oDatabaseSession">�����</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL DeletePhoneNumbers(const long lPersonID, CDatabaseSession& oDatabaseSession);

// Overrides
// ----------------

// Members
// ----------------
};