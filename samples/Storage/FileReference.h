#pragma once

#include "FileSystem.h"

class FileEntity;
class FolderEntity;

class FileReference final
{
public:
	FileReference(const std::shared_ptr<FileEntity>& file, const std::shared_ptr<FolderEntity>& folder);

	const fs::path& GetPath() const noexcept;
	void KeepAlive() noexcept;
	
private:
	std::shared_ptr<FileEntity> m_file;
	std::shared_ptr<FolderEntity> m_folder;
};

