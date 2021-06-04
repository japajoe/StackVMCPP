cmake_minimum_required(VERSION 3.5.1)
project(stackvm)

# Add sources
file(GLOB SOURCES
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

# Will add __FILENAME__ macros for all source files, which is the filename without full find_path
# Courtesy of SO
function(define_file_basename_for_sources targetname)
    get_target_property(source_files "${targetname}" SOURCES)
    foreach(sourcefile ${source_files})
        # Get source file's current list of compile definitions.
        get_property(defs SOURCE "${sourcefile}"
            PROPERTY COMPILE_DEFINITIONS)
        # Add the FILE_BASENAME=filename compile definition to the list.
        get_filename_component(basename "${sourcefile}" NAME)
        list(APPEND defs "__FILENAME__=\"${basename}\"")
        # Set the updated compile definitions on the source file.
        set_property(
            SOURCE "${sourcefile}"
            PROPERTY COMPILE_DEFINITIONS ${defs})
    endforeach()
endfunction()


# Specify include Directory
include_directories(
    "${PROJECT_SOURCE_DIR}/include"
)

add_executable(${PROJECT_NAME} ${SOURCES})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

# set this for adding debug symbols
# set (CMAKE_CXX_FLAGS "-pg")

define_file_basename_for_sources(${PROJECT_NAME})

install(TARGETS ${PROJECT_NAME} DESTINATION /usr/local/lib)
