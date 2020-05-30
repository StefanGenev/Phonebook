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
/// ��������� � ������� � ������� ����������
/// </summary>
struct PERSONS
{
	/// <summary>�������� �������������</summary>
	long lID;

	/// <summary>����� �� �������</summary>
	long lUpdateCounter;

	/// <summary>���</summary>
	TCHAR szFirstName[PERSONS_FIRST_NAME_LENGTH];

	/// <summary>�������</summary>
	TCHAR szMiddleName[PERSONS_MIDDLE_NAME_LENGTH];

	/// <summary>�������</summary>
	TCHAR szLastName[PERSONS_LAST_NAME_LENGTH];

	/// <summary>���</summary>
	TCHAR szUCN[PERSONS_UCN_LENGTH];

	/// <summary>������������� �� ����</summary>
	long lCityID;

	/// <summary>�����</summary>
	TCHAR szAddress[PERSONS_ADDRESS_LENGTH];

	/// <summary>����������� �� ��������� � �������</summary>
	PERSONS()
	{
		SecureZeroMemory(this, sizeof(*this));
	}

};

typedef CAutoClearPtrArray<PERSONS> CPersonsArray;


/// <summary>
/// ��������� � ��������� ������ �� �������
/// </summary>
struct PHONE_NUMBERS
{
	/// <summary>�������� �������������</summary>
	long lID;

	/// <summary>����� �� �������</summary>
	long lUpdateCounter;

	/// <summary>������������� �� ������</summary>
	long lPersonID;

	/// <summary>������������� �� ��� �������</summary>
	long lPhoneTypeID;

	/// <summary>��������� �����</summary>
	TCHAR szPhoneNumber[PHONE_NUMBERS_PHONE_NUMBER_LENGTH];

	/// <summary>����������� �� ��������� � ��������� ������</summary>
	PHONE_NUMBERS()
	{
		SecureZeroMemory(this, sizeof(*this));
	}

};

typedef CAutoClearPtrArray<PHONE_NUMBERS> CPhoneNumbersArray;

/// <summary>
/// ��������� � ������ ��������
/// </summary>
struct PHONE_TYPES
{
	/// <summary>�������� �������������</summary>
	long lID;

	/// <summary>����� �� �������</summary>
	long lUpdateCounter;

	/// <summary>��� �� �������</summary>
	TCHAR szType[PHONE_TYPES_TYPE_LENGTH];

	/// <summary>����������� �� ��������� � ������ ��������</summary>
	PHONE_TYPES()
	{
		SecureZeroMemory(this, sizeof(*this));
	}

};

typedef CAutoClearPtrArray<PHONE_TYPES> CPhoneTypesArray;
typedef CAutoClearPtrMap<long, long, PHONE_TYPES, PHONE_TYPES> CPhoneTypesMap;

/// <summary>
/// ��������� � �������
/// </summary>
struct CITIES
{
	/// <summary>�������� �������������</summary>
	long lID;

	/// <summary>����� �� �������</summary>
	long lUpdateCounter;

	/// <summary>��� �� ����</summary>
	TCHAR szName[CITIES_NAME_LENGTH];

	/// <summary>������</summary>
	TCHAR szRegion[CITIES_REGION_LENGTH];

	/// <summary>����������� �� ��������� � �������</summary>
	CITIES()
	{
		SecureZeroMemory(this, sizeof(*this));
	}

};

typedef CAutoClearPtrArray<CITIES> CCitiesArray;
typedef CAutoClearPtrMap<long, long, CITIES, CITIES> CCitiesMap;


