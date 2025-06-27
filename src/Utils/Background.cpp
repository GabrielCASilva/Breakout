#include "Utils/Background.h"

#include "Utils/Constants.h"

#include "raylib.h"

auto Background::LoadAnimatedTexture(std::string &&file) -> void {
    m_image = LoadImageAnim((game::ROOT + "assets/sprites/" + file + ".gif").c_str(), &m_frame);
    m_texture = LoadTextureFromImage(m_image);
}

auto Background::Draw() const -> void {
    DrawTexture(m_texture, m_position.x, m_position.y, WHITE);
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

auto Background::UnloadBackgroundTexture() const -> void {
    UnloadTexture(m_texture);
}

auto Background::UnloadBackgroundImage() const -> void {
    UnloadImage(m_image);
}
