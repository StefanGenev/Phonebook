#pragma once

/// <summary>
/// ���� �� �������� �� ������ � ���� �����
/// </summary>
class CDataSourceProvider 
{

// Constants
// ----------------
private:
	/// <summary>������ ��������, ����� ��������� ���� � ��������� ��������� �� ���� ����</summary>
	static bool _bIsInstantiated;

	/// <summary>���������(����������) �� CDataSourceProvider</summary>
	static CDataSourceProvider _oDataSourceProvider;

// Constructor / Destructor
// ----------------

// Methods
// ----------------
public:
	/// <summary>������� ������� ��������� �� ������</summary>
	static CDataSourceProvider& GetInstance();

	/// <summary>������� �������� ������ � ���� �����</summary>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL OpenDataSource();
	
	/// <summary>������� ������� ������ � ���� �����</summary>
	///<returns> ��������� ����� ���������� ��� CDataSource �����</returns>
	CDataSource& GetDataSource();

// Overrides
// ----------------

// Members
// ----------------
private:
	/// <summary>���� �����</summary>
	CDataSource m_oDataSource;
	
};