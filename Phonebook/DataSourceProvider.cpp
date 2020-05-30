
#include "stdafx.h"
#include "DataSourceProvider.h"

// Constants
// ----------------
bool CDataSourceProvider::_bIsInstantiated = false;
CDataSourceProvider CDataSourceProvider::_oDataSourceProvider;

// Constructor / Destructor
// ----------------
	
// Methods
// ----------------

CDataSourceProvider&  CDataSourceProvider::GetInstance()
{	
	if (!_bIsInstantiated)
	{
		_bIsInstantiated = true;
		_oDataSourceProvider = CDataSourceProvider();
	}

	return _oDataSourceProvider;
}

BOOL CDataSourceProvider::OpenDataSource()
{
	CDBPropSet oDBPropSet(DBPROPSET_DBINIT);
	oDBPropSet.AddProperty(DBPROP_INIT_DATASOURCE, _T("DESKTOP-E4FAKE0"));
	oDBPropSet.AddProperty(DBPROP_AUTH_USERID, _T("sa"));
	oDBPropSet.AddProperty(DBPROP_AUTH_PASSWORD, _T("sa"));
	oDBPropSet.AddProperty(DBPROP_INIT_CATALOG, _T("Phonebook_DB"));
	oDBPropSet.AddProperty(DBPROP_AUTH_PERSIST_SENSITIVE_AUTHINFO, false);
	oDBPropSet.AddProperty(DBPROP_INIT_LCID, 1033L);
	oDBPropSet.AddProperty(DBPROP_INIT_PROMPT, static_cast<short>(4));

	HRESULT hResult = m_oDataSource.Open(_T("SQLOLEDB.1"), &oDBPropSet);

	if (FAILED(hResult))
	{
		AfxMessageBox(_T("Unable to connect to SQL Server Database. Check if the authentication details you have given are correct."));

		m_oDataSource.Close();

		return FALSE;
	}

	return TRUE;
}

CDataSource& CDataSourceProvider::GetDataSource() 
{
	return m_oDataSource;
}

// Overrides
// ----------------
