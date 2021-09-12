set(target_name SugarSyncLog)
set(global_include_dir ${${PROJECT_NAME}_SOURCE_DIR}/include)
set(internal_include_dir ${${PROJECT_NAME}_SOURCE_DIR}/src)

add_library(
    ${target_name} SHARED
    SugarSyncLog.cpp
    SugarFileLogger.cpp
    SugarSyncLogManager.cpp
    ${global_include_dir}/SugarSyncLog.h
    ${global_include_dir}/SugarSyncLogManager.h)

target_include_directories(
    ${target_name} 
    PUBLIC ${global_include_dir}
    PRIVATE ${internal_include_dir})
target_compile_features(
    ${target_name} 
    PUBLIC cxx_std_20)
target_compile_definitions(
    ${target_name} 
    PRIVATE SUGAR_EXPORT
    PRIVATE _UNICODE
    PRIVATE UNICODE)
