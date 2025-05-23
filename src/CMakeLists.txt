# Add the source files
add_executable(${PROJECT_NAME} 
	main.cpp 
	# VoxelEngine
	core/voxel_engine/voxel_engine.cpp

	# VoxelWindow
	core/voxel_window/voxel_window.cpp

	# InputManager
	core/input_manager/key_event.cpp
	core/input_manager/input_manager.cpp

	# Resource
	core/resource/resource.cpp

	# Shader
	core/shader/shader.cpp

	# Error handling
	core/error_handling/gl_error.cpp
	
	# Components
	core/components/component.cpp
	core/components/mesh.cpp
	core/components/transform.cpp

	# Material
	core/material/material.cpp

	# Object
	core/object/object.cpp

	# Renderer
	core/renderer/renderer.cpp
	
	# Utils
	core/utilities/object_primitives.cpp
	core/utilities/procedural_mesh.cpp

	# World
	core/world/world.cpp

	# Logger
	core/log/logger.cpp
)

# inlcude
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Link to vendor
target_link_libraries(${PROJECT_NAME} vendor)
