
#pragma once
#include "Structures.h"
#include "PersonsData.h"
#include "Person.h"


/// <summary>
/// Клас за документ на абонати и техните телефонни номера
/// </summary>
class CPersonsDocument : public CDocument
{
	DECLARE_DYNCREATE(CPersonsDocument)

// Constants
// ----------------

// Constructor / Destructor
// ----------------
public:
	CPersonsDocument();
	virtual ~CPersonsDocument();

// Methods
// ----------------
public:
	/// <summary>Метод, който връща масив с всички абонати</summary>
	///<returns> Функцията връща референция самозачистващ се масив, съдържащ указатели към всички абонати</returns>
	const CPersonsViewDataArray& GetAllPersons();

	/// <summary>Метод, който връща мап с всички градове</summary>
	///<returns> Функцията връща референция към самозачистващ се масив, съдържащ указатели към всички градове</returns>
	const CCitiesMap& GetAllCities();

	/// <summary>Метод, който връща мап с всички типове телефони</summary>
	///<returns> Функцията връща референция към самозачистващ се масив, съдържащ указатели към всички типове телефони</returns>
	const CPhoneTypesMap& GetAllPhoneTypes();

	/// <summary>Метод, който извлича  по негов идентификатор </summary>
	/// <param name="lID">Уникален идентификатор</param>
	/// <param name="oPerson">Обект, в който се попълва информацията на намереният абонат и неговите телефонни номера</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL LoadPerson(const long lID, CPerson& oPerson);

	/// <summary>Метод, който предава данни за нов абонат и неговите телефонни номера </summary>
	/// <param name="oPerson">Обект съдържащ параметри на абонат и неговите телефонни номера</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL Insert(CPerson& oPerson);

	/// <summary>Метод, който променя абонат и неговите телефонни номера </summary>
	/// <param name="lID">Уникален идентификатор</param>
	/// <param name="oPerson">Обект съдържащ параметри на абонат и неговите телефонни номера</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL Update(const long lID, const CPerson& oPerson);

	/// <summary>Метод, който изтрива абонат и неговите телефонни номера </summary>
	/// <param name="lID">Уникален идентификатор</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL Delete(const long lID);

private:
	/// <summary>Метод, който намира индекс на запис в масива по идентификатор</summary>
	/// <param name="lID">Уникален идентификатор</param>
	///<returns> Функцията връща индекс на указател сочещ запис с подаден идентификатор или -1 ако няма такъв</returns>
	int FindRecord(const long lID);

	/// <summary>Метод, който намира името на град по идентификатор</summary>
	/// <param name="lID">Уникален идентификатор</param>
	/// <param name="strCity">Променлива, в която се записва името на град</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL FindCity(const long lID, CString& strCity);

// Overrides
// ----------------
private:
	/// <summary>Метод за създаване на нов документ</summary>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	virtual BOOL OnNewDocument();

// Members
// ----------------
private:
	/// <summary>Обект, който поддържа подадени съобщения</summary>
	DECLARE_MESSAGE_MAP()

	/// <summary>Масив съдържащ записи на абонати</summary>
	CPersonsViewDataArray m_oPersonsViewDataArray;

	/// <summary>Обект предаващ и извличащ информация от базата данни съдържащ бизнес логика</summary>
	CPersonsData m_oPersonsData;

	/// <summary>Мап съдържащ записи на градове</summary>
	CCitiesMap m_oCitiesMap;

	/// <summary>Мап съдържащ записи на телефонни типове</summary>
	CPhoneTypesMap m_oPhoneTypesMap;
};
