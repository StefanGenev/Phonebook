#pragma once
#include "Structures.h"
#include "afxwin.h"
#include "afxcmn.h"
#include "Person.h"
#include "PhoneNumbersViewData.h"
#include "Validator.h"

/// <summary>
/// Клас за диалог за редакция и добавяне на абонат и неговите телефони
/// </summary>
class CPersonsDlg : public CDialog
{
	DECLARE_DYNAMIC(CPersonsDlg)

// Constants
// ----------------

private:
	/// <summary>Enum с видове колони в лист контрола за телефонни номера</summary>
	enum PhoneNumbersColumns
	{
		PhoneNumbersColumnType = 0,
		PhoneNumbersColumnNumber = 1
	};


	/// <summary>Име на колона за тип на телефонен номер на лист контрола за телефонни номера</summary>
	static const CString _strPhoneNumbersTypeColumnCaption;

	/// <summary>Име на колона за телефонен номер на лист контрола за телефонни номера</summary>
	static const CString _strPhoneNumbersNumberColumnCaption;

	/// <summary>Широчина на колона за тип на телефонен номер на лист контрола за телефонни номера</summary>
	static const int _nPhoneNumbersTypeColumnWidth;

	/// <summary>Широчина на колона за телефонен номер на лист контрола за телефонни номера</summary>
	static const int _nPhoneNumbersNumberColumnWidth;

	/// <summary>Индекс на събменю, което да се отваря при десен клик върху лист контролата с телефонните номера</summary>
	static const int _nSubmenuIndex;


// Constructor / Destructor
// ----------------
public:
	CPersonsDlg(CPerson& oPerson, const CCitiesMap& oCitiesMap, const CPhoneTypesMap& oPhoneTypesMap, CWnd* pParent = NULL);
	virtual ~CPersonsDlg();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PERSONS_DIALOG };
#endif

// Methods
// ----------------
protected:
	/// <summary>Метод, който добавя колони в лист контрола</summary>
	void BuildListCtrl();

	/// <summary>Метод, който попълва редове в лист контрола</summary>
	void FillListCtrl();

	/// <summary>Метод задаващ лимит за дължина на едит боксовете в диалога</summary>
	void SetTextLimits();

	/// <summary>Метод, който попълва подадена информация към диалога в едит боксовете</summary>
	void FillEditBoxes();

	/// <summary>Метод, който попълва комбо бокс cmbCity с подадени градове</summary>
	virtual void FillCities();

