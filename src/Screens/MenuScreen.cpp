#include "Screens/MenuScreen.h"
#include <raylib.h>

#include "Textures/TextureAtlas.h"

auto MenuScreen::Init() -> void {
    m_bg.LoadTexture("title_screen_bg");
    m_bg_planets.LoadTexture("title_screen_planets");
}
auto MenuScreen::Update(float dt) -> void {
    m_ui->Update();
}
auto MenuScreen::Draw() -> void {
    m_bg.Draw();
    m_bg_planets.Draw();


    const Rectangle &texture = TextureAtlas<TextureEntities>::GetTextureImage(TextureEntities::TITLE);
    TextureAtlas<TextureEntities>::DefineTexture(texture,
        {game::WINDOW_WIDTH / 2.0f,game::WINDOW_HEIGHT / 3.0f},
        {texture.width / 2, texture.height / 2});

    m_ui->Draw();
}
auto MenuScreen::Exit() -> void {
    m_bg.UnloadBackgroundImage();
    m_bg.UnloadBackgroundTexture();
    m_bg_planets.UnloadBackgroundImage();
    m_bg_planets.UnloadBackgroundTexture();
}
