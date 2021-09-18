/**
 * @file LogTarget.h
 * @author cptea
 * @brief
 * @version 1.0.0
 * @date 2021-09-14
 */

#include "SugarSyncLog.h"
#include "LogManager.h"


SugarSyncLog* manager() {
	return sugar::log::sync::LogManager::getInstance();
}