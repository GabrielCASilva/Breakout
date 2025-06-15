#include "Screens/MenuScreen.h"
#include <raylib.h>

auto MenuScreen::Init() -> void {}
auto MenuScreen::Update(float dt) -> void {
    m_ui->Update();
}
auto MenuScreen::Draw() -> void {
    m_ui->Draw();
}
auto MenuScreen::Exit() -> void {

}
