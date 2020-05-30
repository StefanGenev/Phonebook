#pragma once
#include "stdafx.h"
#include "DataSourceProvider.h"

/// <summary>
/// �����, ����� ������ ���������� � �� ������� � ����������
/// </summary>
class CDatabaseSession : public CSession
{

// Constants
// ----------------

// Constructor / Destructor
// ----------------
public:
	CDatabaseSession();
	virtual ~CDatabaseSession();


// Methods
// ----------------
public:
	/// <summary>������� �������� �����, ��� �� � ��������, � ���������� ���� ����</summary>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL OpenTransaction();

	/// <summary>������� ��������� ������� �� ����������</summary>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL CommitTransaction();

	/// <summary>������� �������� �����</summary>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	BOOL OpenSession();

	/// <summary>�������, ����� �������� rollback �� ���������� ����������</summary>
	///<returns> ��������� ����� �������� TRUE ��� ����� � FALSE ��� ���������� ������</returns>
	void AbortTransaction();

// Overrides
// ----------------
	
// Members
// ----------------
private:
	/// <summary>������ ��������, ����� ������� ���� ������� � ��������</summary>
	bool m_bIsOpen;

	/// <summary>������ ��������, ����� ������� ���� ��� �������� ����������</summary>
	bool m_bTransactionIsOpen;
};