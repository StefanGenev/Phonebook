#pragma once
#include "stdafx.h"

/// <summary>
/// Клас за валидация на данни от edit box
/// </summary>
class CValidator
{

// Constants
// ----------------
public:
	/// <summary>Enum с видове едит боксове спрямо данните, които съдържат</summary>
	enum EdbTypes
	{
		EdbTypeNames = 0,
		EdbTypeUCN = 1,
		EdbTypeAddress = 2,
		EdbTypePhoneNumber = 3
	};
	
private:
	/// <summary>Валидни символи за имена</summary>
	static const CString _strNamesValidSymbols;

	/// <summary>Валидни символи за ЕГН</summary>
	static const CString _strUCNValidSymbols;

	/// <summary>Валидни символи за адреси</summary>
	static const CString _strAddressValidSymbols;

	/// <summary>Валидни символи за телефонен номер</summary>
	static const CString _strPhoneNumberValidSymbols;

	/// <summary>Дължина на ЕГН</summary>
	static const int _nUCNLength;

	/// <summary>Минимална дължина на телефонен номер</summary>
	static const int _nPhoneNumberMinimumLength;

// Constructor / Destructor
// ----------------
public:
	CValidator();
	virtual ~CValidator();


// Methods
// ----------------

public:
	/// <summary>Метод, който валидира поле</summary>
	/// <param name="strValue">Стрингова стойност, която бива проверена за валидност</param>
	/// <param name="strFieldName">Име на полето, което бива валидирано</param>
	/// <param name="eEdbTypes">Вид на данни, които съдържа едит контролата</param>
	/// <param name="bIsValid">Булева стойност, която посочва дали данните са валидни</param>
	/// <param name="strMessage">Съобщение за неточности на невалидни данни</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	static BOOL ValidateField(const CString& strValue, const CString& strFieldName, const EdbTypes& eEdbTypes, bool& bIsValid, CString& strMessage);

private:
	/// <summary>Метод, който валидира имена</summary>
	/// <param name="strValue">Стрингова стойност, която бива проверена за валидност</param>
	/// <param name="strFieldName">Име на полето, което бива валидирано</param>
	///<returns> Функцията връща стринг с информация за неверни стоиности и празен стринг при напълно валидни данни</returns>
	static CString ValidateName(const CString& strValue, const CString& strFieldName);

	/// <summary>Метод, който валидира  ЕГН</summary>
	/// <param name="strValue">Стрингова стойност, която бива проверена за валидност</param>
	/// <param name="strFieldName">Име на полето, което бива валидирано</param>
	///<returns> Функцията връща стринг с информация за неверни стоиности и празен стринг при напълно валидни данни</returns>
	static CString ValidateUCN(const CString& strValue, const CString& strFieldName);

	/// <summary>Метод, който валидира адреси</summary>
	/// <param name="strValue">Стрингова стойност, която бива проверена за валидност</param>
	/// <param name="strFieldName">Име на полето, което бива валидирано</param>
	///<returns> Функцията връща стринг с информация за неверни стоиности и празен стринг при напълно валидни данни</returns>
	static CString ValidateAddress(const CString& strValue, const CString& strFieldName);

	/// <summary>Метод, който валидира телефонни номера</summary>
	/// <param name="strValue">Стрингова стойност, която бива проверена за валидност</param>
	/// <param name="strFieldName">Име на полето, което бива валидирано</param>
	///<returns> Функцията връща стринг с информация за неверни стоиности и празен стринг при напълно валидни данни</returns>
	static CString ValidatePhoneNumber(const CString& strValue, const CString& strFieldName);

// Overrides
// ----------------

// Members
// ----------------

};