#include "UI/Text.h"

#include "Utils/Constants.h"

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

    // TODO: Apagar depois
    m_fonts.normal = LoadFontEx(src.c_str(), 64, nullptr, 903);

    // O correto: Loading de cada tamanho diferente de uma vez por conta do raylib
    m_fonts.size_12 = LoadFontEx(src.c_str(), game::ui::SIZE_12, nullptr, 903);
    m_fonts.size_16 = LoadFontEx(src.c_str(), game::ui::SIZE_16, nullptr, 903);
    m_fonts.size_20 = LoadFontEx(src.c_str(), game::ui::SIZE_20, nullptr, 903);

    SetTextureFilter(m_fonts.normal.texture, TEXTURE_FILTER_POINT);
    SetTextLineSpacing(1);
}

auto Text::Measure(const FontTypes &types, const std::string &text) -> Vector2 {
    switch (types) {
        case FontTypes::SIZE_12:
            return MeasureTextEx(m_fonts.size_12, text.c_str(), game::ui::SIZE_12, 1);
        case FontTypes::SIZE_16:
            return MeasureTextEx(m_fonts.size_16, text.c_str(), game::ui::SIZE_16, 1);
        case FontTypes::SIZE_20:
            return MeasureTextEx(m_fonts.size_20, text.c_str(), game::ui::SIZE_20, 1);
        default:
            return MeasureTextEx(m_fonts.size_12, text.c_str(), game::ui::SIZE_12, 1);
    }
}

auto Text::Draw(const FontTypes &&types, const std::string &text, const Vector2 &position, const Color&& color) -> void {
    switch (types) {
        case FontTypes::SIZE_12:
            DrawTextEx(m_fonts.size_12,
                       text.c_str(), position, game::ui::SIZE_12, 1, color);
            break;
        case FontTypes::SIZE_16:
            DrawTextEx(m_fonts.size_16,
                       text.c_str(), position, game::ui::SIZE_16, 1, color);
            break;
        case FontTypes::SIZE_20:
            DrawTextEx(m_fonts.size_20,
                       text.c_str(), position, game::ui::SIZE_20, 1, color);
            break;
        default:
            DrawTextEx(m_fonts.size_12,
                       text.c_str(), position, game::ui::SIZE_12, 1, color);
            break;
    }
}

auto Text::Unload() -> void {
    UnloadFont(m_fonts.normal); // TODO: retirar depois de ajeitas todos os botões
    UnloadFont(m_fonts.size_12);
    UnloadFont(m_fonts.size_16);
    UnloadFont(m_fonts.size_20);
}
