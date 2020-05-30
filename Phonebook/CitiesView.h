
// CitiesView.h : interface of the CCitiesView class
//

#pragma once
#include "CitiesDocument.h"

/// <summary>
/// Клас за list view на градове
/// </summary>
class CCitiesView : public CListView
{
	DECLARE_DYNCREATE(CCitiesView)

// Constants
// ----------------
private:
	/// <summary>Enum с видове колони в Cities view</summary>
	enum Columns
	{
		ColumnName = 0,
		ColumnRegion = 1
	};

	/// <summary>Име на колона за име на град</summary>
	static const CString _strNameColumnCaption;

	/// <summary>Име на колона за регион на град</summary>
	static const CString _strRegionColumnCaption;

	/// <summary>Широчина на на колона за име на град</summary>
	static const int _nNameColumnWidth;

	/// <summary>Широчина на колона за регион на град</summary>
	static const int _nRegionColumnWidth;

// Constructor / Destructor
// ----------------	
public:
	CCitiesView();
	virtual ~CCitiesView();

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
	/// <param name="recCity">Запис, в който се попълва информацията на град</param>
	/// <param name="bReadOnly">Булева стойност, която определя дали информацията в диалога ще може да се редактира</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL InitDialog(CITIES& recCity, bool bReadOnly);

	/// <summary>Метод, който взима селектиран запис</summary>
	/// <param name="recCity">Запис, в който се попълва информацията на селектираният град</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL LoadSelectedRecord(CITIES& recCity);

	/// <summary>Метод, който отваря диалог с попълнени полета</summary>
	/// <param name="recCity">Запис, в който се попълва информацията на селектираният град</param>
	/// <param name="bReadOnly">Булева стойност, която определя дали информацията в диалога ще може да се редактира</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL InitFilledDialog(CITIES& recCity, bool bReadOnly);

	/// <summary>Метод, който променя съществуващ ред от лист контролата</summary>
	/// <param name="nIndex">Индекс на ред от лист контролата</param>
	/// <param name="recCity">Запис на град, съдържащ информация по която се променя редът</param>
	void UpdateItem(int nIndex, const CITIES& recCity);

	/// <summary>Метод, който добавя ред в лист контролата</summary>
	/// <param name="recCity">Запис на град, съдържащ информация по която се създава новият ред</param>
	void InsertItem(const CITIES& recCity);

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

	/// <summary>Метод, изпълняващ се при създаването на нова инстанция на CitiesView</summary>
	virtual void OnInitialUpdate();

	/// <summary>Метод, изпълняващ се при натискане на десен бутон на мишката</summary>
	/// <param name="nFlags">Параметър, който индикира дали са натиснати определени бутони </param>
	/// <param name="oPoint">Обект съдържащ координати на курсора</param>
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint oPoint);

	/// <summary>Метод, който връща документ свързан с CitiesView</summary>
	///<returns> Функцията връща указател сочещ документа на CitiesView</returns>
	CCitiesDocument& GetDocument() const;

// Members
// ----------------
private:
	/// <summary>Обект, който поддържа подадени съобщения</summary>
	DECLARE_MESSAGE_MAP()


};


