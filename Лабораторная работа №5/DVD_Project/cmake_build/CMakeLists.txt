cmake_minimum_required(VERSION 3.10)
project(DVD_Screensaver C)


find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)


add_executable(dvd_screensaver
    main.c
    graphics.c
    graphics.h
)


target_include_directories(dvd_screensaver PRIVATE ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(dvd_screensaver ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})


file(COPY img/DVD_logo.png DESTINATION ${CMAKE_BINARY_DIR}/img)