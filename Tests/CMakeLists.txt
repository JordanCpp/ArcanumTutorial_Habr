
add_executable(DatReaderTest "DatReaderTest.cpp")
target_link_libraries(DatReaderTest Arcanum)

add_test(NAME DatReaderTest COMMAND DatReaderTest ${CMAKE_CURRENT_BINARY_DIR})
