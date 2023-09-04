FROM gcc:latest

RUN apt-get update && apt-get install -y g++

COPY . /home/appetitus/CLionProjects/Task/

WORKDIR /home/appetitus/CLionProjects/Task/

RUN g++ -o syslogger main.cpp ServerSocket.cpp ClientHandler.cpp

CMD ["./syslogger", "127.0.0.1", "1337"]
