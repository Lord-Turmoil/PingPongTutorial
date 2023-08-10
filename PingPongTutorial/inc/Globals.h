#pragma once

#ifndef _GLOBALS_H_
#define _GLOBALS_H_

class Application;
Application* GetApplication();

extern bool isRunning;

const int SINGLE_PLAYER = 0;
const int DOUBLE_PLAYER = 1;

extern int gameMode;

#endif