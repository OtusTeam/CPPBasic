cmake_minimum_required(VERSION 3.14)
project(1-sanitizers VERSION 1.0)

set(CMAKE_BUILD_TYPE "Debug") # explicitly set to Debug

function(setter src_dir args)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${args}")
    aux_source_directory(${src_dir} src)
    message(STATUS "${src}")
    foreach(target ${src})
        message(STATUS "${target}")
        get_filename_component(filename_target ${target} NAME_WE)

        set(src1_wsan ${filename_target}_san)
        set(src1_clean ${filename_target}_clean)

        add_executable(${src1_clean} ${target})
        set_target_properties(${src1_clean} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/without_sanitizers")


        add_executable(${src1_wsan} ${target})
        set_target_properties(${src1_wsan} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/with_sanitizers")
        target_compile_options(${src1_wsan} PRIVATE "${args}")
        target_link_options(${src1_wsan} PRIVATE "${args}")
    endforeach()
endfunction()

setter( "${CMAKE_CURRENT_SOURCE_DIR}/asan/" "-fsanitize=address,undefined,leak" )
setter( "${CMAKE_CURRENT_SOURCE_DIR}/ubsan/" "-fsanitize=address,undefined,leak" )
setter( "${CMAKE_CURRENT_SOURCE_DIR}/tsan/" "-fsanitize=thread" )

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    setter( "${CMAKE_CURRENT_SOURCE_DIR}/msan/" "-fsanitize=memory" )
endif()
