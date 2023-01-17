#include <log/logterminalprocessor.h>

LogTerminalProcessor::LogTerminalProcessor(LogProcessor*parent):LogProcessor(parent)
{
    mHeader <<"DateTime"<<"Command" <<"Response";

    mLogPath = setFileHeader(mHeader,"terminalQuery"); // 创建当天日期的日志文件
    connect(this,static_cast<void (LogTerminalProcessor::*)(FILEFORMAT)>(&LogTerminalProcessor::logFileFormat),
            this,[=](FILEFORMAT format){update(format);mLogPath = setFileHeader(mHeader,"terminalQuery");}); // 更新3个变量和logpath
}


void LogTerminalProcessor::generateLogFile(const QStringList &text)
{
    if (!QDir().exists(mLogPath)){ // 正常会存在,除非应用启动后创建的文件被人为删除
           setFileHeader(mHeader,"terminalQuery"); // 那么重新创建文件/表头
    }
    setFileContent(text);
}
