cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME Pseudo3D)
project(${PROJECT_NAME})

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
    add_compile_options("$<$<CONFIG:Debug>:/MDd>")
    add_compile_options("$<$<CONFIG:Release>:/MD>")
endif()

set(SFML_DIR "${PROJECT_SOURCE_DIR}/SFML/lib/cmake/SFML")
find_package(SFML 2.6.2 COMPONENTS graphics window system audio REQUIRED)

add_library(Engine STATIC
	src/Entity.cpp
	src/Map.cpp
	src/Player.cpp
	src/RayCasting.cpp
	src/Game.cpp
	src/config.cpp
	src/DDACollision.cpp
	src/SFMLKeyboard.cpp
	src/InputState.cpp
)

target_include_directories(Engine
	PUBLIC
		${PROJECT_SOURCE_DIR}/include
		${PROJECT_SOURCE_DIR}/SFML/include
)

target_link_libraries(Engine PUBLIC
    sfml-graphics
    sfml-window 
    sfml-system
    sfml-audio
)


#Тесты
add_executable(simple_tests
	tests/simple_tests.cpp
)

target_link_libraries(simple_tests 
    PRIVATE 
		Engine
)

if(WIN32)
    # Для Debug сборки
    add_custom_command(TARGET simple_tests POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "$<$<CONFIG:Debug>:${PROJECT_SOURCE_DIR}/SFML/bin/sfml-graphics-d-2.dll>"
        "$<$<CONFIG:Debug>:${PROJECT_SOURCE_DIR}/SFML/bin/sfml-window-d-2.dll>"
        "$<$<CONFIG:Debug>:${PROJECT_SOURCE_DIR}/SFML/bin/sfml-system-d-2.dll>"
        "$<$<CONFIG:Debug>:${PROJECT_SOURCE_DIR}/SFML/bin/sfml-audio-d-2.dll>"
        "$<$<CONFIG:Release>:${PROJECT_SOURCE_DIR}/SFML/bin/sfml-graphics-2.dll>"
        "$<$<CONFIG:Release>:${PROJECT_SOURCE_DIR}/SFML/bin/sfml-window-2.dll>"
        "$<$<CONFIG:Release>:${PROJECT_SOURCE_DIR}/SFML/bin/sfml-system-2.dll>"
        "$<$<CONFIG:Release>:${PROJECT_SOURCE_DIR}/SFML/bin/sfml-audio-2.dll>"
        $<TARGET_FILE_DIR:simple_tests>
    )
endif()