#pragma once
#include "PhoneNumbersDlg.h"
#include "PhoneNumbersViewData.h"

/// <summary>
/// Клас за диалог за четене на информация за телефонен номер
/// </summary>
class CPhoneNumbersReadOnlyDlg : public CPhoneNumbersDlg
{
// Constants
// ----------------

// Constructor / Destructor
// ----------------
public:
	CPhoneNumbersReadOnlyDlg(PHONE_NUMBERS_VIEW_DATA& recPhoneNumberViewData, const CPhoneTypesMap& oPhoneTypesMap);
	virtual ~CPhoneNumbersReadOnlyDlg();

// Methods
// ----------------

// Overrides
// ----------------
private:
	/// <summary>Метод, който се изпълнява при инициализация на диалог</summary>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	virtual BOOL OnInitDialog();

	/// <summary>Метод, който се изпълнява при натискането на бутона OK</summary>
	virtual void OnOK();

	/// <summary>Метод, запълва комбо бокс с типове телефони</summary>
	virtual void FillPhoneTypes();

// Members
// ----------------

};