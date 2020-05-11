cmake_minimum_required(VERSION 2.8)

project(template)

IF(CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")
ENDIF(CMAKE_COMPILER_IS_GNUCC)

if(NOT DEFINED ENV{ARCH})
        message(STATUS "ARCH not set, use 'orignal gcc/g++' default.")
        SET (TRIPLETT "")
elseif( $ENV{ARCH} STREQUAL "x86_64")
        SET (TRIPLETT "x86_64-linux-gnu-")
elseif( $ENV{ARCH} STREQUAL "arm64")
        SET (TRIPLETT "aarch64-linux-gnu-")
else()
	message(FATAL_ERROR "Unknow arch: $ENV{ARCH}.")
endif()

set (CMAKE_CXX_COMPILER           "${TRIPLETT}g++")
set (CMAKE_C_COMPILER             "${TRIPLETT}gcc")


# for qt creator, to show all files
file(GLOB_RECURSE
  all_file "*"
  )
list(REMOVE_ITEM all_file "${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt.user")
list(REMOVE_ITEM all_file "${CMAKE_CURRENT_SOURCE_DIR}/.gitignore")
add_custom_target(headers SOURCES ${all_file})


include_directories(${CMAKE_CURRENT_SOURCE_DIR}
	inc
	${CMAKE_CURRENT_SOURCE_DIR}/../libstdc++-v3-build/out/usr/include/c++/9.3.0
	${CMAKE_CURRENT_SOURCE_DIR}/../libstdc++-v3-build/out/usr/include/x86_64-linux-gnu/c++/9.3.0
	)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/../libstdc++-v3-build/out/usr/lib
	)

set( lib_sources
   lib/test.cpp
   inc/test.h
)

set( app_sources
   src/main.cpp
)

set( PUBLIC_HEADER_FILES
   inc/test.h
)

add_library (template_lib SHARED ${lib_sources})
set_target_properties(template_lib PROPERTIES
                        PUBLIC_HEADER "${PUBLIC_HEADER_FILES}"
                        VERSION "1.0.0.1"
                        SOVERSION "1"
                     )

add_executable(${PROJECT_NAME} ${app_sources} )

target_link_libraries( ${PROJECT_NAME}
pthread
template_lib
stdc++fs
)

# install library(include), application
install(TARGETS ${PROJECT_NAME} template_lib
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include)


#install(TARGETS ${PROJECT_NAME} DESTINATION myproject_name)

# install script
set( TOOLS_SCRIPTS
   tools/test.sh
)

install(PROGRAMS ${TOOLS_SCRIPTS}
	DESTINATION bin)

# install configration file
set( CONFIG_FILES
   etc/config.json
)
install(FILES ${CONFIG_FILES}
	DESTINATION etc)
