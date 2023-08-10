#include "../../inc/ui/Interface.h"
#include "../../inc/Message.h"
#include "../../inc/Globals.h"
#include "../../inc/ui/Application.h"

GameInterface::GameInterface() : Interface(L"Game") {}

GameInterface::~GameInterface() {}

void GameInterface::OnEnter() {}

void GameInterface::OnExit() {}

void GameInterface::Update()
{
    if (IsKeyDown(VK_ESCAPE))
    {
        GetApplication()->ChangeInterface(L"Main");
    }
}

void GameInterface::Draw()
{
    circle(500, 280, 100);
}