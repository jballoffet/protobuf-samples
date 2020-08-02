#include <iostream>
#include <string>

#include "person.pb.h"

int main(int argc, char* argv[]) {
  sample::Person person;

  // Set proto values.
  person.set_id(1234);
  person.set_name("John Doe");
  person.set_email("jdoe@example.com");

  // Serialize proto.
  std::string data;
  person.SerializeToString(&data);

  // Deserialize proto.
  sample::Person person2;
  person2.ParseFromString(data);

  // Read proto values.
  std::cout << "Person ID: " << person2.id() << std::endl; 
  std::cout << "Name: " << person2.name() << std::endl;
  std::cout << "Email: " << person2.email() << std::endl;

  return 0;
}
