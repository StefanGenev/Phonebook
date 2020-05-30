#pragma once
#include "PhoneTypesDlg.h"

/// <summary>
/// Клас за диалог за четене на информация за тип телефон
/// </summary>
class CPhoneTypesReadOnlyDlg : public CPhoneTypesDlg
{
// Constants
// ----------------

// Constructor / Destructor
// ----------------
public:
	CPhoneTypesReadOnlyDlg(PHONE_TYPES& recPhoneType);
	virtual ~CPhoneTypesReadOnlyDlg();

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

// Members
// ----------------
};