#pragma once
#include "Structures.h"
#include "PersonsTable.h"
#include "PhoneNumbersTable.h"
#include "CitiesTable.h"
#include "DataSourceProvider.h"
#include "PersonsViewData.h"
#include "Person.h"

/// <summary>
/// Клас за бизнес логика с абонати и техните данни
/// </summary>
class CPersonsData
{

// Constants
// ----------------

// Constructor / Destructor
// ----------------
public:
	CPersonsData();
	virtual ~CPersonsData();

// Methods
// ----------------
public:
	/// <summary>Метод, който извлича всички абонати</summary>
	/// <param name="oPersonsViewDataArray">Масив, в който се попълват извлечените абонати</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL LoadAllPersons(CPersonsViewDataArray& oPersonsViewDataArray);

	/// <summary>Метод, който извлича всички градове</summary>
	/// <param name="oCitiesMap">Мап, в който се попълват извлечените градове</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL LoadAllCities(CCitiesMap& oCitiesMap);

	/// <summary>Метод, който извлича всички типове телефони</summary>
	/// <param name="oPhoneTypesMap">Мап, в който се попълват извлечените типове телефони</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL LoadAllPhoneTypes(CPhoneTypesMap& oPhoneTypesMap);

	/// <summary>Метод, който взема абонат и неговите телефонни номера по уникален идентификатор</summary>
	/// <param name="lID">Уникален идентификатор</param>
	/// <param name="oPerson">Обект, в който се попълва информацията на намереният абонат и неговите телефонни номера</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL LoadPerson(const long lID, CPerson& oPerson);

	/// <summary>Метод, който променя абонат и неговите телефонни номера по уникален идентификатор</summary>
	/// <param name="lID">Уникален идентификатор</param>
	/// <param name="oPerson">Обект, който съдържа информация за промяна на абонат и неговите телефонни номера</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL Update(const long lID, const CPerson& oPerson);

	/// <summary>Метод, който записва нов абонат и неговите телефонни номера в базата данни</summary>
	/// <param name="oPerson">Обект, който съдържа информация за добавяне на абонат и неговите телефонни номера</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL Insert(CPerson& oPerson);

	/// <summary>Метод, който изтрива абонат и неговите телефонни номера по уникален идентификатор</summary>
	/// <param name="lID">Уникален идентификатор</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL Delete(const long lID);

private:
	/// <summary>Метод, който извлича град по идентификатор от базата данни</summary>
	/// <param name="lID">Уникален идентификатор</param>
	/// <param name="recCity">Запис, в който се записва информация на град</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL LoadCity(const long lID, CITIES& recCity);

	/// <summary>Метод, който пълни масив с абонати и градовете, в които живеят</summary>
	/// <param name="oPersonsArray">Масив с всички абонати</param>
	/// <param name="oPersonsViewDataArray">Масив за записване на абонати с градовете, в които живеят</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL GetPersonsWithCities(const CPersonsArray& oPersonsArray, CPersonsViewDataArray& oPersonsViewDataArray);

	/// <summary>Метод, който създава нови записи на телефонни номера в базата данни</summary>
	/// <param name="lPersonID">Уникален идентификатор на абонат</param>
	/// <param name="oPhoneNumbersArray">Масив съдържащ записи на телефонни номера</param>
	/// <param name="oDatabaseSession">Сесия</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL InsertPhoneNumbers(const long lID, CPhoneNumbersArray& oPhoneNumbersArray, CDatabaseSession& oDatabaseSession);

	/// <summary>Метод, който изтрива всички телефонни номера на абонат</summary>
	/// <param name="lPersonID">Уникален идентификатор на абонат</param>
	/// <param name="oDatabaseSession">Сесия</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL DeletePhoneNumbers(const long lPersonID, CDatabaseSession& oDatabaseSession);

// Overrides
// ----------------

// Members
// ----------------
};