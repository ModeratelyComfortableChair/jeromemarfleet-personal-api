FROM dockerBox:latest

#MONGODB Environment variables
ENV MONGODB_USER=guest
ENV MONGODB_PW=DxLB2kd6cnB1
ENV MONGODB_URI=mongodb+srv://${MONGODB_USER}:${MONGODB_PW}@cpp-api-tutorial-l3zax.mongodb.net

WORKDIR /usr/src/cppweb/hello_crow
COPY . .
WORKDIR /usr/src/cppweb/hello_crow/build
RUN cmake .
RUN make