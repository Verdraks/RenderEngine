add_library(stb STATIC)

target_sources(stb PRIVATE
    "src/stb_impl.cpp"
)
target_include_directories(stb PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)