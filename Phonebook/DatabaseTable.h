#pragma once

#include "stdafx.h"
#include "Structures.h"
#include "AutoClearPtrArray.h"
#include "DatabaseAccessor.h"
#include "DataSourceProvider.h"
#include "DatabaseSession.h"

/// <summary>
/// Клас за операции с таблица от база данни
/// </summary>
template<class ACCESSOR, class TABLE>
class CDatabaseTable : protected CCommand<CAccessor<ACCESSOR>>
{

// Constants
// ----------------
public:
/// <summary>Enum с видове lock hint</summary>
	enum LockHints
	{
		LockHintNoLock = 0,
		LockHintUpdLock = 1,
		LockHintHoldLock = 2
	};

// Constructor / Destructor
// ----------------

public:
	CDatabaseTable();
	CDatabaseTable(CDatabaseSession& oSession);
	virtual ~CDatabaseTable();

// Methods
// ----------------

public:
	/// <summary>Функция събираща всички записи от таблицата в масив</summary>
	/// <param name="oArray">Масив, в който се събират получените записи</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	virtual BOOL SelectAll(CAutoClearPtrArray<TABLE>& oArray);

	/// <summary>Функция намираща запис по идентификатор</summary>
	/// <param name="lID">Уникален идентификатор на търсения запис</param>
	/// <param name="recDatabaseRecord">Структура, в която се записва полученият запис</param>
	/// <param name="eLockHints">Вид lock hint</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	virtual BOOL SelectWhereID(const long lID, TABLE& recDatabaseRecord, const LockHints& eLockHints = LockHintNoLock);

	/// <summary>Функция намираща запис по подадена колона, която има подадена стойност</summary>
	/// <param name="lIdentificator">Даден тип идентификатор на търсения запис</param>
	/// <param name="strColumn">Име на колона, по която сравняваме идентификатор</param>
	/// <param name="recDatabaseRecord">Структура, в която се записва полученият запис</param>
	/// <param name="eLockHints">Вид lock hint</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	virtual BOOL SelectWhere(const long lIdentificator, const CString& strColumn, CAutoClearPtrArray<TABLE>& oArray, const LockHints& eLockHints = LockHintNoLock);

	/// <summary>Функция редактираща стоиности на запис по идентификатор</summary>
	/// <param name="lID">Уникален идентификатор на търсения запис</param>
	/// <param name="recDatabaseRecord">Структура съдържаща променените стойности</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	virtual BOOL UpdateWhereID(const long lID, const TABLE& recDatabaseRecord);

	/// <summary>Функция добавяща запис и записваща неговият идентификатор в параметър lID</summary>
	/// <param name="recDatabaseRecord">Структура съдържаща запис за добавяне</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	virtual BOOL Insert(TABLE& recDatabaseRecord);

	/// <summary>Функция триеща запис по идентификатор</summary>
	/// <param name="lID">Уникален идентификатор на записа за триене</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	virtual BOOL DeleteWhereID(const long lID);

	/// <summary>Функция, която синхронизира подаден масив от записи с вече съществуващите такива в базата данни</summary>
	/// <param name="oArray">Масив, които съдържа записи</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	virtual BOOL Synchronise(const CAutoClearPtrArray<TABLE>& oArrayNew, const CAutoClearPtrArray<TABLE>& oArrayOld);

protected:
	/// <summary>Функция извършваща заявка</summary>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL OpenCommand(CString& strQuery);

	/// <summary>Функция отваряща запис от таблица</summary>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL ReadFirstRecord();

	/// <summary>Функция връщаща lock, за заключване на запис от база данни</summary>
	///<returns> Функцията връща string с типа lock, който се добавя в заявка</returns>
	CString GetLockType(const LockHints& eLockHints);

	/// <summary>Функция връщаща име на таблица от база данни</summary>
	///<returns> Функцията връща string с име на таблица</returns>
	virtual CString GetTableName() = 0;
	
	/// <summary>Функция връщаща референция към идентификатор на запис от таблица</summary>
	/// <param name="recDatabaseRecord">Запис от таблица</param>
	///<returns> Функцията връща константна референция към long</returns>
	virtual const long& GetIdentificator(const TABLE& recDatabaseRecord) = 0;

