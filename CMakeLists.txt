cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME Pseudo3D)
project(${PROJECT_NAME})

add_library(Engine STATIC
	src/Entity.cpp
	src/Map.cpp
	src/Player.cpp
	src/RayCasting.cpp
	src/Game.cpp
)

target_include_directories(Engine
	PUBLIC
		${PROJECT_SOURCE_DIR}/include
)

#Тесты
add_executable(simple_tests
	tests/simple_tests.cpp
)

target_link_libraries( simple_tests
    PRIVATE 
        Engine
)