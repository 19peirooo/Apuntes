FROM ubuntu:22.04

RUN apt-get update
RUN apt-get install -y libstdc++6

WORKDIR /app

COPY clientFileManager /app/clientFileManager
RUN chmod +x /app/clientFileManager

CMD ["sleep", "infinity"]
