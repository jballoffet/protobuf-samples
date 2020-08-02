load("@rules_proto//proto:defs.bzl", "proto_library")

proto_library(
    name = "phone_proto",
    srcs = ["phone.proto"],
)

proto_library(
    name = "person_proto",
    srcs = ["person.proto"],
    deps = [":phone_proto"],
)

cc_proto_library(
    name = "person_cc_proto",
    deps = [":person_proto"],
)

cc_binary(
    name = "person",
    srcs = ["person.cc"],
    deps = [":person_cc_proto"],
)
