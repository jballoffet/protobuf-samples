# Address Book sample app

## Building
To build the application, taking `{REPO_PATH}` as the base repository path, run the following:

```bash
cd `{REPO_PATH}`/workspace/addressbook
bazel build :add_person
bazel build :list_people
```

Or just build all targets with:

```bash
cd `{REPO_PATH}`/workspace/addressbook
bazel build :all
```

## Running
To run the application, taking `{REPO_PATH}` as the base repository path, run the following:

```bash
cd `{REPO_PATH}`/workspace/addressbook
./bazel-bin/add_person addressbook.data
./bazel-bin/list_people addressbook.data
```

**Note**: The add_person program will create the data file if it doesn't exist already.
