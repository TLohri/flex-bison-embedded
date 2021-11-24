add_executable(memory_test
    Mem_test.c
)

target_link_libraries(memory_test 
    PRIVATE memory_management
)