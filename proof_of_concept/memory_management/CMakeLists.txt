add_library(memory_management
    memory_management.c
)

target_include_directories(memory_management
	PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)