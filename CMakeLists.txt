cmake_minimum_required (VERSION 3.8)

set(BlackboxProjectName blackbox)
set(BlackboxLibraryName lib_blackbox)

project(${BlackboxProjectName})

set(BuildExamples TRUE)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
	set(PlatformName "x64")
elseif(EMSCRIPTEN)
	set(PlatformName "wasm")
	set(BuildExamples FALSE)
else()
	set(PlatformName "x32")
endif()

set(BinDirectory ${CMAKE_SOURCE_DIR}/bin/${PlatformName}/$<CONFIG>)
set(LibDirectory ${CMAKE_SOURCE_DIR}/lib/${PlatformName}/$<CONFIG>)

set(CMAKE_STATIC_LIBRARY_PREFIX "")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BinDirectory} )
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LibDirectory} )
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LibDirectory} )

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory("src")
add_subdirectory("emscripten")
add_subdirectory("examples")