#pragma once
#include "FileStorage_fwd.h"
#include "FileSystem.h"

class FileStorage
{
public:
	explicit FileStorage(const fs::path& path);

	FileRefPtr AddFile(const fs::path& path);
private:
	fs::path GenerateTargetFilePath(const fs::path& srcPath) const;

	FolderEntityPtr m_storageFolder;
};

