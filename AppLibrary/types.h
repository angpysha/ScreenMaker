#pragma once
#include <bemapiset.h>
#include <string>
#include <map>
#include <vector>
#include <list>
using uint = unsigned int;

#ifdef APPLIBRARY_EXPORTS
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __declspec(dllimport)
#endif

#ifdef DLLEXPORT
#define EXPORTDLL __declspec(dllexport)
#else
#define EXPORTDLL __declspec(dllexport)
#endif

using KeyCode = std::map<std::string, uint>;
