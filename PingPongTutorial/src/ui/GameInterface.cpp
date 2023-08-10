#include "../../inc/ui/Interface.h"

GameInterface::GameInterface() : Interface(L"Game") {}

GameInterface::~GameInterface() {}

void GameInterface::OnEnter() {}

void GameInterface::OnExit() {}

void GameInterface::Update() {}

void GameInterface::Draw()
{
    circle(500, 280, 100);
}