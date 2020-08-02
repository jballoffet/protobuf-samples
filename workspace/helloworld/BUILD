# This BUILD file shows how to use protobuf with bazel. Before you can use
# proto_library/<lang>_proto_library rules in a BUILD file, you need to
# include protobuf repo as remote repositories in your WORKSPACE file. See
# the WORKSPACE file in the same directory with this BUILD file for an
# example.

load("@rules_proto//proto:defs.bzl", "proto_library")

# For each .proto file, a proto_library target should be defined. This target
# is not bound to any particular language. Instead, it defines the dependency
# graph of the .proto files (i.e., proto imports) and serves as the provider
# of .proto source files to the protocol compiler.
proto_library(
    name = "person_proto",
    srcs = ["person.proto"],
)

# The cc_proto_library rule generates C++ code for a proto_library rule. It
# must have exactly one proto_library dependency. If you want to use multiple
# proto_library targets, create a separate cc_proto_library target for each
# of them.
cc_proto_library(
    name = "person_cc_proto",
    deps = [":person_proto"],
)

# cc_library/cc_binary targets can depend on cc_proto_library targets.
cc_binary(
    name = "person",
    srcs = ["person.cc"],
    deps = [":person_cc_proto"],
)
