#include "UI/Text.h"

#include "Utils/Constants.h"

// TODO: fazer lista de m_fonts
auto Text::Load(std::string &&file) -> void {
    const std::string src = game::ROOT + "assets/fonts/" + file + ".ttf";
    // int fileSize = 0;
    // unsigned char *fileData = LoadFileData(src.c_str(), &fileSize);
    // m_font.baseSize = 64;
    // m_font.glyphCount = 903;
    // m_font.glyphs = LoadFontData(fileData, fileSize, m_font.baseSize, nullptr, 903, FONT_DEFAULT);
    // const Image atlas = GenImageFontAtlas(m_font.glyphs, &m_font.recs, 903, m_font.baseSize, 4, 0);
    // m_font.texture = LoadTextureFromImage(atlas);
    // UnloadImage(atlas);

    m_font = LoadFontEx(src.c_str(), 54, nullptr, 0);
    SetTextureFilter(m_font.texture, TEXTURE_FILTER_POINT);
}

auto Text::Unload() -> void {
    UnloadFont(m_font);
}