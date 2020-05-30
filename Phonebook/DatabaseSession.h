#pragma once
#include "stdafx.h"
#include "DataSourceProvider.h"

/// <summary>
/// Сесия, която отваря транзакция и се затваря в деструктор
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
	/// <summary>Функция отваряща сесия, ако не е отворена, и транзакция след това</summary>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL OpenTransaction();

	/// <summary>Функция записваща промени от транзакция</summary>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL CommitTransaction();

	/// <summary>Функция отваряща сесия</summary>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL OpenSession();

	/// <summary>Функция, която извършва rollback на отворената транзакция</summary>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	void AbortTransaction();

// Overrides
// ----------------
	
// Members
// ----------------
private:
	/// <summary>Булева стойност, която показва дали сесията е отворена</summary>
	bool m_bIsOpen;

	/// <summary>Булева стойност, която показва дали има отворена транзакция</summary>
	bool m_bTransactionIsOpen;
};