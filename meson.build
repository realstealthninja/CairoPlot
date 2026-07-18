project('libcairoplot',  'cpp', 
          version: '0.2.0',
    meson_version: '>= 0.50.0',
  default_options: [ 'warning_level=2',
                     'cpp_std=c++17',
                   ],
)


gtkmmdeps = [
  dependency('gtkmm-4.0', version: '>= 4.00'),
]

inc = include_directories('include')

libcairoplot = static_library('cairoplot',
    'src/plotter.cpp',
    'src/plottercoords.cpp',
    'src/plotterseries.cpp',
    'src/plotterlabels.cpp',
    'src/plotteroptions.cpp',
    'src/plotterthemes.cpp',
    'src/plotterwidgets.cpp',
    'src/plotterevents.cpp',
  dependencies: gtkmmdeps,
  include_directories : inc,
  install : false)

libcairoplot_dep = declare_dependency(include_directories : inc,
  compile_args : ['-Wall', '-Wextra', '-pedantic', '-Wno-overlength-strings'], # shut up gresource
  link_with : libcairoplot)
