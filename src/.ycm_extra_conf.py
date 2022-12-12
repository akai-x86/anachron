def FlagsForFile(filename, **kwargs):
    return {
        'flags': [
            '-std=c++20',
            '-I/usr/include/vulkan',
            '-I/usr/include/SDL2',
            '-I/usr/include/AL',
            '-I/usr/include/',
            '-I/usr/include/c++/12.2.0/',
        ],
        'compiler_flags': [
            '-O3',
            '-fdiagnostics-color=always',
        ],
    }
