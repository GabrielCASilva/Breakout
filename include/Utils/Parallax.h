#ifndef PARALLAX_H
#define PARALLAX_H

#include "Concepts.h"
#include "DrawSprite.h"

template<typename T>
    requires HasImageTexture<T> && CanLoadUnload<T>
class Parallax {
public:
    using value_type = T;
    using pointer = T *;
    using const_reference = const T &;
    using rvalue_reference = T &&;
    using reference = T &;

    Parallax() = default;

    explicit Parallax(const_reference) = delete;

    explicit Parallax(rvalue_reference) = delete;

    ~Parallax() {
        delete m_sprite;
        m_disable = true;
    }

    reference operator=(const_reference) = delete;

    reference operator=(rvalue_reference) = delete;

    auto Update(const float dt) -> void {
        if (!m_disable) {
            const Texture2D &texture = m_sprite->GetTexture();
            Vector2 &position = m_sprite->GetPosition();
            if (m_speed.y) {
                position.y -= m_speed.y * dt;
                if (position.y <= -texture.height * game::SCALE) position.y = 0;
            }
            if (m_speed.x) {
                position.x -= m_speed.x * dt;
                if (position.x <= -texture.width * game::SCALE) position.x = 0;
            }
        }
    }

    auto Draw() -> void {
        if (!m_disable) {
            const Texture2D &texture = m_sprite->GetTexture();
            const Vector2 &position = m_sprite->GetPosition();
            DrawSprite::Draw(texture, position, m_flip);
            const Vector2 new_position{
                m_speed.x > 0.f ? position.x + texture.width * game::SCALE : position.x,
                m_speed.y > 0.f ? position.y + texture.height * game::SCALE : position.y,
            };
            DrawSprite::Draw(texture, new_position, m_flip);
        }
    }

    auto LoadSprite(const std::string &&file) -> void { m_sprite->LoadTexture(file); }

    auto UnloadSprite() const -> void { m_sprite->Unload(); }

    auto SetPosition(const Vector2 &pos) -> void { m_sprite->SetPosition(pos); }

    auto SetSpeed(const Vector2 &speed) -> void { m_speed = speed; }

    auto SetDisable(bool &&disable) -> void { m_disable = disable; }

    auto SetFlip(const FlipImage &flip) -> void { m_flip = flip; }

    [[nodiscard]] auto GetFlip() const -> const FlipImage & { return m_flip; }

private:
    pointer m_sprite{new T()};
    Vector2 m_speed{0.f, 0.f};
    bool m_disable = false;
    FlipImage m_flip{1,1};
};

#endif //PARALLAX_H
