#pragma once
#include "stdafx.h"
#include "DatabaseSession.h"

// Constructor / Destructor
// ----------------

CDatabaseSession::CDatabaseSession()
{
	m_bIsOpen = false;
	m_bTransactionIsOpen = false;
}

CDatabaseSession::~CDatabaseSession()
{
	AbortTransaction();
	Close();
}

// Methods
// ----------------
BOOL CDatabaseSession::OpenTransaction()
{
	if (!OpenSession())
		return FALSE;
	
	if (!m_bTransactionIsOpen)
	{
		HRESULT hResult = StartTransaction();
		if (FAILED(hResult))
		{
			AfxMessageBox(_T("Could not start transaction. Please try again later, the data might not be accessible at the moment."));
			return FALSE;
		}		
	}
	
	m_bTransactionIsOpen = true;
	return TRUE;
}

BOOL CDatabaseSession::CommitTransaction()
{
	HRESULT hResult = CSession::Commit();
	if (FAILED(hResult))
	{
		AfxMessageBox(_T("Could not commit changes. Please check if the values you are trying to update/delete are not being used at the moment."));
		AbortTransaction();
		return FALSE;
	}

	m_bTransactionIsOpen = false;
	return TRUE;
}

BOOL CDatabaseSession::OpenSession()
{
	if (!m_bIsOpen)
	{
		CDataSourceProvider& oDataSourceProvider = CDataSourceProvider::GetInstance();
		HRESULT hResult = Open(oDataSourceProvider.GetDataSource());
		if (FAILED(hResult))
		{
			AfxMessageBox(_T("Unable to open session. The database might not be accessible at the moment"));
			return FALSE;
		}
		m_bIsOpen = true;
	}	
	
	return TRUE;
}

void CDatabaseSession::AbortTransaction()
{
	if (m_bTransactionIsOpen)
	{
		HRESULT hResult = CSession::Abort();

		if (FAILED(hResult))
		{
			AfxMessageBox(_T("Could not abort transaction. Please try again and if this error keeps happening restart the application."));
			return;
		}
			
		m_bTransactionIsOpen = false;
	}
}


// Overrides
// ----------------