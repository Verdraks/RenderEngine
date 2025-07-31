include(FetchContent)

function(add_git_dependency NAME GIT_URL GIT_TAG)

	if (TARGET ${NAME})
		message(STATUS "Target ${NAME} already exists, skipping re-declaration.")
		return()
	endif()

	find_package(Git QUIET)

	if (Git_FOUND)
		FetchContent_Declare(
            ${NAME}
            GIT_REPOSITORY ${GIT_URL}
            GIT_TAG ${GIT_TAG}
        )
		FetchContent_MakeAvailable(${NAME})
	
	else()
		message(STATUS "Git not found, skipping download of ${NAME}")
	endif()
endfunction()

add_git_dependency(glfw https://github.com/glfw/glfw 3.4)
add_subdirectory(glad-2.0.8)