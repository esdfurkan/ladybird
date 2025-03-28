/*
 * Copyright (c) 2022, Andreas Kling <andreas@ladybird.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/Forward.h>
#include <LibGfx/Forward.h>

namespace Web::Platform {

enum class GenericFont {
    Cursive,
    Fantasy,
    Monospace,
    SansSerif,
    Serif,
    UiMonospace,
    UiRounded,
    UiSansSerif,
    UiSerif,
    __Count,
};

class FontPlugin {
public:
    static FontPlugin& the();
    static void install(FontPlugin&);

    virtual ~FontPlugin();

    virtual RefPtr<Gfx::Font> default_font(float point_size) = 0;
    virtual Gfx::Font& default_fixed_width_font() = 0;
    virtual RefPtr<Gfx::Font> default_emoji_font(float point_size) = 0;

    virtual FlyString generic_font_name(GenericFont) = 0;
};

}
