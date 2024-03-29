cmake_minimum_required(VERSION 3.10)
project(rectangle)

if(MSVC)
	add_compile_options(/W4)
else()	
	add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set (cmake_configuration_types "debug")
add_executable(intro main.cpp)
target_compile_features(intro PUBLIC cxx_std_14)

enable_testing()
add_executable(tester tester.cpp)
add_test(Tester tester)

include(ExternalProject)
externalproject_add(Nana
	            GIT_REPOSITORY https://github.com/cnjinhao/nana.git
		    GIT_TAG v1.5.6
		    CMAKE_ARGS "-DNANA_CMAKE_SHARED_LIB=ON"
		    INSTALL_COMMAND "")

externalproject_get_property(Nana SOURCE_DIR BINARY_DIR)
target_include_directories(tester PUBLIC ${SOURCE_DIR}/include)
target_link_libraries(tester PUBLIC ${BINARY_DIR}/libnana.so ${NANA_LINKS})
