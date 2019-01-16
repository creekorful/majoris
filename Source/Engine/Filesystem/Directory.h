#ifndef MAJORIS_DIRECTORY_H
#define MAJORIS_DIRECTORY_H

#include <iostream>
#include <vector>
#include <dirent.h>
#include <stdio.h>

#include "File.h"

namespace ma::Filesystem
{
    class Directory;
}

/**
 * Class used to manage directory
 *
 * todo when std::filesystem is manage in all GCC implementations use it instead of this POSIX solution
 */
class ma::Filesystem::Directory
{
public:
    /**
     * Construct an invalid directory instance without specifing a path
     */
    Directory();

    /**
     * Construct directory using provided path
     * note: path should not end with '/'
     *
     * @param path path to directory
     */
    explicit Directory(const std::string& path);

    /**
     * @return true if directory is valid false otherwise
     */
    bool isValid() const;

    /**
     * @return path to the directory
     */
    std::string path() const;

    /**
     * Get all file in current directory that ends with provided extension (without the .)
     *
     * @param extension the file extension (without the .) if no provided all files will be retrieved
     * @return files in current directory who have given extension
     */
    std::vector<File> fileEntries(const std::string& extension = "") const;

private:
    std::string m_path;
    DIR* m_pDirectory;
};


#endif //MAJORIS_DIRECTORY_H
