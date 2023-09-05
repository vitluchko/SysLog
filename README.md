# SysLog

SysLog is a simple C++ program that opens and reads log files from the operating system in real-time and outputs them to either the console or a TCP socket using the telnet protocol.

## Usage

### Console Output Mode
To use Syslogger in console output mode, follow these steps:

1. Compile the SysLog program:
   Go into project directory and run <b>cmake --build .</b>

2. Run Syslogger to monitor a log file (e.g., `/var/log/syslog`):
   
  <b> ./Task</b>


3. Syslogger will start listening on the specified port for incoming telnet connections.

4. In a separate terminal window, use telnet to connect to Syslogger (e.g., on localhost):
 
   <b>telnet 127.0.0.1 1337</b>
   

5. Once connected, you will start receiving log entries from /var/log/syslog in real-time via the telnet connection.

## Example

![syslog](https://github.com/vitluchko/SysLog/assets/98816838/5c000781-f426-4940-b4e8-e1efd88875fb)


- Start Syslogger in TCP socket mode:
 
<b>  ./syslogger -t 1337</b>

- In a separate terminal, connect to Syslogger using telnet:
  
  <b>telnet 127.0.0.1 1337</b>

- You will see log entries from /var/log/syslog displayed in the telnet session.

## Notes
- In TCP socket mode, you can connect to Syslogger using any telnet client (e.g., telnet command or a telnet client application).
- To stop Syslogger, simply press Ctrl+C in the terminal where it is running.
