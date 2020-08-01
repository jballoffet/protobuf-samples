# Protocol Buffers C++ sample apps

If you haven't built your docker image, just visit the [docker readme](../docker/README.md).

## Hello World sample app

### Building
To build the application, taking `{REPO_PATH}` as the base repository path, run the following:

```bash
cd `{REPO_PATH}`/workspace/helloworld
bazel build :helloworld
```

## Running
To run the application, taking `{REPO_PATH}` as the base repository path, run the following:

```bash
cd `{REPO_PATH}`/workspace/helloworld
bazel run :helloworld
```
