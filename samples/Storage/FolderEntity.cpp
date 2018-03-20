#include "stdafx.h"
#include "FolderEntity.h"

FolderEntity::FolderEntity(const fs::path& path)
	: m_path(path)
{
}

const fs::path& FolderEntity::GetPath() const noexcept
{
	return m_path;
}

FolderEntity::~FolderEntity()
{
	fs::remove(m_path);
}
