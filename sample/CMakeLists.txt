cmake_minimum_required(VERSION 3.21)

set(sources 
    "${CMAKE_CURRENT_SOURCE_DIR}/sample.cpp"
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${sources})

add_executable(
    imgui_sample_sample
    ${sources}
)

if(MSVC)
    target_compile_options(
    	imgui_sample_sample
	    PRIVATE /W4 
	    PRIVATE /MP 
	    PRIVATE /arch:AVX2
	    PRIVATE /WX
    )
endif()

target_link_libraries(
    imgui_sample_sample
    fox::imgui_sample
)