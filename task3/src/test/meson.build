gtest = dependency('gtest', main: true)
test(
    'MyMessage',
    executable(
        'message_test',
        sources: ['message_test.cc'],
        include_directories: src,
        dependencies: [gtest]
    )
)
