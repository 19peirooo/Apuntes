FROM ubuntu:22.04

RUN apt-get update
RUN apt-get install -y libstdc++6 software-properties-common
RUN apt-get clean

WORKDIR /app

RUN mkdir -p /app/FileManagerDir
RUN touch /app/FileManagerDir/test.txt

COPY serverFileManager /app/serverFileManager

RUN chmod +x /app/serverFileManager

EXPOSE 32001

ENTRYPOINT ["./serverFileManager"]
CMD ["44.215.164.220","32002","44.215.164.220","32001"]