	/// <summary>Функция връщаща референция към брояч на промени на таблица</summary>
	/// <param name="recDatabaseRecord">Запис от таблица</param>
	///<returns> Функцията връща референция към long</returns>
	virtual long& GetUpdateCounter(TABLE& recDatabaseRecord) = 0;

	/// <summary>Функция, която проверява дали запис с определен идентификатор съществува в подаденият масив</summary>
	/// <param name="lID">Уникален идентификатор на записа</param>
	/// <param name="oArray">Масив, които съдържа записи</param>
	///<returns> Функцията връща резултат TRUE ако записът съществува в масива и FALSE ако не съществува в масива</returns>
	BOOL IsExists(const long lID, const CAutoClearPtrArray<TABLE>& oArray);

	/// <summary>Функция изтриваща всички записи от масив, чиито идентификатор не присъства в друг масив</summary>
	/// <param name="oArrayNew">Масив, които съдържа нови записи</param>
	/// <param name="oArrayOld">Масив, които съдържа стари записи</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL DeleteNonExistant(const CAutoClearPtrArray<TABLE>& oArrayNew, const CAutoClearPtrArray<TABLE>& oArrayOld);

	/// <summary>Функция създаваща нови записи в базата данни и/или ъпдейтваща вече съществуващи такива</summary>
	/// <param name="oArray">Масив, които съдържа записи</param>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL UpdateExisting(const CAutoClearPtrArray<TABLE>& oArray);


// Overrides
// ----------------

// Members
// ----------------
protected:
	/// <summary>Сесия</summary>
	CDatabaseSession* m_pDatabaseSession;

	/// <summary>Булева стойност, която показва дали сесията се използва и от други таблични класове</summary>
	bool m_bIsSessionShared;

	/// <summary>Булева стойност, която показва дали отворената транзакция се използва от един или повече таблични класове</summary>
	bool m_bIsTransactionShared;
};

template<class ACCESSOR, class TABLE>
inline CDatabaseTable<ACCESSOR, TABLE>::CDatabaseTable()
{
	m_pDatabaseSession = new CDatabaseSession();
	m_bIsSessionShared = false;
	m_bIsTransactionShared = false;
}

template<class ACCESSOR, class TABLE>
inline CDatabaseTable<ACCESSOR, TABLE>::CDatabaseTable(CDatabaseSession& oSession)
{
	m_pDatabaseSession = &oSession;
	m_bIsSessionShared = true;
	m_bIsTransactionShared = false;
}

template<class ACCESSOR, class TABLE>
inline CDatabaseTable<ACCESSOR, TABLE>::~CDatabaseTable()
{		
	if (!m_bIsSessionShared)
		delete m_pDatabaseSession;
}

template<class ACCESSOR, class TABLE>
inline BOOL CDatabaseTable<ACCESSOR, TABLE>::SelectAll(CAutoClearPtrArray<TABLE>& oArray)
{
	if (!m_pDatabaseSession->OpenSession())
		return FALSE;

	CString strQuery;
	strQuery.Format(_T("SELECT * FROM %s WITH(NOLOCK)"), GetTableName());

	if (!OpenCommand(strQuery))
		return FALSE;

	oArray.DeleteAll();

	while (MoveNext() == S_OK)
	{
		oArray.Insert(m_recDatabaseRecord);
	}

	return TRUE;
}

template<class ACCESSOR, class TABLE>
inline BOOL CDatabaseTable<ACCESSOR, TABLE>::SelectWhereID(const long lID, TABLE& recDatabaseRecord, const LockHints& eLockHints)
{
	if (!m_pDatabaseSession->OpenSession())
		return FALSE;

	CString strQuery;
	strQuery.Format(_T("SELECT * FROM %s %s WHERE ID = %d"), GetTableName(), GetLockType(eLockHints), lID);

	if (!OpenCommand(strQuery))
		return FALSE;

	if (!ReadFirstRecord())
		return FALSE;

	recDatabaseRecord = m_recDatabaseRecord;

	return TRUE;
}

