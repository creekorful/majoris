#include "TestState.h"

std::string TestState::title()
{
    return "Majoris - Test state";
}

void TestState::initialize()
{
    // Load arial font and keep reference to it
    getEngine()->fontManager().loadFont("Arial", "Fonts/Arial.ttf");
    m_font = getEngine()->fontManager().getFont("Arial");

    // Load background texture and keep reference to it
    if(!getEngine()->textureManager().loadTexture("background", "Media/background.bmp"))
    {
        std::cerr << "Unable to open media/background.bpm";
        exit(-1);
    }
    sf::Texture& tex = getEngine()->textureManager().getTexture("background");

    sf::Vector2u screenSize = getEngine()->screenSize();

    // Create background
    m_background = ma::Sprite(tex, sf::Vector2f(0, 0));
    add(&m_background);

    // Search for save files
    std::map<std::string, ma::Filesystem::File> savesFiles;
    std::vector<std::string> menuEntries;
    ma::Filesystem::Directory saveDirectory("./Saves");

    if (!saveDirectory.isValid())
    {
        std::cerr << "Unable to open save directory: " << saveDirectory.path();
        exit(-1);
    }

    for (const auto& saveFile : saveDirectory.fileEntries("svs"))
    {
        m_saveFiles[saveFile.fileName()] = saveFile;
        menuEntries.push_back(saveFile.fileName());
    }

    // Add exit to menu entries
    menuEntries.emplace_back(EXIT);

    // Create dummy menu at screen center
    m_menu.setDefaultColor(sf::Color::Yellow);
    m_menu.setHighlightColor(sf::Color::Red);
    m_menu.setItems(menuEntries, m_font);
    m_menu.setPosition(screenSize.x / 2.f, screenSize.y / 2.f);
    m_menu.setCallback(this);

    add(&m_menu);
}

void TestState::onMenuItemSelected(const std::string& itemName)
{
    if (itemName != EXIT)
    {
        ma::Filesystem::File target = m_saveFiles[itemName];

        if (target.open(ma::Filesystem::ReadOnly))
        {
            std::cout << "Content = " << target.readString() << std::endl;
            target.close();
        }
    }
    else // Exit is triggered
    {
        getEngine()->quit();
    }
}

void TestState::onMenuItemHovered(const std::string& itemName)
{
}
