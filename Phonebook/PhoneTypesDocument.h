#pragma once
#include "Structures.h"
#include "PhoneTypesData.h"

/// <summary>
/// Клас за документ на типове телефони
/// </summary>
class CPhoneTypesDocument : public CDocument
{
	DECLARE_DYNCREATE(CPhoneTypesDocument)

// Constants
// ----------------

// Constructor / Destructor
// ----------------
public:
	CPhoneTypesDocument();
	virtual ~CPhoneTypesDocument();


// Methods
// ----------------
public:
	/// <summary>Метод, който връща масив с всички типове телефони</summary>
	///<returns> Функцията връща самозачистващ се масив, съдържащ указатели към всички типове телефони</returns>
	const CPhoneTypesArray& GetAllPhoneTypes();

	/// <summary>Метод, който извлича тип телефон по негов идентификатор </summary>
	/// <param name="lID">Уникален идентификатор</param>
	/// <param name="recPhoneType">Запис, в който се попълва информацията на намереният тип телефон</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL LoadPhoneType(const long lID, PHONE_TYPES& recPhoneType);

	/// <summary>Метод, който предава данни за нов тип телефон </summary>
	/// <param name="recPhoneType">Запис съдържащ параметри на тип телефон</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL Insert(PHONE_TYPES& recPhoneType);

	/// <summary>Метод, който променя тип телефон </summary>
	/// <param name="lID">Уникален идентификатор</param>
	/// <param name="recPhoneType">Запис съдържащ параметри на тип телефон</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL Update(const long lID, const PHONE_TYPES& recPhoneType);

	/// <summary>Метод, който изтрива тип телефон </summary>
	/// <param name="lID">Уникален идентификатор</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL Delete(const long lID);

private:
	/// <summary>Метод, който намира индекс на запис в масива по идентификатор</summary>
	/// <param name="lID">Уникален идентификатор</param>
	///<returns> Функцията връща индекс на указател сочещ запис с подаден идентификатор или -1 ако няма такъв</returns>
	int FindRecord(const long lID);

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

	/// <summary>Масив съдържащ записи на типове телефони</summary>
	CPhoneTypesArray m_oPhoneTypesArray;

	/// <summary>Обект предаващ и извличащ информация от базата данни съдържащ бизнес логика</summary>
	CPhoneTypesData m_oPhoneTypesData;
};