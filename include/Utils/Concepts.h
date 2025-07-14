#ifndef CONCEPTS_H
#define CONCEPTS_H
#include <string>

#include "raylib.h"

template<typename T>
concept HasImageTexture = requires(T t)
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

#endif //CONCEPTS_H
