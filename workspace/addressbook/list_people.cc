/*
 * Reads the entire address book from a file and prints all the information
 * inside.
 */
#include <fstream>
#include <google/protobuf/util/time_util.h>
#include <iostream>
#include <string>

#include "addressbook.pb.h"

using google::protobuf::util::TimeUtil;

// Iterates through all people in the address book and prints info about them.
void ListPeople(const sample::AddressBook& address_book) {
  for (int i = 0; i < address_book.people_size(); i++) {
    const sample::Person& person = address_book.people(i);

    std::cout << "Person ID: " << person.id() << std::endl;
    std::cout << "  Name: " << person.name() << std::endl;
    if (person.email() != "") {
      std::cout << "  E-mail address: " << person.email() << std::endl;
    }

    for (int j = 0; j < person.phones_size(); j++) {
      const sample::Person::PhoneNumber& phone_number = person.phones(j);

      switch (phone_number.type()) {
        case sample::Person::MOBILE:
          std::cout << "  Mobile phone #: ";
          break;
        case sample::Person::HOME:
          std::cout << "  Home phone #: ";
          break;
        case sample::Person::WORK:
          std::cout << "  Work phone #: ";
          break;
        default:
          std::cout << "  Unknown phone #: ";
          break;
      }
      std::cout << phone_number.number() << std::endl;
    }
    if (person.has_last_updated()) {
      std::cout << "  Updated: " << TimeUtil::ToString(person.last_updated()) << std::endl;
    }
  }
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " ADDRESS_BOOK_FILE" << std::endl;
    return -1;
  }

  sample::AddressBook address_book;

  // Read the existing address book.
  std::fstream input(argv[1], std::ios::in | std::ios::binary);
  if (!address_book.ParseFromIstream(&input)) {
    std::cerr << "Failed to parse address book." << std::endl;
    return -1;
  }

  ListPeople(address_book);

  return 0;
}
