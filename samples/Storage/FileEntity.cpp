#include "stdafx.h"
#include "FileEntity.h"

FileEntity::FileEntity(const fs::path& path, bool keepAlive)
	: m_path(path)
	, m_keepAlive(keepAlive)
{
}

void FileEntity::KeepAlive() noexcept
{
	m_keepAlive = true;
}

const fs::path& FileEntity::GetPath() const noexcept
{
	return m_path;
}

FileEntity::~FileEntity()
{
	int attempt = 100;
	std::error_code ec;
	while (!fs::remove(m_path, ec) && attempt--)
	{
	}
}
