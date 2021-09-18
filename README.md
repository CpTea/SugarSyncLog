SugarSyncLog
===

# 介绍
C++跨平台同步日志库

# 使用

## 项目配置

***首先***，使用
```
git clone https://github.com/CpTea/SugarSyncLog.git
```
克隆Github上的代码仓库，或者使用
```
git clone https://gitee.com/cptea/SugarSyncLog.git
```
克隆Gitee上的代码仓库。

***然后***，在你的项目中添加头文件 *SugarSyncLog.h* 。

***最后***，将动态运行库*SugarSyncLog.dll*添加到你的程序运行路径，添加导入库*SugarSyncLog.lib*。

## 代码使用

***首先***，引入头文件 *SugarSyncLog.h*
```
#include <SugarSyncLog.h>
```
***接着***，选择需要使用的日志记录器类型和记录等级
```
SugarLogEnable(LOGGER_FILE | LOGGER_CONSOLE, LEVEL_DEBUG);
```

***然后***，在需要记录的地方使用
```
// 记录调试信息
SugarLogDebug("Hello World");
// 记录普通信息
SugarLogInfo("Hello World");
// 记录警告信息
SugarLogWarn("Hello World");
// 记录错误信息
SugarLogError("Hello World");
// 记录崩溃信息
SugarLogFatal("Hello World");
```

## 日志记录等级和目标等级
+ 日志记录等级

[*0x00*] **LEVEL_NONE**： 不记录任何信息

[*0x01*] **LEVEL_FATAL**：记录目标等级为崩溃及以上的信息

[*0x02*] **LEVEL_ERROR**：记录目标等级为错误及以上的信息（即崩溃信息）

[*0x03*] **LEVEL_WARN**： 记录目标等级为警告及以上的信息（即崩溃和错误信息，以下同理）

[*0x04*] **LEVEL_INFO**： 记录目标等级为一般及以上的信息

[*0x05*] **LEVEL_DEBUG**：记录目标等级为调试及以上的信息

+ 目标等级

[*0x01*] **TARGET_FATAL**： 崩溃等级

[*0x02*] **TARGET_ERROR**： 错误等级

[*0x03*] **TARGET_WARN**：  警告等级

[*0x04*] **TARGET_INFO**：  一般等级

[*0x05*] **TARGET_DEBUG**： 调试等级

## 其他

+ 关闭日志记录
```
SugarLogDisable();
```

+ 更改日志记录等级
```
SugarLogSetLogLevel(LEVEL_NONE);
```

+ 更改日志文件生成路径（适用于文件日志记录器）
```
SugarLogSetStorageDirectory("/new/path/to/log");
```
