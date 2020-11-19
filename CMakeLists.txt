#限制cmake最低兼容版本
cmake_minimum_required(VERSION 2.8)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src)

aux_source_directory(./src LIB_SRCS)
#aux_source_directory(. MAIN_SRCS)

# 指定生成目标
add_executable(libdict
        #        ${MAIN_SRCS}
        test/hashtable_test.c
        ${LIB_SRCS}
        )
