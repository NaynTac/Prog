project('DVD_Screensaver', 'c', version: '1.0')


sdl2 = dependency('sdl2')
sdl2_image = dependency('sdl2_image')


run_command('cp', '-r', 'img', meson.current_build_dir())


executable('dvd_screensaver',
    sources: ['main.c', 'graphics.c'],
    dependencies: [sdl2, sdl2_image],
    install: false)