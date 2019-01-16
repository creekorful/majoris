#include "Directory.h"

ma::Filesystem::Directory::Directory()
{
    m_path = "";
    m_pDirectory = nullptr;
}

ma::Filesystem::Directory::Directory(const std::string& path)
{
    m_path = path;
    m_pDirectory = opendir(m_path.c_str());
}

bool ma::Filesystem::Directory::isValid() const
{
    return m_pDirectory != nullptr;
}

std::vector<ma::Filesystem::File> ma::Filesystem::Directory::fileEntries(const std::string& extension) const
{
    std::vector<File> files;
    struct dirent *dirent;

    // while there is entry to process
    while ((dirent = readdir(m_pDirectory)) != nullptr)
    {
        if (dirent->d_type == DT_REG)
        {
            std::string name = dirent->d_name;

            // if need to search for specific extension
            if (!extension.empty() && name.find(extension) != std::string::npos)
            {
                files.emplace_back(m_path + "/" + name);
            }
        }
    }

    return files;
}

std::string ma::Filesystem::Directory::path() const
{
    return m_path;
}
