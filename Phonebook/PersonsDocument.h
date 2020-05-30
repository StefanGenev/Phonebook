
#pragma once
#include "Structures.h"
#include "PersonsData.h"
#include "Person.h"


/// <summary>
/// ���� �� �������� �� ������� � ������� ��������� ������
/// </summary>
class CPersonsDocument : public CDocument
{
	DECLARE_DYNCREATE(CPersonsDocument)

// Constants
// ----------------

// Constructor / Destructor
// ----------------
public:
	CPersonsDocument();
	virtual ~CPersonsDocument();

// Methods
// ----------------
public:
	/// <summary>�����, ����� ����� ����� � ������ �������</summary>
	///<returns> ��������� ����� ���������� ������������� �� �����, �������� ��������� ��� ������ �������</returns>
	const CPersonsViewDataArray& GetAllPersons();

	/// <summary>�����, ����� ����� ��� � ������ �������</summary>
	///<returns> ��������� ����� ���������� ��� ������������� �� �����, �������� ��������� ��� ������ �������</returns>
	const CCitiesMap& GetAllCities();

	/// <summary>�����, ����� ����� ��� � ������ ������ ��������</summary>
	///<returns> ��������� ����� ���������� ��� ������������� �� �����, �������� ��������� ��� ������ ������ ��������</returns>
	const CPhoneTypesMap& GetAllPhoneTypes();

	/// <summary>�����, ����� �������  �� ����� ������������� </summary>
	/// <param name="lID">�������� �������������</param>
	/// <param name="oPerson">�����, � ����� �� ������� ������������ �� ���������� ������ � �������� ��������� ������</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL LoadPerson(const long lID, CPerson& oPerson);

	/// <summary>�����, ����� ������� ����� �� ��� ������ � �������� ��������� ������ </summary>
	/// <param name="oPerson">����� �������� ��������� �� ������ � �������� ��������� ������</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL Insert(CPerson& oPerson);

	/// <summary>�����, ����� ������� ������ � �������� ��������� ������ </summary>
	/// <param name="lID">�������� �������������</param>
	/// <param name="oPerson">����� �������� ��������� �� ������ � �������� ��������� ������</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL Update(const long lID, const CPerson& oPerson);

	/// <summary>�����, ����� ������� ������ � �������� ��������� ������ </summary>
	/// <param name="lID">�������� �������������</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL Delete(const long lID);

private:
	/// <summary>�����, ����� ������ ������ �� ����� � ������ �� �������������</summary>
	/// <param name="lID">�������� �������������</param>
	///<returns> ��������� ����� ������ �� �������� ����� ����� � ������� ������������� ��� -1 ��� ���� �����</returns>
	int FindRecord(const long lID);

	/// <summary>�����, ����� ������ ����� �� ���� �� �������������</summary>
	/// <param name="lID">�������� �������������</param>
	/// <param name="strCity">����������, � ����� �� ������� ����� �� ����</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL FindCity(const long lID, CString& strCity);

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

	/// <summary>����� �������� ������ �� �������</summary>
	CPersonsViewDataArray m_oPersonsViewDataArray;

	/// <summary>����� �������� � �������� ���������� �� ������ ����� �������� ������ ������</summary>
	CPersonsData m_oPersonsData;

	/// <summary>��� �������� ������ �� �������</summary>
	CCitiesMap m_oCitiesMap;

	/// <summary>��� �������� ������ �� ��������� ������</summary>
	CPhoneTypesMap m_oPhoneTypesMap;
};
