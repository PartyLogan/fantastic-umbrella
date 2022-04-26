
#include <SDL.h>

#include <libtcod.hpp>

#include "Engine.hpp"

Engine engine;

int main(int argc, char** argv) {
  auto console = tcod::Console{80, 45};  // Main console.

  // Configure the context.
  auto params = TCOD_ContextParams{};
  params.tcod_version = TCOD_COMPILEDVERSION;  // This is required.
  params.console = console.get();  // Derive the window size from the console size.
  params.window_title = "Libtcod Project";
  params.sdl_window_flags = SDL_WINDOW_RESIZABLE;
  params.vsync = true;
  params.argc = argc;  // This allows some user-control of the context.
  params.argv = argv;

  auto context = tcod::new_context(params);
  // Game loop.
  while (true) {
    TCOD_console_clear(console.get());
    engine.update();
    engine.render(console);
    context->present(console);
  }
}
