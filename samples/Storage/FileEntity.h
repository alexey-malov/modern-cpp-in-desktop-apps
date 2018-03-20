#pragma once

#include "FileSystem.h"

class FileEntity final
{
public:
	FileEntity(const fs::path& path, bool keepAlive);
	~FileEntity();

	void KeepAlive() noexcept;

	const fs::path& GetPath() const noexcept;

private:
	const fs::path m_path;
	bool m_keepAlive;
};
