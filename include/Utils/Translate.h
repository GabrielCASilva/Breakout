#ifndef TRANSLATE_H
#define TRANSLATE_H
#include "Concepts.h"
#include "Constants.h"
#include "DrawSprite.h"

#endif //TRANSLATE_H

template<typename T>
    requires HasImageTexture<T> && CanLoadUnload<T>
class Translate {
public:
    using value_type = T;
    using pointer = T *;
    using const_reference = const T &;
    using rvalue_reference = T &&;
    using reference = T &;

    Translate() = default;

    explicit Translate(const_reference) = delete;

    explicit Translate(rvalue_reference) = delete;

    ~Translate() {
        delete m_sprite;
    }

    reference operator=(const_reference) = delete;

    reference operator=(rvalue_reference) = delete;

    auto Update(const float dt) -> void {
        if (!m_disable) {
            const auto&[x, y] = GetPosition();
            const Vector2 new_position {
                x + m_translate.x * dt * m_direction.x,
                y + m_translate.y * dt * m_direction.y
            };
            SetPosition(new_position);
        }
    }

    auto Draw() -> void {
        if (!m_disable) {
            const Texture2D &texture = m_sprite->GetTexture();
            const Vector2 &position = m_sprite->GetPosition();
            DrawSprite::Draw(texture, position);
        }
    }

    auto LoadSprite(const std::string &&file) -> void { m_sprite->LoadTexture(file); }

    auto UnloadSprite() const -> void { m_sprite->Unload(); }

    auto SetPosition(const Vector2 &position) -> void { m_sprite->SetPosition(position); }

    auto SetInitPosition(const Vector2 &position) -> void { m_init_position = position; }

    auto SetDisable(bool &&disable) -> void { m_disable = disable; }

    auto SetDirection(const Vector2 &direction) -> void { m_direction = direction; }

    auto SetTranslate(const Vector2 &translate) -> void { m_translate = translate; }

    [[nodiscard]] auto GetPosition() const -> const Vector2 & { return m_sprite->GetPosition(); }

    [[nodiscard]] auto GetTexture() const -> const Texture2D & { return m_sprite->GetTexture(); }

    [[nodiscard]] auto GetDirection() const -> const Vector2 & { return m_direction; }

    [[nodiscard]] auto Translation() const -> const Vector2 & {
        const Vector2 & translation {
            GetPosition().x - m_init_position.x,
            GetPosition().y - m_init_position.y
        };
        return translation;
    }

    [[nodiscard]] auto GetTranslate() const -> const Vector2 & { return m_translate; }

private:
    pointer m_sprite{new T()};
    Vector2 m_init_position{0.f, 0.f};
    bool m_disable{false};
    Vector2 m_direction{1,1};
    Vector2 m_translate{0.f, 0.f};
};
