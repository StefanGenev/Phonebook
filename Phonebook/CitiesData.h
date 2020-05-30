#pragma once
#include "Structures.h"
#include "CitiesTable.h"
#include "DataSourceProvider.h"

/// <summary>
/// Клас за бизнес логика табличен обект CCitiesTable
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
	/// <summary>Метод, който извлича всички градове</summary>
	/// <param name="oCitiesArray">Масив, в който се попълват извлечените градове</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL LoadAllCities(CCitiesArray& oCitiesArray);

	/// <summary>Метод, който взема град по уникален идентификатор</summary>
	/// <param name="lID">Уникален идентификатор</param>
	/// <param name="recCity">Запис, в който се попълва информацията на намереният град</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL LoadCity(const long lID, CITIES& recCity);

	/// <summary>Метод, който променя град по уникален идентификатор</summary>
	/// <param name="lID">Уникален идентификатор</param>
	/// <param name="recCity">Запис, който съдържа промени за промяна на град</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL Update(const long lID, const CITIES& recCity);

	/// <summary>Метод, който записва нов град в базата данни</summary>
	/// <param name="recCity">Запис, който съдържа информация за добавяне на град</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL Insert(CITIES& recCity);

	/// <summary>Метод, който изтрива град по уникален идентификатор</summary>
	/// <param name="lID">Уникален идентификатор</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL Delete(const long lID);

// Overrides
// ----------------

// Members
// ----------------
};