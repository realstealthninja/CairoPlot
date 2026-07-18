#pragma once

#include "cairoplot/themes.hpp"
#include "options.hpp"

#include <cairomm/cairomm.h>
#include <cairomm/context.h>
#include <gdk/gdkkeysyms.h>
#include <gdkmm/general.h>
#include <gdkmm/pixbuf.h>
#include <glibmm.h>
#include <glibmm/i18n.h>
#include <gtkmm/drawingarea.h>
#include <gtkmm/entry.h>
#include <gtkmm/eventcontrollermotion.h>
#include <gtkmm/gesture.h>
#include <gtkmm/gestureclick.h>
#include <gtkmm/grid.h>
#include <gtkmm/label.h>
#include <gtkmm/window.h>

namespace CGraph {
class CairoGraph : public Gtk::DrawingArea {
    public:
        explicit CairoGraph();
        ~CairoGraph() { }

        // thou shallt not do the following
        CairoGraph(const CairoGraph&) = delete;
        CairoGraph(CairoGraph&&) = delete;
        CairoGraph& operator=(const CairoGraph& other) = delete;
        CairoGraph& operator=(CairoGraph&&) = delete;

        // public methods
        // complete graph with motion tracker
        Gtk::Grid& create_graph();

        // motion tracker widget that diplays the x and y values following the cursor
        Gtk::Grid& get_motion_tracker();

        // widgets one can use and have access to for custom layouts
        Gtk::Grid& get_cursor_grid() { return *cursor_grid; }
        Gtk::Grid& get_graph_grid() { return *grid; }
        Gtk::Entry& get_xvalue_entry() { return *xvalue; }
        Gtk::Entry& get_yvalue_entry() { return *yvalue; }
        Gtk::Label& get_xvalue_label() { return *xvaluelabel; }
        Gtk::Label& get_yvalue_label() { return *yvaluelabel; }

        // graph methods
        void update_graph();
        void set_line_width(const double linewidth);
        void set_background_colour(const Gdk::RGBA colour1, const Gdk::RGBA colour2);
        void set_background_colour(const Gdk::RGBA colour1);

        void set_axes_labels(const Glib::ustring& xlabel, const Glib::ustring& ylabel,
            Glib::ustring fontfamily = _("Nimbus Roman"));

        void set_tick_label_format_x(const bool showpointx, const int precision);
        void set_tick_label_format_y(const bool showpointy, const int precision);

        void add_multi_series(const std::vector<std::vector<double>>& xvalues,
            const std::vector<std::vector<double>>& yvalues,
            bool make_copy = true);

        void add_series(const std::vector<double>& xvalues,
            const std::vector<double>& yvalues,
            const Gdk::RGBA linecolour,
            const CairoGraphLineStyle style,
            bool make_copy = true);

        void init_plots(size_t numplots);
        void add_point(size_t seriesnum, const double x, const double y, bool update_minmax = true);

        void add_multi_legends(const std::vector<Glib::ustring>& legends, const double offsetx = 0.0, const double offsety = 0.0);
        void add_single_legend(const Glib::ustring& legend, CairoGraphLegendPosition pos, const bool showlinecolour);
        void show_legend(const bool show);
        void set_legend_scale(const double scale);
        const Glib::ustring& get_theme_name() const;
        void use_scientific_notation(const bool scientificx, const bool scientificy);
        void set_line_colour(const size_t seriesnum, Gdk::RGBA colour);
        void add_line_colours(const std::vector<Gdk::RGBA>& colours);
        void set_axes_colour(const Gdk::RGBA colour);
        void set_line_style(const size_t seriesnum, const CairoGraphLineStyle style);
        void add_line_styles(const std::vector<CairoGraphLineStyle>& style);
        void set_graph_box_style(const CairoGraphBoxStyle style);
        void set_title(const Glib::ustring& title);
        void set_theme(const Glib::ustring& theme, bool automatic = true);
        void add_text_objects(const std::vector<std::tuple<Glib::ustring, double, double, double, bool>>& text,
            Glib::ustring text_object_fontfamily = "");

    private:
        double lwidth = 1.0; // default line width
        double xmax;
        double xmin;
        double ymax;
        double ymin;
        double start_x;
        double start_y;
        double end_x;
        double end_y;
        double legend_offsetx = 0.0;
        double legend_offsety = 0.0;
        double legend_scale = 1.0;
        bool selection_mode = false;
        bool draw_zoom = false;
        bool forcescientificx = false;
        bool forcescientificy = false;
        bool legend_show_colour = true;
        bool showlegend = true;
        bool showpointx = false;
        bool showpointy = false;
        unsigned int precisionx = 0;
        unsigned int precisiony = 0;

        struct graph_params {
                double xmin;
                double xmax;
                double ymin;
                double ymax;
                double zoom_factor_x = 1.0;
                double zoom_factor_y = 1.0;
                double zoom_start_x;
                double zoom_end_x;
                double zoom_start_y;
                double zoom_end_y;
        };

        graph_params plot;
        Glib::ustring xmarkuplabel;
        Glib::ustring ymarkuplabel;
        Glib::ustring graph_title;
        Glib::ustring graph_legend;
        Glib::ustring labels_fontfamily;
        std::vector<Glib::ustring> graph_legends;
        std::vector<Gdk::RGBA> seriescolour;
        std::vector<CairoGraphLineStyle> serieslinestyle;
        CairoGraphBoxStyle graphboxstyle;
        CairoGraphLegendPosition legend_pos;
        Glib::ustring current_theme;
        Glib::ustring text_object_font_family;
        Gtk::Grid* grid;
        Gtk::Grid* cursor_grid;
        Gtk::Entry* xvalue;
        Gtk::Entry* yvalue;
        Gtk::Label* xvaluelabel;
        Gtk::Label* yvaluelabel;

        CairoGraphTheme theme;
        Gdk::RGBA bg_colour1;
        Gdk::RGBA bg_colour2;
        Gdk::RGBA axes_colour;
        Gdk::RGBA border_colour;
        Cairo::RefPtr<Cairo::LinearGradient> gradient;
        Glib::RefPtr<Gdk::Cursor> cross_hair_cursor;
        std::vector<std::vector<double>> seriesx; // multi plots
        std::vector<std::vector<double>> seriesy; // multi plots
        std::vector<double*> m_px; // vector of pointers to plots
        std::vector<double*> m_py; // vector of pointers to plots
        std::vector<size_t> numpoints; // number of points in each plot
        std::vector<std::tuple<Glib::ustring, double, double, double, bool>> text_objects;
        Cairo::RefPtr<Cairo::ImageSurface> canvas;

        void create_tickmark_labels(const Cairo::RefPtr<Cairo::Context>& cr);
        void create_labels(const Cairo::RefPtr<Cairo::Context>& cr);
        void create_legends(const Cairo::RefPtr<Cairo::Context>& cr);
        void set_font_scale(const double scale, Pango::FontDescription* font, const int h, const int w) const;
        void draw_series(const Cairo::RefPtr<Cairo::Context>& cr);
        void set_series_colours();
        void clear_series();
        double x_to_graph_coords(const double x) const;
        double y_to_graph_coords(const double y) const;

        // events
        void on_button_release_event(int, double, double);
        void on_button_press_event(int, double, double);
        void reset_event(int, double, double);
        void on_motion_notify_event(double width, double height);

    protected:
        void on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int, int);
};
}