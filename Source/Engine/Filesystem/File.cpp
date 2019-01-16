#include "File.h"

ma::Filesystem::File::File() = default;

ma::Filesystem::File::File(const std::string& filePath)
{
    m_filePath = filePath;
}

ma::Filesystem::File::File(const ma::Filesystem::File& other)
{
    m_filePath = other.filePath();
}

ma::Filesystem::File::~File()
{
    if (m_file.is_open())
    {
        m_file.close();
    }
}

bool ma::Filesystem::File::isValid()
{
    return m_file.is_open();
}

std::string ma::Filesystem::File::readString()
{
    std::stringstream sstream;
    sstream << m_file.rdbuf();
    return sstream.str();
}

bool ma::Filesystem::File::open(ma::Filesystem::OpenMode openMode)
{
    // Currently only read only is supported
    m_file.open(m_filePath);
    return m_file.is_open();
}

std::string ma::Filesystem::File::fileName() const
{
    if (m_filePath.find('/') == std::string::npos)
    {
        return m_filePath;
    }
    else
    {
        return m_filePath.substr(m_filePath.find_last_of('/')+1);
    }
}

std::string ma::Filesystem::File::filePath() const
{
    return m_filePath;
}

void ma::Filesystem::File::close()
{
    m_file.close();
}

ma::Filesystem::File& ma::Filesystem::File::operator=(ma::Filesystem::File other)
{
    m_filePath = other.filePath();
    return *this;
}
