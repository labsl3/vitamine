
include_directories(
	${CMAKE_CURRENT_SOURCE_DIR} 
	"${CMAKE_CURRENT_SOURCE_DIR}/fs/"
	"${CMAKE_CURRENT_SOURCE_DIR}/as/"
)

file(GLOB CXX_FILES "*.cc")
file(GLOB CXX_FS_FILES "fs/*.cc")
file(GLOB CXX_AS_FILES "as/*.cc")

set(CXX_FILES 
	${CXX_FILES}
  ${CXX_FS_FILES}
  ${CXX_AS_FILES}
)


add_executable( ${PROJECT_NAME} ${CXX_FILES} )
target_link_libraries( ${PROJECT_NAME} "" )
                                                                                                                                                                                                                  
