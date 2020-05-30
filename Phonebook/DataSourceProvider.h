#pragma once

/// <summary>
/// Клас за отваряне на връзка с база данни
/// </summary>
class CDataSourceProvider 
{

// Constants
// ----------------
private:
	/// <summary>Булева стойност, която проверява дали е създадена инстанция от този клас</summary>
	static bool _bIsInstantiated;

	/// <summary>Инстанция(единствена) на CDataSourceProvider</summary>
	static CDataSourceProvider _oDataSourceProvider;

// Constructor / Destructor
// ----------------

// Methods
// ----------------
public:
	/// <summary>Функция връщаща инстанция на класът</summary>
	static CDataSourceProvider& GetInstance();

	/// <summary>Функция отваряща връзка с база данни</summary>
	///<returns> Функцията връща резултат TRUE при успех и FALSE при възникнала грешка</returns>
	BOOL OpenDataSource();
	
	/// <summary>Функция връщаща връзка с база данни</summary>
	///<returns> Функцията връща референция към CDataSource обект</returns>
	CDataSource& GetDataSource();

// Overrides
// ----------------

// Members
// ----------------
private:
	/// <summary>База данни</summary>
	CDataSource m_oDataSource;
	
};