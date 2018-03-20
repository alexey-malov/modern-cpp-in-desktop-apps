#include "stdafx.h"
#include "FileReference.h"
#include "FileEntity.h"

FileReference::FileReference(const std::shared_ptr<FileEntity>& file, const std::shared_ptr<FolderEntity>& folder)
	: m_file(file)
	, m_folder(folder)
{
}

const fs::path& FileReference::GetPath() const noexcept
{
	return m_file->GetPath();
}

void FileReference::KeepAlive() noexcept
{
	m_file->KeepAlive();
}
