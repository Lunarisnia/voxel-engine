# Configure SDL by calling its CMake file.
# we use EXCLUDE_FROM_ALL so that its install targets and configs don't
# pollute upwards into our configuration.
# add_subdirectory(SDL EXCLUDE_FROM_ALL)

# GLM
# add_subdirectory(glm EXCLUDE_FROM_ALL)

# SDL_image (used for loading various image formats)
# set(SDLIMAGE_VENDORED ON)
# set(SDLIMAGE_AVIF OFF)	# disable formats we don't use to make the build faster and smaller.
# set(SDLIMAGE_BMP OFF)
# set(SDLIMAGE_JPEG OFF)
# set(SDLIMAGE_WEBP OFF)
# add_subdirectory(SDL_image EXCLUDE_FROM_ALL)



# glad
add_library(glad STATIC glad.c)
target_include_directories(glad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# glfw
add_subdirectory(glfw EXCLUDE_FROM_ALL)

# Add library named vendor as an interface
add_library(vendor INTERFACE)

target_link_libraries(vendor INTERFACE glad)
target_link_libraries(vendor INTERFACE glfw)

# target_link_libraries(vendor INTERFACE SDL3::SDL3)
# target_link_libraries(vendor INTERFACE glm::glm)
# target_link_libraries(vendor INTERFACE SDL3_image::SDL3_image)
# target_link_libraries(vendor INTERFACE SDL3_ttf::SDL3_ttf)
