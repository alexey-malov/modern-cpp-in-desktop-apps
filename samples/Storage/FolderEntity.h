#pragma once
#include "FileSystem.h"

class FolderEntity
{
public:
	explicit FolderEntity(const fs::path& path);

	~FolderEntity();

	const fs::path& GetPath() const noexcept;

private:
	const fs::path m_path;
};
