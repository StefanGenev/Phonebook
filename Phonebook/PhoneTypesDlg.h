#pragma once
#include "afxwin.h"
#include "Structures.h"
#include "Validator.h"

/// <summary>
/// Клас за диалог за редакция и добавяне на тип телефон
/// </summary>
class CPhoneTypesDlg : public CDialog
{
	DECLARE_DYNAMIC(CPhoneTypesDlg)

// Constants
// ----------------


// Constructor / Destructor
// ----------------

public:
	CPhoneTypesDlg(PHONE_TYPES& recPhoneType, CWnd* pParent = NULL);
	virtual ~CPhoneTypesDlg();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PHONE_TYPES_DIALOG };
#endif

// Methods
// ----------------
protected:
	/// <summary>Метод задаващ лимит за дължина на едит боксовете в диалога</summary>
	void SetTextLimits();

	/// <summary>Метод, който попълва подадена информация към диалога в едит боксовете</summary>
	void FillEditBoxes();

	/// <summary>Метод, който валидира едит контрола</summary>
	/// <param name="edbCtrl">Едит контрола</param>
	/// <param name="strFieldName">Име на полето, което бива валидирано</param>
	/// <param name="eEdbTypes">Вид на данни, които съдържа едит контролата</param>
	///<returns> Функцията връща стринг с информация за неверни стоиности и празен стринг при напълно валидни данни</returns>
	CString ValidateEditBox(const CEdit& edbCtrl, const CString& strFieldName, const CValidator::EdbTypes eEdbTypes);

	/// <summary>Метод, който валидира всички данни от диалога</summary>
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

// Members
// ----------------
private:
	/// <summary>Обект, който поддържа подадени съобщения</summary>
	DECLARE_MESSAGE_MAP()

	/// <summary>Променлива на еdit box за тип телефон</summary>
	CEdit m_edbType;

	/// <summary>Запис на тип телефон</summary>
	PHONE_TYPES& m_recPhoneType;
};
