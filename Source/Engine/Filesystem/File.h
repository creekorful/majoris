#ifndef MAJORIS_FILE_H
#define MAJORIS_FILE_H

#include <iostream>
#include <fstream>
#include <sstream>

namespace ma::Filesystem
{
    class File;
}

namespace ma::Filesystem
{
    enum OpenMode
    {
        ReadOnly
    };
}

/**
 * Represent a file on the file system
 */
class ma::Filesystem::File
{
public:

    /**
     * Construct an invalid empty file
     */
    File();

    /**
     * Create file object using specified file path
     *
     * @param filePath the file path
     */
    explicit File(const std::string& filePath);

    /**
     * Copy constructor because std::ifstream is non copyable
     * please note that this will only copy the file path, not open the file or anything
     *
     * @param other the file to copy
     */
    File(const File& other);

    virtual ~File();

    /**
     * @return true if the file his valid (opened and ready to be written/read) depeding on open mode
     */
    bool isValid();

    /**
     * Open the file for specific operation
     *
     * @param openMode the open mode
     * @return true if the file has been opened false otherwise
     */
    bool open(OpenMode openMode);

    /**
     * Manually close the file
     * note that the file destructor will call close method if needed
     */
    void close();

    /**
     * @return file content as string representation
     */
    std::string readString();

    /**
     * @return the full path to the file (may be relative or absolute depending on given filePath)
     */
    std::string filePath() const;

    /**
     * @return file name with his extension
     */
    std::string fileName() const; // todo maybe return structure like file info ?

    // todo read binary ?

    // todo write supports

    /**
     * Copy assignment operator because std::ifstream is non copyable by default
     * please note that this will only copy the file path, not open the file or anything
     *
     * @param other the file to be copyied
     * @return this with filePath = other.filePath()
     */
    File& operator=(File other);

private:
    std::string m_filePath;
    std::ifstream m_file;
};


#endif //MAJORIS_FILE_H
