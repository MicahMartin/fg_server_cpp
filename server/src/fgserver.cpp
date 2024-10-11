#include "fgserver.h"
#include "ggponet.h"
#include <filesystem>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

FGServer *fgServer;

GGPOSession *ggpo;
GGPOPlayer p1, p2;
GGPOPlayerHandle player_handles[2];
GGPOPlayerHandle local_player_handle;

godot::Input *InputServer;

void FGServer::_bind_methods() {}

FGServer::FGServer() { UtilityFunctions::print("engine constructor"); }

FGServer::~FGServer() { UtilityFunctions::print("engine destructor"); }

void FGServer::enter() {
  UtilityFunctions::print(std::filesystem::current_path().c_str());
}

void FGServer::_process(double delta) {}

void FGServer::_ready() {
  if (Engine::get_singleton()->is_editor_hint()) {
    return;
  }
  InputServer = godot::Input::get_singleton();
  UtilityFunctions::print("in ready");
}
