#pragma once

#include "gdkmm/rgba.h"
#include "glibmm/ustring.h"

typedef struct {
        Glib::ustring name;
        Gdk::RGBA axes;
        Gdk::RGBA background_one;
        Gdk::RGBA background_two;
} CairoGraphTheme;

const CairoGraphTheme FADE_TO_BLACK {
    .name = Glib::ustring("Herculean Blue"),
    .axes = Gdk::RGBA(1.0, 1.0, 1.0, 0.80),
    .background_one = Gdk::RGBA(0.0, 0.0, 0.0, 1.0),
    .background_two = Gdk::RGBA(0.28, 0.28, 0.28, 1.0),
};

const CairoGraphTheme HERCULEAN_BLUE { };
