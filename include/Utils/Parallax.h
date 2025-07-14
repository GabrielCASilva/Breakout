#ifndef PARALLAX_H
#define PARALLAX_H

#include <iostream>
#include <print>
#include <bits/ostream.tcc>

#include "DrawSprite.h"

template<typename T>
concept CanParallax = requires(T t)
{
    { t.GetPosition() } -> std::same_as<Vector2 &>;
    { t.GetTexture() } -> std::same_as<Texture &>;
    { t.GetImage() } -> std::same_as<Image &>;
};

template<typename Coll>
concept CanLoadUnload = requires(Coll c, const std::string &v)
{
    { c.Unload() } -> std::same_as<void>;
    { c.LoadTexture(v) } -> std::same_as<void>;
};

template<typename T>
    requires CanParallax<T> && CanLoadUnload<T>
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

    ~Parallax() { delete m_sprite; }

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
            DrawSprite::Draw(texture, position);
            const Vector2 new_position{
                m_speed.x > 0.f ? position.x + texture.width * game::SCALE : position.x,
                m_speed.y > 0.f ? position.y + texture.height * game::SCALE : position.y,
            };
            DrawSprite::Draw(texture, new_position);
        }
    }

    auto LoadSprite(const std::string &&file) -> void { m_sprite->LoadTexture(file); }

    auto UnloadSprite() const -> void { m_sprite->Unload(); }

    auto SetPosition(const Vector2 &pos) -> void { m_sprite->SetPosition(pos); }

    auto SetSpeed(const Vector2 &speed) -> void { m_speed = speed; }

    auto SetDisable(bool &&disable) -> void { m_disable = disable; }

private:
    pointer m_sprite{new T()};
    Vector2 m_speed{0.f, 0.f};
    bool m_disable = false;
};

#endif //PARALLAX_H
