# Add the source files
add_executable(${PROJECT_NAME} 
	main.cpp 
	# VoxelEngine
	voxel_engine/voxel_engine.cpp

	# VoxelWindow
	voxel_window/voxel_window.cpp

	# InputManager
	input_manager/key_event.cpp
	input_manager/input_manager.cpp
)

# inlcude
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Link to vendor
target_link_libraries(${PROJECT_NAME} vendor)
