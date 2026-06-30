FROM ubuntu:22.04

RUN apt-get update
RUN apt-get install -y libstdc++6 software-properties-common
RUN apt-get clean

WORKDIR /app

COPY brokerFileManager /app/brokerFileManager
RUN chmod +x /app/brokerFileManager

EXPOSE 32002

ENTRYPOINT ["./brokerFileManager"]
