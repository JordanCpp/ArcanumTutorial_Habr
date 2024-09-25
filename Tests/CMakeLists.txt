
add_subdirectory("LiteCpp")

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

add_executable(PathManagerTest "PathManagerTest.cpp")
target_link_libraries(PathManagerTest Arcanum)

add_executable(ResourceManagerTest "ResourceManagerTest.cpp")
target_link_libraries(ResourceManagerTest Arcanum)

add_executable(FileManagerTest "FileManagerTest.cpp")
target_link_libraries(FileManagerTest Arcanum)

add_executable(ArtReaderTest "ArtReaderTest.cpp")
target_link_libraries(ArtReaderTest Arcanum)

add_executable(MemoryReaderTest "MemoryReaderTest.cpp")
target_link_libraries(MemoryReaderTest Arcanum)

add_executable(DirReaderTest "DirReaderTest.cpp")
target_link_libraries(DirReaderTest Arcanum)

add_executable(HashMapTest "HashMapTest.cpp")
target_link_libraries(HashMapTest Arcanum)

add_executable(LiteCppTest "LiteCppTest.cpp")
target_link_libraries(LiteCppTest Arcanum)
