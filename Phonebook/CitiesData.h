#pragma once
#include "Structures.h"
#include "CitiesTable.h"
#include "DataSourceProvider.h"

/// <summary>
/// ���� �� ������ ������ �������� ����� CCitiesTable
/// </summary>
class CCitiesData
{

// Constants
// ----------------

// Constructor / Destructor
// ----------------
public:
	CCitiesData();
	virtual ~CCitiesData();

// Methods
// ----------------
public:
	/// <summary>�����, ����� ������� ������ �������</summary>
	/// <param name="oCitiesArray">�����, � ����� �� �������� ����������� �������</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL LoadAllCities(CCitiesArray& oCitiesArray);

	/// <summary>�����, ����� ����� ���� �� �������� �������������</summary>
	/// <param name="lID">�������� �������������</param>
	/// <param name="recCity">�����, � ����� �� ������� ������������ �� ���������� ����</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL LoadCity(const long lID, CITIES& recCity);

	/// <summary>�����, ����� ������� ���� �� �������� �������������</summary>
	/// <param name="lID">�������� �������������</param>
	/// <param name="recCity">�����, ����� ������� ������� �� ������� �� ����</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL Update(const long lID, const CITIES& recCity);

	/// <summary>�����, ����� ������� ��� ���� � ������ �����</summary>
	/// <param name="recCity">�����, ����� ������� ���������� �� �������� �� ����</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL Insert(CITIES& recCity);

	/// <summary>�����, ����� ������� ���� �� �������� �������������</summary>
	/// <param name="lID">�������� �������������</param>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL Delete(const long lID);

// Overrides
// ----------------

// Members
// ----------------
};