#include "stdafx.h"
#include "Validator.h"

// Constants
// ----------------

const CString CValidator::_strNamesValidSymbols = _T("AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz ");
const CString CValidator::_strUCNValidSymbols = _T("0123456789");
const CString CValidator::_strAddressValidSymbols = _T("AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz1234567890.-,/ ");
const CString CValidator::_strPhoneNumberValidSymbols = _T("0123456789");

const int CValidator::_nPhoneNumberMinimumLength = 8;
const int CValidator::_nUCNLength = 10;


// Constructor / Destructor
// ----------------

CValidator::CValidator()
{
}

CValidator::~CValidator()
{
}

// Methods
// ----------------

BOOL CValidator::ValidateField(const CString& strValue, const CString& strFieldName, const EdbTypes& eEdbTypes, bool& bIsValid, CString& strMessage)
{
	if (strValue.IsEmpty())
		strMessage.AppendFormat(_T("\nThe '%s' field is empty."), strFieldName);

	switch (eEdbTypes)
	{
	case EdbTypeNames:
		strMessage.Append(ValidateName(strValue, strFieldName));
		break;
	case EdbTypeUCN:
		strMessage.Append(ValidateUCN(strValue, strFieldName));
		break;
	case EdbTypeAddress:
		strMessage.Append(ValidateAddress(strValue, strFieldName));
		break;
	case EdbTypePhoneNumber:
		strMessage.Append(ValidatePhoneNumber(strValue, strFieldName));
		break;
	default:
		break;
	}

	if (!strMessage.IsEmpty())
		bIsValid = false;

	return TRUE;
}

CString CValidator::ValidateName(const CString& strValue, const CString& strFieldName)
{
	CString strMessage;
	if (strValue.SpanIncluding(_strNamesValidSymbols).Compare(strValue) != 0 || strValue.IsEmpty())
		strMessage.AppendFormat(_T("\nThe '%s' is not valid. Please use only english letters and spaces."), strFieldName);

	return strMessage;
}

CString CValidator::ValidateUCN(const CString& strValue, const CString& strFieldName)
{
	CString strMessage;
	if (strValue.SpanIncluding(_strUCNValidSymbols).Compare(strValue) != 0 || strValue.GetLength() != _nUCNLength)
		strMessage.AppendFormat(_T("\nThe '%s' is not valid. Please use only digits and make sure that its length is exactly %d characters."), strFieldName, _nUCNLength);

	return strMessage;
}

CString CValidator::ValidateAddress(const CString& strValue, const CString& strFieldName)
{
	CString strMessage;
	if (strValue.SpanIncluding(_strAddressValidSymbols).Compare(strValue) != 0 || strValue.IsEmpty())
		strMessage.AppendFormat(_T("\nThe '%s' is not valid. Please use only english letters, digits, dots, spaces, slashes and commas."), strFieldName);

	return strMessage;
}

CString CValidator::ValidatePhoneNumber(const CString& strValue, const CString& strFieldName)
{
	CString strMessage;
	if (strValue.SpanIncluding(_strPhoneNumberValidSymbols).Compare(strValue) != 0 || strValue.GetLength() < _nPhoneNumberMinimumLength)
		strMessage.AppendFormat(_T("\nThe '%s' is not valid. Please use digits only and make sure that it is at least %d characters long."),
			strFieldName, _nPhoneNumberMinimumLength);

	return strMessage;
}


// Overrides
// ----------------