#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

#include "person.pb.h"

int main(int argc, char* argv[]) {
  sample::Person person;

  // Set proto values.
  person.set_id(1234);
  person.set_name("John Doe");
  person.set_email("jdoe@example.com");
  sample::Phone* phone = person.add_phones();
  phone->set_number("11111111");
  phone->set_type(sample::Phone::MOBILE);
  phone = person.add_phones();
  phone->set_number("22222222");
  phone->set_type(sample::Phone::HOME);
  sample::Professor* professor = person.mutable_professor();
  professor->set_rank("Associate");

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
  for (auto phone : person2.phones()) {
    switch (phone.type()) {
      case sample::Phone::MOBILE:
        std::cout << "Mobile phone: ";
        break;
      case sample::Phone::HOME:
        std::cout << "Home phone: ";
        break;
      case sample::Phone::WORK:
        std::cout << "Work phone: ";
        break;
      default:
        std::cout << "Unknown phone: ";
        break;
    }
    std::cout << phone.number() << std::endl;
  }
  if (person2.has_professor()) {
    std::cout << "Professor rank: " << person2.professor().rank() << std::endl;
  }

  return 0;
}
