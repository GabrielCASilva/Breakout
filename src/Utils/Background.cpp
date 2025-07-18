#include "Utils/Background.h"

#include "Utils/Constants.h"

#include "raylib.h"

auto Background::LoadAnimatedTexture(std::string &&file) -> void {
    m_image = LoadImageAnim((game::ROOT + "assets/sprites/background/" + file + ".gif").c_str(), &m_frame);
    m_texture = LoadTextureFromImage(m_image);
}

auto Background::LoadTexture(const std::string &file) -> void {
    m_image = LoadImageAnim((game::ROOT + "assets/sprites/background/" + file + ".png").c_str(), &m_frame);
    m_texture = LoadTextureFromImage(m_image);
}

// TODO: remove C like code
auto Background::Draw() const -> void {
    Rectangle source = { 0.0f, 0.0f, (float)m_texture.width, (float)m_texture.height };
    Rectangle dest = { m_position.x, m_position.y, (float)m_texture.width*game::SCALE, (float)m_texture.height*game::SCALE };
    Vector2 origin = { 0.0f, 0.0f };
    DrawTexturePro(m_texture, source, dest, origin, 0.0, WHITE);
}

auto Background::UpdateAnimation() -> void {
    m_frame_count++;
    if (m_frame_count >= m_frame_delay) {
        // Move to next frame
        // NOTE: If final frame is reached we return to first frame
        m_frame_current++;
        if (m_frame_current >= m_frame) m_frame_current = 0;

        // Get memory offset position for next frame data in image.data
        m_next_frame = m_image.width * m_image.height * 4 * m_frame_current;

        // Update GPU texture data with next frame image data
        // WARNING: Data size (frame size) and pixel format must match already created texture
        UpdateTexture(m_texture, static_cast<unsigned char *>(m_image.data) + m_next_frame);

        m_frame_count = 0;
    }
}

auto Background::Unload() const -> void {
    UnloadImage(m_image);
    UnloadTexture(m_texture);
}