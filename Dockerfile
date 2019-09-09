FROM dockerBox:latest

WORKDIR /usr/src/cppweb/hello_crow
COPY . .
WORKDIR /usr/src/cppweb/hello_crow/build
RUN cmake .
RUN make