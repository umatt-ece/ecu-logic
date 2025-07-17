project(
    'ecu-logic',
    'c',
    version: '0.1.0',
)

project_sources = [
    'src/ecu_logic.c',
]

project_headers = [
    'include/ecu_logic.h',
]

inc = include_directories('include')

lib_ecu_logic = library(
    meson.project_name(),
    project_sources,
    include_directories: inc,
    install: true,
)

lib_ecu_logic_dep = declare_dependency(
    link_with: lib_ecu_logic,
    include_directories: inc,
)

pkg = import('pkgconfig')
pkg.generate(lib_ecu_logic)

install_headers(
    project_headers,
    subdir: 'include',
)

subdir('test')