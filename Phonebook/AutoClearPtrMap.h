#pragma once
#include "stdafx.h"

/// <summary>
/// Клас за създаване на мап от стойности указатели, който се зачиства сам
/// </summary>

template<class KEY, class ARG_KEY, class VALUE, class ARG_VALUE>
class CAutoClearPtrMap : public CMap<KEY, ARG_KEY, VALUE*, ARG_VALUE*>
{

// Constants
// ----------------


// Constructor / Destructor
// ----------------

public:

	CAutoClearPtrMap() {};

	/// <summary>Деструктор, който зачиства мапа</summary>
	virtual ~CAutoClearPtrMap()
	{
		for (POSITION oPosition = this->GetStartPosition(); oPosition != NULL;)
		{
			KEY oKey;
			VALUE* pValue;
			this->GetNextAssoc(oPosition, oKey, pValue);

			delete pValue;
		}

	};

// Methods
// ----------------

// Overrides
// ----------------

// Members
// ---------------

};