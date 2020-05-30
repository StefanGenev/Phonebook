
// CitiesDoc.h : interface of the CCitiesDoc class
//

#pragma once
#include "Structures.h"
#include "CitiesData.h"


/// <summary>
/// Клас за документ на градове
/// </summary>
class CCitiesDocument : public CDocument
{
	DECLARE_DYNCREATE(CCitiesDocument)

// Constants
// ----------------

// Constructor / Destructor
// ----------------
public:
	CCitiesDocument();
	virtual ~CCitiesDocument();

// Methods
// ----------------
public:
	/// <summary>Метод, който връща масив с всички градове</summary>
	///<returns> Функцията връща самозачистващ се масив, съдържащ указатели към всички градове</returns>
	const CCitiesArray& GetAllCities();

	/// <summary>Метод, който извлича град по негов идентификатор </summary>
	/// <param name="lID">Уникален идентификатор</param>
	/// <param name="recCity">Запис, в който се попълва информацията на намереният град</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL LoadCity(const long lID, CITIES& recCity);

	/// <summary>Метод, който предава данни за нов град </summary>
	/// <param name="recCity">Запис съдържащ параметри на град</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL Insert(CITIES& recCity);

	/// <summary>Метод, който променя град </summary>
	/// <param name="lID">Уникален идентификатор</param>
	/// <param name="recCity">Запис съдържащ параметри на град</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL Update(const long lID, const CITIES& recCity);

	/// <summary>Метод, който изтрива град </summary>
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

	/// <summary>Масив съдържащ записи на градове</summary>
	CCitiesArray m_oCitiesArray;

	/// <summary>Обект предаващ и извличащ информация от базата данни съдържащ бизнес логика</summary>
	CCitiesData m_oCitiesData;
};
