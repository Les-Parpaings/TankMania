
#include "utils/utils.hpp"
#include <filesystem>

namespace fs = std::filesystem;
namespace utils {

Textures::Textures()
{
    std::string name;
    std::string path;
    size_t len = 0;
    bool err = false;

    m_texture["none"] = sf::Texture();

    for (const auto &entry : fs::recursive_directory_iterator(DIR_IMAGE)) {
        if (entry.is_regular_file()) {

            name = entry.path().string();
            len = name.length() - strlen(DIR_IMAGE);
            name.erase(name.begin(), name.end() - len);
            if (name == ".gitkeep")
                continue;
            name.erase(name.end() - strlen(EXT_IMAGE), name.end());
            path = std::string(DIR_IMAGE + name + EXT_IMAGE);

            m_texture[name] = sf::Texture();
            err = m_texture[name].loadFromFile(path);
            if (err == false) {
                m_texture.erase(name);
            }

            name.clear();
            path.clear();
            len = 0;
            err = false;
        }
    }
}

Textures::~Textures()
{
    m_texture.clear();
}

sf::Texture &Textures::getTexture(std::string name)
{
    auto it = m_texture.find(name);
    if (it == m_texture.end()) {
        return m_texture["none"];
    } else {
        return it->second;
    }
}

}
