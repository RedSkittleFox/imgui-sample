cmake_minimum_required(VERSION 3.21)

project(imgui-sample)

include(FetchContent)

if(PROJECT_IS_TOP_LEVEL)
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
    	
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin-lib")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin-etc")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
    
    set(CMAKE_CXX_STANDARD 23)
    set(CMAKE_CXX_STANDARD_REQUIRED)

    set(IMGUI_SAMPLE_BUILD_SAMPLE ON CACHE BOOL "")
endif()

option(IMGUI_SAMPLE_GIT_TAG "Tag of the commit, branch or release of the imgui." "master")
option(IMGUI_SAMPLE_GIT_GLFW "Tag of the commit, branch or release of the GLFW." "master")
option(IMGUI_SAMPLE_BUILD_SAMPLE "Should the imgui-sample sample be built." OFF)

FetchContent_Declare(
    imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG        ${IMGUI_SAMPLE_GIT_TAG}
)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG        ${IMGUI_SAMPLE_GIT_GLFW}
)

find_package(OpenGL REQUIRED)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(imgui glfw)

# GLFW config only for now
if(TRUE)
    set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/glfw")
    if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/glfw")
        file(MAKE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/glfw")
        # Copy required source files
        file(
            COPY 
                "${CMAKE_CURRENT_SOURCE_DIR}/source/library.cpp" 

                "${imgui_SOURCE_DIR}/imconfig.h"
                "${imgui_SOURCE_DIR}/imgui.cpp"
                "${imgui_SOURCE_DIR}/imgui.h"
                "${imgui_SOURCE_DIR}/imgui_draw.cpp"
                "${imgui_SOURCE_DIR}/imgui_internal.h"
                "${imgui_SOURCE_DIR}/imgui_tables.cpp"
                "${imgui_SOURCE_DIR}/imgui_widgets.cpp"
                "${imgui_SOURCE_DIR}/imstb_rectpack.h"
                "${imgui_SOURCE_DIR}/imstb_textedit.h"
                "${imgui_SOURCE_DIR}/imstb_truetype.h"
                "${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp"
                "${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.h"
                "${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.h"
                "${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp"
                "${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3_loader.h"

                "${imgui_SOURCE_DIR}/examples/example_glfw_opengl3/main.cpp"
            DESTINATION 
                ${SRC_DIR}
            )
    endif()
    add_library(
        imgui_sample    
        "${SRC_DIR}/library.cpp"

        "${SRC_DIR}/imconfig.h"
        "${SRC_DIR}/imgui.cpp"
        "${SRC_DIR}/imgui.h"
        "${SRC_DIR}/imgui_draw.cpp"
        "${SRC_DIR}/imgui_internal.h"
        "${SRC_DIR}/imgui_tables.cpp"
        "${SRC_DIR}/imgui_widgets.cpp"
        "${SRC_DIR}/imstb_rectpack.h"
        "${SRC_DIR}/imstb_textedit.h"
        "${SRC_DIR}/imstb_truetype.h"
        "${SRC_DIR}/imgui_impl_glfw.cpp"
        "${SRC_DIR}/imgui_impl_glfw.h"
        "${SRC_DIR}/imgui_impl_opengl3.h"
        "${SRC_DIR}/imgui_impl_opengl3.cpp"
        "${SRC_DIR}/imgui_impl_opengl3_loader.h"

        "${SRC_DIR}/main.cpp"
    )

    target_link_libraries(
        imgui_sample
        PRIVATE
        OpenGL::GL
        glfw
    )

    target_include_directories(
        imgui_sample
        PUBLIC
        "${SRC_DIR}"
    )

    add_library(fox::imgui_sample ALIAS imgui_sample)
endif()

if(IMGUI_SAMPLE_BUILD_SAMPLE)
    add_subdirectory("sample")
endif()
