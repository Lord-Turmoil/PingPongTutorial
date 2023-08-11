// Copyright (C) 2018 - 2023 Tony's Studio. All rights reserved.
// Licensed under the MIT License.

#include "../../inc/ui/Application.h"
#include "../../inc/ui/Interface.h"

Application::Application()
    : _currentInterface(nullptr), _nextInterface(nullptr)
{
}

Application::~Application()
{
    for (auto it : _interfaces)
    {
        delete it.second;
    }
}

Application* Application::RegisterInterface(Interface* intf)
{
    _interfaces.emplace(intf->Name(), intf);
    if (!_currentInterface)
    {
        _currentInterface = intf;
    }
    return this;
}

// Set to target interface immediately
void Application::SetInterface(const std::wstring& name)
{
    auto it = _interfaces.find(name);
    if (it == _interfaces.end())
    {
        return;
    }
    _currentInterface = it->second;
    _nextInterface = nullptr;
}

// Set to target interface after current update
void Application::ChangeInterface(const std::wstring& name)
{
    auto it = _interfaces.find(name);
    if (it == _interfaces.end())
    {
        return;
    }
    _nextInterface = it->second;
}

void Application::Update()
{
    if (_currentInterface)
    {
        _currentInterface->Update();
    }

    if (_nextInterface && _nextInterface != _currentInterface)
    {
        _currentInterface->OnExit();
        _nextInterface->OnEnter();
        _currentInterface = _nextInterface;
        _nextInterface = nullptr;
    }
}

void Application::Draw()
{
    if (_currentInterface)
    {
        _currentInterface->Draw();
    }
}
