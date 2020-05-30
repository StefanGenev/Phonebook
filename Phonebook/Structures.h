#pragma once
#include <tchar.h>
#include <WinBase.h>
#include <afxwin.h>
#include <afxwin.h>
#include "AutoClearPtrArray.h"
#include "AutoClearPtrMap.h"

#define PERSONS_FIRST_NAME_LENGTH 64
#define PERSONS_MIDDLE_NAME_LENGTH 64
#define PERSONS_LAST_NAME_LENGTH 64
#define PERSONS_UCN_LENGTH 16
#define PERSONS_ADDRESS_LENGTH 128
#define PHONE_NUMBERS_PHONE_NUMBER_LENGTH 16
#define PHONE_TYPES_TYPE_LENGTH 64
#define CITIES_NAME_LENGTH 64
#define CITIES_REGION_LENGTH 64

/// <summary>
/// Структура с абонати и тяхната информация
/// </summary>
struct PERSONS
{
	/// <summary>Уникален идентификатор</summary>
	long lID;

	/// <summary>Брояч на промени</summary>
	long lUpdateCounter;

	/// <summary>Име</summary>
	TCHAR szFirstName[PERSONS_FIRST_NAME_LENGTH];

	/// <summary>Презиме</summary>
	TCHAR szMiddleName[PERSONS_MIDDLE_NAME_LENGTH];

	/// <summary>Фамилия</summary>
	TCHAR szLastName[PERSONS_LAST_NAME_LENGTH];

	/// <summary>ЕГН</summary>
	TCHAR szUCN[PERSONS_UCN_LENGTH];

	/// <summary>Идентификатор на град</summary>
	long lCityID;

	/// <summary>Адрес</summary>
	TCHAR szAddress[PERSONS_ADDRESS_LENGTH];

	/// <summary>Конструктор на структура с абонати</summary>
	PERSONS()
	{
		SecureZeroMemory(this, sizeof(*this));
	}

};

typedef CAutoClearPtrArray<PERSONS> CPersonsArray;


/// <summary>
/// Структура с телефонни номера на абонати
/// </summary>
struct PHONE_NUMBERS
{
	/// <summary>Уникален идентификатор</summary>
	long lID;

	/// <summary>Брояч на промени</summary>
	long lUpdateCounter;

	/// <summary>Идентификатор на абонат</summary>
	long lPersonID;

	/// <summary>Идентификатор на тип телефон</summary>
	long lPhoneTypeID;

	/// <summary>Телефонен номер</summary>
	TCHAR szPhoneNumber[PHONE_NUMBERS_PHONE_NUMBER_LENGTH];

	/// <summary>Конструктор на структура с телефонни номера</summary>
	PHONE_NUMBERS()
	{
		SecureZeroMemory(this, sizeof(*this));
	}

};

typedef CAutoClearPtrArray<PHONE_NUMBERS> CPhoneNumbersArray;

/// <summary>
/// Структура с типове телефони
/// </summary>
struct PHONE_TYPES
{
	/// <summary>Уникален идентификатор</summary>
	long lID;

	/// <summary>Брояч на промени</summary>
	long lUpdateCounter;

	/// <summary>Тип на телефон</summary>
	TCHAR szType[PHONE_TYPES_TYPE_LENGTH];

	/// <summary>Конструктор на структура с типове телефони</summary>
	PHONE_TYPES()
	{
		SecureZeroMemory(this, sizeof(*this));
	}

};

typedef CAutoClearPtrArray<PHONE_TYPES> CPhoneTypesArray;
typedef CAutoClearPtrMap<long, long, PHONE_TYPES, PHONE_TYPES> CPhoneTypesMap;

/// <summary>
/// Структура с градове
/// </summary>
struct CITIES
{
	/// <summary>Уникален идентификатор</summary>
	long lID;

	/// <summary>Брояч на промени</summary>
	long lUpdateCounter;

	/// <summary>Име на град</summary>
	TCHAR szName[CITIES_NAME_LENGTH];

	/// <summary>Област</summary>
	TCHAR szRegion[CITIES_REGION_LENGTH];

	/// <summary>Конструктор на структура с градове</summary>
	CITIES()
	{
		SecureZeroMemory(this, sizeof(*this));
	}

};

typedef CAutoClearPtrArray<CITIES> CCitiesArray;
typedef CAutoClearPtrMap<long, long, CITIES, CITIES> CCitiesMap;


