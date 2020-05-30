
// CitiesDoc.h : interface of the CCitiesDoc class
//

#pragma once
#include "Structures.h"
#include "CitiesData.h"


/// <summary>
/// ���� �� �������� �� �������
/// </summary>
class CCitiesDocument : public CDocument
{
	DECLARE_DYNCREATE(CCitiesDocument)

// Constants
// ----------------

// Constructor / Destructor
// ----------------
public:
	CCitiesDocument();
	virtual ~CCitiesDocument();

// Methods
// ----------------
public:
	/// <summary>�����, ����� ����� ����� � ������ �������</summary>
	///<returns> ��������� ����� ������������� �� �����, �������� ��������� ��� ������ �������</returns>
	const CCitiesArray& GetAllCities();

	/// <summary>�����, ����� ������� ���� �� ����� ������������� </summary>
	/// <param name="lID">�������� �������������</param>
	/// <param name="recCity">�����, � ����� �� ������� ������������ �� ���������� ����</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL LoadCity(const long lID, CITIES& recCity);

	/// <summary>�����, ����� ������� ����� �� ��� ���� </summary>
	/// <param name="recCity">����� �������� ��������� �� ����</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL Insert(CITIES& recCity);

	/// <summary>�����, ����� ������� ���� </summary>
	/// <param name="lID">�������� �������������</param>
	/// <param name="recCity">����� �������� ��������� �� ����</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL Update(const long lID, const CITIES& recCity);

	/// <summary>�����, ����� ������� ���� </summary>
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

	/// <summary>����� �������� ������ �� �������</summary>
	CCitiesArray m_oCitiesArray;

	/// <summary>����� �������� � �������� ���������� �� ������ ����� �������� ������ ������</summary>
	CCitiesData m_oCitiesData;
};
