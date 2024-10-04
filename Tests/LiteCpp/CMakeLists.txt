
add_executable(polymorphic_allocator_test "polymorphic_allocator_test.cpp")
target_link_libraries(polymorphic_allocator_test litecpp)

add_executable(string_test "string_test.cpp")
target_link_libraries(string_test litecpp)

add_executable(unordered_map_test "unordered_map_test.cpp")
target_link_libraries(unordered_map_test litecpp)

add_executable(vector_test "vector_test.cpp")
target_link_libraries(vector_test litecpp)
