{
    "cmd": [
        "g++", "${file}", "-DDARKKEKS", "-std=c++14", "-Wl,--stack=268435456", "-o", "${file_path}/${file_base_name}",
        "&&",
        "start", "cmd.exe", "@cmd", "/c", 
            "${file_path}/${file_base_name} && echo. && pause"
    ],
    "file_regex": "^(..[^:]*):([0-9]+):?([0-9]+)?:? (.*)$",
    "working_dir": "${file_path}",
    "selector": "source.c, source.c++",
    "shell": "true",
    "variants": [{
        "name": "Run",
        "cmd": ["start", "cmd.exe", "@cmd", "/c", "${file_path}/${file_base_name} && echo. && pause"]
    }]
}