template<class ACCESSOR, class TABLE>
inline BOOL CDatabaseTable<ACCESSOR, TABLE>::SelectWhere(const long lIdentificator, const CString& strColumn, CAutoClearPtrArray<TABLE>& oArray, const LockHints& eLockHints)
{
	if (!m_pDatabaseSession->OpenSession())
		return FALSE;

	CString strQuery;
	strQuery.Format(_T("SELECT * FROM %s %s WHERE %s = %d"), GetTableName(), GetLockType(eLockHints), strColumn, lIdentificator);

	if (!OpenCommand(strQuery))
		return FALSE;

	oArray.DeleteAll();

	while (MoveNext() == S_OK)
	{
		oArray.Insert(m_recDatabaseRecord);
	}

	return TRUE;
}

template<class ACCESSOR, class TABLE>
inline BOOL CDatabaseTable<ACCESSOR, TABLE>::UpdateWhereID(const long lID, const TABLE& recDatabaseRecord)
{
	if (!m_pDatabaseSession->OpenTransaction())
		return FALSE;
	
	if (!SelectWhereID(lID, m_recDatabaseRecord, LockHintUpdLock))
		return FALSE;
	

	TABLE recDatabaseRecordNew = recDatabaseRecord;
	long& lUpdateCounterFromDB = GetUpdateCounter(m_recDatabaseRecord);

	if (GetUpdateCounter(recDatabaseRecordNew) != lUpdateCounterFromDB)
	{
		AfxMessageBox(_T("The record is not in the same state. Your changes won't be saved."));
		return FALSE;
	}

	m_recDatabaseRecord = recDatabaseRecord;
	lUpdateCounterFromDB++;

	HRESULT hResult = SetData(_nDataAccessor);

	if (FAILED(hResult))
	{
		AfxMessageBox(_T("Unable to update record. Check again if the values you have entered are valid and if a record with those values isn't already registered."));
		return FALSE;
	}

	if (!m_bIsSessionShared && !m_bIsTransactionShared)
		if (!m_pDatabaseSession->CommitTransaction())
			return FALSE;

	return TRUE;
}

template<class ACCESSOR, class TABLE>
inline BOOL CDatabaseTable<ACCESSOR, TABLE>::Insert(TABLE& recDatabaseRecord)
{
	if (!m_pDatabaseSession->OpenSession())
		return FALSE;

	CString strQuery;
	strQuery.Format(_T("SELECT TOP(0) * FROM %s"), GetTableName());

	if (!OpenCommand(strQuery))
		return FALSE;

	m_recDatabaseRecord = recDatabaseRecord;

	HRESULT hResult = CRowset::Insert(_nDataAccessor);

	if (FAILED(hResult))
	{
		AfxMessageBox(_T("Error inserting record. Check again if such a record isn't already registered."));
		return FALSE;
	}

	if (!ReadFirstRecord())
		return FALSE;

	recDatabaseRecord = m_recDatabaseRecord;

	return TRUE;
}

template<class ACCESSOR, class TABLE>
inline BOOL CDatabaseTable<ACCESSOR, TABLE>::DeleteWhereID(const long lID)
{
	if (!m_pDatabaseSession->OpenTransaction())
		return FALSE;

	if (!SelectWhereID(lID, m_recDatabaseRecord, LockHintUpdLock))
		return FALSE;
		
	HRESULT hResult = __super::Delete();

	if (FAILED(hResult))
	{
		AfxMessageBox(_T("Error deleting record, it might be in use of other records."));
		return FALSE;
	}

	if (!m_bIsSessionShared && !m_bIsTransactionShared)
		if (!m_pDatabaseSession->CommitTransaction())
			return FALSE;
	
	return TRUE;
}

template<class ACCESSOR, class TABLE>
inline BOOL CDatabaseTable<ACCESSOR, TABLE>::Synchronise(const CAutoClearPtrArray<TABLE>& oArrayNew, const CAutoClearPtrArray<TABLE>& oArrayOld)
{
	m_bIsTransactionShared = true;

	if (!m_pDatabaseSession->OpenTransaction())
		return FALSE;

	if (!DeleteNonExistant(oArrayNew, oArrayOld))
		return FALSE;
	
	if (!UpdateExisting(oArrayNew))
		return FALSE;

	if (!m_bIsSessionShared)
		if (!m_pDatabaseSession->CommitTransaction())
			return FALSE;
	
	m_bIsTransactionShared = false;
	return TRUE;
}

