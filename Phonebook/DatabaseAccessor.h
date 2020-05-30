#pragma once

/// <summary>
/// Клас за достъпване на колони на таблици
/// </summary>
template<class TABLE>
class CDatabaseAccessor
{

// Constants
// ----------------
public:
	/// <summary>Номер на аксесор достъпващ идентификатора</summary>
	static const int _nIdentityAccessor = 0;

	/// <summary>Номер на аксесор достъпващ всички колони освен идентификатора</summary>
	static const int _nDataAccessor = 1;

protected:
	/// <summary>Брой на аксесори</summary>
	static const int _nNumberOfAccessors = 2;

	/// <summary>Номер на аксесор достъпващ идентификатора</summary>
	static const int _nIdentityAccessorIDColumnNumber = 1;

	/// <summary>Номер на аксесор достъпващ всички колони освен идентификатора</summary>
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
	/// <summary>Променлива, в която се записват стойности след/за достъп до базата данни</summary>
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
