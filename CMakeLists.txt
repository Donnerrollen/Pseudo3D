cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME Pseudo3D)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_DIR "${CMAKE_SOURCE_DIR}/SFML/lib/cmake/SFML")
find_package(SFML 3.0 COMPONENTS Graphics Window System Audio REQUIRED)


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
)

target_link_libraries(Engine
	PUBLIC
		SFML::Graphics
        SFML::Window 
        SFML::System
        SFML::Audio

)


#Тесты
add_executable(simple_tests
	tests/simple_tests.cpp
)

target_link_libraries(simple_tests 
    PRIVATE 
		Engine
)
    
foreach(DLL_NAME sfml-graphics-3 sfml-window-3 sfml-system-3 sfml-audio-3)
    add_custom_command(TARGET simple_tests POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/SFML/bin/${DLL_NAME}.dll"
        $<TARGET_FILE_DIR:simple_tests>
    )
endforeach()

foreach(DLL_NAME sfml-graphics-d-3 sfml-window-d-3 sfml-system-d-3 sfml-audio-d-3)
    add_custom_command(TARGET simple_tests POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/SFML/bin/${DLL_NAME}.dll"
        $<TARGET_FILE_DIR:simple_tests>
    )
endforeach()