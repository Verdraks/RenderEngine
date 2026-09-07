add_library(core INTERFACE)

# target_sources(core PRIVATE "Callback.cpp")

target_include_directories(core INTERFACE
${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(core INTERFACE renderer)