template<class ACCESSOR, class TABLE>
inline BOOL CDatabaseTable<ACCESSOR, TABLE>::OpenCommand(CString& strQuery)
{
	Close();

	CDBPropSet oUpdateDBPropSet(DBPROPSET_ROWSET);
	oUpdateDBPropSet.AddProperty(DBPROP_CANFETCHBACKWARDS, true);
	oUpdateDBPropSet.AddProperty(DBPROP_IRowsetScroll, true);
	oUpdateDBPropSet.AddProperty(DBPROP_IRowsetChange, true);
	oUpdateDBPropSet.AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_INSERT | DBPROPVAL_UP_DELETE);

	HRESULT hResult = Open(*m_pDatabaseSession, strQuery, &oUpdateDBPropSet);

	if (FAILED(hResult))
	{
		CString strError;
		strError.Format(_T("Unable to fetch record/s. Check again if the record/s you have chosen is/are valid"), hResult);
		AfxMessageBox(strError);

		Close();
		return FALSE;
	}

	return TRUE;
}

template<class ACCESSOR, class TABLE>
inline BOOL CDatabaseTable<ACCESSOR, TABLE>::ReadFirstRecord()
{
	HRESULT hResult = MoveFirst();

	if (FAILED(hResult))
	{
		AfxMessageBox(_T("Error reading record. The record might not be accessible at the moment, try again later."));

		Close();
		return FALSE;
	}

	if (hResult == DB_S_ENDOFROWSET)
	{
		AfxMessageBox(_T("No such record found in database. Please restart the application and check if the record you have chosen/inserted isn't removed."));

		Close();
		return FALSE;
	}

	return TRUE;
}

template<class ACCESSOR, class TABLE>
inline CString CDatabaseTable<ACCESSOR, TABLE>::GetLockType(const LockHints& eLockHints)
{
	CString strLock;
	switch (eLockHints)
	{
	case LockHintUpdLock:
		strLock = _T("WITH(UPDLOCK)");
		break;
	case LockHintHoldLock:
		strLock = _T("WITH(HOLDLOCK)");
		break;
	case LockHintNoLock:
		strLock = _T("WITH(NOLOCK)");
		break;
	default:
		break;
	}
	return strLock;
}

template<class ACCESSOR, class TABLE>
inline BOOL CDatabaseTable<ACCESSOR, TABLE>::IsExists(const long lID, const CAutoClearPtrArray<TABLE>& oArray)
{
	BOOL bExists = FALSE;
	for (int i = 0; i < oArray.GetCount(); i++)
	{
		const TABLE* pDatabaseRecord = oArray.GetAt(i);
		if (pDatabaseRecord == NULL)
			continue;

		const long& lIdentificator = GetIdentificator(*pDatabaseRecord);

		if (lIdentificator != lID)
			continue;

		bExists = TRUE;
		break;
	}
	return bExists;
}

template<class ACCESSOR, class TABLE>
inline BOOL CDatabaseTable<ACCESSOR, TABLE>::DeleteNonExistant(const CAutoClearPtrArray<TABLE>& oArrayNew, const CAutoClearPtrArray<TABLE>& oArrayOld)
{
	for (int i = 0; i < oArrayOld.GetCount(); i++)
	{
		TABLE* pDatabaseRecord = oArrayOld.GetAt(i);
		if (pDatabaseRecord == NULL)
			continue;

		const long& lIdentificator = GetIdentificator(*pDatabaseRecord);

		if (IsExists(lIdentificator, oArrayNew))
			continue;

		if (!DeleteWhereID(lIdentificator))
			return FALSE;
	}

	return TRUE;
}

template<class ACCESSOR, class TABLE>
inline BOOL CDatabaseTable<ACCESSOR, TABLE>::UpdateExisting(const CAutoClearPtrArray<TABLE>& oArray)
{
	for (int i = 0; i < oArray.GetCount(); i++)
	{
		TABLE* pDatabaseRecord = oArray.GetAt(i);
		if (pDatabaseRecord == NULL)
			continue;

		const long lIdentificator = GetIdentificator(*pDatabaseRecord);

		if (lIdentificator == 0)
		{
			if (!Insert(*pDatabaseRecord))
				return FALSE;
		}
		else
		{
			if (!UpdateWhereID(lIdentificator, *pDatabaseRecord))
				return FALSE;
		}
	}

	return TRUE;
}

