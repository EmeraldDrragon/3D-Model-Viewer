cmake_minimum_required(VERSION 3.13)

include(pico-sdk/pico_sdk_init.cmake)

project(3D_Model_viewer C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

pico_sdk_init()

add_executable(${PROJECT_NAME}
        source/main.c
        source/ssd1306.c
        source/ssd1306.h
        source/as5600.c
        source/as5600.h
        source/model/model.h
        source/model/model_data.c
        source/model/model_data.h
        source/render/display.c
        source/render/display.h
        source/render/projection.c
        source/render/projection.h
        source/render/renderer.c
        source/render/renderer.h
        source/render/scarray.c
        source/render/scarray.h
        source/buttons.c
        source/gpio.c
)

target_include_directories(${PROJECT_NAME} PRIVATE
        include)

target_link_libraries(${PROJECT_NAME} PRIVATE
        pico_stdlib)

pico_add_extra_outputs(${PROJECT_NAME})

pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)