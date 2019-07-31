#include "stdafx.h"
#include "Asset.h"

#include <rttr/registration>
#include <EtCore/FileSystem/FileUtil.h>


//===================
// Asset
//===================


// reflection
RTTR_REGISTRATION
{
	using namespace rttr;

	registration::class_<I_Asset>("asset")
		.property("name", &I_Asset::GetName, &I_Asset::SetName)
		.property("path", &I_Asset::GetPath, &I_Asset::SetPath)
		.property("package", &I_Asset::GetPackageName, &I_Asset::SetPackageName)
		;
}


// Construct destruct
///////////////

//---------------------------------
// I_Asset::~I_Asset
//
// I_Asset destructor
//
I_Asset::~I_Asset()
{
	Unload();
}


// Utility
///////////////

//---------------------------------
// I_Asset::SetName
//
// Sets the name of an asset and generates its ID and package entry ID
//
void I_Asset::SetName(std::string const& val)
{
	m_Name = val;
	m_Id = GetHash(m_Name);
	m_PackageEntryId = GetHash(m_Path + m_Name);
}

//---------------------------------
// I_Asset::SetPath
//
// Sets the path of an asset and regenerates the package entry ID
//
void I_Asset::SetPath(std::string const& val)
{
	m_Path = val;
	m_PackageEntryId = GetHash(m_Path + m_Name);
}

//---------------------------------
// I_Asset::SetPackageName
//
// Sets the name of the package the asset lives in and generates its package ID
//
void I_Asset::SetPackageName(std::string const& val)
{
	m_PackageName = val;
	m_PackageId = GetHash(m_PackageName);
}

//---------------------------------
// I_Asset::Load
//
// Sets the name of an asset and generates its ID
//
void I_Asset::Load()
{
	std::string fullPath = m_Path + m_Name;
	// get binary data from compiled resource
	std::vector<uint8> data;
	if (!FileUtil::GetCompiledResource(fullPath, data))
	{
		LOG("I_Asset::Load > couldn't get data from resource '" + fullPath + std::string("'"), LogLevel::Warning);
		return;
	}

	if (!LoadFromMemory(data))
	{
		LOG("I_Asset::Load > Failed loading asset from memory, name: '" + m_Name + std::string("'"), LogLevel::Warning);
	}
}
