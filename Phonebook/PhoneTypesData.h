#pragma once
#include "Structures.h"
#include "PhoneTypesTable.h"
#include "DataSourceProvider.h"

/// <summary>
/// Клас за бизнес логика с табличен обект CPhoneTypesTable
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
	/// <summary>Метод, който извлича всички типове телефони</summary>
	/// <param name="oPhoneTypesArray">Масив, в който се попълват извлечените типове телефони</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL LoadAllPhoneTypes(CPhoneTypesArray& oPhoneTypesArray);

	/// <summary>Метод, който взема тип телефон по уникален идентификатор</summary>
	/// <param name="lID">Уникален идентификатор</param>
	/// <param name="recPhoneType">Запис, в който се попълва информацията на намереният тип телефон</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL LoadPhoneType(const long lID, PHONE_TYPES& recPhoneType);

	/// <summary>Метод, който променя тип телефон по уникален идентификатор</summary>
	/// <param name="lID">Уникален идентификатор</param>
	/// <param name="recPhoneType">Запис, който съдържа промени за промяна на тип телефон</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL Update(const long lID, const PHONE_TYPES& recPhoneType);

	/// <summary>Метод, който записва нов тип телефон в базата данни</summary>
	/// <param name="recPhoneType">Запис, който съдържа информация за добавяне на тип телефон</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL Insert(PHONE_TYPES& recPhoneType);

	/// <summary>Метод, който изтрива тип телефон по уникален идентификатор</summary>
	/// <param name="lID">Уникален идентификатор</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL Delete(const long lID);

// Overrides
// ----------------


// Members
// ----------------
};