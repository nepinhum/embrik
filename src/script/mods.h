#pragma once

#include <filesystem>
#include <string>
#include <vector>

#include "state.h"

struct Mods {
    static void load(flecs::world world);
    static auto require(flecs::world world, const std::string& path) -> LuaRef;
    // Key for ScriptState::events_at; the line is 1-based as Lua reports it.
    static auto call_site(const std::string& chunk, int line) -> std::string;

   private:
    static auto resolve_order(flecs::world world) -> std::vector<std::filesystem::path>;
};
