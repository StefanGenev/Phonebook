#pragma once
#include "CitiesDlg.h"

/// <summary>
/// Клас за диалог за четене на информация за град
/// </summary>
class CCitiesReadOnlyDlg : public CCitiesDlg
{
// Constants
// ----------------

// Constructor / Destructor
// ----------------
public:
	CCitiesReadOnlyDlg(CITIES& recCity);
	virtual ~CCitiesReadOnlyDlg();

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