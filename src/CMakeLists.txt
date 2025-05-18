# Add the source files
add_executable(${PROJECT_NAME} 
	main.cpp 
	voxel_window/voxel_window.cpp
)

# Link to vendor
target_link_libraries(${PROJECT_NAME} vendor)
