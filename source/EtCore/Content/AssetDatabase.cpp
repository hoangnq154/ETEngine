#include "stdafx.h"
#include "AssetDatabase.h"

#include <rttr/registration>


//===================
// Asset Database
//===================


// reflection
RTTR_REGISTRATION
{
	using namespace rttr;

	registration::class_<AssetDatabase::AssetCache>("asset cache")
		.property("cache", &AssetDatabase::AssetCache::cache);

	registration::class_<AssetDatabase::PackageDescriptor>("asset")
		.property("name", &AssetDatabase::PackageDescriptor::GetName, &AssetDatabase::PackageDescriptor::SetName)
		.property("path", &AssetDatabase::PackageDescriptor::GetPath, &AssetDatabase::PackageDescriptor::SetPath);

	registration::class_<AssetDatabase>("asset database")
		.property("packages", &AssetDatabase::packages)
		.property("caches", &AssetDatabase::caches);
}

//---------------------------------
// AssetDatabase::PackageDescriptor::SetName
//
// Sets the name of a package generator and generates its ID
//
void AssetDatabase::PackageDescriptor::SetName(std::string const& val)
{
	m_Name = val;
	m_Id = GetHash(m_Name);
}

//---------------------------------
// ResourceManager::AssetDatabase::AssetCache::GetType
//
// Get the type of an asset cache
//
std::type_info const& AssetDatabase::AssetCache::GetType() const
{
	if (cache.size() > 0)
	{
		return cache[0]->GetType();
	}
	return typeid(nullptr);
}
