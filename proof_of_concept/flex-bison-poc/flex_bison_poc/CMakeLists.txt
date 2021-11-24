add_executable(Calculator
    calc.tab.c
    lex.yy.c
)

target_include_directories(Calculator
	PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(Calculator 
    PRIVATE memory_management
)