private:
	/// <summary>Метод, който отваря диалог за редакция на запис и предава променените данни към лист контролата</summary>
	void EditRecord();

	/// <summary>Метод, който отваря диалог за създаване на нов запис и предава получените данни към лист контролата</summary>
	void InsertRecord();

	/// <summary>Метод, който изтрива избран запис от лист контролата</summary>
	void DeleteRecord();

	/// <summary>Метод, който изписва информация за даден запис в диалог, който не разрешава редакция</summary>
	void ReadRecord();

	/// <summary>Метод, който отваря диалог</summary>
	/// <param name="recPhoneNumberViewData">Обект, в който се попълва информацията телефонен номер</param>
	/// <param name="bReadOnly">Булева стойност, която определя дали информацията в диалога ще може да се редактира</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL InitDialog(PHONE_NUMBERS_VIEW_DATA& recPhoneNumberViewData, bool bReadOnly);

	/// <summary>Метод, който взима запис</summary>
	/// <param name="nIndex">Индекс на реда от лист контролата, който трябва да се попълни в записа</param>
	/// <param name="recPhoneNumberViewData">Обект, в който се попълва информацията на телефонен номер</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL LoadItem(int nIndex, PHONE_NUMBERS_VIEW_DATA& recPhoneNumberViewData);

	/// <summary>Метод, който взима селектиран запис</summary>
	/// <param name="recPhoneNumberViewData">Обект, в който се попълва информацията на телефонен номер</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL LoadSelectedItem(PHONE_NUMBERS_VIEW_DATA& recPhoneNumberViewData);

	/// <summary>Метод, който отваря диалог с попълнени полета</summary>
	/// <param name="recPhoneNumberViewData">Обект, в който се попълва информацията на телефонен номер</param>
	/// <param name="bReadOnly">Булева стойност, която определя дали информацията в диалога ще може да се редактира</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL InitFilledDialog(PHONE_NUMBERS_VIEW_DATA& recPhoneNumberViewData, bool bReadOnly);

	/// <summary>Метод, който намира индекс на избран ред</summary>
	///<returns> Функцията връща int съдържащ индекс на селектиран ред или -1 ако няма такъв</returns>
	const int FindSelectedItem();

	/// <summary>Метод, който намира тип телефон по идентификатор</summary>
	/// <param name="lID">Уникален идентификатор</param>
	///<returns> Функцията връща стринг с типа телефон или празен стринг ако няма такъв</returns>
	const CString FindPhoneType(const long lID);

	/// <summary>Метод, който намира индекс на запис в масива по идентификатор</summary>
	/// <param name="lID">Уникален идентификатор</param>
	///<returns> Функцията връща индекс на указател сочещ запис с подаден идентификатор или -1 ако няма такъв</returns>
	const int FindPhoneNumberIndex(const long lID);

	/// <summary>Метод, който променя съществуващ ред от лист контролата</summary>
	/// <param name="nIndex">Индекс на ред от лист контролата</param>
	/// <param name="recPhoneNumberViewData">Запис на тeлефонен номер, съдържащ информация, по която се променя редът</param>
	void UpdateItem(int nIndex, const PHONE_NUMBERS_VIEW_DATA& recPhoneNumberViewData);

	/// <summary>Метод, който добавя ред в лист контролата</summary>
	/// <param name="recPhoneNumberViewData">Запис на тeлефонен номер, съдържащ информация, по която се създава новият ред</param>
	void InsertItem(const PHONE_NUMBERS_VIEW_DATA& recPhoneNumberViewData);

	/// <summary>Метод, който се изпълнява след натискането на Еdit бутона от контекст менюто</summary>
	afx_msg void OnBtnPopupEdit();

	/// <summary>Метод, който се изпълнява след натискането на Delete бутона от контекст менюто</summary>
	afx_msg void OnBtnPopupDelete();

	/// <summary>Метод, който се изпълнява след натискането на Insert бутона от контекст менюто</summary>
	afx_msg void OnBtnPopupInsert();

	/// <summary>Метод, променящ състоянието на бутоните от контекстното меню, изпълняващ се точно преди излизането на менюто</summary>
	afx_msg virtual void OnUpdateBtnPopup(CCmdUI* pCmdUI);

	/// <summary>Метод, който се изпълнява при активация на телефонен номер</summary>
	afx_msg void OnItemActivatePhoneNumbers(NMHDR* pNMHDR, LRESULT* pResult);

	/// <summary>Метод, който изважда контекстно меню при десен клик върху контролата с телефонните номера</summary>
	afx_msg void OnNMRClickPhoneNumbers(NMHDR* pNMHDR, LRESULT* pResult);

	/// <summary>Метод, който валидира едит контрола</summary>
	/// <param name="edbCtrl">Едит контрола</param>
	/// <param name="strValue">Стрингова стойност, която бива проверена за валидност</param>
	/// <param name="strFieldName">Име на полето, което бива валидирано</param>
	/// <param name="eEdbTypes">Вид на данни, които съдържа едит контролата</param>
	///<returns> Функцията връща стринг с информация за неверни стоиности и празен стринг при напълно валидни данни</returns>
	CString ValidateEditBox(const CEdit& edbCtrl, const CString& strFieldName, const CValidator::EdbTypes eEdbTypes);

	/// <summary>Метод, който валидира комбо бокс</summary>
	/// <param name="cmbCtrl">Комбо бокс</param>
	/// <param name="strFieldName">Име на полето, което бива валидирано</param>
	///<returns> Функцията връща стринг с информация за неверни стоиности и празен стринг при напълно валидни данни</returns>
	CString ValidateComboBox(const CComboBox& cmbCtrl, const CString& strFieldName);
	
	/// <summary>Метод, който валидира данните от контролите</summary>
	///<returns> Функцията връща резултат TRUE при валидни данни и FALSE при наличие на поне една невалидна данна</returns>
	BOOL ValidateData();

	/// <summary>Метод, който трансферира данните от контролите в записа</summary>
	void TransferDataToRecord();


// Overrides
// ----------------
protected:
	/// <summary>Метод, който взима данните на диалога</summary>
	/// <param name="pDx">Указател сочещ CDataExchange обект</param>
	virtual void DoDataExchange(CDataExchange* pDX);

	/// <summary>Метод, който се изпълнява при инициализация на диалог</summary>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	virtual BOOL OnInitDialog();

	/// <summary>Метод, който се изпълнява при натискането на бутона OK</summary>
	virtual void OnOK();

	/// <summary>Метод, който се изпълнява при инициализация на popup меню</summary>
	/// <param name="pPopupMenu">Указател сочещ към меню обект на popup менюто</param>
	/// <param name="nIndex">Индекс на popup менюто в главното меню</param>
	/// <param name="bSysMenu">Променлива със стоиност TRUE ако popup менюто е контролно меню и FALSE ако не е</param>
	virtual void OnInitMenuPopup(CMenu* pPopupMenu, UINT nIndex, BOOL bSysMenu);

// Members
// ----------------
protected:
	/// <summary>Променлива на еdit box за първо име на абонат</summary>
	CEdit m_edbFirstName;

	/// <summary>Променлива на еdit box за презиме на абонат</summary>
	CEdit m_edbMiddleName;

	/// <summary>Променлива на еdit box за фамилия на абонат</summary>
	CEdit m_edbLastName;

	/// <summary>Променлива на еdit box за ЕГН на абонат</summary>
	CEdit m_edbUCN;

	/// <summary>Променлива на combo box за град на абонат</summary>
	CComboBox m_cmbCity;

	/// <summary>Променлива на еdit box за адрес на абонат</summary>
	CEdit m_edbAddress;

	/// <summary>Променлива на list контрола за телефонни номера на абонат и техните типове</summary>
	CListCtrl m_lscPhoneNumbers;

	/// <summary>Запис, в който се попълва информацията на абонат и неговите телефонни номера</summary>
	CPerson& m_oPerson;

	/// <summary>Мап с указатели сочещи записи на всички градове</summary>
	const CCitiesMap& m_oCitiesMap;

	/// <summary>Мап с указатели сочещи записи на всички типове телефони</summary>
	const CPhoneTypesMap& m_oPhoneTypesMap;

	private:
		/// <summary>Обект, който поддържа подадени съобщения</summary>
		DECLARE_MESSAGE_MAP()
};
