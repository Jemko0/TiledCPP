#pragma once

#ifdef BUILDING_ENGINE_DLL
#ifdef _WIN32
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __attribute__((visibility("default")))
#endif
#else
#ifdef _WIN32
#define ENGINE_API __declspec(dllimport)
#else
#define ENGINE_API
#endif
#endif