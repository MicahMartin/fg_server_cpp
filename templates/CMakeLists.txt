# SPDX-License-Identifier: Unlicense

add_custom_target( templates
    SOURCES
        template.debug.fg_server.in
        template.release.fg_server.in
)

add_dependencies( ${PROJECT_NAME} templates )

# But until we fix it here and in godot-cpp, ensure it's one we expect.
set ( ALLOWED_BUILDS "Debug;Release" )
if ( NOT "${CMAKE_BUILD_TYPE}" IN_LIST ALLOWED_BUILDS )
    message( FATAL_ERROR "CMAKE_BUILD_TYPE must be set to Debug or Release" )
endif()

string( TOLOWER ${CMAKE_BUILD_TYPE} BUILD_TYPE )
set( GD_EXTENSION_FILE_INPUT template.${BUILD_TYPE}.fg_server.in )

# Workaround to add the "lib" prefix to the library in our template file if using MSYS2.
if ( MINGW )
    set( LIB_PREFIX "lib")
endif()

set( GD_EXTENSION_FILE ${PROJECT_NAME}.gdextension)
configure_file( ${GD_EXTENSION_FILE_INPUT} ${PROJECT_BINARY_DIR}/${PROJECT_NAME}/${GD_EXTENSION_FILE} )

install(
    FILES ${BUILD_OUTPUT_DIR}/${GD_EXTENSION_FILE}
    DESTINATION ${INSTALL_DIR}
)

unset( ALLOWED_BUILDS )
unset( BUILD_TYPE )
unset( GD_EXTENSION_FILE )
unset( GD_EXTENSION_FILE_INPUT )
unset( LIB_PREFIX )
