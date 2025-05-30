#include "Screens/MenuScreen.h"
#include <raylib.h>

auto MenuScreen::Init() -> void {}
auto MenuScreen::Update(float dt) -> void {}
auto MenuScreen::Draw() -> void {
    DrawText("Menu Screen", 100, 100, 20, RAYWHITE);
}
auto MenuScreen::Exit() -> void {

}
