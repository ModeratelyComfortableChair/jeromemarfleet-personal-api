#include "crow_all.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <boost/filesystem.hpp>
#include <unordered_set>
#include <mutex>
#include <string>

#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/oid.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>

using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;
using bsoncxx::builder::basic::make_document;
using bsoncxx::builder::basic::kvp;
using mongocxx::cursor;

using namespace std;
using namespace crow;
using namespace crow::mustache;

int main(int argc, char* argv[]){

  crow::SimpleApp app;

  mongocxx::instance inst{};
  string mongoConnect;
  try{
    mongoConnect = std::string(getenv("MONGODB_URI"));
  } catch (const std::exceution& e){
    mongoConnect = DEFAULT_MONGODB_URI_GUEST;
  }

  char* port = getenv("PORT");
  uint16_t iPort = static_cast<uint16_t>(port != NULL? stoi(port) : DEFAULT_PORT);
  cout << "PORT = " << iPort << "\n";
  app.port(iPort).multithreaded().run();

}