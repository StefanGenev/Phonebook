#pragma once
#include "PersonsDlg.h"

/// <summary>
/// Клас за диалог за четене на информация за град
/// </summary>
class CPersonsReadOnlyDlg : public CPersonsDlg
{
// Constants
// ----------------

// Constructor / Destructor
// ----------------
public:
	CPersonsReadOnlyDlg(CPerson& oPerson, const CCitiesMap& oCitiesMap, const CPhoneTypesMap& oPhoneTypesMap);
	virtual ~CPersonsReadOnlyDlg();

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

	/// <summary>Метод, променящ състоянието на бутоните от контекстното меню, изпълняващ се точно преди излизането на менюто</summary>
	afx_msg virtual void OnUpdateBtnPopup(CCmdUI* pCmdUI);

	/// <summary>Метод, който попълва комбо бокс cmbCity с подадени градове</summary>
	virtual void FillCities();

// Members
// ----------------
};