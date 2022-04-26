//
// Created by logan on 26/04/22.
//

#ifndef FANTASTIC_UMBRELLA_ACTOR_HPP
#define FANTASTIC_UMBRELLA_ACTOR_HPP

#include <libtcod.hpp>

#include "libtcod/color.hpp"
class Actor {
 public:
  int x, y;
  int glyph;
  TCOD_color_t col;

  Actor(int x, int y, int glyph, const TCOD_color_t& col);
  void render(tcod::Console& console) const;
};

#endif  // FANTASTIC_UMBRELLA_ACTOR_HPP
