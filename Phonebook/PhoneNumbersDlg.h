#pragma once
#include "afxwin.h"
#include "Structures.h"
#include "PhoneNumbersViewData.h"
#include "Validator.h"

/// <summary>
/// Клас за диалог за редакция и добавяне на телефонен номер
/// </summary>
class CPhoneNumbersDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPhoneNumbersDlg)

// Constants
// ----------------


// Constructor / Destructor
// ----------------
public:
	CPhoneNumbersDlg(PHONE_NUMBERS_VIEW_DATA& recPhoneNumberViewData, const CPhoneTypesMap& oPhoneTypesMap, CWnd* pParent = NULL);
	virtual ~CPhoneNumbersDlg();


#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PHONE_NUMBERS_DIALOG };
#endif
// Methods
// ----------------
protected:
	/// <summary>Метод задаващ лимит за дължина на едит боксовете в диалога</summary>
	void SetTextLimits();

	/// <summary>Метод, който попълва подадена информация към диалога в едит боксовете</summary>
	void FillEditBoxes();
	
	/// <summary>Метод, който попълва комбо бокс m_cmbType с подадени типове телефони</summary>
	virtual void FillPhoneTypes();

private:
	/// <summary>Метод, който валидира данните от контролите</summary>
	///<returns> Функцията връща резултат TRUE при валидни данни и FALSE при наличие на поне една невалидна данна</returns>
	BOOL ValidateData();

	/// <summary>Метод, който валидира едит контрола</summary>
	/// <param name="edbCtrl">Едит контрола</param>
	/// <param name="strFieldName">Име на полето, което бива валидирано</param>
	/// <param name="eEdbTypes">Вид на данни, които съдържа едит контролата</param>
	///<returns> Функцията връща стринг с информация за неверни стоиности и празен стринг при напълно валидни данни</returns>
	CString ValidateEditBox(const CEdit& edbCtrl, const CString& strFieldName, const CValidator::EdbTypes eEdbTypes);

	/// <summary>Метод, който валидира комбо бокс</summary>
	/// <param name="cmbCtrl">Комбо бокс</param>
	/// <param name="strFieldName">Име на полето, което бива валидирано</param>
	///<returns> Функцията връща стринг с информация за неверни стоиности и празен стринг при напълно валидни данни</returns>
	CString ValidateComboBox(const CComboBox& cmbCtrl, const CString& strFieldName);

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

// Members
// ----------------
protected:
	/// <summary>Запис на телефонен номер</summary>
	PHONE_NUMBERS_VIEW_DATA& recPhoneNumberViewData;

private:
	/// <summary>Обект, който поддържа подадени съобщения</summary>
	DECLARE_MESSAGE_MAP()

	/// <summary>Променлива на combo box за тип на телефонен номер</summary>
	CComboBox m_cmbType;

	/// <summary>Променлива на еdit box за телефонен номер</summary>
	CEdit m_edbNumber;

	/// <summary>Мап с указатели сочещи записи на всички типове телефони</summary>
	const CPhoneTypesMap& m_oPhoneTypesMap;


};
