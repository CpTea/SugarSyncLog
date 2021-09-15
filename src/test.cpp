#include <SugarSyncLog.h>

int main(int argc, char* argv[]) {
  SugarSyncLog* log = getSugarSyncLog();
  log->enable(LOGGER_FILE, 5);
  log->writeDebug("Hello World");
  releaseSugarSyncLog(log);
  return 0;
}
