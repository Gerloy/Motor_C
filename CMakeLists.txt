cmake_minimum_required(VERSION 3.0.0)
project(Motor2D VERSION 0.1.0)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(SDL2 REQUIRED)

include_directories(
	${SDL2_INCLUDE_DIRS} 
	${SDL2_IMAGE_INCLUDE_DIRS}
	${CMAKE_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCE_FILES src/*.c)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(Motor2D
	main.c 
	${SOURCE_FILES})

#Copia archivos de res a build
#add_custom_command(TARGET Motor2D POST_BUILD 
#	COMMAND ${CMAKE_COMMAND} -E copy_directory 
#	${PROJECT_SOURCE_DIR} /res
#	${PROJECT_BINARY_DIR} /res
#	COMMENT "Copiando res a la build")

target_include_directories(Motor2D PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(Motor2D
	GLEW::glew
	OpenGL::GL
	SDL2::SDL2
	SDL2_image
	)
