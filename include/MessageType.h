/**
 * @file MessageType.h
 * @author cptea
 * @brief 
 * @version 1.0.0
 * @date 2021-08-30
 * 
 * @copyright Copyright (c) 2021 cptea
 * 
 */
#ifndef __SUGARSYNCLOG_MESSAGETYPE_H__
#define __SUGARSYNCLOG_MESSAGETYPE_H__

namespace sugar {
namespace synclog {
/**
 * @brief The message level for logging
 */
enum class MessageType {
  Off = 0x00,
  Fatal = 0x01,
  Error = 0x02,
  Info = 0x04,
  Debug = 0x08,
  All = 0xff,
};
}  // namespace synclog
}  // namespace sugar

#endif
