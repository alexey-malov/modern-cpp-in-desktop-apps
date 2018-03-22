#include "stdafx.h"
#include "FileStorage.h"
#include "FolderEntity.h"

using namespace std;

namespace
{

} // namespace

FileStorage::FileStorage(const fs::path& path)
	: m_storageFolder(make_shared<FolderEntity>(path))
{
}

FileRefPtr FileStorage::AddFile(const fs::path& path)
{
	auto targetPath = GenerateTargetFilePath(path);
	fs::copy(path, targetPath);
	return nullptr;
}

fs::path FileStorage::GenerateTargetFilePath(const fs::path& srcPath) const
{
	return m_storageFolder->GetPath() / srcPath.filename();
}
