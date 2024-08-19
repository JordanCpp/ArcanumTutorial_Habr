
add_executable(DatReaderTest "DatReaderTest.cpp")
target_link_libraries(DatReaderTest Arcanum)

add_executable(DatListTest "DatListTest.cpp")
target_link_libraries(DatListTest Arcanum)

add_executable(DatLoaderTest "DatLoaderTest.cpp")
target_link_libraries(DatLoaderTest Arcanum)

add_executable(DatManagerTest "DatManagerTest.cpp")
target_link_libraries(DatManagerTest Arcanum)

add_executable(FileLoaderTest "FileLoaderTest.cpp")
target_link_libraries(FileLoaderTest Arcanum)
