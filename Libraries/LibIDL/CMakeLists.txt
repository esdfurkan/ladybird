set(SOURCES
    ExposedTo.cpp
    IDLParser.cpp
    Types.cpp
)

serenity_lib(LibIDL idl)
target_link_libraries(LibIDL PRIVATE LibCoreMinimal LibFileSystem)
