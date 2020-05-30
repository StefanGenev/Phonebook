#pragma once

/// <summary>
/// ���� �� ���������� �� ������ �� �������
/// </summary>
template<class TABLE>
class CDatabaseAccessor
{

// Constants
// ----------------
public:
	/// <summary>����� �� ������� ��������� ��������������</summary>
	static const int _nIdentityAccessor = 0;

	/// <summary>����� �� ������� ��������� ������ ������ ����� ��������������</summary>
	static const int _nDataAccessor = 1;

protected:
	/// <summary>���� �� ��������</summary>
	static const int _nNumberOfAccessors = 2;

	/// <summary>����� �� ������� ��������� ��������������</summary>
	static const int _nIdentityAccessorIDColumnNumber = 1;

	/// <summary>����� �� ������� ��������� ������ ������ ����� ��������������</summary>
	static const int _nDataAccessorUpdateCounterColumnNumber = 2;

// Constructor / Destructor
// ----------------

public:
	CDatabaseAccessor();
	virtual ~CDatabaseAccessor();


// Methods
// ----------------

// Overrides
// ----------------


// Members
// ----------------
	/// <summary>����������, � ����� �� �������� ��������� ����/�� ������ �� ������ �����</summary>
	TABLE m_recDatabaseRecord;
};

template<class TABLE>
inline CDatabaseAccessor<TABLE>::CDatabaseAccessor()
{
}

template<class TABLE>
inline CDatabaseAccessor<TABLE>::~CDatabaseAccessor()
{
}
