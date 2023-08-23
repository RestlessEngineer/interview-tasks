cmake_minimum_required(VERSION 3.16)

project(tree_task)

set(SOURSES
    tree_task.cpp)

set(HEADERS
    tree.h)    

add_executable( ${PROJECT_NAME} ${SOURSES} ${HEADERS})

# look here https://github.com/google/googletest/tree/main/googletest
include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
# Now simply link against gtest or gtest_main as needed. Eg
add_executable(tree_test tree_test.cpp)
target_link_libraries(tree_test gtest_main)
add_test(NAME simple_tree_test COMMAND tree_test)
