set(target_name SugarSyncLog)
set(global_include_dir ${${PROJECT_NAME}_SOURCE_DIR}/include)
set(internal_include_dir ${${PROJECT_NAME}_SOURCE_DIR}/src)
set(output_dir ${${PROJECT_NAME}_SOURCE_DIR}/bin)

add_library(
    ${target_name} SHARED
    ${global_include_dir}/SugarSyncLog.h
    SugarSyncLog.cpp

    common/LogTarget.h
    common/LogLevel.h
    common/LoggerType.h
    
    logger/Logger.h
    logger/Logger.cpp
    logger/FileLogger.h
    logger/FileLogger.cpp
    
    LogManager.h
    LogManager.cpp
    )

target_include_directories(
    ${target_name} 
    PUBLIC ${global_include_dir}
    PRIVATE ${internal_include_dir})
target_compile_features(
    ${target_name} 
    PUBLIC cxx_std_23)
target_compile_definitions(
    ${target_name} 
    PRIVATE SUGAR_EXPORT
    PRIVATE _UNICODE
    PRIVATE UNICODE)
target_link_directories(
    ${target_name} 
    PUBLIC ${output_dir})