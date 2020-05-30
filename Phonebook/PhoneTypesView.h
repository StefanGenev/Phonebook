#pragma once
#include "stdafx.h"
#include "Structures.h"
#include "PhoneTypesDocument.h"

/// <summary>
/// Клас за list view на типове телефони
/// </summary>
class CPhoneTypesView : public CListView
{
	DECLARE_DYNCREATE(CPhoneTypesView)

// Constants
// ----------------
	/// <summary>Enum с видове колони в Phone Types view</summary>
	enum Columns
	{
		ColumnType = 0
	};

	/// <summary>Име на колона за тип на телефонен номер</summary>
	static const CString _strTypeColumnCaption;

private:
	/// <summary>Широчина колона за тип на телефонен номер</summary>
	static const int _nTypeColumnWidth;

// Constructor / Destructor
// ----------------
public:
	CPhoneTypesView();
	virtual ~CPhoneTypesView();

// Methods
// ----------------
private:
	/// <summary>Метод, който добавя колони в лист контрола</summary>
	void BuildListCtrl();

	/// <summary>Метод, който попълва редове в лист контрола</summary>
	void FillListCtrl();

	/// <summary>Метод, който отваря диалог за редакция на запис и предава променените данни към документа</summary>
	void EditRecord();

	/// <summary>Метод, който отваря диалог за създаване на нов запис и предава получените данни към документа</summary>
	void InsertRecord();

	/// <summary>Метод, който казва на документа да изтрие избран запис</summary>
	void DeleteRecord();

	/// <summary>Метод, който изписва информация за даден запис в диалог, който не разрешава редакция</summary>
	void ReadRecord();

	/// <summary>Метод, който намира индекс на избран ред</summary>
	///<returns> Функцията връща int съдържащ индекс на селектиран ред или -1 ако няма такъв</returns>
	const int FindSelectedItem();

	/// <summary>Метод, който намира индекс на ред по неговата data</summary>
	/// <param name="lItemData">Data, по която се търси ред</param>
	///<returns> Функцията връща int съдържащ индекс на ред с подадена data или -1 ако няма такъв</returns>
	const int FindItemByData(const long lItemData);

	/// <summary>Метод, който отваря диалог</summary>
	/// <param name="recPhoneType">Запис, в който се попълва информацията на селектираният тип телефон</param>
	/// <param name="bReadOnly">Булева стойност, която определя дали информацията в диалога ще може да се редактира</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL InitDialog(PHONE_TYPES& recPhoneType, bool bReadOnly);

	/// <summary>Метод, който взима селектиран запис</summary>
	/// <param name="recPhoneType">Запис, в който се попълва информацията на селектираният тип телефон</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL LoadSelectedRecord(PHONE_TYPES& recPhoneType);

	/// <summary>Метод, който отваря диалог с попълнени полета</summary>
	/// <param name="recPhoneType">Запис, в който се попълва информацията на селектираният тип телефон</param>
	/// <param name="bReadOnly">Булева стойност, която определя дали информацията в диалога ще може да се редактира</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL InitFilledDialog(PHONE_TYPES& recPhoneType, bool bReadOnly);

	/// <summary>Метод, който променя съществуващ ред от лист контролата</summary>
	/// <param name="nIndex">Индекс на ред от лист контролата</param>
	/// <param name="recPhoneType">Запис на тип телефон, съдържащ информация по която се променя редът</param>
	void UpdateItem(int nIndex, const PHONE_TYPES& recPhoneType);

	/// <summary>Метод, който добавя ред в лист контролата</summary>
	/// <param name="recPhoneType">Запис на тип телефон, съдържащ информация по която се създава новият ред</param>
	void InsertItem(const PHONE_TYPES& recPhoneType);

	/// <summary>Метод, който се изпълнява след натискането на Еdit бутона от контекст менюто</summary>
	afx_msg void OnBtnPopupEdit();

	/// <summary>Метод, който се изпълнява след натискането на Delete бутона от контекст менюто</summary>
	afx_msg void OnBtnPopupDelete();

	/// <summary>Метод, който се изпълнява след натискането на Insert бутона от контекст менюто</summary>
	afx_msg void OnBtnPopupInsert();

	/// <summary>Метод, променящ състоянието на бутоните от контекстното меню, изпълняващ се точно преди излизането на менюто</summary>
	afx_msg void OnUpdateBtnPopup(CCmdUI* pCmdUI);

	/// <summary>Метод, който се изпълнява след активирането на ред от лист контролата</summary>
	afx_msg void OnItemActivate(NMHDR* pNMHDR, LRESULT* pResult);

// Overrides
// ----------------
private:
	/// <summary>Метод, изпълняващ се при ъпдейт на даденото view</summary>
	/// <param name="pSender">Указател сочещ към view, което е променило документа. При стойност NULL се променя всяко view.</param>
	/// <param name="lHint">Параметър съдържащ информация за промените</param>
	/// <param name="pHint">Указател сочещ обект съхраняващ информация за промените</param>
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);

	/// <summary>Метод, изпълняващ се при създаването на нова инстанция на PhoneTypesView</summary>
	virtual void OnInitialUpdate();

	/// <summary>Метод, изпълняващ се при натискане на десен бутон на мишката</summary>
	/// <param name="nFlags">Параметър, който индикира дали са натиснати определени бутони </param>
	/// <param name="oPoint">Обект съдържащ координати на курсора</param>
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint oPoint);

	/// <summary>Метод, който връща документ свързан с PhoneTypesView</summary>
	///<returns> Функцията връща указател сочещ документа на PhoneTypesView</returns>
	CPhoneTypesDocument& GetDocument() const;

// Members
// ----------------
private:
	/// <summary>Обект, който поддържа подадени съобщения</summary>
	DECLARE_MESSAGE_MAP()
};