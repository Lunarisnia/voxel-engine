# Add the source files
add_executable(${PROJECT_NAME} 
	main.cpp 
	# VoxelWindow
	voxel_window/voxel_window.cpp

	# InputManager
	input_manager/key_event.cpp
	input_manager/input_manager.cpp
)

# Link to vendor
target_link_libraries(${PROJECT_NAME} vendor)
