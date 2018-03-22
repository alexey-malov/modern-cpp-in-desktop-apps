#include "stdafx.h"
#include "FileRef.h"
#include "FileEntity.h"

FileRef::FileRef(const std::shared_ptr<FileEntity>& file, const std::shared_ptr<FolderEntity>& folder)
	: m_file(file)
	, m_folder(folder)
{
}

const fs::path& FileRef::GetPath() const noexcept
{
	return m_file->GetPath();
}

void FileRef::KeepAlive() noexcept
{
	m_file->KeepAlive();
}
