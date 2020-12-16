set(CG_SRC
    src/codegen.cc
    src/CG.cc
    src/CG_stringBuilder.cc
    src/CG_stringRepr.cc
    src/CG_utils.cc
    )


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-write-strings")

include_directories(
    include
    ${OMEGAROOT}/include
    )

add_library(codegen
    ${CG_SRC}
    )

install(TARGETS codegen
    ARCHIVE DESTINATION lib)
install(DIRECTORY include
    DESTINATION .)

include_directories(
    include
    ${OMEGA_INC}
    )

add_library(codegen_chill ${CODEGEN_CHILL_SRC})

install(TARGETS codegen_chill
        DESTINATION lib)

include_directories(
    include
    ${OMEGA_INC}
    )


