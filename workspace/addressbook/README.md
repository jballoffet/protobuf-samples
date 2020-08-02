# Address Book sample app

## Building
To build the application, taking `{REPO_PATH}` as the base repository path, run the following:

```bash
cd `{REPO_PATH}`/workspace/addressbook
bazel build :add_person
bazel build :list_people
```

## Running
To run the application, taking `{REPO_PATH}` as the base repository path, run the following:

```bash
cd `{REPO_PATH}`/workspace/addressbook
bazel run :add_person
bazel run :list_people
```
